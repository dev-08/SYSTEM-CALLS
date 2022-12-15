#include "kernel/system.h"
#include <minix/endpoint.h>

#if USE_RESETMSG

//static int tc = 0;

int do_resetmsg(struct proc *caller, message *m_ptr)
{
    //printf("Kernel: Trap incrementer started \n");
    //ct=ct+1;
    mt=0;
    m_ptr->m_pm_lsys_project2.num = mt;
    //printf("Kernel: do_trapinc called %d times\n",ct); 
    //printf("KERNEL: RESETTRA ");
    return OK;
}

#endif