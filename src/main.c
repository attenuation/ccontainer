#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
};


int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("ccontainer is my toy container base on linux\npleause use `ccontainer start [..OPTIONS]` to start\n");
        exit(EXIT_FAILURE);
    }
    int opt;
    struct arguements_start  strat_opt = {false,false};
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
    }
    return 0;
}