#include <stdio.h>
#include "Utils/HeaderUtils/Studant.h"
#include "Utils/HeaderUtils/controleArquivo.h"

int main() {
    biTree *b = NULL;
    setvbuf(stdout, NULL, _IONBF, 0);
    b = treeInitialized();
    b = readTreeAlunoFromFile(b);
    menu(b);
    writeMenu(b);
    freeBiTree(b);

    return 0;
}
