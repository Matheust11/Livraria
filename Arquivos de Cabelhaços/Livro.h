#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro{
    private:
	string titulo;
	string genero;
	unsigned int codigo;
	float preco;
    public:
        Livro( string = " ", unsigned int = 0, float = 0.0);
	
	void setTitulo(string);
        string getTitulo() const;
        void setGenero(string);
        string getGenero() const;
	void setCodigo(unsigned int);
    	unsigned int getCodigo() const;
    	void setPreco(float);
	float getPreco() const;
        void imprime()const;
};

#endif

