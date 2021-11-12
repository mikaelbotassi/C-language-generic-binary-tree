//
// Created by mikae on 03/11/2021.
//

#include "BinaryTree.h"

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

node * freeNode(node * n){
    if(empty(n)){}
    else{
        n->left = freeNode(n->left);
        n->right = freeNode(n->right);
        free(n);
        n = NULL;
    }
    return n;
}

biTree * freeBiTree(biTree * b){
    if(b->root == NULL){}
    else{
        b->root = freeNode(b->root);
        free(b);
    }
    return b;
}

int calculateHeight(node *n) {
    if (empty(n)) return 0;
    else if (empty(n->right) && empty(n->left)) return 0;
    else {
        int hLeft = calculateHeight(n->left);
        int hRight = calculateHeight(n->right);
        if (hLeft > hRight) {
            return 1 + hLeft;
        } else {
            return 1 + hRight;
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


void search(node *n, int key, CMP_REGISTRATION, PRINT){
    int traversedElements = 0;
    node * aux = n;
    while(!empty(aux)){
        traversedElements++;
        if(comp(aux->type, aux->element, key) == 1){
            aux = aux->right;
        }
        else if(comp(aux->type, aux->element, key) == -1){
            aux = aux->left;
        }
        else{
            print(aux->type, aux->element);
            printf("\nCOMPARATION NUMBER: %d\n", traversedElements);
            return;
        }
    }
    printf("\n\tALUNO NAO EXISTE!\n");
}

node * prune(node * n, int key, CMP_REGISTRATION, PRINT){
    if (n == NULL) {
        printf("\n\tALUNO NAO EXISTE!\n");
        return NULL;
    }
    else if (comp(n->type, n->element, key) == -1)
        n->left = prune(n->left, key, comp, print);
    else if (comp(n->type, n->element, key) == 1)
        n->right = prune(n->right, key, comp, print);
    else {//Se chegar aqui achei o no a ser removido
        print(n->type, n->element);
        printf("\n\tALUNO EXCLUIDO!\n");

        // Se o nó não tem filhos só o desaloco
        if (n->left == NULL && n->right == NULL) {
            free (n);
            //Coloco NULL em r para retornar
            n = NULL;
        }
            // Se o nó só tem filho à direita, desaloco o nó e guardo o filho a direita para retornar
        else if (n->left == NULL) {
            node * d = n->right;
            free (n);
            n=d;
        }
            // Se o nó só tem filho à esquerda, desaloco o nó e guardo o filho a esquerda para retornar
        else if (n->right == NULL) {
            node * e = n->left;
            free (n);
            n=e;
        }
            // Se o nó tem os dois filhos, acho o elemento mais à direita da árvore a esquerda
            //Troco a informação da raiz pela desse elemento e o desaloco
        else {
            node * e = n->left;
            //Laço para encontrar o maior elemento da subarvore esquerda
            while (e->right != NULL) {
                e = e->right;
            }
            //Troco a informação do maior elemento da esquerda com a raiz
            void * aux = n->element;
            n->element = e->element;
            e->element = aux;
            //Agora chamo o método para remover a folha.
            n->left = prune(n->left, key, comp, print);
        }
    }
    return n;
}
