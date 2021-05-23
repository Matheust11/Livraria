#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream> // Possibilita a leitura e gravação de dados em um arquivo.
using std::ofstream;
using std::ifstream;

#include <algorithm>
using std::sort; // Ordena os elementos do vector por meio dos iteradores.

#include <stdexcept>
using std::out_of_range;

#include <locale>

#include "/home/matheus/Livraria/Métodos/Livro.cpp"
#include "/home/matheus/Livraria/Métodos/LivroAutor.cpp"
#include "/home/matheus/Livraria/Métodos/LivroGenero.cpp"
#include "/home/matheus/Livraria/Métodos/Estoque.cpp"
#include "/home/matheus/Livraria/Métodos/Vendas.cpp"

int Menu(){

    int op(0);

    do{
        cout << "\n\t\tCONTROLE DE ESTOQUE LIVRARIA"
             <<"\nEscolha uma opção: "
             <<"\n1 - Inserir um novo Livro ao estoque"
             <<"\n2 - Gerir livros em estoque"
             <<"\n3 - Imprime lista de Livros"
             <<"\n4 - Remover livro da lista pelo código"
             <<"\n5 - Pesquisar Livro"
             <<"\n6 - Ordenar Estoque"
             <<"\n7 - Controle de Vendas"
			 <<"\n8 - Visualizar Despesas"
             <<"\n0 - Sair"
             <<"\nOpção: ";
         cin >> op;
	}while(op < 0 || op > 9);
    
	system("read -p 'Pressione Enter para continuar...' var");
	system("clear");
    
    return op;
}

int MenuSecao(){
	
	int op(0);

    do{
        cout <<"\n1 - Seção de Livro Gênero "
             <<"\n2 - Seção de Livro Autor "
			 <<"\n3 - Seção de Livro"
             <<"\nOpção: ";
        cin >> op;
		while(cin.fail())
		{
			cout << "Entrada inválida. Tente novamente." << endl;
			cin.clear();
			cin.ignore(256,'\n');  
			cin >> op;
		}
		
		cout << endl;
		system("read -p 'Pressione Enter para continuar...' var");
		system("clear");

	}while(op < 1 || op > 4);

    return op;
}

int MenuVendas(){

	int op(0);

	do{
        cout <<"\n1 - Registrar Compras"
             <<"\n2 - Visualizar Resumo Financeiro Atual da Livraria"
			 <<"\n3 - Sair"
             <<"\nOpção: ";
        cin >> op;
		while(cin.fail())
		{
			cout << "Entrada inválida. Tente novamente." << endl;
			cin.clear();
			cin.ignore(256,'\n');  
			cin >> op;
		}
		
		cout << endl;
		system("read -p 'Pressione Enter para continuar...' var");
		system("clear");

	}while(op < 1 || op > 4);

    return op;
}

