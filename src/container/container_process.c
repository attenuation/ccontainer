#include <stdio.h>
#include <stdbool.h>

size_t run_container(bool tty,char *command) {
    char *argv[2];
    argv[0] = "init";
    argv[1] = command;
    printf("%s %s\n",argv[0],argv[1]);
    return 0;
}

int main() {
    run_container(true,"/bin/ls");
    return  0;
}