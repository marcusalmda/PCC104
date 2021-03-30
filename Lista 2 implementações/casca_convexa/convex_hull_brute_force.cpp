//Algoritmo baseado em exemplo encontrado em: https://www.programmersought.com/article/60806295079/
#include <iostream>
#include <vector>
  
using namespace std;
  
int main()
{

std::vector<std::vector<double>> matriz = { {1,2,0},
	{1,8,0},
	{2,-2,0},
	{2,-4,0},
	{6,4,0},
	{6,-2,0}};
    
    int c_tam = matriz[0].size();
    int l_tam = matriz.size();
    cout << "As cordenadas dos pontos são: \n";
    for(int i = 0; i < l_tam; ++i)
    {
    
        for(int j = 0; j < c_tam-1; ++j)
        {
            std::cout <<matriz[i][j]<<"\t";
        }
        cout << std::endl;
    }
    int a,b,c,assi1,assi2;
	int x = 0;
    int y = 1;
    for(int i=0;i<l_tam;i++){
		for(int j=i+1;j<l_tam;j++){
            a = matriz[j][y] - matriz[i][y];
            b = matriz[i][x] - matriz[j][x];
            c = ((matriz[i][x])*(matriz[j][y]))-((matriz[i][y])*(matriz[j][x]));
            assi1=0;
			assi2=0;
            for(int k=0;k<l_tam;k++){
                if((k==j) || (k==i)){
                    continue;
                }
                if((a*matriz[k][x])+(b*matriz[k][y])==c){
					assi1++;
					assi2++;
				}
				if((a*matriz[k][x])+(b*matriz[k][y])>c){
					assi1++;
				}
				if((a*matriz[k][x])+(b*matriz[k][y])<c){
					assi2++;
				}
            }
            if(assi1==l_tam-2 ||assi2==l_tam -2){
				matriz[i][2]=1;
				matriz[j][2]=1;
                cout <<"Uma linha entre: "<< matriz[i][0]<<", "<<matriz[i][1] <<" e "<< matriz[j][0] <<", "<<matriz[j][1]<< endl;
			}
        }
    }    
    cout << "As cordenadas do casco convexo são: \n";
    for(int i = 0; i < l_tam; ++i)
    {
        for(int j = 0; j < c_tam-1; ++j)
        {
            if (matriz[i][2] == 1)
            {
                std::cout <<matriz[i][j]<<"\t";

            }
        }cout << std::endl;
    }

return 0;
}
