#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstring>

//compilar: g++ p2ac.cpp -o virtual
//executar: ./virtual lru arquivo.log 4 128
using namespace std;

int main(int argc, char* argv[])
{
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