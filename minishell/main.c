#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define destroy(cmd) free(&(cmd.argc)); \
                             free(cmd.argv); \
                             free(&cmd);
#include "interpreteur.h"

int main()
{
    printf("Hello world!\n");
    char input[100];
    while(1){
        printf("Shell: ");
        fgets(input, 100, stdin);
        Command cmd = createCommand(input);
        interpreteur(cmd);
        destroy(cmd);
    }
    return 0;
}


