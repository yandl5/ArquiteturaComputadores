#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include "page.h"
#include "memoriaVirtual.h"


//compilar:  g++ -std=c++11 page.cpp memoriaVirtual.cpp p2ac.cpp randomGenerator.cpp -o virtual
//executar: ./virtual lru arquivo.log 4 128
using namespace std;

int main(int argc, char* argv[])
{
	//memoria virtual e variaveis tokenização
	//referencia: https://pt.stackoverflow.com/questions/190755/como-separar-uma-string-em-peda%C3%A7os?rq=1
	Memoria memoria;
	vector<string> tokens;
	string token;
	Page pageAux;

	//dados de entrada
	string algoritmo;
	string file;
	int sizeFrame;
	int sizeMemory;

	//ler args
	for(int i=0;i<argc;i++)
	{
		if(i==1)
			algoritmo=argv[i];
		else if(i==2)
			file = argv[i];
		else if(i==3)
			sizeFrame = atoi(argv[i]);
		else if(i==4)
			sizeMemory = atoi(argv[i]);

	}
	cout<<algoritmo<<" "<<file<<" "<<sizeFrame<<" "<<sizeMemory<<endl;

	//arquivo
	int lidas=0;
	int escritas=0;
	string linha;
	char nomeArquivo[file.size()+1];
	strcpy(nomeArquivo,file.c_str());
	ifstream fileRead(nomeArquivo);
	//ler arquivo de entrada
	cout<<"Executando o simulador..."<<endl;
	if(fileRead.is_open())
	{
		while(! fileRead.eof())
		{
			getline(fileRead,linha);
			size_t foundR = linha.find(" R");
			size_t foundW = linha.find(" W");
			if(foundR!=string::npos)
				lidas+=1;
			if(foundW!=string::npos)
				escritas+=1;
			//tokenizar e separar as string para armazenar na classe memória como devidas páginas
			istringstream tokenizer {linha};
			while(tokenizer >> token)
				tokens.push_back(token);
       		pageAux.setAdress(tokens[0]);
       		pageAux.setOperation(tokens[1]);
       		tokens.clear();
       		memoria.adicionarNovaPagina(pageAux);
       		cout<<endl;
		}
	}

	//printar relaório
	cout<<"Arquivo de entrada: "<<file<<endl;
	cout<<"Tamanho de memória: "<<sizeMemory<<" "<<"KB"<<endl;
	cout<<"Tamanho das páginas: "<<sizeFrame<<" "<<"KB"<<endl;
	cout<<"Técnica de reposição: "<<algoritmo<<endl;
	cout<<"Páginas lidas: "<<lidas<<endl;
	cout<<"Páginas escritas: "<<escritas<<endl;
	return 0;
}