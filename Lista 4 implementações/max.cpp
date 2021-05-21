#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void DCMinMax(std::vector<int>& v, int l, int r, int & maxi) {

    if (l == r) {
        maxi = v[l];
    }
    else if (r - l == 1) {
        if (v[l] < v[r]) {
            maxi = v[r];
        }
        else {
            maxi = v[l];
        }
    }
    else if (r - l > 1) {
        int max2 = 0;
        DCMinMax(v, l, std::floor((r + l) / 2), maxi);
        DCMinMax(v, std::floor((r + l) / 2) + 1, r, max2);
        if(maxi < max2){
            maxi = max2;
            
        }
            
    }

}


int main(){
    std::vector<int> v({4,6,10 });
    int maxi = 0;

    DCMinMax(v, 0, v.size() - 1, maxi);

    std::cout << maxi << std::endl;
    
    return 0;
}