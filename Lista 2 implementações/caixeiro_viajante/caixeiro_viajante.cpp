//Algoritmo baseado em exemplo encontrado em: https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
#include <bits/stdc++.h>
using namespace std;
/*
grafo com pesos
	0	1	2	3
0 | 0	10	15	20 |
1 | 10	0	35	25 |
2 | 15	35	0	30 |
3 | 20 	25	30	0  |
*/

int caixeiroviajante(std::vector<std::vector<int>> &grafo , int s, int V)
{
	// registra em um vetor todos os vertices a parte.
	vector<int> vertices;
	vector<int> caminho;
	for (int i = 0; i < V; i++){
        if (i != s){
            vertices.push_back(i);
        }
    }
	// registra o menor caminho.
	int min_path = INT_MAX;
	do {
		int caminho_atual = 0;
		// computa o menor caminho.
		int k = s;
		for (int i = 0; i < vertices.size(); i++) {
			caminho_atual += grafo[k][vertices[i]];
			k = vertices[i];
		}
		caminho_atual += grafo[k][s];

		//salvando menor caminho
		if(caminho_atual <= min_path){
			for(int i = 0; i < V-1; i++)
            caminho.assign(vertices.begin(), vertices.end());
		}
		// atualiza menor caminho
		min_path = min(min_path, caminho_atual);
	} while (
		next_permutation(vertices.begin(), vertices.end()));
	cout<<"caminho: "<<s<<"-"<<caminho[0]<<", ";
	int i;
	for(i = 0; i < V-2; i++)
        std::cout <<caminho[i]<<"-"<< caminho[i+1]<<", ";
    cout <<caminho[V-2]<<"-"<< s  <<std::endl;
	return min_path;
}

int main()
{
	// matriz represensentado um grafo
	std::vector<std::vector<int>> grafo = 
					{ { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int V = grafo.size(); //numero de vertices			
	int s; // vertice o qual o cominho começa e termina
	cout <<"Entre com o vertice inicial (0...3): ";
	cin >> s;
	cout <<"custo = " <<caixeiroviajante(grafo, s, V) << endl;
	return 0;
}
