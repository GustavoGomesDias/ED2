#include <stdlib.h>
#include <stdio.h>
#include "exer5.h"

int main(int argc, char **argv){
	const char src[50] = "Gustavo Gomes Dias";
	char dest[50] = "Olá mundo";
	printf("Antes do meu memcpy:\n");
	printf("%s e %s\n", src, dest);
	meu_memcpy(dest, src);
	printf("Depois do meu memcpy:\n");
	printf("%s e %s", src, dest);
	return 0;
}