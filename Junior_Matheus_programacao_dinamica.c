#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include <math.h>

/* abordagem bottom-up
* começamos pelo caso base: zero itens com zero valor
* e começamos a encher a mochila
*/
int calcula (int capacidade, int pesos[3], int valores[3], int quantidadeItens) {
	int n = quantidadeItens;
	int i, j;
	int k[n+1][capacidade+1];
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= capacidade; j++) {
			// condição inicial -> Mochila esta sem itens ainda 
			if(( i == 0) || (j ==0)){
				k[i][j] = 0;
			}
			else{
				//ainda da para tentar inserir o item na mochila
				if(pesos[i-1] <= j){
					// 2º condições: ainda tem espaço ou tentamos retirar um item
					if(valores[i-1] + k[i-1][j-pesos[i-1]] > k[i-1][j]){
						k[i][j] = valores[i-1] + k[i-1][j-pesos[i-1]];
					}else{
						k[i][j] = k[i-1][j];
					}
				}else{
					//mochila já está cheia
					k[i][j] = k[i-1][j];
				}
			}		
		}
	}
    
	 //imprime matriz
	for(i = 0; i < n; i++) {
		for(j = 0; j < capacidade; j++) 
			printf("%5d", k[i][j]);
			printf("\n\n"); 
	}
	
	return k[n][capacidade];
 }

int main(){
	setlocale(LC_ALL, "Portuguese");
	int valores[3] = {31, 47, 14};
	int pesos[3] = {2,3,1};
	int quantidadeItens = 4;
	int capacidade = 4;
	printf("Valor máximo que pode ser armazenado na mochila: %d\n", calcula(capacidade, pesos, valores, quantidadeItens));
	return 0;
}

