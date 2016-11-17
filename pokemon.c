#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"poCkemon.h"

void imprime(celula tab[LINHA][COLUNA]){
	int x,y;
	for(x=0;x<LINHA;x++){
		for(y=0;y<COLUNA;y++){
			if(tab[x][y].vazio==0){
				if(tab[x][y].p.d==jogador){
					printf(" * ");
				}
				else
					printf(" - ");
			}
			else
				printf(" - ");
		}
	}
}

void cria_pokemon(pokemon p[N]){
	int x;
	strcpy(p[0].nome,"Chikorita");
	p[0].t=floresta;
	p[0].forca=15;
	strcpy(p[1].nome,"BulbaCaur");
	p[1].t=floresta;
	p[1].forca=20;
	strcpy(p[2].nome,"Charmander");
	p[2].t=terra;
	p[2].forca=30;
	strcpy(p[3].nome,"Ceodude");
	p[3].t=terra;
	p[3].forca=25;
	strcpy(p[4].nome,"TentaCool");
	p[4].t=agua;
	p[4].forca=30;
	strcpy(p[5].nome,"HorCea");
	p[5].t=agua;
	p[5].forca=15;
	strcpy(p[6].nome,"PikaChu");
	p[6].t=eletricidade;
	p[6].forca=50;
	strcpy(p[7].nome,"ChinChol");
	p[7].t=eletricidade;
	p[7].forca=20;
	for(x=0;x<N;x++){
		p[0].xp=0;
		p[0].lvl=1;
	}
}

void ptabuleiro(celula tab[LINHA][COLUNA]){
	int x,y;
	for(x=0;x<LINHA;x++){
		for(y=0;y<COLUNA;y++){
			tab[x][y].vazio=1;
			if(x<LINHA/2-1 && y<COLUNA/2-1)
				tab[x][y].t=agua;
			if(x<LINHA/2-1 && y>=COLUNA/2-1)
				tab[x][y].t=floresta;
			if(x>=LINHA/2-1 && y<COLUNA/2-1)
				tab[x][y].t=terra;
			if(x>=LINHA/2-1 && y>=COLUNA/2-1)
				tab[x][y].t=eletricidade;
		}
	}
}

void rand_posiciona(celula tab[LINHA][COLUNA], dono d, pokemon p[N], int n){
	int i;
	coor c[LINHA*COLUNA];
	pokemon pok;
	int x,y,n=0,r;
	for(i=0;i<n;i++){
		n=0;
		pok = p[rand()%N];
		for(x=0;x<LINHA;x++){
			for(y=0;y<COLUNA;y++){
				if(tab[x][y].)vazio==1 && tab[x][y].t==pok.t{
					c[n].x=x;
					c[n].y=y;
					n++;
				}
			}
		}
		r=rand()%n;
		coor cp = c[r];
		tab[cp.x][cp.y].p=pok;
		tab[cp.x][cp.y].vazio=0;
		tab[cp.x][cp.y].p.d=d;
	}
}

void read_coor(int *x, int *y){
	char buffer[500];
	scanf("%s",buffer);
	*x=buffer[0]-'A';
	*y=buffer[1]-'0';
}


//0=nada
//1=selvagem
//2=oponente
//3=jogador
void jogada(celula tab[LINHA][COLUNA], celula *pokedex[PMAX], int n){
	int x,y,i;
	do{
		read_coor(&x,&y);
	}while(x<0 || x>LINHA || y<0 || y)>COLUNA || (tab[x][y].vazio==0 && tab[x][y].p.d=jogador));
	if(tab[x][y].vazio==1)
		return;
	if(tab[x][y].p.d==selvagem){
		//batalhar, capturar ou fugir
	}	
	if(tab[x][y].p.d==oponente){
		for(i=0;i<n;i++)
			printf("%d - %s",i,*pokedex[i].nome);
		int cp;
		scanf("%d",&cp);
		batalha(tab,pokedex[i], &tab[x][y]);
	}
}

void remove_lista(celula *pokedex[PMAX], celula *c), int *n{
	int i,j,n;
	for(i=0;i<*n && pokedex[i]!=c;i++);
	for(j=i;j<*n-1;j++)
		pokedex[j]=pokedex[j+1];
	*n--;
}

void batalha(celula *atk, celula *trouxa, celula *atk_pokedex[PMAX], int *n_atk, celula *atk_trouxa[PMAX], int *n_trouxa){
	int dano;
	switch(*atk.p.t){
		case agua:
			dano=rand()%*atk.p.forca;
		break;
		case floresta:
			dano=rand()%*atk.p.forca+20;
		break;
		case terra:
			dano=2*(rand()%*atk.p.forca);
		break;
		case eletricidade:
			dano=rand()%*atk.p.forca+30;
		break;
	}
	printf("%s causou %d de dano em %s", *atk.p.nome, rand()%*atk.p.forca, *trouxa.p.nome);
	*trouxa;
}
