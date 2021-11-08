//
// Created by mikae on 03/11/2021.
//

#include "Headers/BinaryTree.h"

//====================== CONSTANTS =======================================

//==============================================================================

//===================== PRIVATE FUNCTIONS ======================================
int empty(node *n);
//=============================================================================


//====================== PUBLIC FUNCTIONS =====================================
biTree * treeInitialized() {
    biTree * t = (biTree *) malloc(sizeof(biTree));
    t->root = NULL;
    return t;
}

node * nodeInitialized(node *n) {
    n = (node *) malloc(sizeof(node));
    n->type = '\0';
    n->element = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int empty(node *n) {
    if (n == NULL) {
        return 1;
    }
    return 0;
}

void freeNode(node * n){
    if(empty(n)){}
    else{
        freeNode(n->left);
        freeNode(n->right);
        free(n);
        n = NULL;
    }
}

void freeBiTree(biTree * b){
    if(b->root == NULL){}
    else{
        freeNode(b->root);
        free(b);
    }
}

void preOrder(node * root, PRINT){
    if(empty(root)){}
    else{
        print(root->type,root->element);
        preOrder(root->left, print);
        preOrder(root->right, print);
    }
}

void inOrder(node * root, PRINT){
    if(empty(root)){}
    else{
        inOrder(root->left, print);
        print(root->type,root->element);
        inOrder(root->right, print);
    }
}

void posOrder(node * root, PRINT){
    if(empty(root)){}
    else{
        posOrder(root->left, print);
        posOrder(root->right, print);
        print(root->type, root->element);
    }
}

int calculateHeight(node *n) {
    if (empty(n)) {
        return 0;
    } else {
        if (calculateHeight(n->left) > calculateHeight(n->right)) {
            return 1 + calculateHeight(n->left);
        } else {
            return 1 + calculateHeight(n->right);
        }
    }
}

node * insert(char type,  node *n, void *elem, CMP_ALUNO){
    if(!empty(n)) {
        if (comp(type, elem, n->element)) {
            n->right = insert(type, n->right, elem, comp);
        } else {
            n->left = insert(type, n->left, elem, comp);
        }
    } else {
        n = nodeInitialized(n);
        n->type = type;
        n->element = elem;
    }
    return n;
}

biTree * graft(char type,  biTree * t, void *elem, CMP_ALUNO) {
    t->root = insert(type, t->root, elem, comp);
    return t;
}


node * search(node *n, int key, EQUALS, CMP_REGISTRATION){
    node * aux = n;
    while(!empty(aux)){
        if(equals(key, aux)){
            return aux;
        }
        else if(comp(aux->type, aux->element, key)){
            aux = aux->right;
        }
        else{
            aux = aux->left;
        }
    }
    return NULL;
}

void prune(node * n, int key, EQUALS, CMP_REGISTRATION){
}
