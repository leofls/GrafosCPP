//GRAFO - DFS (Busca em profundidade)

#include <iostream>
#include <list>
#include <algorithm> //função find
#include <stack> // pilha para usar na DFS

using namespace std;

class Grafo{
    int V; //numero de vertices
    list<int> *adj; // Ponteirio para um array contendo as listas de adjacências

public:
    Grafo(int V); // Construtor
    void adicionarAresta( int v1, int v2); // Adiciona uma aresta no grafo

    //faz uma DFS apartir de um vertice (Raiz)
    void dfs(int v);
};

Grafo::Grafo(int V){
    this->V = V; // Atribui o numero de vertices

    adj = new list<int>[V]; //cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
    // basta retornar v2 a lista de vertices adjjacentes de v1
    adj[v1].push_back(v2);
}

void Grafo::dfs(int v){
    stack<int> pilha;
    bool visitados[V]; //vetor de visitados

    //marca todos como não visitados
    for(int i = 0; i<V; i++){
        visitados[i] = false;
    }

    while(true){
        if(!visitados[v]){
            cout << "Visitando vertices " << v <<" ...\n";
            visitados[v]=true; //marca como visitado
            pilha.push(v); //insere "v" na pilha
        }

        bool achou = false;
        list<int>::iterator it;

        //Busca por um vizinho não visitado
        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if(!visitados[*it]){ //se não foi visitado
                achou=true;
                break;
            }
        }

        if(achou){
            v = *it; //atualizar o vertice corrente "v"
        }else{
            //Se todos vizinhos estão vizitados ou não existe vizinhos
            //remove da pilha
            pilha.pop();

            //se a pilha ficar vazia, então terminou a busca
            if(pilha.empty())
                break;
            //Se chegou aqui, é porque pode pegar elemento do topo
            v = pilha.top();

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
    grafo.adicionarAresta(1,3);
    grafo.adicionarAresta(1,4);
    grafo.adicionarAresta(2,5);
    grafo.adicionarAresta(2,6);
    grafo.adicionarAresta(6,7);

    grafo.dfs(0);

    return 0;
}
