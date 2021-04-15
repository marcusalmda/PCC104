#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_vector(std::vector<int> &a)
{
    for (auto it = a.cbegin(); it != a.cend(); it++) {
        std::cout << *it << ' ';
    }
}

void insertion_sort(std::vector<int> &a)
{
    int v, j;
    for(int i = 1; i < a.size(); i++)
    {
        v = a[i];
        j = i-1;
        while(j>=0 && a[j]>v)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = v;
    }
}

int main()
{
    std::vector<int> a {10, 9, 8, 7, 6 ,5 ,4, 3, 2, 1};
    cout<<"vector size = "<<a.size()<<std::endl;
    cout << "\nOs elementos a serem ordenados sao: ";
    print_vector(a);
    insertion_sort(a);
    cout << "\nOs elementos  ordenados sao: ";
    print_vector(a);
    
    

    return 0;
}