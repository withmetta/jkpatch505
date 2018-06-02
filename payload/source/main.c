/* main.c
 * RStock
 * 
 * Updated to 5.05 using:
 * - MiraFW - https://github.com/OpenOrbis/mira-project/blob/master/Firmware/MiraFW/src/mira/boot/patches/patches505.c
 */

#include "jkpatch.h"
#include "install.h"

// perfect for putty
void ascii_art(void *_printf) {
	printf("\n\n");
	printf("   _ _                _       _     \n");
	printf("  (_) | ___ __   __ _| |_ ___| |__  \n");
	printf("  | | |/ / '_ \\ / _` | __/ __| '_ \\ \n");
	printf("  | |   <| |_) | (_| | || (__| | | |\n");
	printf(" _/ |_|\\_\\ .__/ \\__,_|\\__\\___|_| |_|\n");
	printf("|__/     |_|                        \n");
	printf("\n\n");
}

void jailbreak(struct thread *td, uint64_t kernbase) {
	void **prison0 =   (void **)(kernbase + __prison0);
	void **rootvnode = (void **)(kernbase + __rootvnode);

	struct ucred* cred;
	struct filedesc* fd;

	fd = td->td_proc->p_fd;
	cred = td->td_proc->p_ucred;

	cred->cr_uid = 0;
	cred->cr_ruid = 0;
	cred->cr_rgid = 0;
	cred->cr_groups[0] = 0;
	cred->cr_prison = *prison0;
	fd->fd_rdir = fd->fd_jdir = *rootvnode;
}

void debug_patches(struct thread *td, uint64_t kernbase) {
	// sorry... this is very messy!
	// debug settings patches (Updated for 5.05)
	*(uint8_t *)(kernbase + 0x1CD0686) |= 0x14;
	*(uint8_t *)(kernbase + 0x1CD06A9) |= 0x3;
	*(uint8_t *)(kernbase + 0x1CD06AA) |= 0x1;
	*(uint8_t *)(kernbase + 0x1CD06C8) |= 0x1;


	// Old. For 4.55
	// *(uint32_t *)(kernbase + 0x69F4E0) = 0x90C3C031; // flatz RSA check patch
	// *(uint64_t *)(kernbase + 0x62D30D) = 0x3D38EB00000001B8; // flatz enable debug rifs
	
	// Updated for 5.05
	*(uint8_t *)(kernbase + 0x736250) = 0xC3;		// disable sysdump_perform_dump_on_fatal_trap, will continue execution and give more information on crash, such as rip
	*(uint32_t *)(kernbase + 0x6A2700) = 0x90C3C031; // flatz disable pfs signature check 5.05
	*(uint32_t *)(kernbase + 0x64B2B0) = 0x90C301B0; // flatz enable debug RIFs 5.05
	*(uint32_t *)(kernbase + 0x64B2D0) = 0x90C301B0;

	// patch vm_map_protect check
	memcpy((void *)(kernbase + 0x396A58), "\x90\x90\x90\x90\x90\x90", 6); // TODO Check if needs update for 5.05

	// patch ASLR, thanks 2much4u
	// KERN_PROCESS_ASLR = 0x1BA559
	*(uint16_t *)(kernbase + 0x1BA559) = 0x9090; // TODO Check if needs update for 5.05 
}

