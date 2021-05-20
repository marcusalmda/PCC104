#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
//Soma de pesos das moedas
int sumMoedas(std::vector<int>& lista,  int ini, int fim){
    int sum = 0,ii;
    for(ii=ini;ii<fim;ii++){
        sum += lista[ii];
    }
    return sum;
}

int FakeCoinProblem(std::vector<int>& A, int ini, int fim){
    
    int ii,jj,kk,peso1,peso2,peso3,n=fim-ini;

    if (n <= 1)
        return ini;
    else if (n == 2){
        if(A[ini] > A[ini+1])
            return ini+1;
        else
            return ini;
    }
    else{
        ii = floor(n/3);
        jj = 2*floor(n/3);
        kk = 3*floor(n/3);
        peso1 = sumMoedas(A,ini,ini+ii);
        peso2 = sumMoedas(A,ini+ii,ini+jj);
        peso3 = sumMoedas(A,ini+jj,ini+kk);

        if((peso1==peso2)&&(peso1==peso3)){
            FakeCoinProblem(A, ini+kk, fim);
        }
        else if(peso1==peso2){
            FakeCoinProblem(A, ini+jj,ini+kk);
        }
        else if(peso1>peso2){
            FakeCoinProblem(A, ini+ii,ini+jj);
        }
        else{
            FakeCoinProblem(A, ini,ini+ii);
        }
    }
}



void print_vector(std::vector<int>& coins)
{
	for (auto i = coins.begin(); i != coins.end(); ++i)
	{
		std::cout << *i << ' ';
	}

	std::cout << std::endl;
}

int main(){
    std::vector<int> coins(15,1);
	coins[5] = 0;
    int size = coins.size();
	print_vector(coins);
    int retorno = FakeCoinProblem(coins,0,size);
    std::cout<<retorno;
 

    return 0;
}