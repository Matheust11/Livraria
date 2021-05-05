#ifndef ESTOQUE_H
#define ESTOQUE_H




#include <string>

#include <vector>
#include "Livro.h"
#include "LivroUnidade.h"

class Estoque{
	private:
		// definindo vectors para armazenar diversos livros usando alocacao dinamica de memoria	
		vector <Livro> Livros;
		vector <LivroUnidade> Unidades;

	public:
		// construtor 
	    	Estoque();
	    	// destrutor 
	    	~Estoque();
	    	// metodos para inserir Livro
	    	string inserirLivro(Livro);
	    	
	    	// metodo para imprime Livro
	    	void imprimeLivro() const;
	    	
	    	// metodo para remover Livro
	    	long int removerLivro(long int);
	    	
	    	// MÉTODO PARA PESQUISAR LIVROS PELO NOME OU CÓDIGO DE BARRAS
	    	bool pesquisarLivro(string) const;
	    	bool pesquisarLivro(long int) const;
	    	
	 	
	    	
	    	// MÉTODO PARA ORDENAR OS LIVROS EM ORDEM ALFABETICA
	    	void ordenaLivrosNome(void);

	    	

	    	// MÉTODO QUE RETORNA O CÓDIGO DO LIVRO POR NOME OU CÓDIGO DE BARRAS
	    	int getIndiceLivro(string) const;
	    	int getIndiceLivro(long int) const;

    
       
       
};

#endif



