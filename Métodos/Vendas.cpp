#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Vendas.h"

#include <ctime>
#include <iomanip>

using namespace std;

Vendas::Vendas(void)
{
	float f;
	
    ifstream myfile1;
    myfile1.open("/home/matheus/Livraria/Financeiro/faturamento.txt");
    myfile1 >> f;
    this -> faturamento  = f;
    myfile1.close();
    
    ifstream myfile2;
    myfile2.open("/home/matheus/Livraria/Financeiro/saldo.txt");
    myfile2 >> f;
    this -> saldo = f;
    myfile2.close();
}

Vendas::~Vendas(void)
{
	ofstream myfile1;
	myfile1.open("/home/matheus/Livraria/Financeiro/faturamento.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile1.is_open())
	{
		myfile1 << (this -> faturamento);
		myfile1.close();
	}
	else cout << "Não foi possível abrir o arquivo.";
	
	ofstream myfile2;
	myfile2.open("/home/matheus/Livraria/Financeiro/saldo.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile2.is_open())
	{
		myfile2 << (this -> saldo);
		myfile2.close();
	}
	else cout << "Não foi possível abrir o arquivo.";
}

void Vendas::setFaturamento(float faturamento)
{
	this->faturamento+=(faturamento>0)?faturamento:0;

	return; 
}

void Vendas::setSaldo(float saldo)
{
	this->saldo+=(saldo>0)?saldo:0; 

	return;
}

void Vendas::inserirNotaLivro(Livro aux){
	
	livro_nota.push_back(aux);
	
	return;
}

void Vendas::Notafiscal(void)
{
		cout << fixed << setprecision(2);
		
		ofstream myfile;
		myfile.open ("/home/matheus/Livraria/Financeiro/notafiscal.txt", std::ofstream::out | std::ofstream::app);
		if (myfile.is_open())
		{
			myfile << "=== Nota Fiscal da Livraria ===" <<endl<<endl;
			for(unsigned i(0); i < livro_nota.size(); i++)
			{
				myfile << "Nome do Livro: " << livro_nota[i].getTitulo() << endl;
				myfile << "Preço do Livro: " << livro_nota[i].getPrecoConsumidor() << " R$" << endl;
				myfile << "Código de Barras: " << livro_nota[i].getCodigo() << endl;
			}
			myfile << endl;
			myfile.close();
		}
		else cout << "Não foi possível abrir o arquivo.";

		for(unsigned i(0); i < livro_nota.size(); i++)
		{
			setSaldo(livro_nota[i].getPrecoConsumidor());
			setFaturamento(livro_nota[i].getPrecoConsumidor() - livro_nota[i].getPrecoFabrica());
		}
		
	limpaCarrinho();

	return;

}

void Vendas::limpaCarrinho(void)
{
	livro_nota.clear();
	
	return;
} 

float Vendas::getFaturamento(void) const{
	return faturamento;
}

float Vendas::getSaldo(void) const{
	return saldo;
}
