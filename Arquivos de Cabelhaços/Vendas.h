#ifndef VENDA_H
#define VENDA_H

#include "Estoque.h"

class Vendas: public Estoque{
    private: 
    	float faturamento;
    	float saldo;

		vector <Livro> livro_nota;
		vector <LivroGenero> lgen_nota;
		vector <LivroAutor> laut_nota;
    public:
    	Vendas(void);
    	~Vendas(void);

		void setFaturamento(float);
    	void setSaldo(float);
    	
    	float getFaturamento(void) const;
    	float getSaldo(void) const;

		void inserirNotaLivro(Livro);
		void inserirNotaLivroGenero(LivroGenero);
		void inserirNotaLivroAutor(LivroAutor);

        void Notafiscal(void);
		void limpaCarrinho(void);

		//void fecharCaixa(void);

		void getDespesas();

};

#endif
