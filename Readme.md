# Simulador de Memória Virtual

Este projeto simula o gerenciamento de memória virtual, implementando algoritmos de substituição de páginas. É possível testar diferentes algoritmos, como o LRU (Least Recently Used), utilizando um arquivo de entrada que descreve operações de leitura e escrita de páginas.

## Descrição

O simulador gerencia a memória virtual realizando operações de leitura e escrita com base em um arquivo de log fornecido. O objetivo é observar o comportamento do sistema de memória virtual e o desempenho dos algoritmos de substituição de páginas.

## Funcionalidades

- Suporte a algoritmos de substituição de páginas (ex.: LRU).
- Leitura e processamento de arquivos de log com operações de memória.
- Relatórios sobre páginas lidas, escritas e page faults.

## Estrutura do Código

- **page.h / page.cpp**: Define e implementa a classe `Page`, representando uma página de memória.
- **memoriaVirtual.h / memoriaVirtual.cpp**: Define e implementa a classe `Memoria`, gerenciando a memória virtual e as páginas.
- **p2ac.cpp**: Contém a função `main`, o ponto de entrada do programa para a simulação.
- **randomGenerator.cpp**: Utilizado para gerar valores aleatórios (não incluído diretamente no código principal fornecido).

## Compilação e Execução

Para compilar e executar o código, siga os passos abaixo:

1. **Compilar:**
   ```sh
   g++ -std=c++11 page.cpp memoriaVirtual.cpp p2ac.cpp randomGenerator.cpp -o virtual