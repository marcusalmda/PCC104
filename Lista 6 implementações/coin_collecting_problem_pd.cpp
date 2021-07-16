#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
void print_board(std::vector<std::vector<int>> b) {
    for (std::vector<int> bi : b) {
        for (int bj : bi) {
            if (bj == 0) { std::cout << "-"; }
            else { std::cout << "x"; }
        }
        std::cout << std::endl;
    }
}
void print_boardv(std::vector<std::vector<int>> b) {
    for (std::vector<int> bi : b) {
        for (int bj : bi) {
             std::cout << bj<<" "; 
        }
        std::cout << std::endl;
    }
}
int collect_collecting_pd(std::vector<std::vector<int>>& c){

    int n = c.size();
    int m = c[0].size();
    std::vector<std::vector<int>> f(n, std::vector<int>(m));

    f[0][0] = c[0][0];
    //primeira linha 
    for (int j = 1; j <  m; j++){
        f[0][j] = f[0][j-1] + c[0][j];
    }
    //primeira coluna
    for (int i = 1; i < n; i++) { 
        f[i][0] = f[i - 1][0] + c[i][0]; 
    }
    for (int i = 1;i < n;i++){
        for (int j = 1;j < m;j++){
            f[i][j] = std::max(f[i-1][j],f[i][j-1]) + c[i][j];   
        }
        

    }
    print_boardv(f);
    std::cout<<std::endl;
    return f[n-1][m-1];
}





int main(){
    std::vector<std::vector<int>> b = { { 1,0,0,1 },
                                        { 1,1,0,0 },
                                        { 0,0,1,0 },
                                        { 1,0,1,1 }, };
    std::cout << "Tabuleiro: " << std::endl;
    print_board(b);
    std::cout<<std::endl;
    std::cout<<"Max de moedas coletadas = "<<collect_collecting_pd(b);
    

    return 0;
}