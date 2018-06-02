// 06/01/1988 - RStock
// This is the only thing I've touched so far. Looking to get the rest of the offsets before recompiling.
// 
// 
// To update the offsets I used: 
// https://github.com/OpenOrbis/oni-framework/blob/4633038397cd524d7e6103a214cbb4935988fe2c/include/oni/utils/kdlsym/orbis505.h
// https://github.com/fail0verflow/ps4-kexec/blob/master/magic.h
// https://github.com/xvortex/ps4-hen-vtx/blob/master/kpayload/include/offsets.h#L16
// https://github.com/ExodusSecurity/PS4Offsets-With-Payloads
//
// Original file: 
// https://github.com/xemio/jkpatch/blob/38771ae100afe446bf8622501e01b8f1a958a45e/payload/include/magic.h
//
// ref FFFFFFFF8F59C000 (Didn't know what this comment meant)
// 

#define __Xfast_syscall							0x1C0  		// Updated using AppToUsb50X 
#define __copyin								0x1EA710  	// Updated using fail0verflow 
#define __copyout								0x1EA630	// Updated using fail0verflow 
#define __printf								0x436040    // Updated using fail0verflow 
#define __malloc								0x10E250    // Not in fail0verflow's or fail0verflow's kern_off_kmem_alloc_contig.
#define __free									0x3F7930    // Updated using ps4-hen-vtx
#define __memcpy								0x1EA530	// Updated using ps4-hen-vtx
#define __memset								0x3205C0	// Updated using ps4-hen-vtx
#define __memcmp								0x050AC0	// Updated using ps4-hen-vtx
#define __kmem_alloc							0x16ECD0  	// ???
#define __strlen                                0x3B71A0	// Updated using ps4-hen-vtx

#define __disable_console_output                0x09ECEB0	// Updated using ExodusSecurity
#define __M_TEMP					        	0x14B4110	// Updated using ps4-hen-vtx
#define __kernel_map                            0x1AC60E0 	// Updated using fail0verflow 
#define __prison0                               0x10986A0 	// Updated using AppToUsb50X
#define __rootvnode                             0x22C1A70 	// Updated using AppToUsb50X
