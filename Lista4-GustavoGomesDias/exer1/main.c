#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exer1.h"


int main(int argv, char **argc){
    cadastro *c1 =  criaCadatro();
    cadastro *c2 =  criaCadatro();
    cadastro *c3 =  criaCadatro();

    popula_cad(c1);
    popula_cad(c2);
    popula_cad(c3);

    printf("\n");
    imprime(c1);
    printf("\n");
    imprime(c2);
    printf("\n");
    imprime(c3);
    return 0;
}