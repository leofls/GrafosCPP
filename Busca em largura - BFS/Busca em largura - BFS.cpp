//GRAFO - BFS (Busca em Largura)

#include <iostream>
#include <list>
#include <queue> //Fila para usar na BFS

using namespace std;

class Grafo{
    int V; //numero de vertices
    list<int> *adj; // Ponteirio para um array contendo as listas de adjacências

public:
    Grafo(int V); // Construtor
    void adicionarAresta( int v1, int v2); // Adiciona uma aresta no grafo

    //faz uma BFS apartir de um vertice (Raiz)
    void bfs(int v);
};

Grafo::Grafo(int V){
    this->V = V; // Atribui o numero de vertices

    adj = new list<int>[V]; //cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // basta retornar v2 a lista de vertices adjjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo::bfs(int v){

    queue<int> fila;

    bool visitados[V]; //vetor de visitados

    for(int  i = 0; i < v; i++){
        visitados[i] = false; //marca todos como não visitado
    }

    cout<< "Visitando vertice " << v << " ...\n";
    visitados[v] = true; // marca como visitado

    while(true){
        list<int>::iterator it;

        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if(!visitados[*it]){
                cout<<"Visitando Vertice " << *it << " ...\n";
                visitados[*it] = true; // Marca como visitado
                fila.push(*it);//insere na fila
            }
        }

        //verifica se a fila não está vazia
        if(!fila.empty()){
            v = fila.front(); //obtém o primeiro elemento
            fila.pop(); //remove da fila

        }else {
            break; //sai do loop
        }

    }
}

int main()
{
    //criando um grafo de 8 vertices
    int V = 8;
    Grafo grafo(V);

    //adicionando arestas
    grafo.adicionarAresta(0,1);
    grafo.adicionarAresta(0,2);
    grafo.adicionarAresta(0,6);
    grafo.adicionarAresta(1,3);
    grafo.adicionarAresta(2,4);
    grafo.adicionarAresta(2,5);
    grafo.adicionarAresta(5,7);

    grafo.bfs(0);

    return 0;
}
