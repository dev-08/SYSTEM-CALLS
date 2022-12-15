#include "syslib.h"

int sys_inittrapcounter(endpoint_t proc_ep)
{
    printf("Making a kernel call next \n");
    message m;
    // m.m_source = proc_ep;
    // m.m_type = 1;
    // printf("SYS_INITTRAPCOUNTER %d \n",SYS_INITTRAPCOUNTER);
    return(_kernel_call(SYS_INITTRAPCOUNTER, &m));
}