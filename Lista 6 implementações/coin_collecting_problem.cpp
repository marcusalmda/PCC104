#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

//Converte de decimal para binário tamanho = n dígitos
std::vector<int> decimal_p_binary(int dec, int n) {
    //saida
    std::vector<int> b(n, 0);
    int i = n - 1;
    while (dec > 0) {
        b[i] = dec % 2;
        //atualiza e arredonda para baixo
        if(dec % 2 == 0){
            dec = dec/2;            
        }else{
            dec = (dec - 1)/2;
        }
        i--;
    }
    return b;
}
int collect_collecting_bf(std::vector<std::vector<int>>& b){
    int row = b.size();
    int col = b[0].size();

    //std::cout<<"row: "<<row<<" col: "<<col<<std::endl;
    //Vetor de índices 0 ou 1
    //0: movimenta em linha, quando 1: movimenta em coluna
    std::vector<int> I;
    int sum_ones, i_row = 0, i_col = 0, max_coins = 0;

    //num de movimentos possiveis
    int k = row + col - 2;
    

    for (int i = 0; i < pow(2, k); i++){
        I = decimal_p_binary(i, k);
        sum_ones = 0;
        for(int v : I){sum_ones += v;}

        //verifica se a tragetoria é valida
        if(sum_ones == col - 1){
            int sum_coins = b[0][0];
            i_row = 0;
            i_col = 0;

            for(int j : I){
                if(j == 0){
                    i_row += 1;
                }
                else{
                    i_col += 1;
                }
                sum_coins += b[i_row][i_col];
            }
            //salva o valor coma maior quantidade de moedas
            max_coins = std::max(sum_coins, max_coins);
        }
    }
    return max_coins;
}



void print_board(std::vector<std::vector<int>> b) {
    for (std::vector<int> bi : b) {
        for (int bj : bi) {
            if (bj == 0) { std::cout << "-"; }
            else { std::cout << "x"; }
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<std::vector<int>> b = { { 1,0,0,1 },
                                        { 0,1,0,0 },
                                        { 1,0,1,0 },
                                        { 0,0,1,1 }, };
    std::cout << "Tabuleiro: " << std::endl;
    print_board(b);
    std::cout<<"Max de moedas coletadas = "<<collect_collecting_bf(b);
    return 0;
}