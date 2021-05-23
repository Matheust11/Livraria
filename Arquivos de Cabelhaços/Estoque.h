#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <string>
#include <stdexcept>

#include "Livro.h"
#include "LivroAutor.h"
#include "LivroGenero.h"

using std::string;
using std::out_of_range;


class Estoque{
	private:
			// definindo vectors para armazenar diversos livros usando alocacao dinamica de memoria	
			vector <Livro> lista_livros;
			vector <LivroAutor> lista_autor;
			vector <LivroGenero> lista_genero;

			// metodos para ler de um arquivo objetos salvos
			void lerLivro(void);
			void lerLivroGenero(void);
			void lerLivroAutor(void);
	public:
			// construtor 
	    	Estoque();
	    	// destrutor 
	    	~Estoque();

			// metodos para gravar em um arquivo objetos definidos
    		bool salvarLivro();
			bool salvarLivroGenero();
			bool salvarLivroAutor();

	    	// metodos para inserir Livro
	    	bool inserirLivro(Livro);
			bool inserirLivroGenero(LivroGenero);
	    	bool inserirLivroAutor(LivroAutor);

	    	// metodo para imprime Livro
	    	void imprimeLivro() const;
			void imprimeLivroGenero() const;
			void imprimeLivroAutor() const;
	    	
	    	// metodo para remover Livro
	    	bool removerLivro(unsigned int);
			bool removerLivroGenero(unsigned int);
			bool removerLivroAutor(unsigned int);
	    	
	    	// MÉTODO PARA PESQUISAR LIVROS PELO NOME OU CÓDIGO DE BARRAS
	    	bool pesquisarLivro(string) const;
	    	bool pesquisarLivro(unsigned int) const;
			bool pesquisarLivroGenero(string) const;
	    	bool pesquisarLivroGenero(unsigned int) const;
			bool pesquisarLivroAutor(string) const;
	    	bool pesquisarLivroAutor(unsigned int) const;
	    	
	 	
	    	
	    	// MÉTODO PARA ORDENAR OS LIVROS EM ORDEM ALFABETICA
	    	void ordenaLivrosNome(void);
			void ordenaLivrosNomeGenero(void);
			void ordenaLivrosNomeAutor(void);

	    	bool setSaidaEstoqueLivro(unsigned int, int);
			bool setEntradaEstoqueLivro(unsigned int, int);
			bool setSaidaEstoqueLivroGenero(unsigned int, int);
			bool setEntradaEstoqueLivroGenero(unsigned int, int);
			bool setSaidaEstoqueLivroAutor(unsigned int, int);
			bool setEntradaEstoqueLivroAutor(unsigned int, int);


	    	// MÉTODO QUE RETORNA O CÓDIGO DO LIVRO POR NOME OU CÓDIGO DE BARRAS
	    	int getIndiceLivro(string) const;
	    	int getIndiceLivro(unsigned int) const;
			int getIndiceLivroGenero(string) const;
			int getIndiceLivroGenero(unsigned int) const;
			int getIndiceLivroAutor(string) const;
			int getIndiceLivroAutor(unsigned int) const;

			float getDespesas() const;


			Livro getLivro(int indice) const;
			LivroGenero getLivroGenero(int indice) const;
			LivroAutor getLivroAutor(int indice) const;

			// metodos que retornam uma copia da lista de vector em um estado atua
    		vector <Livro> getListaLivro(void) const; 
			vector <LivroGenero> getListaLivroGenero(void) const;
			vector <LivroAutor> getListaLivroAutor(void) const; 		
};

#endif



