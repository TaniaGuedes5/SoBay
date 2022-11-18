// Trabalho Pratico SO -> DEIS-ISEC 2022-2023
// Autoria:
// Tânia Guedes - a2020139445@isec.pt
// José Maria Antunes - a21280272@isec.pt

#include "backEnd.h"
#include "users_lib.h"

          
int main(int argc, char *argv[], char *envp[]){
	
	//verificar parametros
	if(argc!=1){
		printf("[ERRO] SINTAXE: ./backEnd\n");
		return -1;
	}
	
	//variaveis menu
		int opt,flagBack=0, flagEnd=0;
	//Variaveis-Comando
		char cmd[30], cmdCopy[30];
		char *p = NULL;
		char *saveCmdCopy[3];
		saveCmdCopy[1] = "";
		saveCmdCopy[2] = "";
		char saveCmd[50];
		int strtokCont = 0;
		int flagCloseCmd = 0;  
	//Variaveis-Pipe
		int sendPipe[2], receivePipe[2], n,res, verifiyResRead,verifyResWrite;
	    	char promotorAnswer[50];
	//Variaveis-Promotor
	    	char copyPromotorAnswer[30]; 
	    	char *saveAnswerPromotor[3];
	    	char saveCategory[20];
	    	int saveDiscount, saveDuration;
	 //Variaveis-estruturas
	     struct PROMOTOR promotor;
	 //variaveis- ficheiro dos itens
	 	FILE *fItems;
	 	int total=0;
		struct ITEMS items;
	 //variaveis- ficheiro dos users
		 int numfUsers,balance;
		 FILE *fUsers;
		 int balanceNum;
		 char url[]="FUSERS.txt";
		 char username[LEN],password[LEN];
		 int flagCaseThree=1;
		 int updateBalance;
		 struct USER user; 
	 

	  printf("\n ----------BackEnd----------\n\n");
    	  fflush(stdout);
         

     do{ 
	     do{
		      printf("\n----------MENU---------- \n");
		      printf("\n1-Introduzir comando; \n");
		      printf("\n2-Executar promotor; \n");
		      printf("\n3-Visualizacao da lista de utilizadores; \n");
		      printf("\n4-Visualizacao da lista de items; \n");
		      printf("\n5-Sair\n");
		      printf("\n-->Deseja testar que funcionalidade? \n");
		      printf("\n->Resposta: ");
		      scanf("%d",&opt);
	      }while(opt<=0 || opt>=6);
	      
	      switch(opt){
	      	case 1:
	      	{
	      		do{
			    	printf("\nIntroduza um comando:");
			    	scanf(" %[^\n]", cmd);
				strcpy(cmdCopy,cmd);
				p = strtok (cmdCopy, " ");
				while (p != NULL){
					saveCmdCopy[strtokCont++] = p;
					p = strtok (NULL, " ");
				}strtokCont = 0;
				strcpy(saveCmd,saveCmdCopy[0]);
			
				if(strcmp(saveCmd,"users") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sintaxe: <users>\n\n");
						saveCmdCopy[1] ="";
					}else {
						printf("\n----------------------------------------\n");
						printf("-----------Listando USERS-------------\n");    
					 	printf("\n----------------------------------------\n\n");
					}		
		     		}else if(strcmp(saveCmd,"list") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sintaxe: <list>\n\n");
							saveCmdCopy[1] ="";
					}else {
					   printf("\n----------------------------------------\n");
					   printf("-----------Listando ITENS-------------\n");    
					   printf("\n----------------------------------------\n\n");
					}
				}else if(strcmp(saveCmd,"kick") == 0){
					if(strcmp(saveCmdCopy[1],"")==0){
						printf("[ERRO]: Sinxtaxe: <kick> <userName>\n\n");
							saveCmdCopy[1] ="";
					}else if((strcmp(saveCmdCopy[1],"")==0) || (strcmp(saveCmdCopy[2],"")!=0)){
						printf("[ERRO]: Sinxtaxe: <kick> <userName>\n\n");
						saveCmdCopy[1] ="";
						saveCmdCopy[2] ="";
					}else {
					    printf("\n----------------------------------------\n");
					    printf("-----------Banindo Cliente--------------\n");    
					    printf("\n----------------------------------------\n\n");
					}
				}else if(strcmp(saveCmd,"prom") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sinxtaxe: <prom>\n\n");
						saveCmdCopy[1] ="";
					}else{
						printf("\n----------------------------------------\n");
						printf("-----------Listar promotores ativos--------------");    
					    	printf("\n----------------------------------------\n\n");
					 }
				}else if(strcmp(saveCmd,"reprom") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sintaxe: <reprom>\n\n");
						saveCmdCopy[1] ="";
					}else {
						printf("\n----------------------------------------\n");
						printf("-----------Atualizar promotores--------------\n");    
					    	printf("\n----------------------------------------\n\n");
					}	
				}else if(strcmp(saveCmd,"cancel") == 0){
					if(strcmp(saveCmdCopy[1],"")==0){
						printf("[ERRO]: Sinxtaxe: <cancel> <nomeExecutávelPromotor>\n\n");
						saveCmdCopy[1] ="";
					}else if(strcmp(saveCmdCopy[1],"")==0 || (strcmp(saveCmdCopy[2],"")!=0)){
						printf("[ERRO]: Sinxtaxe: <cancel> <nomeExecutávelPromotor>\n\n");
							saveCmdCopy[1] ="";
					}else {
						printf("\n----------------------------------------\n");
						printf("-----------Closando--------------\n");    
					    	printf("\n----------------------------------------\n\n");
					}	
				}else if(strcmp(saveCmd,"close") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sinxtaxe: <close> \n\n");
						saveCmdCopy[1] ="";
					}else {
				    		flagCloseCmd = 1;
					}
				}else if(strcmp(saveCmd,"help")==0){
					printf("\nLISTA DE COMANDOS QUE O ADMINISTRADOR PODE INTRODUZIR:");
					printf("\n->users");
					printf("\n->list");
					printf("\n->kick <userName>");
					printf("\n->prom");
					printf("\n->reprom");
					printf("\n->cancel <nomeExecutávelPromotor>");
					printf("\n->close\n\n");
					printf("\n->Back\n");
				}else if(strcmp(saveCmd,"back") == 0){
					if(strcmp(saveCmdCopy[1],"")!=0){
						printf("[ERRO]: Sinxtaxe: <back> \n\n");
						saveCmdCopy[1] ="";
					}else {
				    		flagBack = 1;
					}
				}else{
				printf("\n[ERRO]: O comando %s não existe!\nCaso não saiba os comandos introduza <help>\n\n",cmd);
				}
			
				saveCmdCopy[1] = "";
				saveCmdCopy[2] = "";
			
		     	}while(flagBack == 0 &&( strncmp(cmd,"close",5) != 0 || flagCloseCmd == 0));
		     
		     	flagBack=0;
		     	break;
	      	}
	      	case 2:
	      	{
	      		pipe(sendPipe); 
		      	pipe(receivePipe);
		      	
			res = fork();
			
			 if (res < 0){
				printf("\n[ERRO] ao criar o filho \n");
				exit(1);
			 } 
			 if (res == 0){
				close(STDIN_FILENO);// | fechar stdin do filho
				dup(sendPipe[0]);
				close(sendPipe[0]);
				close(sendPipe[1]);
				close(STDOUT_FILENO);
				dup(receivePipe[1]);
				close(receivePipe[0]);
				close(sendPipe[1]);
				execl("./promotor_oficial", "./promotor_oficial", NULL);
				fprintf(stderr, "[FILHO] Nao consegui executar o CMD!\n");
				exit(2);
				
			 }else{
			 	close(sendPipe[0]);
			 	close(receivePipe[1]);
			    	verifiyResRead = read(receivePipe[0], promotorAnswer, sizeof(promotorAnswer)-1);
			 	if(verifiyResRead == -1){
			 	   fprintf(stderr, "[ERRO] na leitura!\n");
			 	   exit(4);
				}
				promotorAnswer[verifiyResRead] = 0; // Serve para resolver o bug de caracteres que precedem a resposta do promotor_oficial
				printf("\nResposta: %s",promotorAnswer);
				fflush(stdout);
				strcpy(copyPromotorAnswer,promotorAnswer);
				p = strtok (copyPromotorAnswer, " ");
				while (p != NULL){
					saveAnswerPromotor[strtokCont++] = p;
					p = strtok (NULL, " ");			
				}strtokCont = 0;
				strcpy(promotor.category,saveAnswerPromotor[0]);
				promotor.discount = atoi(saveAnswerPromotor[1]);
				promotor.duration = atoi(saveAnswerPromotor[2]);
				printf("\nCategoria: %s;\nDesconto: %d;\nDuracao: %d",promotor.category,promotor.discount,promotor.duration);
		    	}
		    break;
	      	}
	      	case 3:
	      	{
	      	//Leitura e atualização dos utilizadores através da biblioteca fornecida para esse efeito. De cada vez que a funcionalidade é testada, os utilizadores perdem 1 no saldo ficando essa alteração gravada.

		   numfUsers = loadUsersFile(url);
		   if(numfUsers==-1){
		 	printf("\nNao exitem users");
		   }else{
		      	printf("\nExitem %d users\n",numfUsers);
		   }
		   fUsers = fopen(url,"r");
		    if(fUsers==NULL){
		    	printf("\nNao existe ficheiro\n");
		    }else{
		    	while((fscanf(fUsers,"%s %s %d\n", user.userName, user.userPass, &(user.balance)))!=EOF ){
		      		printf("\nUsername:%s\nPassword:%s\nSaldo:%d\n",user.userName, user.userPass,user.balance);
		      		if((getUserBalance(user.userName))==-1)
		      			printf("\nFuncao getUserBalance deu erro\n");
		      		else{
		      			printf("SALDO  de %s ANTES: %d\n",user.userName,getUserBalance(user.userName));
		      			if(getUserBalance(user.userName)==0){
		      				if((updateUserBalance(user.userName,(user.balance)-1))==-1){
		 					printf("\nO saldo do user %s já é 0 e não dá para descontar mais\n",user.userName); break;
		      				}
		      				else{
			      			printf("\nSALDO de %s DEPOIS: %d\n",user.userName,getUserBalance(user.userName));
			      			}
			      			//saveUsersFile(url);
		      			}else if(updateUserBalance(user.userName,(user.balance)-1)==0) {
		      				printf("\nNao foi possivel atualizar o saldo\n");
		      			}
		      			saveUsersFile(url);
	   			}	
		      	 }
		    }
		    
	      	   break;
	      	
	      	}
	      	case 4:
	      	{
	      
	      		fItems = fopen("FITEMS.txt","r+w");
	      		if(fItems==NULL)
	      			printf("\nNao foi possivel abrir o ficheiro para leitura");
	      		else{
	      	    		char productName[LEN];
	      			while( (fscanf(fItems,"%d %s %s %d %d %d %s %s\n", &(items.productId), items.productName, items.productCategory,&(items.currentValue),&(items.buyNowValue), &(items.duration),items.owner,items.buyer))!=EOF ){
	      				total++;
   					printf("\nNumero do produto:%d\nNome do produto:%s\nNome da categoria:%s\nValor atual:%d\nValor buy now:%d\nTempo:%d\nDono:%s\nComprador:%s\n",items.productId, items.productName, items.productCategory,items.currentValue,items.buyNowValue, items.duration,items.owner,items.buyer);
   				
	      			}
	      			printf("\nNeste momento exitem %d produtos\n",total);
	      		}
	      		fclose(fItems);
	      		break;
	      	}
	      	case 5:
	      	{
		      	printf("\nFim backEnd\n");
		      	exit(1);
		      	break;
                }	      
	   }
	   
	}while(strncmp(cmd,"close",5) != 0 || flagCloseCmd == 0);

        printf("\nBackEnd close\n");
	exit(0);
}
