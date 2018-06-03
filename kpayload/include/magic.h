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

#define __Xfast_syscall							0x1C0		// Updated from xvortex 
#define __copyin								0x1EA710  	// Updated using fail0verflow 
#define __copyout								0x1EA630	// Updated using fail0verflow 
#define __printf								0x436040    // Updated using fail0verflow 
#define __vprintf                               0x017FA0
#define __malloc								0x10E250	// Updated using ps4-hen-vtx
#define __free									0x3F7930    // Updated using ps4-hen-vtx
#define __memcpy								0x1EA530	// Updated using ps4-hen-vtx
#define __memset								0x3205C0	// Updated using ps4-hen-vtx
#define __memcmp								0x050AC0	// Updated using ps4-hen-vtx
#define __kmem_alloc							0xFCC80		// Updated via ChendoChap
#define __strlen                                0x3B71A0	// Updated using ps4-hen-vtx
#define __pause									0x261120
#define __kthread_add							0x138360	// Updated using OpenOrbis
#define __kthread_exit							0x138640	// Updated using OpenOrbis
#define __sched_prio							0x072410
#define __sched_add								0x072740
#define __kern_yield							0x261440
#define __fill_regs								0x2829C0
#define __set_regs								0x282AF0
#define __create_thread							0x2ECCD0
#define __kproc_create							0x464700
#define __kthread_set_affinity					0x4655E0
#define __kthread_suspend_check					0x465380
#define __kproc_kthread_add						0x465490
#define __sx_init_flags							0x38F900
#define __sx_xlock								0x38FA30
#define __sx_xunlock							0x38FBC0
#define __mtx_init								0x30E0C0
#define __mtx_lock_spin_flags					0x30DA70
#define __mtx_unlock_spin_flags					0x30DC30
#define __mtx_lock_sleep						0x30D6A0
#define __mtx_unlock_sleep						0x30D940
#define __fpu_kern_enter						0x059580
#define __fpu_kern_leave						0x059680
#define __kern_reboot							0x0998A0
#define __vm_map_lock_read						0x19f140	// Updated using OpenOrbis
#define __vm_map_lookup_entry					0x392C70
#define __vm_map_unlock_read					0x392100
#define __vmspace_free							0x391D10
#define __vm_map_delete							0x394790
#define __vm_map_protect						0x396860
#define __vmspace_acquire_ref					0x19ef90	// Updated using OpenOrbis
#define __vm_map_findspace						0x394E90
#define __vm_map_insert							0x392F70
#define __vm_map_lock							0x391F40
#define __vm_map_unlock 						0x391FB0
#define __proc_rwmem							0x17CB70
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
#define __prison0                               0x10986A0 	// Updated using AppToUsb50X
#define __rootvnode                             0x22C1A70 	// Updated using AppToUsb50X
#define __allproc						0x1AD7718
#define __fpu_kern_ctx					0x251CCC0
#define __mini_syscore_self_binary 		0x1471468
#define __sbl_driver_mapped_pages  		0x2519DD0
#define __sbl_keymgr_key_rbtree			0x2534DE0
