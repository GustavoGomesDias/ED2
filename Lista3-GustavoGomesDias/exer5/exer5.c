#include <stdlib.h>
#include <stdio.h>

void meu_memcpy(char *dest, const char *src){
	int i;
	while(src[i] != '\0'){
		dest[i] = src[i];
		i++;
	}
}