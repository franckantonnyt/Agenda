#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
/*CRIE UM PROGRAMA QUE REALIZE UM CADASTRO SIMPLES DE AGENDA(MEMORIA) COM INCLUSÃO DE NOVAS 
ENTRADAS, CONSULTA, EXCLUSÃO E PESQUISA E ENTRADAS JA EXISTENTES.
-DADOS TAD
-VETOR DE TAMANHO 40 PARA NOME
-VETOR DE TAMANHO 40 PARA EMAIL
-TELEFONE
-CRIAR O APELIDO PARA STRUTURA AGENDA.
*/
//struct
typedef struct {
	char nome[40];
	char email[40];
	char telefone[12];
}agenda;
//menu
int menu(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	do
	{
		printf("\t--DIGITE A OPÇÂO--\n");
		printf("1 - INCLUSÂO\n2 - CONSULTA\n3 - EXCLUSÂO\n4 - PESQUISA\n5 - MOSTRAR AGENDA\n6 - SAIR\n");
		scanf("%i",&x);		
		if(x == 6)
		{
			break;
		}
		if((x > 5) || (x < 0))
		{
			printf("Opção Invalida, Digite Novamente!\n");
			system("pause");
		}
		system("cls");
	}while((x > 5) || (x < 0));
	return x;
}

int main(){
	int i = 1, x, r, j, a=0;
	char nomec[40];
	agenda *p = (agenda*) calloc (i,sizeof(agenda));
	do
	{
		x = menu();
		switch (x)
		{
			case 1:
				printf("\t-INCLUSÂO-\n");
				printf("NUMERO DE REGISTRO %i\n",i);
				printf("Nome - ");
				scanf(" %[^\n]s", p[i-1].nome);
				printf("Email - ");
				scanf("%s",&p[i-1].email);
				printf("Telefone - ");
				scanf("%s",&p[i-1].telefone);
				i++;
				p = (agenda*) realloc(p, i * sizeof(agenda));
				break;
			case 2:
				printf("\t-CONSULTA-\n");
				printf("Numero de Registro - ");
				scanf("%i",&r);
				if(r <= i)
				{
					printf("Nome - %s\n",p[r-1].nome);
					printf("E-mail - %s\n",p[r-1].email);
					printf("Tel - %s\n",p[r-1].telefone);	
				}
				break;
			case 3:
				printf("\t-EXCLUSÃO-\n");
				printf("Numero de Registro - ");
				scanf("%i",&r);
				if(r <= i)
				{
					printf("Nome - %s\n",p[r-1].nome);
					printf("E-mail - %s\n",p[r-1].email);
					printf("Tel - %s\n",p[r-1].telefone);
					printf("CADASTRO EXCLUIDO!\n");
					for(j = 0; j <= i; j++)
					{
						if((r - 1) != j)
						{
							strcpy(p[a].nome,p[j].nome);
							strcpy(p[a].email,p[j].email);
							strcpy(p[a].telefone,p[j].telefone);
							a++; 
						}
					}
					p = (agenda*) realloc(p, a * sizeof(agenda));
					i--;	
				}else
					printf("REGISTRO NÂO EXISTENTE!\n"); 
				break;
			case 4:
				printf("\t-PESQUISA-\n");
				printf("Nome - ");
				scanf(" %[^\n]s",nomec);
				for(j = 0; j <= i; j++)
				{
					a = stricmp(nomec,p[j].nome);
					if(a == 0)
					{
						printf("NUMERO DE REGISTRO %i\n",(j+1));
						printf("Nome - %s\n",p[j].nome);
						printf("E-mail - %s\n",p[j].email);
						printf("Tel - %s\n",p[j].telefone);
					}
				}
				break;
			case 5:
				printf("-AGENDA-\n");
				for(j = 0; j < (i - 1); j++)
				{
					printf("NUMERO DE REGISTRO %i\n",(j+1));
					printf("Nome - %s\n",p[j].nome);
					printf("E-mail - %s\n",p[j].email);
					printf("Tel - %s\n\n",p[j].telefone);
				}
				break;
		}	
		system("pause");
		system("cls");
	}while((x < 6) || (x < 0));
	p = NULL;
	return 0;
}
