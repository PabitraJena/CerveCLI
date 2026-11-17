#include <stdio.h>
#include <string.h>

#include "cerve.h"
#include "server.h"

int main(int argc, char const *argv[]){
    if (argc < 2){
        printf("Usage: cerve <command>\n");
        return 1;
    }
    
    printf("CerveCLI - START\n");

    if (strcmp(argv[1], "help") == 0 || strcmp((argv[1]), "h") == 0 || strcmp((argv[1]), "H") == 0){
        cmd_help();
    }
    if (strcmp(argv[1], "serve") == 0){
        server_start();
    }

    printf("CerveCLI - END\n");
    return 0;
}