#include "syslib.h"


int sys_resetmsg(endpoint_t proc_ep)
{
	message m;
	m.m_source = proc_ep;
	int return_value = _kernel_call(SYS_RESETMSG, &m);
	printf("\n ret value in sys_resetmsg.c");

	return OK;
}
