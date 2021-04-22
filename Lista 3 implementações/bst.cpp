#include <iostream>
#include <memory>

using namespace std;
class Node
{
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

class Arvore
{
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
    void inserirAux(std::shared_ptr<Node> no, int chave)
	{
		// se for menor, então insere à esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda é nulo
			if(no->getEsq() == nullptr)
			{
				std::shared_ptr<Node> novo_no = std::make_shared<Node>(chave);
                no->esq = std::move(novo_no); // seta o novo_no à eaquerda
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
        }
          else if(chave > no->getChave())
		{
			// verifica se a direita é nulo
			if(no->getDir() == NULL)
			{
				std::shared_ptr<Node> novo_no = std::make_shared<Node>(chave);
                no->dir = std::move(novo_no); // seta o novo_no à direita
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		} 
            
		// se for maior, então insere à direita
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
    int buscar(std::shared_ptr<Node> no, int chave)
    {
        if(no == nullptr){
        return 0;            
        }    
        cout<<"no->chave: "<<no->getChave()<<" chave: "<<chave<<endl;
            if(no->getChave() == chave)
            {
                return 1;
            }
            else if(no->getChave() > chave)
            {
                return buscar(no->getEsq(), chave);
            }
            else if(no->getChave() < chave)
            {
                return buscar(no->getDir(), chave);
            }
        
    }

};

int main() {
    
    
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
    int busca = arv.buscar(arv.getRaiz(), 11);
    cout<<busca;

    /*std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
    std::cout<<ptr->getChave()<<std::endl;
    ptr->esq = std::make_shared<Node>(2);
    cout<<ptr->esq->getChave()<<std::endl;
    std::shared_ptr<Node> ptr2;
    ptr2 = ptr->esq;
    cout<<ptr2->getEsq()<<std::endl;*/
    

    return 0;
}





