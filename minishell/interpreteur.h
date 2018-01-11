#ifndef INTERPRETEUR_H_INCLUDED
#define INTERPRETEUR_H_INCLUDED
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "crypto.h"

typedef struct Command Command;
struct Command{
    int argc;
    char **argv;
};

void interpreteur(Command cmd);
Command createCommand(const char* str);
int compterArguments(const char* str);
void printCommand(Command cmd);

#endif // INTERPRETEUR_H_INCLUDED
