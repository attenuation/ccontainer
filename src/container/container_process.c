#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE (1024 * 1024)
static char child_stack[STACK_SIZE];


int child_proc(void *args) {
    sethostname("Changed Namespaca", 12);
    char **args_ptr = args;
    printf("%s %s\n",args_ptr[0],args_ptr[1]);
    execve(args_ptr[0],args_ptr,NULL);
    return 0;
}


size_t run_container(bool tty,char *command) {
    // if(tty) {

    // }
    char *argv[3];
    argv[0] = "/proc/self/exe";
    argv[1] = "init";
    argv[2] = command;
    printf("%s %s\n",argv[0],argv[1]);
    int child_pid = clone(child_proc, child_stack+STACK_SIZE,
           CLONE_NEWPID | CLONE_NEWNS | CLONE_NEWNET | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD, argv);
    waitpid(child_pid, NULL, 0);
    printf("已退出\n");
    exit(1);
}

// int main() {
//     run_container(true,"/bin/ls");
//     return  0;
// }