#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <string>
#include <stdexcept>

#include "Livro.h"
#include "LivroUnidade.h"

using std::string;
using std::out_of_range;


class Estoque{
	private:
			// definindo vectors para armazenar diversos livros usando alocacao dinamica de memoria	
			vector <Livro> lista_livros;
			vector <LivroUnidade> lista_unidades;

			// metodos para ler de um arquivo objetos salvos
			void lerLivro(void);

	public:
			// construtor 
	    	Estoque();
	    	// destrutor 
	    	~Estoque();

			// metodos para gravar em um arquivo objetos definidos
    		bool salvarLivro();

	    	// metodos para inserir Livro
	    	bool inserirLivro(Livro);
	    	
	    	// metodo para imprime Livro
	    	void imprimeLivro() const;
	    	
	    	// metodo para remover Livro
	    	bool removerLivro(unsigned int);
	    	
	    	// MÉTODO PARA PESQUISAR LIVROS PELO NOME OU CÓDIGO DE BARRAS
	    	bool pesquisarLivro(string) const;
	    	bool pesquisarLivro(unsigned int) const;
	    	
	 	
	    	
	    	// MÉTODO PARA ORDENAR OS LIVROS EM ORDEM ALFABETICA
	    	void ordenaLivrosNome(void);

	    	bool setSaidaEstoqueLivro(unsigned int, int);
			bool setEntradaEstoqueLivro(unsigned int, int);

	    	// MÉTODO QUE RETORNA O CÓDIGO DO LIVRO POR NOME OU CÓDIGO DE BARRAS
	    	int getIndiceLivro(string) const;
	    	int getIndiceLivro(unsigned int) const;

			Livro getLivro(int indice) const;

			// metodos que retornam uma copia da lista de vector em um estado atua
    		vector <Livro> getListaLivro(void) const;
       
};

#endif



