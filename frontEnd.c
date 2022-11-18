// Trabalho Pratico SO -> DEIS-ISEC 2022-2023
// Autoria:
// Tânia Guedes - a2020139445@isec.pt
// José Maria Antunes - a21280272@isec.pt


#include "frontEnd.h"



int main(int argc, char *argv[], char *envp[]){
	
	//verificar parametros
	
	if(argc!=3){
		printf("[ERRO] SINTAXE: ./frontEnd nomeUtilizador password \n");
		return -1;
	}
	
	//Variaveis
		//Users
			struct USER saveUsers[20];
		//Commands
			int flagCloseCmd = 0;
	    		int fg=0;
	    		int guardaTempoFreq;
			int strtokCont = 0;
			char cmd[30], cmdCopy[30];
			char saveCmd[50];
			char *p = NULL;
			char *saveCmdCopy[2];
			saveCmdCopy[1] = "";
			saveCmdCopy[2] = "";
			saveCmdCopy[3] = "";
			saveCmdCopy[4] = "";
			saveCmdCopy[5] = "";
	
	int contUsers=0;
	
	strcpy(saveUsers[contUsers].userName,argv[1]);
	strcpy(saveUsers[contUsers].userPass,argv[2]);

	printf("\nBem Vindo utilizador %s!",saveUsers[contUsers].userName);
	printf("\nA sua passe: %s!",saveUsers[contUsers].userPass);

	printf("\n ----------SoBay: ----------\n\n");
	
	fflush(stdout);
	   

	//COMANDOS: 
	do{
		printf("Introduza um comando:\n");
	    	scanf(" %[^\n]", cmd);
		strcpy(cmdCopy,cmd);
		p = strtok (cmdCopy, " ");
		while (p != NULL){
			saveCmdCopy[strtokCont++] = p;
			p = strtok (NULL, " ");
		}strtokCont = 0;
		strcpy(saveCmd,saveCmdCopy[0]);
		
		if(strcmp(saveCmd,"exit") == 0){
			if(strcmp(saveCmdCopy[1],"")!=0){
				printf("[ERRO]: Sintaxe: <exit>\n\n");
				saveCmdCopy[1] ="";
			}else {
				flagCloseCmd = 1;
			}		
	     	}else if(strcmp(saveCmd,"sell")==0){
	     		if((strcmp(saveCmdCopy[1],"")==0)){
	     			printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
	     		}
	     		else if((strcmp(saveCmdCopy[1],"")==0) || ((strcmp(saveCmdCopy[2],"")==0))){	
				printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
			}
	  		else if((strcmp(saveCmdCopy[1],"")==0) || (strcmp(saveCmdCopy[2],"")==0) || (strcmp(saveCmdCopy[3],"")==0)){	
				printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
				saveCmdCopy[3] = "";
			}
	  		else if((strcmp(saveCmdCopy[1],"")==0) || (strcmp(saveCmdCopy[2],"")==0) || (strcmp(saveCmdCopy[3],"")==0)|| (strcmp(saveCmdCopy[4],"")==0)){	
				printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
				saveCmdCopy[3] = "";
				saveCmdCopy[4] = "";
			}
	  		else if((strcmp(saveCmdCopy[1],"")==0) || (strcmp(saveCmdCopy[2],"")==0) || (strcmp(saveCmdCopy[3],"")==0) || (strcmp(saveCmdCopy[4],"")==0) || (strcmp(saveCmdCopy[5],"")==0)){	
				printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
				saveCmdCopy[3] = "";
				saveCmdCopy[4] = "";
				saveCmdCopy[5] = "";
			}else if((strcmp(saveCmdCopy[1],"")==0) || (strcmp(saveCmdCopy[2],"")==0) || (strcmp(saveCmdCopy[3],"")==0) || (strcmp(saveCmdCopy[4],"")==0) || (strcmp(saveCmdCopy[5],"")==0) || (strcmp(saveCmdCopy[6],"")!=0)){	
				printf("[ERRO]: Sintaxe do comando: sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
				saveCmdCopy[3] = "";
				saveCmdCopy[4] = "";
				saveCmdCopy[5] = "";
			}
		
			else{
			 printf("\n----------------------------------------\n");
			 printf("-----------Optou por vender um produto--------------\n");    
			 printf("\n----------------------------------------\n\n");
			}
		}else if(strcmp(saveCmd,"list") == 0){
			if(strcmp(saveCmdCopy[1],"")!=0){
				printf("[ERRO]: Sintaxe: <list>\n\n");
					saveCmdCopy[1] ="";
			}else {
			    printf("\n----------------------------------------\n");
			    printf("-----------Listar--------------\n");    
			    printf("\n----------------------------------------\n\n");
			    
			}
		}else if(strcmp(saveCmd,"licat") == 0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sinxtaxe: <licat> <categoria>\n\n");
					saveCmdCopy[1] ="";
			}else if(strcmp(saveCmdCopy[1],"")==0 || (strcmp(saveCmdCopy[2],"")!=0)){
				printf("[ERRO]: Sinxtaxe: <licat> <categoria>\n\n");
					saveCmdCopy[1] ="";
			}else {
			    printf("\n----------------------------------------\n");
			    printf("-----------LICAT--------------\n");    
			    printf("\n----------------------------------------\n\n");
			}
		}
		else if(strcmp(saveCmd,"lisel") == 0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sinxtaxe: <lisel> <nomeVendedor>\n\n");
				saveCmdCopy[1] ="";
			}else if(strcmp(saveCmdCopy[1],"")==0 || (strcmp(saveCmdCopy[2],"")!=0)){
				printf("[ERRO]: Sinxtaxe: <lisel> <nomeVendedor>\n\n");
					saveCmdCopy[1] ="";
			}else{
				printf("\n----------------------------------------\n");
				printf("-----------LISEL--------------\n");    
			    	printf("\n----------------------------------------\n\n");
			 }
		}else if(strcmp(saveCmd,"lival") == 0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sintaxe: <lival> <valorMaximo>\n\n");
				saveCmdCopy[1] ="";
			}else if(strcmp(saveCmdCopy[1],"")==0 || (strcmp(saveCmdCopy[2],"")!=0)){
				printf("[ERRO]: Sintaxe: <lival> <valorMaximo>\n\n");
					saveCmdCopy[1] ="";
			}else {
				printf("\n----------------------------------------\n");
				printf("-----------LIVAL--------------\n");    
			    	printf("\n----------------------------------------\n\n");
			}	
		}
		else if(strcmp(saveCmd,"litime") == 0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sinxtaxe: <litime> <horaEmSegundos>\n\n");
				saveCmdCopy[1] ="";
			}else if(strcmp(saveCmdCopy[1],"")==0 || (strcmp(saveCmdCopy[2],"")!=0)){
				printf("[ERRO]: Sinxtaxe: <litime> <horaEmSegundos>\n\n");
					saveCmdCopy[1] ="";
			}else {
		    		printf("\n----------------------------------------\n");
				printf("-----------Ler Tempo--------------\n");    
			    	printf("\n----------------------------------------\n\n");
			}
		}else if(strcmp(saveCmd,"time") == 0){
			if(strcmp(saveCmdCopy[1],"")!=0){
				printf("[ERRO]: Sintaxe: <time>\n\n");
					saveCmdCopy[1] ="";
			}else {
			    printf("\n----------------------------------------\n");	
			    printf("-----------Tempo-------------\n");    
			    printf("\n----------------------------------------\n\n");
			    
			}
		}else if(strcmp(saveCmd,"buy")==0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sintaxe do comando: buy <id> <valor>\n\n");
				saveCmdCopy[1] = "";
			}
			else if((strcmp(saveCmdCopy[1],"")==0) || ((strcmp(saveCmdCopy[2],"")==0))){	
				printf("[ERRO]: Sintaxe do comando: buy <id> <valor>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
			}
			else if((strcmp(saveCmdCopy[1],"")==0) || ((strcmp(saveCmdCopy[2],"")==0)) || (strcmp(saveCmdCopy[3],"")!=0)){	
				printf("[ERRO]: Sintaxe do comando: buy <id> <valor>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
			}
			else{
			 printf("\n----------------------------------------\n");
			 printf("-----------Optou por comprar um produto--------------\n");    
			 printf("\n----------------------------------------\n\n");
			}
		}else if(strcmp(saveCmd,"cash") == 0){
			if(strcmp(saveCmdCopy[1],"")!=0){
				printf("[ERRO]: Sintaxe: <cash>\n\n");
					saveCmdCopy[1] ="";
 			} else{
			    printf("\n----------------------------------------\n");	
			    printf("-----------Consultar valor--------------\n");    
			    printf("\n----------------------------------------\n\n");
			    
			}
		}else if(strcmp(saveCmd,"add") == 0){
			if(strcmp(saveCmdCopy[1],"")==0){
				printf("[ERRO]: Sinxtaxe: <add> <valor>\n\n");
				saveCmdCopy[1] ="";
			}else if((strcmp(saveCmdCopy[1],"")==0) || ((strcmp(saveCmdCopy[2],"")!=0))){	
				printf("[ERRO]: Sinxtaxe: <add> <valor>\n\n");
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
			}else {
				printf("\n----------------------------------------\n");
				printf("-----------Adicionar Valor--------------\n");    
			    	printf("\n----------------------------------------\n\n");
			}
				
		}else if(strcmp(saveCmd,"help")==0){
		if(strcmp(saveCmdCopy[1],"")!=0){
				printf("[ERRO]: Sinxtaxe: <help>\n\n");
				saveCmdCopy[1] ="";
			}else{
			printf("\nLISTA DE COMANDOS QUE O CLIENTE PODE INTRODUZIR:");
			printf("\n->sell <nomeItem><categoria><precoBase><precoCompreJa><duracao>");
			printf("\n->list");
			printf("\n->liscat <nomeCategoria>");
			printf("\n->lisel <nomeVendedor>");
			printf("\n->lival <precoMaximo>");
			printf("\n->litime <tempo>");
			printf("\n->buy <id> <valor>");
			printf("\n->cash");
			printf("\n->time");
			printf("\n->add <valor>\n\n");
			}
		}
		else{
			printf("\n[ERRO]: O comando %s não existe!\nCaso não saiba os comandos introduza <help>\n\n",cmd);
		}
		saveCmdCopy[1] = "";
		saveCmdCopy[2] = "";
		saveCmdCopy[3] = "";
		saveCmdCopy[4] = "";
		saveCmdCopy[5] = "";
	     }while(strncmp(cmd,"exit",4) != 0 || flagCloseCmd == 0);
	printf("\nFrontEnd encerrou!\n");

	
	return 0;
}
