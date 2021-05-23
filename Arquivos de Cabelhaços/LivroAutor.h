#ifndef LIVROUNIDADE_H
#define LIVROUNIDADE_H

#include <iostream>
#include <string>

#include "Livro.h"

using std::cout;
using std::endl;
using std::string;

class LivroAutor: public Livro{
    private:
	    string autor;
    public:
        LivroAutor(string = " ", unsigned int = 0, float = 0.0,float = 0.0, int = 0, string = " ");
	
	    void setAutor(string);
        string getAutor() const;
	
	    void imprimeAutor()const;
};

#endif
