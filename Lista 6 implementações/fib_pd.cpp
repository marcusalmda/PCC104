#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>



int fibonacci(int n){
    //caso seja 0 +2;
    std::vector<int> f(n+2);
    f[0] = 0;
    f[1] = 1;

    for(int i =2; i<=n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    int valor = f[n];
    return valor;
}


int main(){
    int n = 9;
    int fib = fibonacci(n);
    std::cout<<fib<<std::endl;
    
    return 0;
}