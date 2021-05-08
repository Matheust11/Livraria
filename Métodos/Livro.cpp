#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"



Livro::Livro(string titulo, unsigned int codigo, float preco){
    setTitulo(titulo);
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
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Preco: "  << getPreco()  << endl;
}