void scesbl_patches(struct thread *td, uint64_t kernbase) {
	char *td_ucred = (char *)td->td_ucred;

	// signed __int64 __fastcall sceSblACMgrGetDeviceAccessType(__int64 a1, __int64 a2, _DWORD *a3)
	// v6 = *(_QWORD *)(a1 + 0x58);
	*(uint64_t *)(td_ucred + 0x58) = 0x3801000000000013; // gives access to everything (Did not change from 5.05)

	/*
	 signed __int64 __fastcall sceSblACMgrIsSystemUcred(__int64 a1) {
		return (*(_QWORD *)(a1 + 0x60) >> 62) & 1LL;
	 }
	*/
	*(uint64_t *)(td_ucred + 0x60) = 0xFFFFFFFFFFFFFFFF;

	/*
	__int64 __fastcall sceSblACMgrHasSceProcessCapability(__int64 a1) {
		return *(_QWORD *)(a1 + 0x68) >> 63;
	}
	*/
	*(uint64_t *)(td_ucred + 0x68) = 0xFFFFFFFFFFFFFFFF;

	// Old 4.55: *(uint8_t *)(kernbase + 0x36057B) = 0; // Haven't checked if updated for 5.05 (but if it's like the rest it probably hasn't)
	// sceSblACMgrIsAllowedSystemLevelDebugging (updated to 5.05 using MiraFW)
	uint8_t *kmem = (uint8_t *)&kernbase[0x00010FC0];
	kmem[0] = 0xB8; kmem[1] = 0x01; kmem[2] = 0x00; kmem[3] = 0x00;
	kmem[4] = 0x00; kmem[5] = 0xC3; kmem[6] = 0x90; kmem[7] = 0x90;

	kmem = (uint8_t *)&kernbase[0x00011756];
	kmem[0] = 0xB8; kmem[1] = 0x01; kmem[2] = 0x00; kmem[3] = 0x00;
	kmem[4] = 0x00; kmem[5] = 0xC3; kmem[6] = 0x90; kmem[7] = 0x90;
	
}

int receive_payload(void **payload, size_t *psize) {
	struct sockaddr_in server;
	server.sin_len = sizeof(server);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = IN_ADDR_ANY;
	server.sin_port = sceNetHtons(9023);
	memset(server.sin_zero, 0, sizeof(server.sin_zero));

	int servsock = sceNetSocket("jkpatch", AF_INET, SOCK_STREAM, 0);

	sceNetBind(servsock, (struct sockaddr *)&server, sizeof(server));

	sceNetListen(servsock, 128);

	int client = sceNetAccept(servsock, NULL, NULL);
	if (client < 0) {
		return 1;
	}

	void *data = (void *)malloc(4096);
	int recvlen = 0;
	int length = 0;

	while (1) {
		recvlen = sceNetRecv(client, data + length, 4096, 0);
		length += recvlen;

		if (recvlen) {
			void *ndata = (void *)realloc(data, length + 4096);
			if (ndata) {
				data = ndata;
			} else {
				break;
			}
		} else {
			break;
		}
	}

	if (payload) {
		*payload = data;
	} else {
		free(data);
	}

	if (psize) {
		*psize = length;
	}

	sceNetSocketClose(servsock);

	return 0;
}

struct jkuap {
	uint64_t sycall;
	void *payload;
	size_t psize;
};

int jkpatch(struct thread *td, struct jkuap *uap) {
	uint64_t kernbase = getkernbase();
	resolve(kernbase);

	// disable write protect
	uint64_t CR0 = __readcr0();
	__writecr0(CR0 & ~CR0_WP);

	// enable uart
	uint8_t *disable_console_output = (uint8_t *)(kernbase + __disable_console_output); // Updated for 5.05
	*disable_console_output = FALSE;

	// real quick jailbreak ;)
	jailbreak(td, kernbase);

	// quick debug patches
	debug_patches(td, kernbase);

	// sceSblMgr patches
	scesbl_patches(td, kernbase);

	// restore CR0
	__writecr0(CR0);

	// print some stuff
	ascii_art(printf);
	printf("jkpatch installer loaded\n");
	printf("[jkpatch] kernbase 0x%llX\n", kernbase);

	printf("[jkpatch] loading payload...\n");

	if (!uap->payload) {
		printf("[jkpatch] payload data is NULL!\n");
		return 1;
	}

	// install wizardry
	if (install_payload(td, kernbase, uap->payload, uap->psize)) {
		printf("[jkpatch] install_payload failed!\n");
		return 1;
	}

	printf("[jkpatch] all done! have fun with homebrew!\n");

	return 0;
}

int _main(void) {
	initKernel();
	initLibc();
	initNetwork();

	// fuck up the updates
	unlink("/update/PS4UPDATE.PUP");
	mkdir("/update/PS4UPDATE.PUP", 777);

	size_t psize = 0;
	void *payload = NULL;
	receive_payload(&payload, &psize);

	syscall(11, jkpatch, payload, psize);

	if (payload) {
		free(payload);
	}

	return 0;
}
