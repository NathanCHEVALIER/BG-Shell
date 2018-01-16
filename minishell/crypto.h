#ifndef CRYPTO_H_INCLUDED
#define CRYPTO_H_INCLUDED
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
void crypterstr(char* str,const char* cle);
void crypterstra(char* str, const char* clee, int a);

void crypterstra(char* str, const char* clee, int a);
void decrypterstra(char* str, const char* clee, int a);

void crypter(const char* chemin, const char* clee);
void decrypter(const char* chemin, const char* clee);

#endif // CRYPTO_H_INCLUDED
