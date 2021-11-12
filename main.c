#include <stdio.h>
#include "Headers/Studant.h"
#include "Headers/controleArquivo.h"

int main() {
    biTree *b = NULL;
    setvbuf(stdout, NULL, _IONBF, 0);
    b = treeInitialized();
    b = readTreeAlunoFromFile(b);
    menu(b);
    writeMenu(b);
    b->height = calculateHeight(b->root);
    printf("\nALTURA = %d\n", b->height);
    freeBiTree(b);

    return 0;
}
