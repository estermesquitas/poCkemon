#include<stdio.h>
#include<stdlib.h>
#define LINHA 8
#define COLUNA 8
#define N 8
#define PMAX 25

typedef enum tipo{
	agua,terra,floresta,terra
}tipo;

typedef enum dono{
	jogador,selvagem,oponente
}dono;

typedef struct pokemon{
	char nome[30];
	tipo t;
	dono d;
	int forca,xp,lvl;
}pokemon;

typedef struct celula{
	pokemon p;
	char vazio;
	tipo t;
}celula;

typedef struct coordenada{
	int x,y;
}coor;

void imprime(celula[LINHA][COLUNA]);
void ptabuleiro(celula tab[LINHA][COLUNA]);
void rand_posiciona(celula tab[LINHA][COLUNA], dono d, pokemon p[N], int n);
