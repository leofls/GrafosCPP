// Grafos - Verifica se um grafo direcionado tem ciclo

#include <iostream>
#include <list>
#include <stack> //pilha para usar na DSF

using namespace std;

class Grafo{
    int V; //Numero de vertices
    list<int> *adj; // Ponteirio para um array contendo as listas de adjacências

public:
    Grafo(int V); // Construtor
    void adicionaAresta(int v1, int v2); // Adiciona uma aresta no grafo

    //Faz uma DFS a partir de um vértice, retorna se achou ciclo ou não
    bool dfs(int v);

    //verifica se o grafo direcionado tem ciclo
    bool temCiclo();

};

//
Grafo::Grafo(int V){
    this->V = V; // Atribui o numero de vertices
    adj = new list<int>[V]; // Cria as listas
}

void Grafo::adicionaAresta(int v1, int v2){
    // basta retornar v2 a lista de vertices adjjacentes de v1
    adj[v1].push_back(v2);
}

bool Grafo::dfs(int v){
    stack<int> pilha;
    bool visitados[V], pilha_rec[V]; //vetor para saber quais são os vertives que estão na pilha

    //inicializa visitados e pilha_rec com false(Não visitdos)
    for(int i = 0; i < V; i++){
        visitados[i] = pilha_rec[i] = false;
    }

    //faz a DFS
    while(true){
        bool achou_vizinho = false;
        list<int>::iterator it;

        if(!visitados[v]){
            pilha.push(v);
            visitados[v] = pilha_rec[v] = true;
        }

        for(it = adj[v].begin();it != adj[v].end(); it++){

            //Se o vizinho está na pilha é porque existe ciclo
            if(pilha_rec[*it]){
                return true;
            }else if(!visitados[*it]){
                //Se não está na pilha e não foi vizitado indica que achou
                achou_vizinho = true;
                break;
            }
        }

        if(!achou_vizinho){
            pilha_rec[pilha.top()] = false; // marca que saiu da pilha
            pilha.pop(); //remove da pilha
            if(pilha.empty()){
                break;
            }

            v = pilha.top();
        } else{
            v = *it;
        }
    }

    return false;
}

bool Grafo::temCiclo(){
    for(int i = 0; i < V; i++){
        if(dfs(i)){
            return true;
        }

        return false;
    }
}

int main(int argc, char *argv[]){
    Grafo grafo(4);

    grafo.adicionaAresta(0,1);
    grafo.adicionaAresta(0,2);
    grafo.adicionaAresta(1,3);
    grafo.adicionaAresta(3,0);

    //Descomente qual opição você deseja


    int var = 3;
    if(grafo.dfs(var)){
        cout<< "Contem ciclo partindo de "<<var<<" \n";
    } else {
       cout<< "NAO contem ciclo partindo de "<<var<<" \n";
    }
    /*
    if(grafo.temCiclo()){
        cout<< "Contem ciclo \n";
    } else {
       cout<< "NAO contem ciclo \n";
    }
    */

    return 0;
}
