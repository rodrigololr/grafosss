# Algoritmos

# Dijkstra:

- Ideia geral:
Dijkstra resolve o problema de encontrar o caminho mínimo de um vértice fonte s para todos os outros vértices de um grafo com pesos positivos.

- Explicando seu pseudo-código:

1. Inicialização

Para cada vértice v, define:

    dist[v] = ∞ (distância infinita)

    prev[v] = -1 (sem predecessor ainda)

Para a fonte s, define:

    dist[s] = 0

Cria uma fila de prioridade H, que organiza os vértices pelo valor da distância.

2. Processamento da fila

Enquanto H não estiver vazia:

    Retira o vértice u de menor distância.

    Para cada vizinho v de u:

        Se a distância atual dist[v] for maior do que dist[u] + peso(u,v):

            Atualiza dist[v] para dist[u] + peso(u,v).

            Atualiza prev[v] como u.

            Atualiza a prioridade de v na fila (inserindo de novo).

3. Em resumo:

Vai expandindo os caminhos mais curtos primeiro.

Sempre que acha um caminho melhor para um vértice, atualiza.

Usa a fila de prioridade para sempre expandir o vértice mais "promissor".



# Bellman - Ford

Ideia geral
    O algoritmo de Bellman-Ford calcula o caminho mínimo de um vértice fonte para todos os outros vértices, inclusive com pesos negativos (desde que não haja ciclos negativos).

Etapas do algoritmo:
    1. Inicialização

        Define dist[s] = 0 para o vértice fonte.

        Todos os outros vértices têm dist[i] = ∞.

    2. Relaxamento das arestas

        Repete n-1 vezes (onde n é o número de vértices).

        Para cada aresta (u, v, w), se dist[v] > dist[u] + w, atualiza dist[v].

    3. Verificação de ciclos negativos

        Após os n-1 passos, percorre todas as arestas mais uma vez:
        Se ainda for possível melhorar a distância, então há um ciclo negativo.