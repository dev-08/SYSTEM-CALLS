#include "kernel/system.h"
#include <minix/endpoint.h>

#if USE_TRAPINC

static int ct = 0;

int do_trapinc(struct proc *caller, message *m_ptr)
{
    printf("Kernel: Trap incrementer started \n");
    ct=ct+1;
    m_ptr->m_pm_lsys_project2.num = ct;
    printf("Kernel: do_trapinc called %d times\n",ct); 
    return OK;
}

#endif