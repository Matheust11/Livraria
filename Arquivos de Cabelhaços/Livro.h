#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <fstream> // Possibilita a leitura e gravação de dados em um arquivo.
using std::ofstream;
using std::ifstream;

class Livro{
    private:
		string titulo;
		unsigned int codigo;
		float precofabrica;
		float precoconsumidor;
		int quantidade;

    public:
        //Livro( string = " ", unsigned int = 0, float = 0.0);
		Livro( string = " ", unsigned int = 0, float = 0.0,float = 0.0, int = 0);

		void setTitulo(string);
        string getTitulo() const;
		void setCodigo(unsigned int);
    	unsigned int getCodigo() const;
    	//void setPreco(float);
		//float getPreco() const;
		// metodo que configura o atributo associado ao preco de aquisicao do produto
		void setPrecoFabrica(float);
		float getPrecoFabrica() const;
		// metodo que configura o atributo associado ao preco repassado ao consumidor
		void setPrecoConsumidor(float);
		float getPrecoConsumidor() const;

		void setQuantidade(int);
        int getQuantidade() const;


		void imprime()const;
};
#endif