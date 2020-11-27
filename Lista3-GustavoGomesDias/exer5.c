#include <stdlib.h>
#include <stdio.h>

void meu_memcpy(char *dest, const char *src){
	int i;
	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
}



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