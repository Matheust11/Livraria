#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroUnidade.h"



LivroUnidade::LivroUnidade(string titulo, string genero, unsigned int codigo, float preco, int quantidade): Livro (titulo, genero, codigo, preco){
    setQuantidade(quantidade);
}

void LivroUnidade::setQuantidade(int quantidade)
{
	this -> quantidade = quantidade;
}

int LivroUnidade::getQuantidade() const{
    return quantidade;
}

void LivroUnidade::imprimeQuantidade()const{
    imprime();
    cout << "Quantidade: " << getQuantidade() << endl;
}