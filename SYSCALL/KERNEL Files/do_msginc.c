#include "kernel/system.h"
#include <minix/endpoint.h>

#if USE_MSGINC

static int mt = 0;

int do_msginc(struct proc *caller, message *m_ptr)
{
    if(m_ptr == OK) { mt++; }
    m_ptr->m_pm_lsys_project2.num = mt;
    printf("KERNEL: Total messages : %d\n",mt); 
    return OK;
}

#endif