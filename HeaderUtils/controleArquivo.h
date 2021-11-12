#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Studant.h"

#ifndef _CONTROLEARQUIVOALUNO_H
#define _CONTROLEARQUIVOALUNO_H

biTree * readTreeAlunoFromFile(biTree * root);

void writeTreeOnFile(biTree * root, int typePrint);

void writeMenu(biTree * root);

void writePreOrder(FILE * fp, node * root);

void writeInOrder(FILE * fp, node * root);

void writePosOrder(FILE * fp, node * root);


#endif //_CONTROLEARQUIVOALUNO_H
