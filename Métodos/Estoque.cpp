#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroGenero.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroAutor.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Estoque.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Sobrecargas.h"
 
Estoque::Estoque()
{
	lerLivro();
	lerLivroGenero();
	lerLivroAutor();
}

Estoque::~Estoque()
{
	salvarLivro();
	salvarLivroGenero();
	salvarLivroAutor();
}

void Estoque::lerLivro()
{
	Livro l;
	ifstream arquivo1; 
	arquivo1.open("/home/matheus/Livraria/Arquivos(txt)/lista_livros.txt"); 
	
	if(arquivo1.is_open()) 
	{
		while(!arquivo1.eof()) 
		{
			arquivo1 >> l; 
			lista_livros.push_back(l);
		}
	}
	arquivo1.close(); 
}
 
void Estoque::lerLivroGenero()
{
	LivroGenero lgen;
	ifstream arquivo2; 
	arquivo2.open("/home/matheus/Livraria/Arquivos(txt)/lista_genero.txt"); 
	
	if(arquivo2.is_open()) 
	{
		while(!arquivo2.eof()) 
		{
			arquivo2 >> lgen; 
			lista_genero.push_back(lgen);
		}
	}
	arquivo2.close(); 
}

void Estoque::lerLivroAutor()
{
	LivroAutor laut;
	ifstream arquivo3; 
	arquivo3.open("/home/matheus/Livraria/Arquivos(txt)/lista_autor.txt"); 
	
	if(arquivo3.is_open()) 
	{
		while(!arquivo3.eof()) 
		{
			arquivo3 >> laut; 
			lista_autor.push_back(laut);
		}
	}
	arquivo3.close(); 
}

bool Estoque::salvarLivro()
{
	ofstream arquivo1; 
	
	arquivo1.open("/home/matheus/Livraria/Arquivos(txt)/lista_livros.txt", std::ios::trunc);
	
	if(arquivo1.is_open())
	{
		for(unsigned i(0); i < lista_livros.size(); i++)
		{
			arquivo1 << lista_livros[i]; 
		}	
		return true;
	}
	else
		return false;	
	
	arquivo1.close();	
} 
 
bool Estoque::salvarLivroGenero()
{
	ofstream arquivo2; 
	
	arquivo2.open("/home/matheus/Livraria/Arquivos(txt)/lista_genero.txt", std::ios::trunc);
	
	if(arquivo2.is_open())
	{
		for(unsigned i(0); i < lista_genero.size(); i++)
		{
			arquivo2 << lista_genero[i]; 
		}	
		return true;
	}
	else
		return false;	
	
	arquivo2.close();	
} 

bool Estoque::salvarLivroAutor()
{
	ofstream arquivo3; 
	
	arquivo3.open("/home/matheus/Livraria/Arquivos(txt)/lista_autor.txt", std::ios::trunc);
	
	if(arquivo3.is_open())
	{
		for(unsigned i(0); i < lista_autor.size(); i++)
		{
			arquivo3 << lista_autor[i]; 
		}	
		return true;
	}
	else
		return false;	
	
	arquivo3.close();	
} 

bool Estoque::inserirLivro(Livro l)
{
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getCodigo() == l.getCodigo())
		{
			return false;
		}
	}
	
	lista_livros.push_back(l);
	
	return true;
}
 
bool Estoque::inserirLivroGenero(LivroGenero lgen)
{
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getCodigo() == lgen.getCodigo())
		{
			return false;
		}
	}
	
	lista_genero.push_back(lgen);
	
	return true;
}

bool Estoque::inserirLivroAutor(LivroAutor laut)
{
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getCodigo() == laut.getCodigo())
		{
			return false;
		}
	}
	
	lista_autor.push_back(laut);
	
	return true;
}

void Estoque::imprimeLivro() const
{
	cout << lista_livros.size() << endl;
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		cout << "===== "<< i+1 << "° Livro =====" << endl;
		lista_livros[i].imprime();
		cout << endl;
	}
}

