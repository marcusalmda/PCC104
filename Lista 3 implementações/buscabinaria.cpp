#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

using namespace std;

int binary_search(std::vector<int>& v,  int key) {
    int esq = 0;
    int dir = v.size() - 1;
    int i;
    do {
        i = (esq + dir) / 2;
        if (v[i] < key) {
            esq = i + 1;
        }
        else {
            dir = i - 1;
        }
    } while (v[i] != key && esq <= dir);
    if (v[i] == key) {
        return i;
    }
    else {
        return -1;
    }
}


int main() {
    std::vector<int> v;
    int i;
    for (i = 0; i < 10; i++){
        v.push_back(i);
    }
    cout<<"O vetor é:";
    for(i=0; i<10; i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
    int chave = 5;
    cout<<"O elmento a ser procurado é:"<< chave <<endl;
    int pos = binary_search(v, chave);
    cout<<"O elemento foi encontrado na posição:"<<pos<<endl;

    return 0;
}





