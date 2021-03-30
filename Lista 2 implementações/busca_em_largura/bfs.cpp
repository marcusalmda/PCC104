//Algoritmo baseado em exemplo encontrado em: https://www.studytonight.com/cpp-programs/cpp-program-for-bfs-traversal#

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> visitado;
vector<vector<int>> grafo;

void bfsTraversal(int b)
{
    //Declare uma fila para armazenar todos os nós conectados a - b
    queue<int> l;
    //insere b na lista
    l.push(b);
    //marca como visitado
    visitado[b] = true;

    cout << "O resultado da busca em largura é:  ";

    while (!l.empty())
    {
        int a = l.front();
        l.pop(); //remove o primeiro elemento da lista

        for (auto j = grafo[a].begin(); j != grafo[a].end(); j++)
        {
            if (!visitado[*j])
            {
                visitado[*j] = true;
                l.push(*j);
            }
        }
        cout << a << "\t";
    }
}

void addaresta(int a, int b)
{
    grafo[a].push_back(b); //aresta entre a e b
}

int main()
{
    
    int n = 7; //numero de vertices

    visitado.assign(n, false);
    grafo.assign(n, vector<int>());

    addaresta(0, 1);
    addaresta(0, 2);
    addaresta(1, 3);
    addaresta(1, 4);
    addaresta(2, 5);
    addaresta(2, 6);

    int vertice_inicial = 0; 
    bfsTraversal(vertice_inicial);

    return 0;
}