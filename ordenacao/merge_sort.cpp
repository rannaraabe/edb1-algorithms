#include <iostream>
#include <algorithm>	// std::copy

/*
 * merge() - Função que combina dois vetores ordenados, L e R, em um vetor A
 *           de maneira que A também fica ordenado após a combinação.
 * precondição: (1) L e R estão ordenados.
 *              (2) Tamanho de A é igual a soma dos tamanhos de L e R.
 * pos condição: O A deverá estar ordenado.
 * observação: O A pode ser *sobrescrito*, visto que os elementos foram salvos em L e R.
 */

void merge( int *firstL, int *lastL    // range L
	    int *firstR, int *lastR    // range R
	    int *firstA )	       // destino A
{	
	// enquanto houver elementos em L ou R faça
	while( (firstL != lastL) and (firstR != lastR) )
	{
		// se o primeiro elemento de L < primeiro elemento de R
		if( *firstL < *firstR )
		{
			*firstA = *firstL;	// atribua primeiro de L em A
			firstL++;		// consumir elemento de L (avanca o ponteiro de L)
		} else {

			*firstA = *firstR;	// atribua primeiro de R em A
			firstR++;		// consumir elemento de R (avanca o ponteiro de R)
		}

		firstA++;	// avanca a posicao ocupada (preenchida) em A
	}

	// se ainda houver elementos em L
	if( firstL != lastL )
	{
		// copiar elementos de L para A
		std::copy( firstL, lastL, firstA );
	} else {
		//copiar elementos de R para A
		std::copy( firstR, lastR, firstA );
	}
}

void merge_rec( int *firstA, int *lastA )
{
	// calcula o comprimento de A
	size_t sz_A = std::distance(firstA, lastA);
	if( sz_A >= 2 )
	{
		// cria dois subvetores L e R
		size_t sz_L = sz_A/2;
		size_t sz_R = sz_A - sz_L;

		int *L = new int[ sz_L ];
		int *R = new int[ sz_R ];
		
		// copia cada metade de A para L e R
		std::copy( firstA, firstA+sz_L, L );
		std::copy( firstA+sz_L, lastA, R );

		merge_rec( L, L+sz_L );	
		merge_rec( R, R+sz_L );

		merge( L, L+sz_L, R, R+z_R, firstA );
		
		delete [] L;
		delete [] R;
	}
}

void print( int *f, int *l )
{
	std::cout << "[";
	while(f != l)
		std::cout << *f++ << " ";
	std::cout << "]";
}

int main(void)
{
	int A[11];
	int L[]{ 1, 13, 17, -3, 4, 0, -15, 8, 14, 6 };
	int R[]{ 4, 6, 8, 12, 20 };

	size_t sz_A = 11;
	size_t sz_L = 6;
	size_t sz_R = 5;

	std::cout << "L: ";
	print( L, L+sz_L );
	std::cout << std::endl;

	std::cout << "R: ";
	print( R, R+sz_R );
	std::cout << std::endl;

	//merge( L, L+sz_L, R, R+sz_R, A );
	merge_rec( A, A+sz_A );

	std::cout << "A: ";
	print( A, A+sz_A );
	std::cout << std::endl;

	return 0;

}
