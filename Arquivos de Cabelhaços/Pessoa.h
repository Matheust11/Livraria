#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
    private:
    	string nome;
	string cpf;
    public:
        Pessoa(string = " ", string = " ");
	// MÉTODO QUE CONFIGURA O NOME DO FUNCIONÁRIO
        void setNome(string);
        // MÉTODO QUE RETORNA O CPF DO FUNCIONÁRIO
        string getNome()const;
        // MÉTODO QUE CONFIGURA O CPF DO FUNCIONÁRIO
        void setCPF(string);
    	// MÉTODO QUE RETORNA O NOME DO FUNCIONÁRIO
        string getCPF()const;
        
        // IMPRIME OS DADOS DO FUNCIONÁRIO
        void imprime()const;
};

#endif
