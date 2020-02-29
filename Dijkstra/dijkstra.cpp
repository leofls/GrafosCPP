//GRAFO - Dijkstra

#include<iostream>
#include<list>
#include<queue>

#define INFINITO 10000000

using namespace std;

class Grafo{
    int V; //num de vertices

    //onteiro para um array contendo as listas de adjacencias
    list<pair<int, int> > *adj;

public:
    //construtor
    Grafo(int V){
        this->V = V; //atribui o numero de vertices

     adj = new list<pair<int, int> >[V];
	}

	// vamos adicionar uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest){
		// vetor distâncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++){
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty()){
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false){
				// marca como visitado
				visitados[u] = true;

                //percorrer a minha lista dos adjacentes desse vertice
				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++){
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custoAresta = it->second;


					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custoAresta)){
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custoAresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
    //tamanho do grafo
	Grafo g(5);

    //define o caminho entre 2 vertices e o peso gerando uma aresta
	g.addAresta(0, 1, 4);
	g.addAresta(0, 2, 2);
	g.addAresta(0, 3, 5);
	g.addAresta(1, 4, 1);
	g.addAresta(2, 1, 1);
	g.addAresta(2, 3, 2);
	g.addAresta(2, 4, 1);
	g.addAresta(3, 4, 1);

	cout << "O resultado com menor custo entre 2 vertices eh: " << endl;
	cout << g.dijkstra(0, 3) << endl;


	return 0;
}
