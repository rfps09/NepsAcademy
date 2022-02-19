#include <iostream>
#include <string.h>

using namespace std;

struct aluno {
    char nome[50];

    void imprimir () {
        printf("%s\n", nome);
    }
};

int main() {
    aluno x;

    strcpy(x.nome,"Rafael");

    x.imprimir();

    return 0;
}