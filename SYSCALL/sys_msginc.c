
#include "syslib.h"

// this is the sys_call in msginc  
int sys_msginc(endpoint_t proc_ep, int *msginc)

{
    printf("\n SYSCALL : MSGINC \n");
    message m;
    m.m_source = proc_ep;
    int ret = _kernel_call(SYS_MSGINC, &m);
    return OK;
    
}
