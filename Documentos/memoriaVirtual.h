#ifndef MEMORIA
#define MEMORIA
#include <string>
#include "page.h"
#include <vector>
#include <iostream>
#include <ctime>
#include "randomGenerator.h"
#include "functionTime.h"
#include <iomanip>
class Memoria
{
private:
	vector<Page> pages;
	int size;
	string algorithm;
	int sizeOfPage;
	int numeroPaginas;
	int contPageFault;
public:
	Memoria();
	~Memoria();
	//gets and sets
	//não contempla o atributo paginas pois este deterá mecanismos próprios de controle
	void setSize(int Size);
	void setAlgorithm(string alg);
	void setSizeOfPage(int SizePage);
	void setContPageFault(int pageFault);
	int getSize();
	string getAlgorithm();
	int getSizeOfPage();
	int getContPageFault();
	//manipular memoria(aqui entrará os algortimos futuros de manipulação de memória)
	void adicionarNovaPagina(Page aux);
	void maxPage();
	void findPage(string adress);
	void insertLRU(Page aux,double timeAtual);
	void insertFIFO(Page aux);
	void insertRANDOM(Page aux);
	void printRam();
};
#endif