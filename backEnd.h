// Trabalho Pratico SO -> DEIS-ISEC 2022-2023
// Autoria:
// Tânia Guedes - a2020139445@isec.pt
// José Maria Antunes - a21280272@isec.pt

#ifndef BACKEND_H
#define BACKEND_H

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


//PROMOTOR
typedef struct PROMOTOR Promotor, *pPromotor;

struct PROMOTOR{ 
    char category[LEN];
    int discount;
    int duration;
    pPromotor prox;
};

//ITEMS
typedef struct ITEMS Items, *pItems;

struct ITEMS{ 
    char productName[LEN];
    int productId;
    char productCategory[LEN];
    int currentValue;
    int buyNowValue;
    int duration;
    char owner[LEN];
    char buyer[LEN];
    pItems prox;
};


//USERS
typedef struct USER User, *pUser;

struct USER{
    char userName[LEN];
    char userPass[LEN];
    int balance;
    int pid;
    pUser prox; 
};

//BACKEND
typedef struct BACKEND BackEnd, *pBackEnd;

struct BACKEND{ //main que faz os forks
    int frontEndNumber; //numero de frontEnd = numero de clientes
    int promotorNumber; //numero de promotores

    char clientName[LEN]; //nome do cliente
    char promotorName[LEN]; //nome do promotor

    char category[LEN]; //categoria (atribuido pelo promotor)
    int duration; //tempo (atribuido pelo promotor)
    int discount; //desconto (atribuido pelo promotor)

    int MAXCLIENTES; //20
    int PROMOTORES; //10
    int MAXITEMSVENDA; //30

    pUser user;// ponteiro para um user
    pPromotor promotor;// ponteiro para um promotor

    pBackEnd prox;
};


//PACOTE DO USER
typedef struct USERPACKAGE UserPackage, *pUserPackage;

struct USERPACKAGE{ 
    char username[LEN];
    char password[LEN];//texto
    int estado; //ativo ou não ativo
    int pid;
    int saldo;
    int returnPid;
    char returnName[LEN];
    char msg[LEN];
       
    pUserPackage prox;
};

//PACOTE DO PROMOTOR
typedef struct PROMOTORPACKAGE PromotorPackage, *pPromotorPackage;

struct PROMOTORPACKAGE{ 
    char name[LEN];
    char category[LEN];
    int duration;
    int discount;
    int pid;
    int estado; //ativo ou não ativo
    char returnName[LEN];
    int returnPid;
    char msg[LEN];
    char msgAlarme[LEN];
    char msgControlC[LEN];
    int flagAlarme;
    
    pPromotorPackage prox;
};



#endif //BACKEND_H
