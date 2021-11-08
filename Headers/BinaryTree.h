//
// Created by mikael on 03/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

//========================= CONSTANTS ===============================
#define CMP_ALUNO int (*comp)(char, void *, void *) //int cmp(char id, node * n1, node *n2)
#define EQUALS int (*equals)(int, node *) //int registrationEquals
#define CMP_REGISTRATION int (comp)(char, void *, int)
#define PRINT void (* print)(char, void *) //printStudant
//===========================================================================

typedef struct Node{
    struct Node * right;
    struct Node *left;
    void * element;
    char type;
}node;

typedef struct BinaryTree{
    node * root;
    int height;
}biTree;

biTree * treeInitialized();

node * nodeInitialized(node * n);

void freeNode(node * n);

void freeBiTree(biTree * b);

void preOrder(node * root, PRINT);

void inOrder(node * root, PRINT);

void posOrder(node * root, PRINT);

int calculateHeight(node *n);

node * insert(char type,  node * n, void *elem, CMP_ALUNO);

biTree * graft(char type,  biTree * t, void *elem, CMP_ALUNO);

node * search(node *n, int key, EQUALS, CMP_REGISTRATION);

void prune(node * n, int key, EQUALS, CMP_REGISTRATION);

#endif //_BINARYTREE_H