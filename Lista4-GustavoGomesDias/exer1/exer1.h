#ifndef __exer1_h__
#define __exer1_h__

typedef struct cadastro cadastro;

cadastro *criaCadatro();

void set_nome(cadastro *A, char *nome);
char *get_nome(cadastro *A);

void set_end(cadastro *A, char *end);
char *get_end(cadastro *A);

void set_tel(cadastro *A, char *tel);
char *get_tel(cadastro *A);

void popula_cad(cadastro *A);

void imprime(cadastro *A);

#endif