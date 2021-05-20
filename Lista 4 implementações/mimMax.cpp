#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void DCMinMax(std::vector<int>& v, int l, int r, pair<int, int>& minmax) {

    if (l == r) {
        minmax.first = v[l];
        minmax.second = v[l];
    }
    else if (r - l == 1) {
        if (v[l] < v[r]) {
            minmax.first = v[l];
            minmax.second = v[r];
        }
        else {
            minmax.first = v[r];
            minmax.second = v[l];
        }
    }
    else if (r - l > 1) {
        pair<int, int> minmax2(0,0);
        DCMinMax(v, l, std::floor((r + l) / 2), minmax);
        DCMinMax(v, std::floor((r + l) / 2) + 1, r, minmax2);

        minmax.first = (minmax.first < minmax2.first) ? minmax.first : minmax2.first;
        minmax.second = (minmax.second > minmax2.second) ? minmax.second : minmax2.second;
    }

}


int main(){
    std::vector<int> v({ 10,5,0,3,4,6,5 });
    pair<int, int> minmax(0,0);

    DCMinMax(v, 0, v.size() - 1, minmax);

    std::cout << minmax.first << std::endl;
    std::cout << minmax.second << std::endl;
    
    return 0;
}