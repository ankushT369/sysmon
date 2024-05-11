#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>

int main(int argc, char* argv[]) {

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
    }

    /* ProcessID of the tracee and regs stands for registers to monitor its changes*/
    pid_t pid;
    struct user_regs_struct regs;

    pid = atoi(argv[1]);

    /* Attaches to the tracee */
    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    
    waitpid(pid, NULL, 0);

    while(1) {
        /* Gets the registers into the struct variable regs*/
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);

        /* Get the systemcall number from orig_rax*/
        long syscall_num = regs.orig_rax;

        printf("Syscall number: %ld\n", syscall_num);   //Print the system call number you can visit this website https://hackeradam.com/x86-64-linux-syscalls/ 

        /* Tracee excutes the next instruction*/
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);

        waitpid(pid, NULL, 0);
    }

    /* Detach from the tracee*/
    ptrace(PTRACE_DETACH, pid, NULL, NULL);

    return 0;
}