void Estoque::imprimeLivroGenero() const
{
	cout << lista_genero.size() << endl;
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		cout << "===== "<< i+1 << "° Livro =====" << endl;
		lista_genero[i].imprimeGenero();
		cout << endl;
	}
}

void Estoque::imprimeLivroAutor() const
{
	cout << lista_autor.size() << endl;
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		cout << "===== "<< i+1 << "° Livro =====" << endl;
		lista_autor[i].imprimeAutor();
		cout << endl;
	}
}

bool Estoque::removerLivro(unsigned int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getCodigo() == codigo)
		{
			lista_livros.erase(lista_livros.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_livros.size())
		return false;
	
	return false;
}

bool Estoque::removerLivroGenero(unsigned int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getCodigo() == codigo)
		{
			lista_genero.erase(lista_genero.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_genero.size())
		return false;
	
	return false;
}

bool Estoque::removerLivroAutor(unsigned int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getCodigo() == codigo)
		{
			lista_autor.erase(lista_autor.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_autor.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivro(string titulo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getTitulo() == titulo)
		{
			lista_livros[i].imprime();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_livros.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivro(unsigned int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getCodigo() == codigo)
		{
			lista_livros[i].imprime();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_livros.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivroGenero(string titulo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getTitulo() == titulo)
		{
			lista_genero[i].imprimeGenero();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_genero.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivroGenero(unsigned int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getCodigo() == codigo)
		{
			lista_genero[i].imprimeGenero();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_genero.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivroAutor(string titulo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getTitulo() == titulo)
		{
			lista_autor[i].imprimeAutor();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_autor.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarLivroAutor(unsigned int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getCodigo() == codigo)
		{
			lista_autor[i].imprimeAutor();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_autor.size())
		return false;
	
	return false;
}

void Estoque::ordenaLivrosNome()
{
	int smallest; 

    for(unsigned i = 0; i < lista_livros.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_livros.size(); index++)
        {
            if(lista_livros[index].getTitulo().compare(lista_livros[smallest].getTitulo()) < 0)
            {
                smallest = index;
            }
        }
		Livro livro_auxiliar;
		livro_auxiliar = lista_livros[i];
    	lista_livros[i] = lista_livros[smallest];
    	lista_livros[smallest] = livro_auxiliar;
    } 		
}

void Estoque::ordenaLivrosNomeGenero()
{
	int smallest; 

    for(unsigned i = 0; i < lista_genero.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_genero.size(); index++)
        {
            if(lista_genero[index].getTitulo().compare(lista_genero[smallest].getTitulo()) < 0)
            {
                smallest = index;
            }
        }
		LivroGenero livro_auxiliar_genero;
		livro_auxiliar_genero = lista_genero[i];
    	lista_genero[i] = lista_genero[smallest];
    	lista_genero[smallest] = livro_auxiliar_genero;
    } 		
}

void Estoque::ordenaLivrosNomeAutor()
{
	int smallest; 

    for(unsigned i = 0; i < lista_autor.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_autor.size(); index++)
        {
            if(lista_autor[index].getTitulo().compare(lista_autor[smallest].getTitulo()) < 0)
            {
                smallest = index;
            }
        }
		LivroAutor livro_auxiliar_autor;
		livro_auxiliar_autor = lista_autor[i];
    	lista_autor[i] = lista_autor[smallest];
    	lista_autor[smallest] = livro_auxiliar_autor;
    } 		
}

bool Estoque::setEntradaEstoqueLivro(unsigned int codigo, int quantidade)
{
	if(pesquisarLivro(codigo))
	{
		int indice = getIndiceLivro(codigo); 
		cout << quantidade << endl;
		lista_livros[indice].setQuantidade(lista_livros[indice].getQuantidade() + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::setEntradaEstoqueLivroGenero(unsigned int codigo, int quantidade)
{
	if(pesquisarLivroGenero(codigo))
	{
		int indice = getIndiceLivroGenero(codigo); 
		cout << quantidade << endl;
		lista_genero[indice].setQuantidade(lista_genero[indice].getQuantidade() + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::setEntradaEstoqueLivroAutor(unsigned int codigo, int quantidade)
{
	if(pesquisarLivroAutor(codigo))
	{
		int indice = getIndiceLivroAutor(codigo); 
		cout << quantidade << endl;
		lista_autor[indice].setQuantidade(lista_autor[indice].getQuantidade() + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::setSaidaEstoqueLivro(unsigned int codigo, int quantidade)
{
	if(pesquisarLivro(codigo))
	{
		int indice = getIndiceLivro(codigo);
		cout << quantidade << endl;
		lista_livros[indice].setQuantidade(lista_livros[indice].getQuantidade()- quantidade);
		return true;
	}
	
	return false;
}

bool Estoque::setSaidaEstoqueLivroGenero(unsigned int codigo, int quantidade)
{
	if(pesquisarLivroGenero(codigo))
	{
		int indice = getIndiceLivroGenero(codigo);
		cout << quantidade << endl;
		lista_genero[indice].setQuantidade(lista_genero[indice].getQuantidade()- quantidade);
		return true;
	}
	
	return false;
}

bool Estoque::setSaidaEstoqueLivroAutor(unsigned int codigo, int quantidade)
{
	if(pesquisarLivroAutor(codigo))
	{
		int indice = getIndiceLivroAutor(codigo);
		cout << quantidade << endl;
		lista_autor[indice].setQuantidade(lista_autor[indice].getQuantidade()- quantidade);
		return true;
	}
	
	return false;
}

int Estoque::getIndiceLivro(unsigned int codigo) const
{
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getCodigo() == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceLivro(string titulo) const
{
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		if(lista_livros[i].getTitulo() == titulo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceLivroGenero(unsigned int codigo) const
{
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getCodigo() == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceLivroGenero(string titulo) const
{
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		if(lista_genero[i].getTitulo() == titulo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceLivroAutor(unsigned int codigo) const
{
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getCodigo() == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceLivroAutor(string titulo) const
{
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		if(lista_autor[i].getTitulo() == titulo)
		{
			return i;
		}
	}
	
	return -1;
}

float Estoque::getDespesas() const
{
	float despesas = 0;

	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		despesas += lista_livros[i].getPrecoConsumidor() * float(lista_livros[i].getQuantidade());
	}
	for(unsigned i(0); i < lista_autor.size(); i++)
	{
		despesas += lista_autor[i].getPrecoConsumidor() * float(lista_autor[i].getQuantidade());
	}
	for(unsigned i(0); i < lista_genero.size(); i++)
	{
		despesas += lista_genero[i].getPrecoConsumidor() * float(lista_genero[i].getQuantidade());
	}

	return despesas;
}

Livro Estoque::getLivro(int indice) const{

	Livro livro_vazio;

	try{
		lista_livros.at(indice);
	}
	catch(out_of_range const& excecao)
	{
			cout << excecao.what() << endl;
			cout << "Retornando objeto vazio." << endl;
			return livro_vazio;
	}
	return lista_livros.at(indice);
}

LivroGenero Estoque::getLivroGenero(int indice) const{

	LivroGenero livro_genero_vazio;

	try{
		lista_genero.at(indice);
	}
	catch(out_of_range const& excecao)
	{
			cout << excecao.what() << endl;
			cout << "Retornando objeto vazio." << endl;
			return livro_genero_vazio;
	}
	return lista_genero.at(indice);
}

LivroAutor Estoque::getLivroAutor(int indice) const{

	LivroAutor livro_autor_vazio;

	try{
		lista_autor.at(indice);
	}
	catch(out_of_range const& excecao)
	{
			cout << excecao.what() << endl;
			cout << "Retornando objeto vazio." << endl;
			return livro_autor_vazio;
	}
	return lista_autor.at(indice);
}

vector <Livro> Estoque::getListaLivro(void) const
{
	return lista_livros;
}

vector <LivroGenero> Estoque::getListaLivroGenero(void) const
{
	return lista_genero;
}

vector <LivroAutor> Estoque::getListaLivroAutor(void) const
{
	return lista_autor;
}
