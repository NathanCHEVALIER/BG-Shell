#include "interpreteur.h"

void interpreteur(Command cmd){
    if(cmd.argc > 0){
        if(strcmp(cmd.argv[0], "exit\0") == 0){
            exit(0);
        }else if(strcmp(cmd.argv[0], "crypter\0") == 0){
            if(cmd.argc == 2) cryter(cmd.argv[1]);
        }else if(strcmp(cmd.argv[0], "caca\0") == 0){
            unsigned int t ;
            for(int i = 0; i <= 100; i++){
                printf("\r");
                t = rand() / 100;

                unsigned int r = rand() / 10000;
                for(int j = 0; j <= r; j++){
                    printf("du blabla qui defile...\n");
                }
                printf("Chargement: %d%%", i, t);

                _sleep(t);
            }
            printf("\n");
        }
    }
}

int compterArguments(const char* str){
    int i = -1;
    int j = 0;
    int last = 1;
    while(str[++i] != '\0' && str[i] != '\n'){
        if(str[i] == ' '){
            last = 1;
        }else{
            if(last){
                j++;
                last = 0;
            }
        }
    }
    return j;
}

Command createCommand(const char* str){
    int i = -1;
    int j = 0;
    int longest = 0;
    int count = 0;
    int last = 1;
    while(str[++i] != '\0' && str[i] != '\n'){
        if(str[i] == ' '){
            last = 1;
            if(count > longest) longest = count;
            count = 0;
        }else{
            if(last){
                j++;
                last = 0;
            }
            count++;
        }
    }
    if(count > longest) longest = count;
    printf("le plus long argument fait %d char\n", longest);


    char **r = NULL;
    r = malloc(sizeof(char*) * j);
    for(int i = 0; i < j; i++){
        r[i] = malloc((longest + 1) * sizeof(char));
    }



    i = -1;
    int a = 0;
    int b = 0;
    last = 0;
    while(str[++i] != '\0'){
        if(str[i] == ' '){
                if(!last){
                    r[a][b] = '\0';
                    last = 1;
                }
        }else if(str[i] == '\n'){
            r[a][b] = '\0';
        }else{
            if(last){
                b = 0;
                a++;
                last = 0;
            }
            r[a][b] = str[i];
            b++;
        }
    }

    Command cmd;
    cmd.argc = j;
    cmd.argv = r;
    return cmd;
}

void printCommand(Command cmd){
    for(int i = 0; i < cmd.argc; i++){
        printf("L'argument %d est: %s\n", i, cmd.argv[i]);
    }
}
