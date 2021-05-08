#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "/home/matheus/Livraria/Métodos/Livro.cpp"
#include "/home/matheus/Livraria/Métodos/LivroUnidade.cpp"


// Programa Principal
int main(){
	
	setlocale(LC_ALL, "Portuguese");
    
    Livro livro;
    LivroUnidade livrouni;

    string titulo, genero;
    unsigned int codigo;
    float preco;
    int quantidade;

	cout<<"Insira os dados da Empresa: " << endl;
	cout << "Título: "; 
    getline( cin, titulo);
	cout << "Gênero: ";
	getline( cin, genero);
	cout << "Código: ";
	cin >> codigo;
    cout << "Preço: ";
    cin >> preco;
    cout << "Quantidade: ";
    cin >> quantidade;

	livrouni.setTitulo(titulo);
    livrouni.setGenero(genero);
    livrouni.setCodigo(codigo);
    livrouni.setPreco(preco);
    livrouni.setQuantidade(quantidade);
	cout << "Livro:" << endl;
	livrouni.imprimeQuantidade();

	return 0;
}