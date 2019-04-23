#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota

// Tamanho padrao para array 
constexpr int ARR_SZ = 10;

using Compare = bool (*)( const int &, const int& );

// Funcao para comparacao
bool compare_ints( const int & a, const int & b )
{
	return ( a < b );
}

/// Ordena os elementos de um array
int *insertion_sort ( int * first, int * last, const int & e, Compare cmp )
{
	auto it(last);
	*it = e;

	while(it>first and cmp(*it, *(it-1)))
	{
		std::swap(*it, *(it-1));
		it--;
	}

	return ++last;
}

/// Imprime os elementos do intervalo [first, last) 
void print_array( const int * first, const int * last )
{
	std::cout << "Array: [ ";
	std::copy( first, last, std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << "]\n";
}

int main()
{
	// Entrada de dados 
	int source[ARR_SZ]; // = {{ 8, 2, 1, 10, 3, 5, 7, 6, 4, 9 } };
	std::iota( std::begin( source ), std::end( source ), 1 );

	// Preenchendo o array com valores aleatorios
#ifdef RANDOM
	std::random_device rd;
	std::mt19937 g(rd());
#else
	std::mt19937 g(100);
#endif
	std::shuffle( std::begin(source), std::end(source), g );

	// Declarando array de destino (array que vai receber os valores ordenados)
	int destination[ ARR_SZ ];
	std::fill( std::begin(destination), std::end(destination), 0 ); // Fill array with zeros.

	// Imprimindo array com os dados
	std::cout << "Dados: \n";
	print_array( std::begin(source), std::end(source) );

	// Imprimindo o array de destino
	std::cout << "Vetor de destino:\n";
	print_array( std::begin(destination), std::end(destination) );

	// Ordenacao dos dados
	std::cout << "Vetor de destino:\n";
	auto last = std::begin(destination);
	for ( const auto & e: source )
	{
		std::cout << "\n>>> Inserindo " << e << std::endl;
		last = insertion_sort( std::begin(destination), last, e, compare_ints );
		print_array( std::begin(destination), last );
	}

	return EXIT_SUCCESS;
}
