#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_array_metade(std::vector<int>& arr, int inicio, int fim){
	for(int i=inicio; i < fim; i++)
    {
        std::cout << arr[i] << " ";
    }
	std::cout << std::endl;

}
void print_array(std::vector<int>& arr){
	for (int p : arr) {
	std::cout << p << " ";
	}
	std::cout << std::endl;

}

std::vector<int> Juntar(std::vector<int>& arr, int inicio, int meio, int fim, std::vector<int>& arrAux) {
    
    int esq = inicio;
    int dir = meio;
    for (int i = inicio; i < fim; ++i) {
        if ((esq < meio) && ((dir >= fim) || (arr[esq] < arr[dir]))) {
            arrAux[i] = arr[esq];
            ++esq;
        }
        else {
            arrAux[i] = arr[dir];
            ++dir;
        }
        print_array(arr);
    }
    //copiando o arr de volta
    for (int i = inicio; i < fim; ++i) {
        arr[i] = arrAux[i];
    }
}    

void MergeSort(std::vector<int>& arr, int inicio, int fim, std::vector<int>& arrAux) {
    if ((fim - inicio) < 2) return;
    print_array_metade(arr,inicio, fim);
    int meio = ((inicio + fim)/2);
    MergeSort(arr, inicio, meio, arrAux);
    MergeSort(arr, meio, fim, arrAux);
    Juntar(arr, inicio, meio, fim, arrAux);

}
void MergeSort(std::vector<int>& arr, int tamanho) { 
    std::vector<int> arrAux(tamanho);
    MergeSort(arr, 0, tamanho, arrAux);
}



int main(){
    std::vector<int> arr({4, 5, 3, 5, 2, 1, 7});
    print_array(arr);
    MergeSort(arr, arr.size());
    print_array(arr);

    return 0;
}