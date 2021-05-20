#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"

/* 
Livro::Livro(string titulo, unsigned int codigo, float preco){
    setTitulo(titulo);
    setCodigo(codigo);
    setPreco(preco);
}
 */
Livro::Livro(string titulo, unsigned int codigo, float precofabrica,float precoconsumidor, int quantidade){
    setTitulo(titulo);
    setCodigo(codigo);
    setPrecoFabrica(precofabrica);
    setPrecoConsumidor(precoconsumidor);
    setQuantidade(quantidade);
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

void Livro::setPrecoFabrica(float precofabrica)
{
	this -> precofabrica = precofabrica;
}

float Livro::getPrecoFabrica() const{
    return precofabrica;
}

void Livro::setPrecoConsumidor(float precoconsumidor)
{
	this -> precoconsumidor = precoconsumidor;
}

float Livro::getPrecoConsumidor() const{
    return precoconsumidor;
}

void Livro::setQuantidade(int quantidade)
{
	this -> quantidade = quantidade;
}

int Livro::getQuantidade() const{
    return quantidade;
}

void Livro::imprime()const{
    cout << "Titulo do Livro: " << getTitulo() << endl;
    cout << "Código de barras: " << getCodigo() << endl;
    cout << "Preco do Livro Comprado na Fabrica: "  << getPrecoFabrica()  << endl;
    cout << "Preco na Livraria: "  << getPrecoConsumidor()  << endl;
    cout << "Quantidade: " << getQuantidade() << endl;
}