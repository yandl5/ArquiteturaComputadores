#include "memoriaVirtual.h"
Memoria::Memoria(){contPageFault=0;}
Memoria::~Memoria(){}
//gets and sets
void Memoria::setSize(int Size){size=Size;}
void Memoria::setAlgorithm(string alg){algorithm=alg;}
void Memoria::setSizeOfPage(int SizePage){sizeOfPage=SizePage;}
void Memoria::setContPageFault(int pageFault){contPageFault=pageFault;}
int Memoria::getSize(){return size;}
string Memoria::getAlgorithm(){return algorithm;}
int Memoria::getSizeOfPage(){return sizeOfPage;}
int Memoria::getContPageFault(){return contPageFault;}
//manipulação memória
void Memoria::adicionarNovaPagina(Page aux)
{
	//to use ctime: https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
	double timeAtual = millis_since_midnight();
	if(pages.size()<numeroPaginas)
	{
		pages.push_back(aux);
	}
	else
	{
		if(algorithm=="lru")
		{
			this->insertLRU(aux,timeAtual);
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
			double timeAtual = millis_since_midnight();
			pages[i].setTime(timeAtual);
			return;
		}
	}
	cout<<"Página não encontrada na busca, criando nova página."<<endl;
	Page aux;
	aux.setAdress(adress);
	aux.setOperation("r");
	aux.setTime(millis_since_midnight());
	this->adicionarNovaPagina(aux);
}
void Memoria::insertLRU(Page aux, double timeAtual)
{
	double lessTime= pages[0].getTime();
	int j = 0;
	for(unsigned int i=0;i<pages.size();i++)
	{
		if(pages[i].getTime()<lessTime)
		{
			j=i;
			lessTime=pages[i].getTime();
		}
	}
	pages.erase(pages.begin()+j);
	contPageFault++;
	aux.setTime(millis_since_midnight());
	pages.push_back(aux);
	cout<<"Posição pagina apagada: "<<j<<endl;
}
void Memoria::insertFIFO(Page aux)
{
	pages.erase(pages.begin());
	aux.setTime(millis_since_midnight());
	pages.push_back(aux);
	contPageFault++;
}
void Memoria::insertRANDOM(Page aux)
{
	dado a(pages.size());
	int random;
	random = a.getValor() - 1;
	pages.erase(pages.begin()+random);
	aux.setTime(millis_since_midnight());
	pages.push_back(aux);
	contPageFault++;
	cout<<"Posição pagina apagada: "<<random<<endl;
}
void Memoria::maxPage(){numeroPaginas = size/sizeOfPage;}
void Memoria::printRam()
{
	for(unsigned int i=0; i<pages.size();i++)
	{
		 std::cout << std::fixed;
    	std::cout << std::setprecision(7);
		cout<<pages[i].getAdress()<<" "<<pages[i].getOperation()<<" "<<pages[i].getTime()<<endl;
	}
}