// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroGenero.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroAutor.h"


#include <string>

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo1, Livro& l)
{
	arquivo1 << l.getTitulo() << endl;
	arquivo1 << l.getCodigo() << endl;
	arquivo1 << l.getPrecoFabrica() << endl;
	arquivo1 << l.getPrecoConsumidor() << endl;
	arquivo1 << l.getQuantidade();
	
	return arquivo1;
}

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo2, LivroGenero& lgen)
{
	arquivo2 << lgen.getTitulo() << endl;
	arquivo2 << lgen.getCodigo() << endl;
	arquivo2 << lgen.getPrecoFabrica() << endl;
	arquivo2 << lgen.getPrecoConsumidor() << endl;
	arquivo2 << lgen.getQuantidade() << endl;
	arquivo2 << lgen.getGenero();
	
	return arquivo2;
}

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo3, LivroAutor& laut)
{
	arquivo3 << laut.getTitulo() << endl;
	arquivo3 << laut.getCodigo() << endl;
	arquivo3 << laut.getPrecoFabrica() << endl;
	arquivo3 << laut.getPrecoConsumidor() << endl;
	arquivo3 << laut.getQuantidade() << endl;
	arquivo3 << laut.getAutor();
	
	return arquivo3;
}


 //Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo1, Livro& l)
{
	string titulo;
	int quantidade;
	unsigned int codigo;
	float precoconsumidor, precofabrica;
	

	getline(arquivo1, titulo);
	l.setTitulo(titulo); 
	arquivo1 >> codigo; 
	arquivo1.ignore();
	l.setCodigo(codigo);
 	arquivo1 >> precofabrica; 
	arquivo1.ignore();
	l.setPrecoFabrica(precofabrica);
	arquivo1 >> precoconsumidor; 
	arquivo1.ignore();
	l.setPrecoConsumidor(precoconsumidor);
	arquivo1 >> quantidade; 
	arquivo1.ignore();
	l.setQuantidade(quantidade);
	
	return arquivo1;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo2, LivroGenero& lgen)
{
	string titulo,genero;
	int quantidade;
	unsigned int codigo;
	float precoconsumidor, precofabrica;
	

	getline(arquivo2, titulo);
	lgen.setTitulo(titulo); 
	arquivo2 >> codigo; 
	arquivo2.ignore();
	lgen.setCodigo(codigo);
	arquivo2 >> precofabrica; 
	arquivo2.ignore();
	lgen.setPrecoFabrica(precofabrica);
	arquivo2 >> precoconsumidor; 
	arquivo2.ignore();
	lgen.setPrecoConsumidor(precoconsumidor);
	arquivo2 >> quantidade; 
	arquivo2.ignore();
	lgen.setQuantidade(quantidade);
	getline(arquivo2, genero);
	lgen.setGenero(genero);
	
	return arquivo2;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo3, LivroAutor& laut)
{
	string titulo,autor;
	int quantidade;
	unsigned int codigo;
	float precoconsumidor, precofabrica;
	

	getline(arquivo3, titulo);
	laut.setTitulo(titulo); 
	arquivo3 >> codigo; 
	arquivo3.ignore();
	laut.setCodigo(codigo);
	arquivo3 >> precofabrica; 
	arquivo3.ignore();
	laut.setPrecoFabrica(precofabrica);
	arquivo3 >> precoconsumidor; 
	arquivo3.ignore();
	laut.setPrecoConsumidor(precoconsumidor);
	arquivo3 >> quantidade; 
	arquivo3.ignore();
	laut.setQuantidade(quantidade);
	getline(arquivo3, autor);
	laut.setAutor(autor);
	
	return arquivo3;
}

