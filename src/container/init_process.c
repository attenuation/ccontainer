#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t init_container(char *command) {
    char *argv[2];
    argv[0] = command;
    argv[1] = NULL;
    printf("%s %s",argv[0],argv[1]);
    execve(argv[0],argv,NULL);
    return 0;
}