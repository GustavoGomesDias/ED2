#ifndef __cell_h__
#define __cell_h__

/* Exer1 */
typedef struct cell Cell;

/* Exer4 */
Cell* create_cell(int info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

/* Exer6 */
void print_cell(Cell *c);

/* Exer8 */
void free_cell(Cell *arg1);

#endif