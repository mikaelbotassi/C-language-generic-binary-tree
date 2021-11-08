#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Studant.h"

#ifndef _CONTROLEARQUIVOALUNO_H
#define _CONTROLEARQUIVOALUNO_H

biTree * readTreeAlunoFromFile(biTree * root);

void writeTreeOnFile(biTree * root);

#endif //_CONTROLEARQUIVOALUNO_H
