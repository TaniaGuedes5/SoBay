// Trabalho Pratico SO -> DEIS-ISEC 2022-2023
// Autoria:
// Tânia Guedes - a2020139445@isec.pt
// José Maria Antunes - a21280272@isec.pt

#ifndef FRONTEND_H
#define FRONTEND_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#define LEN 50



//estrutura do user
typedef struct USER User, *pUser;
		
struct USER{
    char userName[LEN];
    char userPass[LEN];
    int pid;
    pUser prox; 
};



#endif //FRONTEND_H


