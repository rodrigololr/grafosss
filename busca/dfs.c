#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

/*
Esse código tem O(|E|) pq ele vai percorrer todas as arestas querendo ou não

Matriz de adjacencia: computacionalmente falando nn é mt boa, mas boa pra entender
na matriz se tiver zero não são conectados
por exemplo

0 0 1
0 0 1
1 1 0

0 - 2
1 - 2

considere " - " arestas bidirecionais

////////////////////

todos os vértices do grafo tem visitado = -1
logo se ele for visitado, visitado = 1

*/
int adj[MAX_VERTICES][MAX_VERTICES];
int visitado[MAX_VERTICES];

//aqui vamos só adicionar aresta mesmo sem erro no caso (adicionaremos 1 na matriz de adjacencia para
// representar que tem uma aresta
void addEdge(int v1, int v2){
    adj[v1][v2] = 1; 
    adj[v2][v1] = 1;
}



void DFSrec(int v, int n) {
    visitado[v] = 1;
    //insta visitado pq vamos nele direto
    printf("Visitando o vertice %d\n", v);

    // percorre por todo vizinho daquele vertice, 
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visitado[i]){
            DFSrec(i, n); 
        }
    }
}


void DFS(int n) {
    for (int i = 0; i < n; i++) {
        visitado[i] = 0; // vamo inializar o array todo com zero pra dizer q nenhum foi visitado
    }

    
    for (int i = 0; i < n; i++) {
        if (!visitado[i]){  //só chama DFSrec para vértices não visitados
            printf("\nIniciando DFS a partir do vertice %d:\n", i);
            DFSrec(i, n);  //chama DFSrec para o vértice i
        }
    }
}       //aqui como vamos começar e zero estamos dizendo seguinte
        //comece procurando pela primeira linha sabendo que o maximo de vertices é 10


void printGraph(int n) {
    printf("\nMatriz de Adjacencia:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    srand(time(NULL));
    
    printf("Digite o numero de vertices e arestas: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adj[i][j] = 0; // inicializando o array com zero (representando q ngm está conectado a ngm)
        }
    }

    printf("Digite as arestas (v1 v2):\n");
    for (int i = 0; i < m; i++) {
        int v1, v2;
        v1 = rand() % n;
        v2 = rand() % n;
        addEdge(v1, v2); //basicamente aqui vamos colocar as arestas
    }

    printGraph(n); /// só printando a matriz de adjacencia pra entender legal as conexões

    printf("Iniciando DFS a partir do vertice 0:\n");
    DFS(n);

    return 0;
}
