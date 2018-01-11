#include "crypto.h"

void cryter(const char* chemin){
    DIR* rep = opendir(chemin);
    if(rep == NULL){
        exit(1);
    }
    struct dirent* dir = NULL;
    while((dir = readdir(rep)) != NULL){
        if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
            printf("Dossier: %s\n", dir->d_name);
        }
    }
}
