#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota

// Default array size.
constexpr int ARR_SZ = 10;

// Useful alias
using Compare = bool (*)( const int &, const int& );

// The comparison function (strict total order)
bool compare_ints( const int & a, const int & b )
{
	return ( a < b );
}

/// Selection sort function
	int *
selection_sort ( int * first, int * last, Compare cmp )
{
	while(first != last-1)
	{
		auto menor = first;
		auto it{first};

		while(it != last)
		{
			if(cmp(*it, *menor))
				menor = it;

			it++;	
		}
	}

	return nullptr;
}


/// Prints the elemets of the specified range on the standard output stream.
void print_array( const int * first, const int * last )
{
	std::cout << "    Array: [ ";
	std::copy( first, last, std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << "]\n";
}

int main()
{
	// ================================================================================
	// I. PREPARATION
	// --------------------------------------------------------------------------------

	// Source data array.
	int source[ARR_SZ]; // = {{ 8, 2, 1, 10, 3, 5, 7, 6, 4, 9 } };
	std::iota( std::begin( source ), std::end( source ), 1 );
#ifdef RANDOM
	std::random_device rd;
	std::mt19937 g(rd());
#else
	std::mt19937 g(100);
#endif
	std::shuffle( std::begin(source), std::end(source), g );

	// This is the destination (sorted) array that will receive the input data.
	int destination[ ARR_SZ ];
	std::fill( std::begin(destination), std::end(destination), 0 ); // Fill array with zeros.

	std::cout << ">>> Data source\n";
	print_array( std::begin(source), std::end(source) );


	std::cout << ">>> Destination vetor\n";
	print_array( std::begin(destination), std::end(destination) );
	
	std::cout << "\n>>> SELECTION SORT <<<";
	auto last = std::begin(destination);// The last is equal to first, empty array.
	last = selection_sort( std::begin(destination), last, compare_ints );
	print_array( std::begin(destination), last );

	std::cout << "\n>>> Normal ending...\n\n";

	return EXIT_SUCCESS;
}
