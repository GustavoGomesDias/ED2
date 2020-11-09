#include <stdio.h>
#include <stdlib.h>
/* Escreva um programa que gera e escreve os quatro primeiros n ́umeros perfeitos. Um n ́umero perfeito
 ́e aquele que  ́e igual `a soma dos seus divisores (por exemplo, 6, 28, etc) */

 int main(){
    int soma, num, i, j;
    num = 2;
    i = 0;
    while(i < 4){
        soma = 0;
        for(j = 1; j < num; j++){
            if(num%j == 0){
                soma += j;
            }
        }
        if(soma == num){
            printf("%d ", soma);
            i++;
        }
        num += 1;
    }

    return 0;
}