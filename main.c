#include <stdio.h>
#include <stdlib.h>
#include "tipoGrafo.h"

int main()
{
    Grafo Cidade;
    Cidade = fazGrafo(11);
    insereAresta(Cidade, 0, 1);
    insereAresta(Cidade, 1, 5);
    insereAresta(Cidade, 5, 8);
    insereAresta(Cidade, 8, 4);
    insereAresta(Cidade, 4, 6);
    insereAresta(Cidade, 6, 3);
    insereAresta(Cidade, 3, 2);
    insereAresta(Cidade, 2, 1);
    insereAresta(Cidade, 2, 10);
    insereAresta(Cidade, 1, 10);
    insereAresta(Cidade, 9, 10);
    insereAresta(Cidade, 9, 7);

    int distancia[Cidade->A];
    int vertices[Cidade->V];

    printf("\n");
    printf("\n");

    caminhoMinimo(Cidade,0,distancia,vertices);

    return 0;
}
