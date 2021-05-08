#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroGenero.h"



LivroGenero::LivroGenero(string titulo, unsigned int codigo, float preco, string genero): Livro (titulo, codigo, preco){
    setGenero(genero);
}

void LivroGenero::setGenero(string genero)
{
	this -> genero = genero;
}

string LivroGenero::getGenero() const{
    return genero;
}

void LivroGenero::imprimeGenero()const{
    imprime();
    cout << "Genero: " << getGenero() << endl;
}