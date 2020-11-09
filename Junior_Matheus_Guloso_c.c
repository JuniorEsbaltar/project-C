#include <stdio.h> 
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool; 
typedef int TIPOPESO;

typedef struct adjacencia{
	int vertice;
	TIPOPESO peso;
	struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice{
	ADJACENCIA *cab;
} VERTICE;

typedef struct grafo{
	int vertices;
	int arestas;
	VERTICE *adj;
} GRAFO;

GRAFO *criaGrafo(int v) {
	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
	g->vertices = v;
	g->arestas = 0;
	g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));
	
	int i;
	for(i=0; i<v; i++)
		g->adj[i].cab = NULL;
	return (g);
}

ADJACENCIA *criaAdj(int v, int peso){
	ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
	temp->vertice = v;
	temp->peso = peso;
	temp->prox = NULL;
	return(temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf,TIPOPESO p) {
	if(!gr) return(false);
	if((vf<0)||(vf>= gr->vertices))
		return(false);
	if((vi<0)||(vi>=gr->vertices))
		return(false);
	ADJACENCIA *novo = criaAdj(vf,p);
	novo->prox = gr->adj[vi].cab;
	gr->adj[vi].cab = novo;
	gr->arestas++;
	return(true);
}
void inicializaD(GRAFO *g, int *d, int *p, int s){
	int v;
	for(v=0; v<g->vertices; v++){
		d[v] = INT_MAX/2;
		p[v] = -1;
	}
	d[s]=0;
}

void relaxa(GRAFO *g, int *d, int *p, int u, int v){

	ADJACENCIA *ad = g->adj[u].cab;
	while(ad && ad->vertice !=v)
		ad= ad->prox;
	if(ad){
		if(d[v] > d[u] + ad->peso){
			d[v] = d[u] + ad->peso;
			p[v] = u;
			
		}
	}
}

int *dijkstra(GRAFO *g, int s){
	int *d = (int *)malloc(g->vertices*sizeof(int));
	int p[g->vertices];
	bool aberto[g->vertices];
	inicializaD(g,d,p,s);
	
	int i;
	for(i=0; i<g->vertices; i++){
		aberto[i] = true;
	}
	
	while (existeAberto(g,aberto)) {
		int u = menorDist(g,aberto,d);
		aberto[u]=false;
		ADJACENCIA *ad =g->adj[u].cab;
		while(ad){
			relaxa(g,d,p,u,ad->vertice);
			ad =ad->prox;	
		
		}
	}
	return(d);
}

bool existeAberto(GRAFO *g, int *aberto) {
	int i;
	for(i=0; i<g->vertices;i++)
		if(aberto[i]) return(true);
	return(false);
}

int menorDist(GRAFO *g, int *aberto,int *d){
	int i;
	for(i=0; i<g->vertices; i++)
		if(aberto[i]) break;
	if(i==g->vertices){
		return(-1);
		
	}
	int menor = i;
	for(i=menor+1; i<g->vertices; i++)
		if(aberto[i] && (d[menor]>d[i]))
			menor=i;
	return(menor);
}

int convertNumber(char op){
	int num;
	
	switch(op){
		case 'q': 
			num = 0;
		break;
		case 'c': 
			num = 1;
		break;
		case 'e': 
			num = 2;
		break;
		case 'h':
			num = 3;
		break;
		case 'd':
			num = 4;
		break;
		case 'f':
		  num = 5;
		break;
		case 'i':
		  num = 6;
		break;
		case 'l':
		  num = 7;
		break;
		case 'g':
		  num = 8;
		break;
		case 'j':
		  num = 9;
		break;
		case 'm':
		  num = 10;
		break;
		case 'o':
		  num = 11;
		break;
		case 'k':
		  num = 12;
		break;
		case 'n':
		  num = 13;
		break;
		case 'p':
		  num = 14;
		break;
		case 'r':
		  num = 15;
		break;
	}
	
	return num;
}

int main(void) {
	GRAFO *gr = criaGrafo(16);
	
	int i,p,f;
	char op;
	
	printf("Qual ponto deseja iniciar?\n");
	scanf("%c", &op);
	
	p = convertNumber(op);
	
	getchar();
	
	printf("Para qual ponto deseja ir?\n");
	scanf("%c", &op);
	
	f = convertNumber(op);
	
	criaAresta(gr,0,1,1);
	criaAresta(gr,0,4,0);
	criaAresta(gr,1,2,5);
	criaAresta(gr,1,5,4);
	criaAresta(gr,2,3,2);
	criaAresta(gr,2,6,3);
	criaAresta(gr,3,7,3);
	criaAresta(gr,4,5,7);
	criaAresta(gr,4,8,3);
	criaAresta(gr,5,6,1);
	criaAresta(gr,5,9,2);
	criaAresta(gr,6,7,3);
	criaAresta(gr,7,11,5);
	criaAresta(gr,8,12,4);
	criaAresta(gr,8,9,5);
	criaAresta(gr,9,10,2);
	criaAresta(gr,9,13,2);
	criaAresta(gr,10,11,2);
	criaAresta(gr,10,14,8);
	criaAresta(gr,11,15,2);
	criaAresta(gr,12,13,2);
	criaAresta(gr,13,14,4);
	criaAresta(gr,14,15,1);
	
	int *r = dijkstra(gr,p);
	
	if(r[f]>1000){
		printf("Caminho incorrento");
	}else{
		printf("O peso minimo do caminho %d, ate o %d e : %d",p,f,r[f]);
	}
}
