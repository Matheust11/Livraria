#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Livro.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/LivroUnidade.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Estoque.h"
#include "/home/matheus/Livraria/Arquivos de Cabelhaços/Sobrecargas.h"
 
Estoque::Estoque()
{
	lerLivro();
}

Estoque::~Estoque()
{
	salvarLivro();
}


void Estoque::lerLivro(void)
{
	Livro l;
	ifstream arquivo; 
	arquivo.open("/home/matheus/Livraria/Arquivos(txt)/lista_livros.txt"); 
	
	if(arquivo.is_open()) 
	{
		while(!arquivo.eof()) 
		{
			arquivo >> l; 
			lista_livros.push_back(l);
		}
	}
	arquivo.close(); 
	
	return;
}

bool Estoque::salvarLivro()
{
	ofstream arquivo; 
	
	arquivo.open("/home/matheus/Livraria/Arquivos(txt)/lista_livros.txt", std::ios::trunc);
	
	if(arquivo.is_open())
	{
		for(unsigned i(0); i < lista_livros.size(); i++)
		{
			arquivo << lista_livros[i]; 
		}	
		return true;
	}
	else
		return false;	
	
arquivo.close();	
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

void Estoque::imprimeLivro() const
{
	for(unsigned i(0); i < lista_livros.size(); i++)
	{
		cout << "===== "<< i+1 << "° Livro =====" << endl;
		lista_livros[i].imprime();
		cout << endl;
	}
	
	return;
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

void Estoque::ordenaLivrosNome(void)
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
    
    return;			
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

vector <Livro> Estoque::getListaLivro(void) const
{
	return lista_livros;
}