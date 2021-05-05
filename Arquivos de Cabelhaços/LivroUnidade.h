#ifndef LIVROUNIDADE_H
#define LIVROUNIDADE_H

#include <string>
#include "Livro.h"

class LivroUnidade: public Livro{
    private:
	int quantidade;
	
    public:
        LivroUnidade( string = " ", unsigned int = 0, float = 0.0, int = 0);
	// METODO QUE IMPRIME A QUANTIDADE DE LIVROS DO DETERMINADO GENERO
	void setQuantidade(int);
        int getQuantidade() const;
	
	void imprimeQuantidade()const;
};

#endif
