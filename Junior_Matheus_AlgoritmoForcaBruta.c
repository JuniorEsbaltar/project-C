#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char vetorTeste[67] = {'a','A', 'b','B', 'c','C', 'd','D', 'e','E', 'f','F', 'g','G', 'h','H', 'i','I', 'j','J', 'k','K', 'l','L', 'm','M', 'n','N', 'o','O','p','P', 'q','Q','r','R', 's','S', 't','T', 'u','U' ,'v',',V', 'w','W', 'x','X', 'y','Y','Z', 'z','0', '1', '2', '3', '4', '5', '6', '7', '8', '9','@', '#','$', '%', '&'};
	int i,j,k,l,m,p,q;
	
	char senha[6];
	char palavra[6] = "aaaaa";

	printf("Digite a senha com 5 caracters: \n");
	scanf("%s",&senha);
	

	for(i=0; i<67; i++){
		palavra[0] = vetorTeste[i];
		for(j=0; j<67; j++){
			palavra[1] = vetorTeste[j];
			for(k=0; k<67; k++){
				palavra[2] = vetorTeste[k];
				for(l=0; l<67; l++){
					palavra[3] = vetorTeste[l];
					for(m=0; m<67; m++){
						palavra[4] = vetorTeste[m];
								for(p=0; p<5; p++){
									printf("%c",palavra[p]);
									if (strcmp(palavra, senha) == 0){
											printf("\nSenha: ");
											for(q=0; q<5; q++){
												printf("%c",palavra[q]);}
											printf("\n");
											system("pause");
											}
						}
						printf("\n");
					}		
				}
			}

		}
	}
}



