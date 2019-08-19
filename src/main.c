#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./container/container_process.c"
#include "./container/init_process.c"

const char *argp_program_version = "0.1";
const char *argp_program_bug_address = "<ouyangjun1999@gmail.com>";
static char doc[] = "ccontainer is my toy container base on linux";
// static struct argp_option options_start[] = { 
//     { "interactive", 'i', 0, 0, "enable interactive"},
//     { "tty", 't', 0, 0, "enable tty"},
//     { 0 } 
// };


struct arguements_start {
    bool enabletty;
    bool interactive;
    char *command;
};


int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("ccontainer is my toy container base on linux\npleause use `ccontainer start [..OPTIONS]` to start\n");
        exit(EXIT_FAILURE);
    }
    int opt;
    struct arguements_start  strat_opt = {false,false,NULL};
    if(!strcmp(argv[1],"start")){
        while ((opt = getopt(argc-1, argv+1, "ti")) != -1) {
            switch (opt) {
                case 't': strat_opt.enabletty = true; break;
                case 'i': strat_opt.interactive = true; break;
                default:
                    fprintf(stderr, "Usage: %s start [-ti] \n", argv[0]);
                    exit(EXIT_FAILURE);
            }
        }
        strat_opt.command = argv[3];
        run_container(strat_opt.enabletty,strat_opt.command);
    }
    if(!strcmp(argv[1],"init")) {
        init_container(argv[2]);
    }
    return 0;
}