// Programa Principal
int main(){
	
	setlocale(LC_ALL, "Portuguese");

   	Livro l;
	LivroGenero lgen; 
	LivroAutor laut;  
	Estoque estoque;
	Vendas venda;

	int escolha;
	int menu_op(1);
	int menu_secao(1);
	int menu_venda(1);

		while(menu_op){
			
			menu_op = Menu();
			
			switch(menu_op){
				case 0:
				{
					cout << endl << "Obrigado por utilizar nosso software." << endl;
					break;
				}
				case 1:
				{
					cout << " === ESCOLHA A SEÇÃO PARA INSERIR O LIVRO ===:";
					menu_op = MenuSecao();       

					switch(menu_op)
					{
						case 1:
						{
							string titulo, genero; 
							unsigned int codigo;
							float precofabrica, precoconsumidor;
							int quantidade;
							int escolha;
							
							cout << "Informe o preço que o Livro foi adquirido na fábrica: ";
							cin >> precofabrica;
								
							cout << "Informe o preço de venda do Livro para o consumidor: ";
							cin >> precoconsumidor;
			
							cout << "Informe o nome do Livro: ";
							cin.ignore();
							getline(cin, titulo);

							cout << "Informe o gênero do Livro: ";
							cin.ignore();
							getline(cin, genero);
							
							cout << "Informe o código de barras do Livro: ";
							cin >> codigo;
			
							cout << "Informe a quantidade de Livros: ";
							cin >> quantidade;
			
			
							LivroGenero lgen(titulo, codigo, precofabrica, precoconsumidor, quantidade, genero);
							if(estoque.inserirLivroGenero(lgen)){
								cout << "Tem certeza que deseja inserir livro no estoque?" << endl;
								cout << "1 - sim" << endl;
								cout << "2 - não" << endl << endl;
								cout << "Insira sua opção: ";
								cin >> escolha;
								while(cin.fail())
								{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> escolha;
								}
								if(escolha == 1)
								{
									estoque.salvarLivroGenero();
									cout << "Livro cadastrado com sucesso!" << endl;
								}
								else if(escolha == 2)
								{
									cout << "Livro descartado." << endl;
								}
								else
								{
									cout << "Opção inválida. Tente novamente." << endl;
								}	
							}else
								cout << "O cadastro não pode ser realizado!" << endl;
							break;	
						}
						case 2:
						{
							string titulo, autor; 
							unsigned int codigo;
							float precofabrica, precoconsumidor;
							int quantidade;
							int escolha;
							
							cout << "Informe o preço que o Livro foi adquirido na fábrica: ";
							cin >> precofabrica;
								
							cout << "Informe o preço de venda do Livro para o consumidor: ";
							cin >> precoconsumidor;
			
							cout << "Informe o nome do Livro: ";
							cin.ignore();
							getline(cin, titulo);

							cout << "Informe o autor do Livro: ";
							cin.ignore();
							getline(cin, autor);
							
							cout << "Informe o código de barras do Livro: ";
							cin >> codigo;
			
							cout << "Informe a quantidade de Livros: ";
							cin >> quantidade;
			
			
							LivroAutor laut(titulo, codigo, precofabrica, precoconsumidor, quantidade, autor);
							if(estoque.inserirLivroAutor(laut)){
								cout << "Tem certeza que deseja inserir livro no estoque?" << endl;
								cout << "1 - sim" << endl;
								cout << "2 - não" << endl << endl;
								cout << "Insira sua opção: ";
								cin >> escolha;
								while(cin.fail())
								{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> escolha;
								}
								if(escolha == 1)
								{
									estoque.salvarLivroAutor();
									cout << "Livro cadastrado com sucesso!" << endl;
								}
								else if(escolha == 2)
								{
									cout << "Livro descartado." << endl;
								}
								else
								{
									cout << "Opção inválida. Tente novamente." << endl;
								}	
							}else
								cout << "O cadastro não pode ser realizado!" << endl;
							break;	
						}
						case 3:
						{
							string titulo; 
							unsigned int codigo;
							float precofabrica, precoconsumidor;
							int quantidade;
							int escolha;
							
							cout << "Informe o preço que o Livro foi adquirido na fábrica: ";
							cin >> precofabrica;
								
							cout << "Informe o preço de venda do Livro para o consumidor: ";
							cin >> precoconsumidor;
			
							cout << "Informe o nome do Livro: ";
							cin.ignore();
							getline(cin, titulo);
							
							cout << "Informe o código de barras do Livro: ";
							cin >> codigo;
			
							cout << "Informe a quantidade de Livros: ";
							cin >> quantidade;
			
			
							Livro l(titulo, codigo, precofabrica, precoconsumidor, quantidade);
							if(estoque.inserirLivro(l)){
								cout << "Tem certeza que deseja inserir livro no estoque?" << endl;
								cout << "1 - sim" << endl;
								cout << "2 - não" << endl << endl;
								cout << "Insira sua opção: ";
								cin >> escolha;
								while(cin.fail())
								{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> escolha;
								}
								if(escolha == 1)
								{
									estoque.salvarLivro();
									cout << "Livro cadastrado com sucesso!" << endl;
								}
								else if(escolha == 2)
								{
									cout << "Livro descartado." << endl;
								}
								else
								{
									cout << "Opção inválida. Tente novamente." << endl;
								}	
							}else
								cout << "O cadastro não pode ser realizado!" << endl;
							break;
						}
					}
					break;	
				}
				case 2:
				{
					int quantidade;
					unsigned int codigo;
						
					cout << "Escolha o tipo de procedimento a ser realizado: " << endl << endl;
					cout << "1 - Adicionar Livros;" << endl;
					cout << "2 - Remover Livros;" << endl << endl;
					cout << "Opção: ";
					cin >> escolha;
					while(cin.fail())
					{
					cout << "Entrada inválida. Tente novamente." << endl;
					cin.clear();
					cin.ignore(256,'\n');  
					cin >> escolha;
					}

					cout << endl;
					system("read -p 'Pressione Enter para continuar...' var");
					system("clear");  

					switch(escolha)
					{
						case 1:
						{
							cout << "=== ESCOLHA A SEÇÃO A TER LIVROS ADICIONADOS === :" << endl << endl;
							menu_secao = MenuSecao();

							switch(menu_secao)
							{
								case 1:
								{
									cout << "Informe o código de barras do livro a ser aumentado no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de aumento:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setEntradaEstoqueLivroGenero(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros adicionados com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}
								case 2:
								{
									cout << "Informe o código de barras do livro a ser aumentado no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de aumento:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setEntradaEstoqueLivroAutor(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros adicionados com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}
								case 3:
								{
									cout << "Informe o código de barras do livro a ser aumentado no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de aumento:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setEntradaEstoqueLivro(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros adicionados com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}
								default:
									break;
							}
							break;
						}
						case 2:
						{
							cout << "=== ESCOLHA A SEÇÃO A TER LIVROS REMOVIDOS === :" << endl << endl;
							menu_secao = MenuSecao();

							switch(menu_secao)
							{
								case 1:
								{
									cout << "Informe o código de barras do livro a ser diminuido no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de diminuição:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setSaidaEstoqueLivroGenero(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros removidos com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}		
								case 2:
								{
									cout << "Informe o código de barras do livro a ser diminuido no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de diminuição:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setSaidaEstoqueLivroAutor(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros removidos com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}
								case 3:
								{
									cout << "Informe o código de barras do livro a ser diminuido no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de diminuição:";
									cin >> quantidade;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> quantidade;
									}
									
									cout << "Pesquisando..." << endl << endl;
									if(estoque.setSaidaEstoqueLivro(codigo, quantidade))
									{
										cout << endl;
										cout << "Livros removidos com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamente." << endl;
									}
									break;
								}
								default:
									break;
							}
							break;
						}
					}
					break;
				}
				case 3:
				{
					menu_secao = MenuSecao();
					
					switch(menu_secao)
					{
						case 1:
						{
							estoque.imprimeLivroGenero();
							break;
						}
						case 2:
						{
							estoque.imprimeLivroAutor();
							break;
						}
						case 3:
						{
							estoque.imprimeLivro();
							break;
						}
						default:
							break;
					}
					
					break;
				}
				case 4:
				{
					unsigned int codigo;
				
					cout << "=== ESCOLHA A SEÇÃO PARA REMOVER O LIVRO === :" << endl << endl;
					menu_secao = MenuSecao();      
		
					switch(menu_secao)
					{
						case 1:
						{
							cout << "Informe o código de barras do Livro a ser removido: ";
							cin >> codigo;
							while(cin.fail())
							{
							cout << "Entrada inválida. Tente novamente." << endl;
							cin.clear();
							cin.ignore(256,'\n');  
							cin >> codigo;
							}
							
							cout << "Livros Encontrados: " << endl << endl;
							if(estoque.pesquisarLivroGenero(codigo))
							{
								cout << endl;
								cout << "Processando remoção..." << endl;
							}
							
							if(estoque.removerLivroGenero(codigo))
							{
								cout << "Livro removido com sucesso." << endl;
							}
							else
							{
								cout << "Operação não realizada. Tente Novamente." << endl;
							}
							break;
						}
						case 2:
						{
							cout << "Informe o código de barras do Livro a ser removido: ";
							cin >> codigo;
							while(cin.fail())
							{
							cout << "Entrada inválida. Tente novamente." << endl;
							cin.clear();
							cin.ignore(256,'\n');  
							cin >> codigo;
							}
							
							cout << "Livros Encontrados: " << endl << endl;
							if(estoque.pesquisarLivroAutor(codigo))
							{
								cout << endl;
								cout << "Processando remoção..." << endl;
							}
							
							if(estoque.removerLivroAutor(codigo))
							{
								cout << "Livro removido com sucesso." << endl;
							}
							else
							{
								cout << "Operação não realizada. Tente Novamente." << endl;
							}
							break;
						}
						case 3:
						{
							cout << "Informe o código de barras do Livro a ser removido: ";
							cin >> codigo;
							while(cin.fail())
							{
							cout << "Entrada inválida. Tente novamente." << endl;
							cin.clear();
							cin.ignore(256,'\n');  
							cin >> codigo;
							}
							
							cout << "Livros Encontrados: " << endl << endl;
							if(estoque.pesquisarLivro(codigo))
							{
								cout << endl;
								cout << "Processando remoção..." << endl;
							}
							
							if(estoque.removerLivro(codigo))
							{
								cout << "Livro removido com sucesso." << endl;
							}
							else
							{
								cout << "Operação não realizada. Tente Novamente." << endl;
							}
							break;
						}
					}
					break;
				}
				case 5:
				{
					unsigned int codigo;
					string titulo;

					cout << " === ESCOLHA O TIPO DE PESQUISA A SER REALIZADA === :" << endl << endl;
					cout << "1 - Pesquisa por código de barras;" << endl;
					cout << "2 - Pesquisa por título do livro;" << endl;
					cout << "Opção: ";
					cin >> escolha;

					while(cin.fail())
					{
					cout << "Entrada inválida. Tente novamente." << endl;
					cin.clear();
					cin.ignore(256,'\n');  
					cin >> escolha;
					}
						
					cout << endl;
					system("read -p 'Pressione Enter para continuar...' var");
					system("clear"); 

					switch(escolha)
					{
						case 1:
						{
							menu_secao = MenuSecao();

							switch(menu_secao){
									case 1:
									{
										cout << "Informe o código de barras do livro a ser pesquisado: ";
										cin >> codigo;
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> codigo;
										}
										
										if(estoque.pesquisarLivroGenero(codigo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse código no estoque." << endl;
										}
										break;		
									}
									case 2:
									{
										cout << "Informe o código de barras do livro a ser pesquisado: ";
										cin >> codigo;
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> codigo;
										}
										
										if(estoque.pesquisarLivroAutor(codigo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse código no estoque." << endl;
										}
										break;		
									}
									case 3:
									{
										cout << "Informe o código de barras do livro a ser pesquisado: ";
										cin >> codigo;
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> codigo;
										}
										
										if(estoque.pesquisarLivro(codigo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse código no estoque." << endl;
										}
										break;		
									}
							}
							break;	
						}
						case 2:
						{
							menu_secao = MenuSecao();

							switch(menu_secao){
								case 1:
								{
										cout << "Informe o título do livro a ser pesquisado: ";
										cin.ignore();
										getline(cin, titulo);
										
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> titulo;
										}
										
										if(estoque.pesquisarLivroGenero(titulo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse título no estoque." << endl;
										}
										break;		
									}
								case 2:
								{
										cout << "Informe o título do livro a ser pesquisado: ";
										cin.ignore();
										getline(cin, titulo);
										
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> titulo;
										}
										
										if(estoque.pesquisarLivroAutor(titulo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse título no estoque." << endl;
										}
										break;		
									}
								case 3:
								{
										cout << "Informe o título do livro a ser pesquisado: ";
										cin.ignore();
										getline(cin, titulo);
										
										while(cin.fail())
										{
										cout << "Entrada inválida. Tente novamente." << endl;
										cin.clear();
										cin.ignore(256,'\n');  
										cin >> titulo;
										}
										
										if(estoque.pesquisarLivro(titulo))
										{
											cout << endl;
											cout << "Livros acima pertencem ao estoque." << endl;
										}
										else
										{
											cout << endl;
											cout << "Sem ocorrências de Livros com esse título no estoque." << endl;
										}
										break;		
								}
							}
							break;
						}

					}
				
				}
				case 6:
				{
					cout << "=== ESCOLHA A SEÇÃO PARA TER SEUS DADOS ORDENADOS === :" << endl << endl;
					menu_secao = MenuSecao();
					
					switch(menu_secao)
					{
						case 1:
						{
							cout << "=== ESCOLHA O TIPO DE ORDENAÇÃO === :" << endl << endl;
							cout << "1 - Ordenar por título do Livro" << endl;
							
							cout << "Opção: ";
							cin >> escolha;
							while(cin.fail())
							{
								cout << "Entrada inválida. Tente novamente." << endl;
								cin.clear();
								cin.ignore(256,'\n');  
								cin >> escolha;
							}

							cout << endl;
							system("read -p 'Pressione Enter para continuar...' var");
							system("clear");
							
							switch(escolha)
							{
								case 1:
								{
									estoque.ordenaLivrosNomeGenero();
									estoque.imprimeLivroGenero();
									break;
								}
							}
							break;
						}
						case 2:
						{
							cout << "=== ESCOLHA O TIPO DE ORDENAÇÃO === :" << endl << endl;
							cout << "1 - Ordenar por título do Livro" << endl;
							
							cout << "Opção: ";
							cin >> escolha;
							while(cin.fail())
							{
								cout << "Entrada inválida. Tente novamente." << endl;
								cin.clear();
								cin.ignore(256,'\n');  
								cin >> escolha;
							}

							cout << endl;
							system("read -p 'Pressione Enter para continuar...' var");
							system("clear");
							
							switch(escolha)
							{
								case 1:
								{
									estoque.ordenaLivrosNomeAutor();
									estoque.imprimeLivroAutor();
									break;
								}
							}
							break;
						}
						case 3:
						{
							cout << "=== ESCOLHA O TIPO DE ORDENAÇÃO === :" << endl << endl;
							cout << "1 - Ordenar por título do Livro" << endl;
							
							cout << "Opção: ";
							cin >> escolha;
							while(cin.fail())
							{
								cout << "Entrada inválida. Tente novamente." << endl;
								cin.clear();
								cin.ignore(256,'\n');  
								cin >> escolha;
							}

							cout << endl;
							system("read -p 'Pressione Enter para continuar...' var");
							system("clear");
							
							switch(escolha)
							{
								case 1:
								{
									estoque.ordenaLivrosNome();
									estoque.imprimeLivro();
									break;
								}
							}
							break;
						}
					}
					break;
				}
				case 7:
				{
					
					menu_venda = MenuVendas();

					switch (menu_venda)
					{
						case 1:
						{
							cout <<"\n=== Escolha a Seção do Livro a ser registrado ==="
									<<"\n1 - Seção Livro Gênero"
									<<"\n2 - Seção Livro Autor"
									<<"\n3 - Seção Livro"
									<<"\n4 - Desistir das compras"
									<<"\n0 - Montar nota fiscal"
									<<"\nOpção: ";
									cin >> escolha;
								while(cin.fail())
								{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> escolha;
								}
							
								cout << endl;
								system("read -p 'Pressione Enter para continuar...' var");
								system("clear");

								switch(escolha)
								{
									case 0:
									{
										cout << "Nota Fiscal montada com sucesso!" << endl;
										venda.Notafiscal();
										break;
									}
									case 1:
									{
										unsigned int codigo;

										cout << "Insira o código de barras do Livro: ";
										cin >> codigo;
										while(cin.fail())
										{
											cout << "Entrada inválida. Tente novamente." << endl;
											cin.clear();
											cin.ignore(256,'\n');  
											cin >> codigo;
										}
												
										cout << endl;
												
										if(venda.pesquisarLivroGenero(codigo))
										{
											cout << endl;
											cout << "Livro encontrado. Tem certeza que deseja registrar na nota?" << endl;
											cout << "1 - sim" << endl;
											cout << "2 - não" << endl << endl;
											cout << "Insira sua opcão: ";
											cin >> escolha;
											while(cin.fail())
											{
												cout << "Entrada inválida. Tente novamente." << endl;
												cin.clear();
												cin.ignore(256,'\n');  
												cin >> escolha;
											}

											if(escolha == 1)
											{
												lgen = venda.getLivroGenero(venda.getIndiceLivroGenero(codigo));
												venda.inserirNotaLivroGenero(lgen);
												venda.setSaidaEstoqueLivroGenero(codigo, 1);
												cout << endl;
												cout << "Livro Registrado com sucesso." << endl;
											}
											else if(escolha == 2)
											{
												cout << "Livro descartado." << endl;
											}
											else
											{
												cout << "Opção inválida. Tente novamente." << endl;
											}	
										}
										else
										{
											cout << "Livro não encontrado." << endl;
										}
										break;
									}
									case 2:
									{
										unsigned int codigo;

										cout << "Insira o código de barras do Livro: ";
										cin >> codigo;
										while(cin.fail())
										{
											cout << "Entrada inválida. Tente novamente." << endl;
											cin.clear();
											cin.ignore(256,'\n');  
											cin >> codigo;
										}
												
										cout << endl;
												
										if(venda.pesquisarLivroAutor(codigo))
										{
											cout << endl;
											cout << "Livro encontrado. Tem certeza que deseja registrar na nota?" << endl;
											cout << "1 - sim" << endl;
											cout << "2 - não" << endl << endl;
											cout << "Insira sua opcão: ";
											cin >> escolha;
											while(cin.fail())
											{
												cout << "Entrada inválida. Tente novamente." << endl;
												cin.clear();
												cin.ignore(256,'\n');  
												cin >> escolha;
											}

											if(escolha == 1)
											{
												laut = venda.getLivroAutor(venda.getIndiceLivroAutor(codigo));
												venda.inserirNotaLivroAutor(laut);
												venda.setSaidaEstoqueLivroAutor(codigo, 1);
												cout << endl;
												cout << "Livro Registrado com sucesso." << endl;
											}
											else if(escolha == 2)
											{
												cout << "Livro descartado." << endl;
											}
											else
											{
												cout << "Opção inválida. Tente novamente." << endl;
											}	
										}
										else
										{
											cout << "Livro não encontrado." << endl;
										}
										break;
									}
									case 3:
									{
										unsigned int codigo;

										cout << "Insira o código de barras do Livro: ";
										cin >> codigo;
										while(cin.fail())
										{
											cout << "Entrada inválida. Tente novamente." << endl;
											cin.clear();
											cin.ignore(256,'\n');  
											cin >> codigo;
										}
												
										cout << endl;
												
										if(venda.pesquisarLivro(codigo))
										{
											cout << endl;
											cout << "Livro encontrado. Tem certeza que deseja registrar na nota?" << endl;
											cout << "1 - sim" << endl;
											cout << "2 - não" << endl << endl;
											cout << "Insira sua opcão: ";
											cin >> escolha;
											while(cin.fail())
											{
												cout << "Entrada inválida. Tente novamente." << endl;
												cin.clear();
												cin.ignore(256,'\n');  
												cin >> escolha;
											}

											if(escolha == 1)
											{
												l = venda.getLivro(venda.getIndiceLivro(codigo));
												venda.inserirNotaLivro(l);
												venda.setSaidaEstoqueLivro(codigo, 1);
												cout << endl;
												cout << "Livro Registrado com sucesso." << endl;
											}
											else if(escolha == 2)
											{
												cout << "Livro descartado." << endl;
											}
											else
											{
												cout << "Opção inválida. Tente novamente." << endl;
											}	
										}
										else
										{
											cout << "Livro não encontrado." << endl;
										}
										break;
									}
									case 4:
									{
										cout << "As compras foram canceladas." << endl;
										venda.limpaCarrinho();
										break;
									}
								}
							break;
						}
						case 2:
						{
							cout << "\n=== Caixa da Livraria ===" << endl << endl;
							cout << "Saldo Diário: R$" << venda.getSaldo() << endl;
							cout << "Faturamento Diário: R$" << venda.getFaturamento() << endl;
							break;	
						}
						default:
							break;
					}
					break;		
				}
				case 8:
				{
					cout << "Despesas: R$ " << estoque.getDespesas() <<  endl;
					break;
				}			
			}
		}

return 0;
}
