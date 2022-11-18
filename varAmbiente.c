// Trabalho Pratico SO -> DEIS-ISEC 2022-2023
// Autoria:
// Tânia Guedes - a2020139445@isec.pt
// José Maria Antunes - a21280272@isec.pt

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <linux/limits.h>
#include <unistd.h>

int varAmbienteMAXCLIENTS(){
	int save;
	char *var; 
	var = getenv("MAXCLIENTS");		

	if(var == NULL){	
		fprintf(stderr, "[FRONTEND]: A variavel ambiente 'MAXCLIENTS' não existe!\n");
		fprintf(stderr, "[FRONTEND]: Por favor defina uma e tente novamente!\n");
		return -1;
	}
	
	//Atribui à variável guarda o inteiro que vem da variável var e compara para ver se leu bem (==1). se leu mal(!=1) ou se o numero
	//que o utilizador pos é menor que 1 dá erro -> serve para ter pelo menos um cliente.
	if((sscanf(var, "%d", &save)!=1) || save < 1){ 
		fprintf(stderr, "[FRONTEND]: A variavel ambiente 'MAXCLIENTS' tem um valor incorreto: '%s'\n", var);
		fprintf(stderr, "[FRONTEND]: A variavel ambiente 'MAXCLIENTS' deve conter um valor inteiro maior ou igual a 1.\n");
		return -1;
	}

	//save = atoi(var); Não é preciso atoi porque se retorna guarda quer dizer que já vem com inteiro
	return save;
}


