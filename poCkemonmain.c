#include<stdio.h>
#include<stdlib.h>
#define LINHA 8
#define COLUNA 8
int main(){
	
	char inicio, posicao, nomedojogador[100], c;
//	celula teladojogo[LINHA][COLUNA];
	int i, j;
	FILE *f;
	printf("\t\t  BEM VINDO AO poCkemon! \n \n");
	printf("\tNo jogo estao as seguintes regioes de Pokemon: \n  \t  \4 Agua \4 Floresta \4 Terra \4 Eletricidade \4 \n");
	printf("\n Seus Pokemons : 5 \ \n");
	printf("\n\nO que deseja fazer?\n\n<i> - Iniciar o Jogo.\n<r> - Recordes\n<s> - Sair do Jogo.\n\n");
	scanf("%c", &inicio);
	fflush(stdin);
	system("cls");
	switch(inicio){
		case 'i':
			printf("Digite seu nome:\n");
			gets(nomedojogador);
			fflush(stdin);
			system("cls");
			printf("\n     M E N U \n \n 1- Escolher as posicoes dos poCkemons; \n 2- Posicionar aleatoriamente. \n");
			scanf("%c",&posicao);
			fflush(stdin);
			system("cls");
			if(posicao==1){
				for(i=0;i<LINHA;i++){
					for(j=i+1;j<COLUNA;j++){
						
					}
				}
			}
			if(posicao==2){
				
			}
			break;
		case 'r':
				f = fopen("recordes.txt","r");
					if(f==NULL){
					    perror("recordes.txt");
					    return f;
						}
					while(fscanf(f,"%c",&c)!=EOF){
	    			printf("%c", c);  
    				}
   					 printf("\n\n");
					 fclose(f);
					 system("PAUSE");
		case 's':
			printf("Saindo do jogo...\n");
			break;
		default:
            printf("Operacao invalida!\n");
	}
	
system("PAUSE");
return 0;
}
