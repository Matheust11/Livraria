#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"



Livro::Livro(string titulo, string genero, unsigned int codigo, float preco){
    setTitulo(titulo);
    setGenero(genero);
    setCodigo(codigo);
    setPreco(preco);
}

void Livro::setTitulo(string titulo)
{
	this -> titulo = titulo;
}

string Livro::getTitulo() const{
    return titulo;
}

void Livro::setGenero(string genero)
{
	this -> genero = genero;
}

string Livro::getGenero() const{
    return genero;
}

void Livro::setCodigo(unsigned int codigo)
{
	this -> codigo = codigo;
}

unsigned int Livro::getCodigo() const{
    return codigo;
}

void Livro::setPreco(float preco)
{
	this -> preco = preco;
}

float Livro::getPreco() const{
    return preco;
}

void Livro::imprime()const{
    cout << "Titulo: " << getTitulo() << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "COdigo: " << getCodigo() << endl;
    cout << "Preco: "  << getPreco()  << endl;
}