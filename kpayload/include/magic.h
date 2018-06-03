// magic.h
//
// 1/2/2018 - golden
// ------------------
// inspired by fail0verflow, of course
// 4.55
//
// ref FFFFFFFF8F59C000
//
// 6/3/2018 - RStock
// ------------------
// TODO Update all of these
// https://github.com/xvortex/ps4-hen-vtx/blob/master/kpayload/include/offsets.h
// https://github.com/OpenOrbis/oni-framework/blob/4633038397cd524d7e6103a214cbb4935988fe2c/include/oni/utils/kdlsym/orbis505.h
//

#define __Xfast_syscall							0x1c0	    // Updated from xvortex 
#define __copyin								0x1EA710 	// Updated using fail0verflow 
#define __copyout								0x1EA630	// Updated using fail0verflow 
#define __printf								0x436040	// Updated using fail0verflow 
#define __vprintf                               0x10E250
#define __malloc								0x4360B0	// Updated using ps4-hen-vtx
#define __free									0x10E460	// Updated using ps4-hen-vtx
#define __memcpy								0x1EA530	// Updated using ps4-hen-vtx
#define __memset								0x3205C0	// Updated using ps4-hen-vtx
#define __memcmp								0x050AC0	// Updated using ps4-hen-vtx
#define __kmem_alloc							0x0FCC80	// Updated via ChendoChap
#define __strlen                                0x3B71A0	// Updated using ps4-hen-vtx
#define __pause									0x3FB920
#define __kthread_add							0x138360	// Updated using OpenOrbis
#define __kthread_exit							0x138640	// Updated using OpenOrbis
#define __sched_prio							0x31EE00
#define __sched_add								0x31F150
#define __kern_yield							0x3FBC40
#define __fill_regs								0x234BA0
#define __set_regs								0x234CD0
#define __create_thread							0x1BE1F0
#define __kproc_create							0x137df0
#define __kthread_set_affinity					0x138CC0
#define __kthread_suspend_check					0x138A60
#define __kproc_kthread_add						0x138B70
#define __sx_init_flags							0xF5BB0
#define __sx_xlock								0xf5e10
#define __sx_xunlock							0xf5fd0
#define __mtx_init								0x00402780
#define __mtx_lock_spin_flags					0x402100
#define __mtx_unlock_spin_flags					0x4022C0
#define __mtx_lock_sleep						0x401CD0
#define __mtx_unlock_sleep						0x401FA0
#define __fpu_kern_enter						0x1BFF90
#define __fpu_kern_leave						0x1C0090
#define __kern_reboot							0x0010D390
#define __vm_map_lock_read						0x19f140	// Updated using OpenOrbis
#define __vm_map_lookup_entry					0x19F760
#define __vm_map_unlock_read					0x19F190
#define __vmspace_free							0x19EDC0
#define __vm_map_delete							0x1A19D0
#define __vm_map_protect						0x1A3A50
#define __vmspace_acquire_ref					0x19EF90	// Updated using OpenOrbis
#define __vm_map_findspace						0x1A1F60
#define __vm_map_insert							0x1A0280
#define __vm_map_lock							0x19EFF0
#define __vm_map_unlock 						0x19F060
#define __proc_rwmem							0x30D150


#define __sceSblAuthMgrIsLoadable2				0x625C50
#define __sceSblAuthMgrVerifyHeader				0x625CB0
#define __sceSblAuthMgrGetSelfInfo				0x626490
#define __sceSblAuthMgrSmStart					0x622020
#define __sceSblKeymgrSmCallfunc				0x60E680
#define __sceSblPfsKeymgrGenEKpfsForGDGPAC		0x60F000
#define __sceSblPfsSetKey						0x606E00
#define __sceSblPfsClearKey						0x606F80
#define __sceSblServiceMailbox					0x6146C0
#define __sceSblServiceCrypt					0x60C880
#define __sceSblServiceCryptAsync				0x60CA10
#define __AesCbcCfb128Encrypt					0x17A4C0
#define __AesCbcCfb128Decrypt					0x17A6F0
#define __Sha256Hash							0x2D5B80
#define __Sha256Hmac							0x2D5C50
#define __RsaesPkcs1v15Enc2048					0x4667D0
#define __RsaesPkcs1v15Dec2048CRT				0x3EF200

#define __disable_console_output                0x09ECEB0	// Updated using ExodusSecurity
#define __M_TEMP					        	0x14B4110	// Updated using ps4-hen-vtx
#define __kernel_map                            0x1AC60E0 	// Updated using fail0verflow 
#define __prison0                               0x10986a0 	// Updated using AppToUsb50X
#define __rootvnode                             0x22c1a70 	// Updated using AppToUsb50X
#define __allproc								0x2382FF8
#define __fpu_kern_ctx							0x2720840
#define __mini_syscore_self_binary 				0x14C9D48
#define __sbl_driver_mapped_pages  				0x271E208
#define __sbl_keymgr_key_rbtree					0x2744558
