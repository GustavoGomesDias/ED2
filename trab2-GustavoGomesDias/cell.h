#ifndef __cell_h__
#define __cell_h__

typedef struct Cell Cell;

Cell *create_cell();

float get_info(Cell *arg1);
void set_info(Cell *arg1, float info);

int get_linha(Cell *arg1);
void set_line(Cell *arg1, int line);

int get_coluna(Cell *arg1);
void set_column(Cell *arg1, int columns);

Cell *get_next_l(Cell *arg1);
void set_next_l(Cell *arg1, Cell *arg2);

Cell *get_next_c(Cell *arg1);
void set_next_c(Cell *arg1, Cell *arg2);

void free_cell(Cell *arg1);


#endif