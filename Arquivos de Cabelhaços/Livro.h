#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Livro{
    private:
		string titulo;
		unsigned int codigo;
		float preco;
    public:
        Livro( string = " ", unsigned int = 0, float = 0.0);
	
		void setTitulo(string);
        string getTitulo() const;
		void setCodigo(unsigned int);
    	unsigned int getCodigo() const;
    	void setPreco(float);
		float getPreco() const;
        void imprime()const;
};

#endif

