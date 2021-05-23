#ifndef LIVROGENERO_H
#define LIVROGENERO_H

#include <iostream>
#include <string>

#include "Livro.h"

class LivroGenero: public Livro{
    private:
	    string genero;
    public:
        LivroGenero(string = " ", unsigned int = 0, float = 0.0,float = 0.0, int = 0, string = " ");

        void setGenero(string);
        string getGenero() const;
	
	    void imprimeGenero()const;
};

#endif