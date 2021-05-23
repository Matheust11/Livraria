#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroAutor.h"

LivroAutor::LivroAutor(string titulo, unsigned int codigo, float precofabrica,float precoconsumidor, int quantidade, string autor): Livro (titulo, codigo, precofabrica, precoconsumidor, quantidade){
    setAutor(autor);
}

void LivroAutor::setAutor(string autor)
{
	this -> autor = autor;
}

string LivroAutor::getAutor() const{
    return autor;
}

void LivroAutor::imprimeAutor()const{
    imprime();
    cout << "Autor: " << getAutor() << endl;
}

