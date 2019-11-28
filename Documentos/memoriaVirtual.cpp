#include "memoriaVirtual.h"
Memoria::Memoria(){}
Memoria::~Memoria(){}
//gets and sets
void Memoria::setSize(int Size){size=Size;}
void Memoria::setAlgorithm(string alg){algorithm=alg;}
void Memoria::setSizeOfPage(int SizePage){sizeOfPage=SizePage;}
int Memoria::getSize(){return size;}
string Memoria::getAlgorithm(){return algorithm;}
int Memoria::getSizeOfPage(){return sizeOfPage;}
//manipulação memória
void Memoria::adicionarNovaPagina(Page aux)
{
	if(pages.size()<numeroPaginas)
	{
		pages.push_back(aux);
	}
	else
	{
		if(algorithm=="lru")
		{
			this->insertLRU(aux);
		}
		else if(algorithm=="fifo")
		{
			this->insertFIFO(aux);
		}
		else if(algorithm=="random")
		{
			this->insertRANDOM(aux);
		}
	}
}
void Memoria::findPage(string adress)
{
	for(unsigned int i=0;i<pages.size();i++)
	{
		if(adress==pages[i].getAdress())
		{
			cout<<"Página encontrada, endereço: "<<adress<<endl;
			return;
		}
	}
	cout<<"Página não encontrada na busca, criando nova página."<<endl;
	Page aux;
	aux.setAdress(adress);
	aux.setOperation("r");
	this->adicionarNovaPagina(aux);
}
void Memoria::insertLRU(Page aux){}
void Memoria::insertFIFO(Page aux){}
void Memoria::insertRANDOM(Page aux){}
void Memoria::maxPage(){numeroPaginas = size/sizeOfPage;}