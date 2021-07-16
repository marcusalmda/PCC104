#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

void print_board(std::vector<std::vector<int>> b) {
    for (std::vector<int> bi : b) {
        for (int bj : bi) {
             std::cout << bj<<" "; 
        }
        std::cout << std::endl;
    }
}
void fill_vector(std::vector<std::vector<int>> &v, int num) {
    for (int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            v[i][j] = num;
        }
    }
}
//function to check if the cell is attacked or not
int is_attack(int i,int j, std::vector<std::vector<int>> board)
{   
    //chega col e row
    for (int k = 0; k < board.size(); k++){
        if(board[i][k]==1 || board[k][j]){
            return 1;
        }
    }
    //checa diagonais
    for(int k=0;k<board.size();k++)
    {
        for(int l=0;l<board.size();l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int n, std::vector<std::vector<int>> &board)
{
    int i,j;
    //Se n é 0, a solução foi encontrada
    if(n==0)
        return 1;
    for(i = 0; i < board.size(); i++){
        
        for(j = 0; j < board.size(); j++){
            // verificando se podemos colocar uma rainha aqui ou não
            // a rainha não será colocada se o local estiver sendo atacado
            // ou já ocupado
            if(!is_attack(i, j, board) && board[i][j]==0){
                board[i][j] = 1;
                //recursão
                // se podemos colocar a próxima rainha com este arranjo ou não
                if(N_queen(n-1, board)==1){
                        return 1;
                }
                board[i][j] = 0;
            } 
        }
    }
    return 0;
}

int main(){
    int n = 5;
    std::cout<<"Digite o valor de N para NxN: ";
    //std::cin>> n;
    std::cout << n << std::endl;
    std::cout << std::endl;
    std::vector<std::vector<int>> c(n,std::vector<int>(n));
    
    //print_board(c);
    fill_vector(c, 0);
    //print_board(c);
    N_queen(n, c);
    print_board(c);


    return 0;
}