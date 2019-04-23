#include <iostream>
#include <iterator>
#include <chrono>
#include <fstream>
#include "buscas.h"
#include "utils.h"

int main()
{
	unsigned long vector_size = 100000000;
	value_type *vet = new value_type [vector_size];

	std::cout << "Alocou " << std::endl;

	// Preenchendo o vetor 
	preencherVetor(vet, vector_size);

	// Streams de cada busca
	std::ofstream resultsb, resultsi, resultst, resultfib, resultjump, resultsrb, resultsrt;

	// Inicializando o valor a ser buscado no vetor
	value_type value = 0;

	//=========================== Binary Search ====================================	

	resultsrb.open("./res/recursive_binary_search.txt");
	resultsb.open("./res/binary_search.txt");

	resultsb << "vector_size  time_to_find" << std::endl;
	resultsrb << "vector_size  time_to_find" << std::endl;
	
	for(value_type i=1000000; i<=vector_size; i+=1000000)
	{
		value = vector_size+1;
		auto start = std::chrono::system_clock::now();

		for (int j =0 ; j<100; j++)
			binarySearch(vet,&vet[i], value);

		auto end = std::chrono::system_clock::now();       
		auto timeUsed = end-start;
	
		resultsb << i << "  " << timeUsed.count()/100 << std::endl;
		start = std::chrono::system_clock::now();
	
		for (int j =0 ; j<100; j++)
			rbinarySearch(vet,&vet[i], value);
	
		end = std::chrono::system_clock::now();
		timeUsed = end - start;

		resultsrb << i << "  " << timeUsed.count()/100 << std::endl;
	}

	resultsb.close();
	resultsrb.close();
	std::cout << ">>> Binary Search OK" << std::endl;

	//=========================== Ternary Search =================================

	resultst.open("./res/ternary_search.txt");
	resultst << "vector_size  time_to_find" << std::endl;

	resultsrt.open("./res/recursive_ternary_search.txt");

	for(value_type i=1000000; i<=vector_size; i+=1000000)
	{
		value = vector_size+1;
		auto start = std::chrono::system_clock::now();

		for (int j =0 ; j<100;j++)
			ternarySearch(vet,&vet[i], value);

		auto end = std::chrono::system_clock::now();
		auto timeUsed = end-start;

		resultst << i << "  " << timeUsed.count()/100 << std::endl;

		start = std::chrono::system_clock::now();

		for (int j =0 ; j<100; j++)
			rternarySearch(vet,&vet[i], value);

		end = std::chrono::system_clock::now();
		timeUsed = end - start;
		resultsrt << i << "  " << timeUsed.count()/100 << std::endl;
	}

	resultsrt.close();
	resultst.close();
	std::cout << ">>> Ternary Search OK" << std::endl;

	//======================== Fibonacci Search =================================

	resultfib.open("./res/fibonacci_search.txt");
	resultfib << "array_size time_to_find" << std::endl;

	for(value_type i=1000000; i<=vector_size; i+=1000000)
	{
		value = -1;
		auto start = std::chrono::system_clock::now();

		for (int j =0 ; j<100; j++)
			fibonacciSearch(vet,&vet[i], value);

		auto end = std::chrono::system_clock::now();
		auto timeUsed = end-start;

		resultfib << i << "  " << timeUsed.count()/100 << std::endl;
	}

	resultfib.close();
	std::cout << ">>> Fibonnaci Search OK" << std::endl;

	//=========================== Jump Search =================================

	resultjump.open("./res/jump_search.txt");
	resultjump << "array_size time_to_find" << std::endl;

	for(value_type i=1000000; i<=vector_size; i+=1000000)
	{
		value = vector_size+1;

		auto start = std::chrono::system_clock::now();
		for (int j =0 ; j<100;j++)
			jumpSearch(vet, &vet[i], value);
		auto end = std::chrono::system_clock::now();
		auto timeUsed = end-start;
		resultjump << i << "  " << timeUsed.count()/100 << std::endl;
	}	

	resultjump.close();
	std::cout << ">>> Jump Search OK" << std::endl;

	// Apagando o vetorzão
	delete vet;
}
