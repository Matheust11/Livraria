#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroGenero.h"



LivroGenero::LivroGenero(string titulo, unsigned int codigo, float precofabrica,float precoconsumidor, int quantidade, string genero): Livro (titulo, codigo, precofabrica, precoconsumidor, quantidade){
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
    cout << "Gênero: " << getGenero() << endl;
}