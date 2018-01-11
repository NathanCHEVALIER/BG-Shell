#ifndef CRYPTO_H_INCLUDED
#define CRYPTO_H_INCLUDED
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

void cryter(const char* chemin);

#endif // CRYPTO_H_INCLUDED
