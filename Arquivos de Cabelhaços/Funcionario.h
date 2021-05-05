#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario: public Pessoa{
    private:
    	long int id;
	string cargo;
    public:
        Funcionario(string = " ", string = " ", long int = 0, string = " ");
	
	// MÉTODO QUE CONFIGURA A IDENTIFICAÇÃO DO FUNCIONARIO
        void setID(long int);
        // MÉTODO QUE CONFIGURA O CARGO DESEMPENHADO DO FUNCIONARIO
        void setCargo(string);
        // MÉTODO QUE CONFIGURA A IDENTIFICAÇÃO DO FUNCIONARIO
        long int getID() const;
        // MÉTODO QUE CONFIGURA O CARGO DESEMPENHADO PELO FUNCIONARIO
        string getCargo() const;
        
        // IMPRIME OS DADOS DO FUNCIONÁRIO
        void imprime()const;
        
       
};

#endif


