#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>



int ChangeMaking(std::vector<int> &d, int n){
    //Applies dynamic programming to find the minimum number of coins
    //of denominations d1 < d2 < ... < dm where d1 = 1 that add up to a
    //given amount n
    //Input: Positive integer n and array D[1..m] of increasing positive
    // integers indicating the coin denominations where D[1] = 1
    //Output: The minimum number of coins that add up to n
    std::vector<int> f(n);
    int temp, j;
    int m = d.size()-1;
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        temp = 2147483647;
        j = 1;
        while (j <= m && i >= d[j]){
            temp = std::min(f[i - d[j]], temp);
            j++;
        }
        f[i] = temp + 1;
    }
    return f[n];
}


int main(){
    std::vector<int> d{0,1,5,10};
    int num_coins = ChangeMaking(d, 25);
    std::cout<<num_coins<<std::endl;
    return 0;
}