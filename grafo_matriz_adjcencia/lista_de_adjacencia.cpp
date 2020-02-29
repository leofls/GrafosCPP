//GRAFO - LISTA DE ADJACENCIA

#include <iostream>
#include<list>
#include<algorithm>

using namespace std;
class Grafo{
    int V; //numero de vertices
    list<int> *adj; // Ponteirio para um array contendo as listas de adjacências

public:
    Grafo(int V); // Construtor
    void adicionarAresta( int v1, int v2); // Adiciona uma aresta no grafo

    // obtém o grau de saida de um dado vértice
    //grau de saida é o numero de arcos  que saem de "v"
    int obterGrauDeSaida(int v);

    bool existeVizinho(int v1, int v2); //verifica se

};

Grafo::Grafo(int V){
    this->V = V; // Atribui o numero de vertices

    adj = new list<int>[V]; //cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // basta retornar v2 a lista de vertices adjjacentes de v1
    adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v){
    // basta retornar o tamanho da lista que é a quantidade de vizinhos
    return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2){
    if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
        return true;
    return false;
}

int main()
{
    //criando um grafo de 4 vertices
    Grafo grafo(4);

    //adicionando arestas
    grafo.adicionarAresta(0,1);
    grafo.adicionarAresta(0,3);
    grafo.adicionarAresta(1,2);
    grafo.adicionarAresta(3,1);
    grafo.adicionarAresta(3,2);

    // mostrando os graus de saida
    cout << "Grau de saida do vértice 3: " << grafo.obterGrauDeSaida(3);

    //verirfica se existe vizinho
    if(grafo.existeVizinho(0,1))
        cout << "\n\n 0 eh vizinho de 1 \n";
    else
        cout<<"\n\n 0 nao eh vizinho de 1\n";

    return 0;
}
