#include <lib.h>
#define trapinc _trapinc
#define resettrap _resettrap
#define msginc _msginc
#define resetmsg _resetmsg
#include <unistd.h>

int trapinc()
{
	message m;
    printf("Hello from project2.h");
        int r = _syscall(PM_PROC_NR, PM_TRAPINC, &m);
	return m.m_lsys_krn_sys_project2.num;
}
int resettrap()
{
	message m;
    printf("Hello from project2.h");
        int r = _syscall(PM_PROC_NR, PM_RESETTRAP, &m);
	return m.m_lsys_krn_sys_project2.num;
}
int msginc()
{
	message m;
    printf("Hello from project2.h");
        int r = _syscall(PM_PROC_NR, PM_MSGINC, &m);
	return m.m_lsys_krn_sys_project2.num;
}
int resetmsg()
{
	message m;
    printf("Hello from project2.h");
        int r = _syscall(PM_PROC_NR, PM_RESETMSG, &m);
	return m.m_lsys_krn_sys_project2.num;
}