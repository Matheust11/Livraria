#ifndef LIVROGENERO_H
#define LIVROGENERO_H

#include <iostream>
#include <string>
#include "Livro.h"

using std::cout;
using std::endl;
using std::string;

class LivroGenero: public Livro{
    private:
	    string genero;
    public:
        LivroGenero(string = " ", string = " ", unsigned int = 0, float = 0.0, string = " ");

        void setGenero(int);
        int getGenero() const;
	
	    void imprimeGenero()const;
};

#endif