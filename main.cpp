#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "/home/matheus/Livraria/Métodos/Livro.cpp"
#include "/home/matheus/Livraria/Métodos/LivroUnidade.cpp"
#include "/home/matheus/Livraria/Métodos/LivroGenero.cpp"

// Programa Principal
int main(){
	
	setlocale(LC_ALL, "Portuguese");
    
    Livro livro;
    LivroUnidade livrouni;
    LivroGenero livrogen;

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
    

	livrogen.setTitulo(titulo);
    livrogen.setGenero(genero);
    livrogen.setCodigo(codigo);
    livrogen.setPreco(preco);
   
	cout << "Livro:" << endl;
	livrogen.imprimeGenero();

	return 0;
}