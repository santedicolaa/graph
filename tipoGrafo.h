#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define vertex int

struct grafo {
   int V;
   int A;
   int **adj;
};

typedef struct grafo *Grafo;

vertex i, j, v, w;

char bairros[11][12] = {"Pirambu", "Centro", "Aldeota", "Vl Velha", "Meireles", "Papicu", "Varjota", "Pici", "Dende", "Montese", "Genibau"};

int **fazMatriz(int linha, int coluna, int val) {
   int **m = malloc(linha * sizeof (int *));
   for (i = 0; i < linha; ++i)
      m[i] = malloc(coluna * sizeof (int));
   for (i = 0; i < linha; ++i)
      for (j = 0; j < coluna; ++j)
         m[i][j] = val;
   return m;
}

Grafo fazGrafo(int vertices) {
   Grafo G = malloc(sizeof *G);
   G->V = vertices;
   G->A = 0;
   G->adj = fazMatriz(vertices, vertices, 0);
   return G;
}

void removeAresta(Grafo G, vertex v, vertex w) {
   if (G->adj[v][w] != 0) {
      G->adj[v][w] = 0;
      G->adj[w][v] = 0;
      G->A--;
   }
}

void insereAresta(Grafo G, vertex v, vertex w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->adj[w][v] = 1;
      G->A++;
   }
}

void mostraAdj(Grafo G) {
   for (v = 0; v < G->V; ++v) {
      printf("%2d:", v);
      for (w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1)
            printf( " %2d", w);
      printf("\n");
   }
}

void mostraConex(Grafo G) {
    printf("         ");
    for(v = 0; v < G->V; ++v) {
        printf("%9s", bairros[v]);
    }
    printf("\n");
    for(v = 0; v < G->V; ++v){
        printf("%9s", bairros[v]);
        for(w=0;w<G->V;w++){
        if(G->adj[v][w] == 0){
            printf("        -");
        }
        else{
        printf("       %s", "OK");
        }
    }
    printf("\n");
}
}

/*void mostraTempo(Grafo G) {
    printf("\n%26s %53s %26s\n\n", " ","Tempo, em minutos, gasto no trajeto entre os bairros:", " ");
    printf("         ");
    for(v = 0; v < G->V; ++v) {
        printf("%9s", bairros[v]);
    }
    printf("\n");
    for(v = 0; v < G->V; ++v){
        printf("%9s", bairros[v]);
        for(w=0;w<G->V;w++){
        if(G->distancia[v][w] == 0){
            printf("        -");
        }
        else{
        printf("%9d", ((G->distancia[v][w]*G->velocidade[v][w])/60));
        }
        }
        printf("\n");
}
}*/

int calculaGrau(Grafo G, int vertice){
    int grau=0;
    for(i=0;i<G->V;i++){
        if(G->adj[vertice][i] != 0)
            grau++;
    }
    return grau;
}

void BFS(Grafo G, int inicio){
    int visitados[G->V], ordem = 0, i;
    for(i = 0; i < G->V; i++){
        visitados[i] = -1;
    }
    Fila *fila = criaFila();
    visitados[inicio] = ordem++;
    push(fila, inicio);
    while(!vazia(fila))
    {
        printf("Fila: ");
        mostraFila(fila);
        int v = pop(fila);
        printf("pop = %d\n", v);
        for(w = 0; w < G->V; w++)
        {
            if(G->adj[v][w] == 1 && visitados[w] == -1)
            {
                visitados[w] = ordem++;
                push(fila, w);
                printf("push = %d\n", w);
            }
        }
    }
    printf("NUM[]: ");
    for(i = 0; i < G->V; i++)
        printf("%d ", visitados[i]);
    printf("\n");
}

void caminhoMinimo(Grafo G, int inicio, int *dist, int *pa)
{
    int v;
    const int infinito = G->V;
    for(v = 0; v < G->V; v++)
    {
        pa[v] = -1;
        dist[v] = infinito;
    }
    pa[inicio] = inicio;
    dist[inicio] = 0;
    Fila *fila = criaFila();
    push(fila ,inicio);

    while(!vazia(fila))
    {
        int v = pop(fila);
        for(w = 0; w < G->V; w++)
        {
            if(G->adj[v][w] == 1 && dist[w] == infinito)
            {
                dist[w] = dist[v] +1;
                pa[w] = v;
                push(fila, w);
            }
        }
    }

    // Printa os vetores de distancia
    printf("Caminho minimo\nDistancia: ");
    for(i = 0; i < G->V; i++)
        printf("%d ", dist[i]);
    printf("\nPA[]: ");
    for(i = 0; i < G->V; i++)
        printf("%d ", pa[i]);
    printf("\n");
}
