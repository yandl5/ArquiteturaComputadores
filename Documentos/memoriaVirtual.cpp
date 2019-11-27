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
void Memoria::adicionarNovaPagina(Page aux){pages.push_back(aux);}
