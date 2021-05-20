#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

int searchArr(std::vector<int>& a, int n, int mobile)
{
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
           return i + 1;
}
int getMobile(std::vector<int>& a,  std::vector<bool>& dir, int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {
        // direction 0 represents RIGHT TO LEFT.
        if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
  
        // direction 1 represents LEFT TO RIGHT.
        if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > mobile_prev)
            {           
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    cout<<endl;
    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}
int printOnePerm( std::vector<int>& a,  std::vector<bool>& dir, int n)
{
    int mobile = getMobile(a, dir, n); //elemento
    int pos = searchArr(a, n, mobile); //posição
    //std::cout<<mobile<<" "<<pos<<endl;

    // swapping no elementod de acordo com a posição.
    if (dir[a[pos - 1] - 1] ==  RIGHT_TO_LEFT){
        swap(a[pos-1], a[pos-2]);
        //cout<<"pos - 1: "<<pos-1<<" pos-2:"<<pos-2<<endl;
    }
       

  
    else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
       swap(a[pos], a[pos-1]);
  
    // mudando as direcoções dos elementos
    // maiores que o maior inteiro movel
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LEFT_TO_RIGHT)
                dir[a[i] - 1] = RIGHT_TO_LEFT;
            else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
                dir[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }
  
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << " "<<endl;
    for (int i = 0; i < n; i++)
        cout << dir[i];
    cout << " "<<endl;

}
int fact(int n)
{
  return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

// chama printOnePerm()
// um por um para printar todas as permutaçõe
void printPermutation(int n)
{
    // guarda a permutação atual
    std::vector<int> a(n);
    std::vector<bool> dir(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        std::cout << a[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
        dir[i] =  RIGHT_TO_LEFT;
    
    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}
int main(){
    int n = 3;
    printPermutation(n);
    return 0;
}