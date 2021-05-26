#include <iostream>
#include <memory>
#include<queue>
using namespace std;


class Node{
    private:
        int chave;
    public:
        std::shared_ptr<Node> esq, dir;
        Node(int chave)
	    {
		    this->chave = chave;
		    esq = nullptr;
		    dir = nullptr;
	    }
        int getChave()
        {
            return chave;
        }
        std::shared_ptr<Node> getEsq()
        {
            return esq;
        }
        std::shared_ptr<Node> getDir()
        {
            return dir;
        }    
};

class Arvore{
    private:
        std::shared_ptr<Node> raiz;
    public:
        Arvore()
        {
            raiz = nullptr;
        }    
        std::shared_ptr<Node> getRaiz()
        {
        return raiz;
        }
        void inserir(int chave)
	    {
            if(raiz == nullptr) // verifica se a árvore está vazia
                raiz = std::make_shared<Node>(chave); // cria um novo nó
            else
                inserirAux(raiz, chave);
        }
        inserirAux(std::shared_ptr<Node> raiz, int chave){
            std::shared_ptr<Node> temp;
            std::queue<std::shared_ptr<Node>> q;
            q.push(raiz);
            while(!q.empty())
            {
                temp = q.front();
                q.pop();
                /* Insira o nó como o filho esquerdo do nó pai. */
                if(temp->esq == nullptr){
                    temp->esq = make_shared<Node>(chave);
                    break;
                }
                /* Se o nó esquerdo não for nulo, envie-o para a fila. */
                else
                    q.push(temp->esq);
                
                /* Insira o nó como o filho direito do nó pai. */
                if(temp->dir == nullptr) {
                    temp->dir =  make_shared<Node>(chave);
                    break;
                }

                /* Se o nó direito não for nulo, envie-o para a fila. */
                else
                    q.push(temp->dir);
            }

        }
        void emOrdem(std::shared_ptr<Node> no)
        {
            if(no != nullptr)
            {
                emOrdem(no->getEsq());
                cout << no->getChave() << " ";
                emOrdem(no->getDir());
            }
        }
        void preOrdem(std::shared_ptr<Node> no)
        {
            if(no != nullptr)
            {
                cout << no->getChave() << " ";
                preOrdem(no->getEsq());
                preOrdem(no->getDir());
            }
        }
         void posOrdem(std::shared_ptr<Node> no)
        {
            if(no != nullptr)
            {
                posOrdem(no->getEsq());
                posOrdem(no->getDir());
                cout << no->getChave() << " ";
            }
        }
        int tamanho(std::shared_ptr<Node> node) 
        { 
            if (node == nullptr) 
                return 0; 
            else
                return(tamanho(node->getEsq()) + 1 + tamanho(node->getDir())); 
        } 
};

int main(){
     Arvore arv;

	// insere as chaves
	arv.inserir(8);
    arv.inserir(6);
    arv.inserir(9);
    arv.inserir(10);
    arv.inserir(5);
    arv.inserir(2); 
    arv.inserir(7);
    arv.inserir(11);
    arv.inserir(3);;

    cout << "Percorrendo em ordem...\n";

	arv.emOrdem(arv.getRaiz());
    cout<<endl;
    int tam = arv.tamanho(arv.getRaiz());
    cout<<"tamanho = "<<tam<<endl;
    return 0;
}