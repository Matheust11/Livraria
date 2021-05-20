// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"


// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo, Livro& l)
{
	arquivo << l.getTitulo() << endl;
	arquivo << l.getCodigo() << endl;
	arquivo << l.getPrecoFabrica() << endl;;
	arquivo << l.getPrecoConsumidor() << endl;;
	arquivo << l.getQuantidade()<< endl;;
	
	return arquivo;
}


// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo, Livro& l)
{
	string titulo;
	int quantidade;
	unsigned int codigo;
	float precoconsumidor, precofabrica;
	

	getline(arquivo, titulo);
	l.setTitulo(titulo); 
	arquivo >> codigo; 
	arquivo.ignore();
	l.setCodigo(codigo);
	arquivo >> precoconsumidor; 
	arquivo.ignore();
	l.setPrecoConsumidor(precoconsumidor);
 	arquivo >> precofabrica; 
	arquivo.ignore();
	l.setPrecoFabrica(precofabrica);
	arquivo >> quantidade; 
	arquivo.ignore();
	l.setQuantidade(quantidade);
	
	return arquivo;
}

