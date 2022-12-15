
#include "pm.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/syslib.h>
#include "glo.h"
#include "mproc.h"

int do_msginc(){

    register struct mproc *sending_proc = mp;
    int msg = 0;
    int ret = sys_msginc(sending_proc->mp_endpoint, &msg);

/*  if(ret!=OK)
    {
        printf("PM: ERROR in msg function %d", ret);
        return ret;
    }
    
    
    */
   return ret;
}

int do_resetmsg(){

    register struct mproc *sending_proc = mp;
    int ret = sys_resetmsg(sending_proc->mp_endpoint);

/*
    if(ret!=OK)
    {
        printf("\n error in reset msg in interface,c %d", ret);
        return ret;
    }
*/
    return OK;
   }

int do_resettrap(){

    printf(" Reset in interface");
    register struct mproc *sending_proc = mp;
    int retu = sys_resettrap(sending_proc->mp_endpoint);

/*
    if(retu!=OK){
        printf("Error in reset %d", retu);
        return retu;
    }
*/
    return OK:
}

int do_trapinc(){

    printf("PM service: Calling from trapinc \n");
    int proc_n;
    int trap = 0;
    register struct mproc *sending_proc = mp;

    int ret = sys_trapinc(sending_proc->mp_endpoint, &trap);
    /*
    
    if(ret!=OK){

        printf("PM : ERROR %d", ret);
        return ret;
    }

    */

   return ret;
}
