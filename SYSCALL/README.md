// took refrence from class presentaion and minix3.org.

Following are the steps to add four system calls:
To add the system calls first we have to download the source code, download dependencies and finally rebuild the kernel.

Rebuilding kernel can be done in 2 ways i.e. Rebuilding kernel within minix or through cross compilation and we went with the first method i.e. Rebuilding kernel within minix. This requires rebuilding of system.

1.  Firstly we check for any updates required for pkgin using the command pkgin up. After updating the pkgin we download all the dependencies such as git to clone the source code into the trunk of src in minix.
    Using # pkgin_sets we can fetch and download all the required dependencies.

2. Following are commands to clone source code:
    # cd /usr
    # git clone git://git.minix3.org/minix src      


3. Now we have to recompile the system
    # cd /usr/src
    # make build
    After the recompilation reboot the minix and start with updated or latest boot.


Now adding a kernel call:
1. Add(define) the new kernel calls in com.h
     In /usr/src/minix/include/minix/com.h
 #  define SYS_PADCONF (KERNEL_CALL + 57)	
 #  define SYS_TRAPINC    (KERNEL_CALL + 58)      
 #  define SYS_RESETTRAP    (KERNEL_CALL + 59)      
 #  define SYS_MSGINC    (KERNEL_CALL + 60)      
 #  define SYS_RESETMSG    (KERNEL_CALL + 61) 
/* Total */ 
#define NR_SYS_CALLS    62      /* number of kernel calls */


2. Now implement the kernel calls by creating the files in /usr/src/minix/kernel/system/
   Refer the files do_trapinc.c , do_resettrap.c, do_msginc.c, do_resetmsg


3. Now declare these kernel call prototypes in /usr/src/minix/kernel/system.h
 int do_trapinc(struct proc *caller, message *m_ptr);
 #if ! USE_TRAPINC 
 #define do_trapinc NULL
 #endif
int do_resettrap (struct proc *caller, message *m_ptr);
 #if ! USE_RESETTRAP 
 #define do_resettrap NULL
 #endif
int do_ do_msginc (struct proc *caller, message *m_ptr);
 #if ! USE_MSGINC 
 #define do_msginc NULL
 #endif
int do_resetmsg (struct proc *caller, message *m_ptr);
 #if ! USE_RESETMSG 
 #define do_resetmsg NULL
 #endif

4. map the Kernel call with the prototype in /usr/src/minix/kernel/system.c
    map(SYS_TRAPINC, do_trapinc);
    map(SYS_RESETTRAP, do_resettrap);
    map(SYS_MSGINC, do_msginc);
    map(SYS_RESETMSG, do_resetmsg);


5. Enable the kernel code by modifying config.h in /usr/src/minix/kernel/config.h
   #define USE_TRAPINC      1 
   #define USE_RESETTRAP      1 
   #define USE_MSGINC      1 
   #define USE_RESETMSG      1 


6. Create new functions in /usr/src/minix/lib/libsys/
   Refer sys_trapinc.c,sys_msginc,sys_resettrap,sys_resetmsg in the zip file.


7.  Next define the prototypes in syslib i.e. in /usr/src/minix/include/minix/syslib.h
  int sys_trapinc(endpoint_t proc_ep, int * trap);
  int sys_resettrap(endpoint_t proc_ep);
  int sys_msginc(endpoint_t proc_ep, int * trap);
  int sys_resetmsg(endpoint_t proc_ep);


8. In the /usr/src/minix/commands/minix-service/parse.c modify the file parse.c file i.e. add the new system calls in the system tab[].
  { "TRAPINC",             SYS_TRAPINC },
  { "RESETTRAP",             SYS_ RESETTRAP },
  { "MSGINC",             SYS_ MSGINC },
  { "RESETMSG",             SYS_ RESETMSG },


9. Now in /usr/src/minix/kernel/system/Makefile.inc 
    Add the do_trapinc.c, do_resettrap.c, do_msginc.c, do_resetmsg.c 


10. In /usr/src/minix/commands/minix-service/
       # make
       # make install
11. Now in /usr/src/minix/lib/libsys/Makefile add the system call  
       SRCS+=  \ ...         
                     sys_trapinc.c \
 	       sys_resettrap.c \
	       sys_msginc.c \
                     sys_resetmsg.c \
12. Now go to usr/src/releasetools
      # Make hdboot
      After the compilation reboot the os and start with latest minix in boot.



For PM serv:
13. Define the pm call in /usr/src/minix/include/minix/callnr.h
#define PM_TRAPINC  (PM_BASE + 48)
#define PM_RESETTRAP  (PM_BASE + 49)
#define PM_MSGINC  (PM_BASE + 50)
#define PM_RESETMSG  (PM_BASE + 51)
#define NR_PM_CALLS  52

14. Add the prototypes in /usr/src/minix/servers/pm/proto.h
int do_trapinc(void);
int do_resettrap(void);
int do_msginc(void);
int do_resetmsg(void);

15. Add the interface.c file in the pm i.e. /usr/src/minix/servers/pm/
     Refer interface.c file in the zip.
16.Now in /usr/src/minix/servers/pm/table.c modify the table.c i.e add the defined PM proto from above 
CALL(PM_TRAPINC) = do_trapinc
CALL(PM_RESETTRAP) = do_resettrap
CALL(PM_MSGINC) = do_msginc
CALL(PM_RESETMSG) = do_resetmsg
 Now In cd/usr/src/releasetools

16. In /usr/src/include/unistd.h define the prototypes
   Int trapinc(void);
   Void resettrap(void);
   Int msginc(void);
   Void resetmsg(void); 
17. implement the project2.h
    For code refer the project2.h file
18. Add the project2.h in /usr/src/include/Makefile
Now again perform make hdboot in usr/src/releasetools. 
After the make install is done reboot and implement the system calls.
To implement the system calls in project 1 code refer the thread.c file.



