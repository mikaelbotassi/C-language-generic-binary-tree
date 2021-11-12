//
// Created by mikael on 03/11/2021.
//

#include "../../BinaryTree/BinaryTree.h"

#ifndef _STUDANT_H
#define _STUDANT_H

typedef struct Aluno{
    int matricula;
    char nome[31];
    int nota;
}aluno;

void menu(biTree * b);

aluno * allocStudant();

void newStudant(biTree * b);

biTree * insertStudant(biTree * b, aluno * a);

int discoverType(char id);

int registrationCompare(char id, void *n, int key);

int studantCompare(char id, void * n1, void * n2);

void studantSearch(biTree * b);

void excludeStudant(biTree * b);

void printStudant(char id, void *elem);

int returnChave(void * elem, char id);

void printTree(biTree * b);


#endif //_STUDANT_H
