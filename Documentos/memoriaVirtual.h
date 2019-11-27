#ifndef MEMORIA
#define MEMORIA
#include <string>
#include "page.h"
#include <vector>
class Memoria
{
private:
	vector<Page> pages;
	int size;
	string algorithm;
	int sizeOfPage;
public:
	Memoria();
	~Memoria();
	//gets and sets
	//não contempla o atributo paginas pois este deterá mecanismos próprios de controle
	void setSize(int Size);
	void setAlgorithm(string alg);
	void setSizeOfPage(int SizePage);
	int getSize();
	string getAlgorithm();
	int getSizeOfPage();
	//manipular memoria(aqui entrará os algortimos futuros de manipulação de memória)
	void adicionarNovaPagina(Page aux);

};
#endif