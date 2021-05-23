#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Vendas.h"

#include <ctime>
#include <iomanip>

using namespace std;

Vendas::Vendas()
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

Vendas::~Vendas()
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
}

void Vendas::setSaldo(float saldo)
{
	this->saldo+=(saldo>0)?saldo:0; 
}

void Vendas::inserirNotaLivro(Livro aux){
	
	livro_nota.push_back(aux);
}

void Vendas::inserirNotaLivroGenero(LivroGenero aux_lgen){
	
	lgen_nota.push_back(aux_lgen);
}

void Vendas::inserirNotaLivroAutor(LivroAutor aux_laut){
	
	laut_nota.push_back(aux_laut);
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
				myfile << "Nome do Livro: " << livro_nota[i].getTitulo();
				myfile << " / Preço do Livro: R$" << livro_nota[i].getPrecoConsumidor();
				myfile << " / Código de Barras: " << livro_nota[i].getCodigo();
			}
			for(unsigned i(0); i < lgen_nota.size(); i++)
			{
				myfile << "Nome do Livro: " << lgen_nota[i].getTitulo();
				myfile << " / Preço do Produto: R$" << lgen_nota[i].getPrecoConsumidor();
				myfile << " / Código de Barras: " << lgen_nota[i].getCodigo() << endl;
			}
			for(unsigned i(0); i < laut_nota.size(); i++)
			{
				myfile << "Nome do Livro: " << laut_nota[i].getTitulo();
				myfile << " / Preço do Produto: R$" << laut_nota[i].getPrecoConsumidor();
				myfile << " / Código de Barras: " << laut_nota[i].getCodigo() << endl;
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
		for(unsigned i(0); i < laut_nota.size(); i++)
		{
			setSaldo(laut_nota[i].getPrecoConsumidor());
			setFaturamento(laut_nota[i].getPrecoConsumidor() - laut_nota[i].getPrecoFabrica());
		}
		for(unsigned i(0); i < lgen_nota.size(); i++)
		{
			setSaldo(lgen_nota[i].getPrecoConsumidor());
			setFaturamento(lgen_nota[i].getPrecoConsumidor() - lgen_nota[i].getPrecoFabrica());
		}
		
		
	limpaCarrinho();
}
/* 
void Vendas::fecharCaixa(void)
{
	faturamento = 0;
	saldo = 0;
	
	ofstream myfile1;
	myfile1.open("/home/matheus/Livraria/Financeiro/faturamento.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile1.is_open())
	{
		myfile1 << faturamento;
		myfile1.close();
	}
	else cout << "Não foi possível abrir o arquivo.";
	
	ofstream myfile2;
	myfile2.open("/home/matheus/Livraria/Financeiro/saldo.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile2.is_open())
	{
		myfile2 << saldo;
		myfile2.close();
	}
	else cout << "Não foi possível abrir o arquivo.";
	
	return;
}
 */
void Vendas::limpaCarrinho(void)
{
	livro_nota.clear();
	lgen_nota.clear();
	laut_nota.clear();
} 

float Vendas::getFaturamento(void) const{
	return faturamento;
}

float Vendas::getSaldo(void) const{
	return saldo;
}
