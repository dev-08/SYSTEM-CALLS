
#include "syslib.h"
int sys_trapinc(endpoint_t proc_ep, int *trapinc)

{
    printf("call in sys_trapinc");
    message m;
    m.m_source = proc_ep;

    int ret = _kernel_call(SYS_TRAPINC, &m);
    printf("ret value %d" , ret);

    if(ret!=OK) 
    {
            printf("libsys error %d" , ret);
            return ret;

    }
    *trapinc = m.m_lsys_krn_sys_p2.num;
    return OK;
    
}
