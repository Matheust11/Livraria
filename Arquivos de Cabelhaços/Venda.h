#ifndef VENDA_H
#define VENDA_H

#include "Estoque.h"


class Venda: public Estoque{
    private: 
    	float faturamento;
    	float saldo;
    	void adicionarFaturamento(float);
    	void adicionarSaldo(float);
    public:
    	Vendas(void);
    	~Vendas(void);
    	
    	float getFaturamento(void) const;
    	float getSaldo(void) const;
        
};

#endif
