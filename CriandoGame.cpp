#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define tf 100

// Menuzinho com borda  CLEAN
char CriarMenu(void)
{
	clrscr();
	int li , ci , lf , cf;
	li = ci = 1;
	lf = 12;
	cf = 70;
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
	for(int aux=ci+1;aux<cf;aux++)
	{
		gotoxy(aux,li);
		printf("%c",205);
		//Sleep(150);
		gotoxy(aux,lf);
		printf("%c",205);
		//Sleep(150);
	}
	for(li=li+1;li<lf;li++)
	{
		gotoxy(ci,li);
		printf("%c",186);
		//Sleep(150);
		gotoxy(cf,li);
		printf("%c",186);
		//Sleep(150);
	}
	gotoxy(30,2);
	printf("##Opcoes##");
	gotoxy(10,3);
	printf("[A] Ler Vetor");
	gotoxy(10,4);
	printf("[B] Exibe Vetor");
	gotoxy(10,5);
	printf("[C] Frequencia -- Ex.01");
	gotoxy(10,6);
	printf("[D] ConsultarElemento");
	gotoxy(10,7);
	printf("[E] Ordenar Vetor");
	gotoxy(10,8);
	printf("[F] Excluir Elemento");
	gotoxy(10,9);
	printf("[ESC] Sair");
	gotoxy(10,10);
	printf(" OPCAO : ");
	
	
	
	return toupper(getche());
	
}
// Exibir vetor
void ExibirVetor (int vetor[tf],int tl)
{
	if(tl == 0)
		printf("\n Vetor Vazio!!!");
	else
		for(int i = 0; i < tl ; i++)
			printf("\nVetor na pos [%d]: %d ",i,vetor[i]);
	
	
	
	getch();
}


// Por valor é sem o & e referencia usa o &
void Frequencia (int vetor[tf],int tl,int &valor,int &QtdeVezes)
{
	QtdeVezes =0;
	for(int i=0;i<tl;i++)
	{
		int Qtde = 0;
		for(int j=i;j<tl;j++)
		{
			if(vetor[i]==vetor[j])
			{
				Qtde++;
			}
			
		}
	if (Qtde > QtdeVezes )
	{
		QtdeVezes = Qtde;
		valor = vetor[i];
	}	
}
}
// TODO VETOR É PASSADO POR REFERENCIA , OU SEJA NÃO PRECISA DE & , SE COLOCAR VAI DAR ERROR !!!!
void LeValor (int vet[tf],int &tl)
{
	int aux;
	printf("\nDigite um numeros no vetor: ");
	printf ("Vetor[%d]: ",tl);
	scanf("%d",&aux);
	while(tl<tf && aux > 0)
	{
		vet[tl] = aux;
		tl++;
		printf("\nDigite um numeros no vetor: ");
		printf ("Vetor[%d]: ",tl);
		scanf("%d",&aux);
	}
}
// Consulta Exaustiva é ver 1 por 1
int BuscaExaustiva(int vetor[tf],int tl,int valor)
{
		int i;
			for (i=0; i < tl && valor != vetor[i];i++);
			
			
			if ( i > tl)
			{
				return -1;
			}
			else
			{
				return i;
			}
		
}
void Consultar (int Vet[tf],int tl)
{
	int i , pos , elemento;
	printf("\n ## Consultar no Vetor ##");
	if (Qtde == 0) printf("\nVetor Vazio!\n");
	else{
		printf("\nConsultar por: ");
		scanf ("%d",&elemento);
		while(elemento>0)
		{
			pos = BuscaExaustiva(Vet,tl,elemento);
			if(pos == -1);
				printf("\n O numero digitado nao foi encontrado");
			else{
				printf("\nElemento [%d] encontrado na pos [%d]");
				
			}
		getch();
		printf("\n\nConsultar por: ");
		scanf("%d",&elemento);
		}
	}
}
// Fazer um executavel para fazer tudo para o main
void Executar(void)
{
	int V[tf] ,tam=0,Qtde,NrMais,num;
	char op;
	do
	{
		op = CriarMenu();
		switch(op)
		{
			case 'A': if(tam==tf) printf("\nVetor Cheio\n");
						else
						{  clrscr();
							LeValor(V,tam);
							printf("\nElementos Inseridos\n");
						}
					getch();
					break;
			
			case 'B': clrscr();ExibirVetor(V,tam);
					  break;
			
			
			case 'C': clrscr();if (tam == 0) printf("\nVetor Vazio , nao sera possivel calcular a frequencia");
					  else
					  {
					  	Frequencia(V,tam,NrMais,Qtde);
					  	printf("\nNúmero de maior frequencia: %d\nQuantidade de vezes: %d",NrMais,Qtde);
					  }
					getch();
					break;
			case 'D': clrscr(); if (tam == 0) printf("\nVetor Vazio");
						else
							Consultar(V,tam);
							break;
			case 'E': clrscr(); if (tam == 0) printf("\nVetor Vazio");
								else
								{
									
								}
			case 'F': clrscr(); if (tam == 0) printf("\nVetor Vazio");
								else
								{
									
								}
			
		}
		
	}while (op!=27);
}
int main (void)
{
	Executar();
	
	
	
	
	
	return 0;
}
