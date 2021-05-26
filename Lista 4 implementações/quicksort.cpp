#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(std::vector<int>& arr){
	for (int p : arr) {
	std::cout << p << " ";
	}
	std::cout << std::endl;

}

int partition(vector<int> &v, int posinicial, int posfinal){
	
	int pivo = posfinal;
	int j = posinicial;
	for(int i=posinicial;i<posfinal;++i){
		if(v[i]<v[pivo]){
            swap(v[i],v[j]);
            j++;	
		}
	}
	swap(v[j],v[pivo]);
	return j;
	
}

void quicksort(vector<int> &v, int esq, int dir ){

	if(esq<dir){
		int p = partition(v,esq,dir);
        cout<<"pivo: "<<p<<endl;
        print_vector(v);
		quicksort(v,esq,p-1);
		quicksort(v,p+1,dir);
	}
	
}


int main(){
    std::vector<int> vec({ 9 , -3 , 5 , 2 , 6 , 8 , -6 , 1 , 3 });
    print_vector(vec);
    quicksort(vec,0, vec.size()-1);
    print_vector(vec);
    return 0;
}