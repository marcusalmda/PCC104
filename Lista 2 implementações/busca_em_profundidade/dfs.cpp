//Algoritmo baseado em exemplo encontrado em: https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
#include<bits/stdc++.h>
using namespace std;

//adiciona aresta para u e v;
void addAresta(vector<int> grafo[], int a, int b)
{
	grafo[a].push_back(b);
	grafo[b].push_back(a);
}

//recursivamente busca os filhos de u
void DFS2(int u, vector<int> grafo[], vector<bool> &visitado)
{
	visitado[u] = true;
	cout << u << "\t";
	for (int i=0; i<grafo[u].size(); i++)
		if (visitado[grafo[u][i]] == false)
			DFS2(grafo[u][i], grafo, visitado);
}

// chama a função DFS2 para todos os vertices
void DFS(vector<int> grafo[], int V)
{
	vector<bool> visitado(V, false);
	for (int u=0; u<V; u++)
		if (visitado[u] == false)
			DFS2(u, grafo, visitado);
    
}


int main()
{
	int num_vertice = 5;
	vector<int> grafo[num_vertice];

	// vertices de 0 a 4.
	addAresta(grafo, 0, 1);
	addAresta(grafo, 0, 3);
	addAresta(grafo, 1, 2);
	addAresta(grafo, 2, 4);
    cout << "O resultado da busca em profundidade é:  ";
	DFS(grafo, num_vertice);
	return 0;
}
