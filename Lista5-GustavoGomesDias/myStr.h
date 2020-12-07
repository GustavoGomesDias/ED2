#ifndef __myStr_h__
#define __myStr_h__

/* Alias => exer2 */
typedef struct my_str String;

/* Alocação dinâmica => exer3 */
String *cria(int tam);

/* Exer4 */
void fill(String *s, char *c, int len);

/* Exer5 */
void print_char(String *texto, int len);

/* Auxiliares */
void adiciona_char(char *texto, int len);

void set_char(String *arg1, int pos, char l);
char get_char(String *arg1, int pos);

char *get_vetor(String *arg1);

void set_tam(String *arg1, int tam);
char get_tam(String *arg1);

void preence_string(String *texto, int len);

/* Exer6 */
void desaloca_string(String *arg1);

/* Exer7 */
String *concatena_string(String *arg1, String *arg2, int len);

#endif