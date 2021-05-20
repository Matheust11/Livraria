void controle_estoque(void)
{
	Estoque estoque;
	Produto produto;
	ProdutoPerecivel perecivel;
	Remedio remedio;
	Produto_prototipo auxiliar_produto;
	Data vencimento;
	Drogaria informacoes_remedio;
	
	int escolha(1);
	
	while(escolha)
	{
		cout << "=== Controle de Estoque ===" << endl << endl;
		
		cout << "1 - Inserir um novo produto ao estoque;" << endl;
		cout << "2 - Gerir quantidades de produto em estoque;" << endl;
		cout << "3 - Visualizar estoque;" << endl;
		cout << "4 - Remover produtos por código de barra;" << endl;
		cout << "5 - Fazer a gestão da validade dos produtos;" << endl;
		cout << "6 - Pesquisar sobre o produto;" << endl;
		cout << "7 - Ordenação de Estoque;" << endl;
		cout << "8 - Visualizar as depezas atuais;" << endl;
		cout << "9 - Salvar alterações feitas;" << endl;
		cout << "0 - Voltar para o menu principal;" << endl << endl;
		cout << "Digite sua opção: ";
		
		cin >> escolha;
		while(cin.fail())
		{
      	  cout << "Entrada inválida. Tente novamente." << endl;
      	  cin.clear();
      	  cin.ignore(256,'\n');  
      	  cin >> escolha;
		}
		
		cout << endl;
		system("pause");
		system("cls");
		
		switch(escolha)
		{
		case 0:
		{
			cout << "Voltando para o menu principal." << endl;
			break;
		}
		case 1:
		{
			cout << "Escolha o tipo de produto a ser cadastrado: " << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o preço de aquisição do produto: ";
				cin >> auxiliar_produto.preco_loja;
				while(cin.fail())
				{
		      	  cout << "Entrada inválida. Tente novamente." << endl;
		      	  cin.clear();
		      	  cin.ignore(256,'\n');  
		      	  cin >> auxiliar_produto.preco_loja;
				}
				cout << "Informe o preço de venda do produto: ";;
				cin >> auxiliar_produto.preco_consumidor;
				while(cin.fail())
				{
		      	  cout << "Entrada inválida. Tente novamente." << endl;
		      	  cin.clear();
		      	  cin.ignore(256,'\n');  
		      	  cin >> auxiliar_produto.preco_consumidor;
				}
				cin.ignore();
				cout << "Informe o nome do produto: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a categoria do produto: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do produto: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do produto: ";
				cin >> auxiliar_produto.quantidade;
				while(cin.fail())
				{
		      	  cout << "Entrada inválida. Tente novamente." << endl;
		      	  cin.clear();
		      	  cin.ignore(256,'\n');  
		      	  cin >> auxiliar_produto.quantidade;
				}
				cout << "Informe o código de barras do produto: ";
				cin >> auxiliar_produto.codigo;
				while(cin.fail())
				{
		      	  cout << "Entrada inválida. Tente novamente." << endl;
		      	  cin.clear();
		      	  cin.ignore(256,'\n');  
		      	  cin >> auxiliar_produto.codigo;
				}
				
				Produto aux_pro;
				
				aux_pro.set_objeto_produto(auxiliar_produto);
				
				cout << endl;
				if(estoque.pesquisarProduto(aux_pro.get_objeto_produto().codigo) || (!aux_pro.valida_objeto_produto(auxiliar_produto)))
				{
					cout << endl;
					cout << "Produto indevido de cadastro. Tente novamente." << endl;
				}
				else
				{
					estoque.inserirProduto(aux_pro);
					cout << "Produto Cadastrado com sucesso." << endl;	
				}
				break;
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			}
			break;
		}
		case 2:
		{	
			int quantidade;
			long int codigo;
				
			cout << "Escolha o tipo de procedimento a ser realizado: " << endl << endl;
			cout << "1 - Adicionar Produtos;" << endl;
			cout << "2 - Remover Produtos;" << endl << endl;
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
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{	
				cout << "=== Escolha o departamento a ter itens adicionados === :" << endl << endl;
				cout << "1 - Departamento de produtos não perecíveis;" << endl;
				cout << "2 - Departamento de produtos perecíveis;" << endl;
				cout << "3 - Departamento de remédios;" << endl << endl;
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
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "Informe o código de barras do produto a ser aumentado no estoque: ";
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
					if(estoque.set_entrada_estoque_produto(codigo, quantidade))
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
					cout << "Informe o código de barras do produto perecível a ser aumentado no estoque: ";
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
					if(estoque.set_entrada_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perecíveis adicionados com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser aumentado no estoque: ";
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
					if(estoque.set_entrada_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Remédios adicionados com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				default:
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Escolha o departamento a ter itens adicionados: " << endl << endl;
				cout << "1 - Departamento de produtos não perecíveis;" << endl;
				cout << "2 - Departamento de produtos perecíveis;" << endl;
				cout << "3 - Departamento de remédios;" << endl << endl;
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
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
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
					if(estoque.set_saida_estoque_produto(codigo, quantidade))
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
					if(estoque.set_saida_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perecíveis removidos com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser aumentado no diminuido: ";
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
					if(estoque.set_saida_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Remédios removidos com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				default:
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			
			break;
		}
		case 3:
		{
			cout << "=== Escolha o departamento de estoque === :" << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			cout << "2 - Departamento de produtos perecíveis;" << endl;
			cout << "3 - Departamento de remédios;" << endl << endl;
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
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				estoque.imprimirProduto();
				break;
			}
			case 2:
			{
				estoque.imprimirProdutoPerecivel();
				break;
			}
            case 3:
			{
				estoque.imprimirRemedio();
            	break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			
			break;
		}
		case 4:
		{
			long int codigo;
			
			cout << "=== Escolha o departamento a ter o produto subtraido === :" << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			cout << "2 - Departamento de produtos perecíveis;" << endl;
			cout << "3 - Departamento de remédios;" << endl << endl;
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
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o código de barras do produto a ser removido: ";
				cin >> codigo;
				while(cin.fail())
				{
	 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
	 	  	  	  cin.clear();
	 	  	  	  cin.ignore(256,'\n');  
	 	  	  	  cin >> codigo;
				}
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProduto(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
				if(estoque.removerProduto(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o código de barras do produto perecível a ser removido: ";
				cin >> codigo;
				while(cin.fail())
				{
	 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
	 	  	  	  cin.clear();
	 	  	  	  cin.ignore(256,'\n');  
	 	  	  	  cin >> codigo;
				}
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProdutoPerecivel(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
				if(estoque.removerProdutoPerecivel(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Informe o código de barras do remédio a ser removido: ";
				cin >> codigo;
				while(cin.fail())
				{
	 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
	 	  	  	  cin.clear();
	 	  	  	  cin.ignore(256,'\n');  
	 	  	  	  cin >> codigo;
				}
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarRemedio(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
				if(estoque.removerRemedio(codigo))
				{
					cout << "Remédio removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			break;
		}
		case 5:
		{
			int limite;
			
			cout << "=== Escolha o departamento para analisar validade dos produtos === :" << endl << endl;
			cout << "1 - Departamento de produtos perecíveis;" << endl;
			cout << "2 - Departamento de remédios;" << endl << endl;
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
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o limite de validade em dias a ser pesquisado: ";
				cin >> limite;
				while(cin.fail())
				{
	  	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
	 	 	 	  cin.clear();
	  	  	  	  cin.ignore(256,'\n');  
	  	  	  	  cin >> limite;
				}
				if(estoque.pesquisaPerecivelVencido(limite))
				{
					int aux;
					
					cout << endl;
					system("pause");
					system("cls");
					
					cout << "Deseja Remover os produtos perecíveis já vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - não;" << endl;
					cout << "Digite sua opção: ";
					cin >> aux;
					while(cin.fail())
					{
		  	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
		 	 	 	  cin.clear();
		  	  	  	  cin.ignore(256,'\n');  
		  	  	  	  cin >> aux;
					}
					
					if(aux == 1)
					{
						estoque.removerProdutosPereciveisVencidos();
					} 
					else if(aux == 2)
					{
						cout << "Produtos vencidos mantidos." << endl;
					}
					else
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
					}
				}
				else
				{
					cout << "Todos os produtos estão com a validade em dia." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o limite de validade em dias a ser pesquisado: ";
				cin >> limite;
				while(cin.fail())
				{
 	  	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
 	  	  	  	  cin.clear();
 	  	  	  	  cin.ignore(256,'\n');  
 	  	  	  	  cin >> limite;
				}
					
				if(estoque.pesquisaRemedioVencido(limite))
				{
					int aux;
					
					cout << "Deseja Remover os remédios já vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - não" << endl;
					cout << "Digite sua opção: ";
					cin >> aux;
					while(cin.fail())
					{
		  	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
		 	 	 	  cin.clear();
		  	  	  	  cin.ignore(256,'\n');  
		  	  	  	  cin >> aux;
					}
					
					if(aux == 1)
					{
						estoque.removerRemediosVencidos();
					} 
					else if(aux == 2)
					{
						cout << "Remédios vencidos mantidos." << endl;	
					}
					else
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
					}
				}
				else
				{
					cout << "Todos os Remédios estão com a validade em dia." << endl;
				}
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			break;
		}
		case 6:
		{
			cout << "=== Escolha o tipo de pesquisa a ser realizada === :" << endl << endl;
			cout << "1 - Pesquisa por código de barras;" << endl;
			cout << "2 - Pesquisa por nome do produto;" << endl;
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
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				long int codigo;
			
				cout << "=== Escolha o departamento a ter o produto pesquisado === :" << endl << endl;
				cout << "1 - Departamento de produtos não perecíveis;" << endl;
				cout << "2 - Departamento de produtos perecíveis;" << endl;
				cout << "3 - Departamento de remédios;" << endl << endl;
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
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "Informe o código de barras do produto a ser pesquisado: ";
					cin >> codigo;
					while(cin.fail())
					{
		 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
		 	  	  	  cin.clear();
		 	  	  	  cin.ignore(256,'\n');  
		 	  	  	  cin >> codigo;
					}
					
					if(estoque.pesquisarProduto(codigo))
					{
						cout << endl;
						cout << "Produtos acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos com esse código no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o código de barras do produto perecível a ser pesquisado: ";
					cin >> codigo;
					while(cin.fail())
					{
		 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
		 	  	  	  cin.clear();
		 	  	  	  cin.ignore(256,'\n');  
		 	  	  	  cin >> codigo;
					}
					
					if(estoque.pesquisarProdutoPerecivel(codigo))
					{
						cout << endl;
						cout << "Produtos perecíveis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos perecíveis com esse código no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser pesquisado: ";
					cin >> codigo;
					while(cin.fail())
					{
		 	  	  	  cout << "Entrada inválida. Tente novamente." << endl;
		 	  	  	  cin.clear();
		 	  	  	  cin.ignore(256,'\n');  
		 	  	  	  cin >> codigo;
					}
					
					if(estoque.pesquisarRemedio(codigo))
					{
						cout << endl;
						cout << "Remédios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de remédios com esse código no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				}
				break;
			}
			case 2:
			{
				string nome;
			
				cout << "=== Escolha o departamento a ter o produto pesquisado === :" << endl << endl;
				cout << "1 - Departamento de produtos não perecíveis;" << endl;
				cout << "2 - Departamento de produtos perecíveis;" << endl;
				cout << "3 - Departamento de remédios;" << endl << endl;
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
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "Informe o nome do produto a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarProduto(nome))
					{
						cout << endl;
						cout << "Produtos acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos com esse código no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o nome do produto perecível a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarProdutoPerecivel(nome))
					{
						cout << endl;
						cout << "Produtos perecíveis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos perecíveis com esse código no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o nome do remédio a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarRemedio(nome))
					{
						cout << endl;
						cout << "Remédios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de remédios com esse código no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				}
				break;
			}
			default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
			}
			break;
		}
		case 7:
		{
				cout << "=== Escolha o departamento para ter seus dados ordenados === :" << endl << endl;
				cout << "1 - Departamento de produtos não perecíveis;" << endl;
				cout << "2 - Departamento de produtos perecíveis;" << endl;
				cout << "3 - Departamento de remédios;" << endl << endl;
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
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
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
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaProdutoPrecoVenda();
						estoque.imprimirProduto();
						break;
					}
					case 2:
					{
						estoque.ordenaProdutoNome();
						estoque.imprimirProduto();
						break;
					}
					case 3:
					{
						estoque.ordenaProdutoFabricante();
						estoque.imprimirProduto();
						break;
					}
					case 4:
					{
						estoque.ordenaProdutoEstoque();
						estoque.imprimirProduto();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
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
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaPerecivelPrecoVenda();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 2:
					{
						estoque.ordenaPerecivelNome();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 3:
					{
						estoque.ordenaPerecivelFabricante();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 4:
					{
						estoque.ordenaPerecivelEstoque();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl;
					cout << "5 - Ordenar por tarja;" << endl << endl;
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
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaRemedioPrecoVenda();
						estoque.imprimirRemedio();
						break;
					}
					case 2:
					{
						estoque.ordenaRemedioNome();
						estoque.imprimirRemedio();
						break;
					}
					case 3:
					{
						estoque.ordenaRemedioFabricante();
						estoque.imprimirRemedio();
						break;
					}
					case 4:
					{
						estoque.ordenaRemedioEstoque();
						estoque.imprimirRemedio();
						break;
					}
					case 5:
					{
						estoque.ordenaRemedioTarja();
						estoque.imprimirRemedio();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
				default:
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				break;
		}
		case 8:
		{
			cout << "Despezas atuais: " << estoque.get_despezas() << " R$" <<  endl;
			break;
		}
		case 9:
		{
			cout << "Todas as alterações foram salvas." << endl;
			estoque.salvarProduto();
			estoque.salvarProdutoPerecivel();
			estoque.salvarRemedio();
			break;
		}
		default:
			cout << "Opção Inválida. Tente novamente." << endl;
		}
		
		if(escolha)
		{
			cout << endl;
			system("pause");
			system("cls");
		}
		
	}
	
	return;
}
