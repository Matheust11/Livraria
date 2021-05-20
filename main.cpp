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
#include "/home/matheus/Livraria/Métodos/LivroUnidade.cpp"
#include "/home/matheus/Livraria/Métodos/Estoque.cpp"
#include "/home/matheus/Livraria/Métodos/Vendas.cpp"

int Menu(){

    int op = 0;

    do{
        cout << "\n\t\tCONTROLE DE ESTOQUE LIVRARIA"
             <<"\nEscolha uma opção: "
             <<"\n1 - Inserir um novo Livro ao estoque"
             <<"\n2 - Gerir quantidades de Livros em estoque"
             <<"\n3 - Imprime lista de Livros"
             <<"\n4 - Remover Livro da lista pelo código"
             <<"\n5 - Pesquisar Livro"
             <<"\n6 - Ordenar Estoque"
             <<"\n7 - Controle de Vendas"
             <<"\n8 - Salvar alterações"
             <<"\n0 - Sair"
             <<"\nOpção: ";
         cin >> op;

    }while(op < 0 || op > 8);
      
    return op;
}


// Programa Principal
int main(){
	
	setlocale(LC_ALL, "Portuguese");

   	Livro l;
	Estoque estoque;
	Vendas venda;

	int menu_op = 1;

	/* int escolha(1);
	
	while(escolha)
	{
        cout << "=== Controle de Estoque ===" << endl << endl;
		
		cout << "1 - Inserir um novo Livro ao estoque" << endl;
		cout << "2 - Gerir quantidades de Livros em estoque" << endl;
		cout << "3 - Imprime lista de Livros " << endl;
		cout << "4 - Remover Livro da lista pelo código " << endl;
		cout << "5 - Pesquisar Livro" << endl;
		cout << "6 - Ordenar Estoque " << endl;
		cout << "7 - Controle de Vendas " << endl;
		cout << "8 - Salvar alterações" << endl;

		cout << "0 - Encerrar programa!" << endl << endl;
		

        cout << "Opção: ";
		cin >> escolha;
	}	
	*/	

	

	while(menu_op != 0){
		menu_op = Menu();
		switch(menu_op){
			case 0:
			{
				cout << "Voltando para o menu principal." << endl;
				break;
			}
			case 1:
            {
				string titulo; 
    			unsigned int codigo;
    			float precofabrica, precoconsumidor;
				int quantidade;
				
				cout << "Informe o preço que o Livro foi adquirido na fabrica: ";
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
				if(estoque.inserirLivro(l))
					cout << "Livro cadastrado com sucesso!" << endl;
				else
					cout << "O cadastro não pode ser realizado!" << endl;
				
				break;	
			}
			case 2:
			{
				int quantidade;
				unsigned int codigo;
				int escolha;	
					
				cout << "Escolha o tipo de procedimento a ser realizado: " << endl << endl;
				cout << "1 - Adicionar Livros;" << endl;
				cout << "2 - Remover Livros;" << endl << endl;
				cout << "Opção: ";
				cin >> escolha;

				switch(escolha)
				{
					case 1:
					{
						cout << "Informe o código de barras do produto a ser aumentado no estoque: ";
						cin >> codigo;
						
						cout << "Informe a quantidade de aumento:";
						cin >> quantidade;
						
						
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
					case 2:
					{
						cout << "Informe o código de barras do produto perecível a ser diminuido no estoque: ";
						cin >> codigo;
						while(cin.fail())
						{
						cout << "Entrada inválida. Tente novamente." << endl;
						cin.clear();
						cin.ignore(256,'\n');  
						cin >> codigo;
						}
						cout << "Informe a quantidade de diminuição: ";
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
							cout << "Operação não realizada. Tente Novamete." << endl;
						}
						break;
					}
				}
			}
			case 3:
			{
				estoque.imprimeLivro();
				break;
			}
			case 4:
			{
				unsigned int codigo; 

				cout << "Informe o código de barras do Livro a ser removido: ";
				cin >> codigo;
				
				
				cout << "Produtos Encontrados: " << endl << endl;
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
			case 5:
			{
				unsigned int codigo;
				int escolha;
				cout << "=== Escolha o tipo de pesquisa a ser realizada === :" << endl << endl;
				cout << "1 - Pesquisa Livro por código de barras;" << endl;
				cout << "2 - Pesquisa Livro por nome do produto;" << endl;
				cout << "Opção: ";
				cin >> escolha;
				switch(escolha)
				{
					case 1:
					{
						cout << "Informe o código de barras do Livro a ser pesquisado: ";
						cin >> codigo;
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
					case 2:
					{
						string titulo;

						cout << "Informe o Título do Livro a ser pesquisado: ";
						cin.ignore();
						getline(cin, titulo);
						if(estoque.pesquisarLivro(titulo))
						{
							cout << endl;
							cout << "Livros acima pertencem ao estoque." << endl;
						}
						else
						{
							cout << endl;
							cout << "Sem ocorrências de Livros com esse Título no estoque." << endl;
						}
						break;
					}
					
					default:
					{
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
			}
			case 6:
			{
					int escolha;
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por Titulo do Livro;" << endl;
					cout << "Opção: ";
					cin >> escolha;
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaLivrosNome();
						estoque.imprimeLivro();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
			}
			case 7:
			{
					int op;

					
					cout << "=== Controle de Vendas da Livraria ===" << endl << endl;
		
					cout << "1 - Registrar Compras;" << endl;
					cout << "2 - Gerir quantidades de produto em estoque;" << endl;
					//cout << "3 - Visualizar Resumo Financeiro da Livraria;" << endl; 
					cout << "0 - Imprimir nota fiscal"<< endl;
					cout << "Insira uma opção: ";
					cin >> op;
					
					while(cin.fail()){
						cout << "Entrada inválida. Tente novamente." << endl;
						cin.clear();
						cin.ignore(256,'\n');  
						cin >> op;
					}
					switch(op){
						case 0:
						{
							cout << "Nota Fiscal montada com sucesso!" << endl;
							venda.Notafiscal();
							break;
						}
						case 1:
						{	
								Livro registroLivro;
								Vendas venda;

								unsigned int codigo;
								int escolha;

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
										registroLivro = venda.getLivro(venda.getIndiceLivro(codigo));
										venda.inserirNotaLivro(registroLivro);
										estoque.setSaidaEstoqueLivro(codigo, 1);
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
							int quantidade;
							long int codigo;
							int escolha;

							cout << "Escolha o tipo de procedimento a ser realizado: " << endl << endl;
							cout << "1 - Adicionar Produtos;" << endl;
							cout << "2 - Remover Produtos;" << endl << endl;
							cout << "Opção: ";
							cin >> escolha;

							switch(escolha)
							{
								case 1:
								{
									cout << "Informe o código de barras do Livro a ser aumentado no estoque: ";
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
										cout << "Produtos adicionados com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamete." << endl;
									}
									break;
								}
								case 2:
								{
									cout << "Informe o código de barras do produto a ser diminuido no estoque: ";
									cin >> codigo;
									while(cin.fail())
									{
									cout << "Entrada inválida. Tente novamente." << endl;
									cin.clear();
									cin.ignore(256,'\n');  
									cin >> codigo;
									}
									cout << "Informe a quantidade de diminuição: ";
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
										cout << "Produtos removidos com sucesso." << endl;
									}
									else
									{
										cout << "Operação não realizada. Tente Novamete." << endl;
									}
									break;
								}
							}
						}
					}
			}
						
			case 8:
			{
			cout << "Todas as alterações foram salvas." << endl;
			estoque.salvarLivro();
			break;
			}
		}
	}
return 0;
}