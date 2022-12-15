#include "kernel/system.h"
#include <minix/endpoint.h>

#if USE_RESETTRAP

//static int tc = 0;

int do_resettrap(struct proc *caller, message *m_ptr)
{
    //printf("Kernel: Trap incrementer started \n");
    //ct=ct+1;
    ct=0;
    m_ptr->m_pm_lsys_project2.num = ct;
    //printf("Kernel: do_trapinc called %d times\n",ct);
    printf("KERNEL: RESETTRAP Counter \n"); 
    return OK;
}

#endif