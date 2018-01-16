#include "crypto.h"

void crypterstr(char* str,const char* clef){
    int l = strlen(clef);
    int i = -1;
    while(str[++i] != '\0'){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = (str[i] - 65 + clef[i % l]) % 26 + 65;
            printf("majuscule\n");
        }else if(str[i] >= 97 && str[i] <= 122){
            str[i] = (str[i] - 97 + clef[i % l]) % 26 + 97;
            printf("minuscul\n");
        }
    }
}

void decrypterstr(char* str,const char* clef){
    int l = strlen(clef);
    int i = -1;
    while(str[++i] != '\0'){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] - 65 - clef[i % l];
            str[i] = str[i] < 0?(str[i] + 130) % 26 + 65:str[i] + 65;
        }else if(str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 97 - clef[i % l];
            str[i] = str[i] < 0?(str[i] + 130) % 26 + 97:str[i] + 97;
        }
    }
}

void crypterstra(char* str, const char* clef, int a){
    int l = strlen(clef);
    int i = -1;
    while(str[++i] != '\0' && i <= a){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = (str[i] - 65 + clef[i % l]) % 26 + 65;
        }else if(str[i] >= 97 && str[i] <= 122){
            str[i] = (str[i] - 97 + clef[i % l]) % 26 + 97;
        }
    }
}

void decrypterstra(char* str, const char* clef, int a){
    int l = strlen(clef);
    int i = -1;
    while(str[++i] != '\0' && i <= a){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] - 65 - clef[i % l];
            str[i] = str[i] < 0?(str[i] + 130) % 26 + 65:str[i] + 65;
        }else if(str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 97 - clef[i % l];
            str[i] = str[i] < 0?(str[i] + 130) % 26 + 97:str[i] + 97;
        }
    }
}

void crypter(const char* chemin, const char* clee){
    DIR* rep = opendir(chemin);
    if(rep == NULL){
        printf("Problemme lors de l'ouverture d'un dossier\n");
        return;
    }
    struct dirent* dir = NULL;
    while((dir = readdir(rep)) != NULL){
        if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
            int i = -1;
            while(dir->d_name[++i] != '\0' && dir->d_name[i] != '.'){

            }
            int l = strlen(dir->d_name) + strlen(chemin);
            char newchemin[l];
            if(dir->d_name[i] != '.'){
                strcpy(newchemin, chemin);
                strcat(newchemin, dir->d_name);
                strcat(newchemin, "\\");
                crypter(newchemin, clee);

                char* temp[strlen(dir->d_name)];
                strcpy(temp, dir->d_name);
                crypterstra(temp, clee, i - 1);

                strcpy(newchemin, chemin);
                strcat(newchemin, temp);
            }else{
                char* temp[strlen(dir->d_name)];
                strcpy(temp, dir->d_name);
                crypterstra(temp, clee, i - 1);
                strcpy(newchemin, chemin);
                strcat(newchemin, temp);
            }

            char* oldchemin[l];
            strcpy(oldchemin, chemin);
            strcat(oldchemin, dir->d_name);
            if(rename(oldchemin, newchemin)){
                    printf("Erreur lors du renommage\n");
            }
            printf("%s est renommer en %s\n", oldchemin, newchemin);

        }
    }
}

void decrypter(const char* chemin, const char* clee){
    DIR* rep = opendir(chemin);
    if(rep == NULL){
        printf("Problemme lors de l'ouverture d'un dossier\n");
        return;
    }
    struct dirent* dir = NULL;
    while((dir = readdir(rep)) != NULL){
        if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
            int i = -1;
            while(dir->d_name[++i] != '\0' && dir->d_name[i] != '.'){

            }
            int l = strlen(dir->d_name) + strlen(chemin);
            char newchemin[l];
            if(dir->d_name[i] != '.'){
                strcpy(newchemin, chemin);
                strcat(newchemin, dir->d_name);
                strcat(newchemin, "\\");
                decrypter(newchemin, clee);

                char* temp[strlen(dir->d_name)];
                strcpy(temp, dir->d_name);
                decrypterstra(temp, clee, i - 1);

                strcpy(newchemin, chemin);
                strcat(newchemin, temp);
            }else{
                char* temp[strlen(dir->d_name)];
                strcpy(temp, dir->d_name);
                decrypterstra(temp, clee, i - 1);
                strcpy(newchemin, chemin);
                strcat(newchemin, temp);
            }

            char* oldchemin[l];
            strcpy(oldchemin, chemin);
            strcat(oldchemin, dir->d_name);
            if(rename(oldchemin, newchemin)){
                    printf("Erreur lors du renommage\n");
            }
            printf("%s est renommer en %s\n", oldchemin, newchemin);

        }
    }
}
