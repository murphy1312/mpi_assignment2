// ConsoleApplication1.cpp
// use monte carlo to calculate pi
/** simple program to test the MPI stuff to see if it works **/
/** includes **/
#include "stdafx.h"
#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>


int world_rank;

// print an array
template<typename Type>
void printArray(Type *array, int size)
{
	for (int i = 0; i<size; i++)
	{
		std::cout << array[i] << "\t";
		
	}
	std::cout << std::endl;
}

// sum an array and return the sum
template<typename Type>
Type sum(Type *array, int size)
{
	Type sum;
	for (int i = 0; i<size; i++)
	{
		if(i == 0)
		{
			sum = array[i];
		}
		else
		{
			sum = sum + array[i];
		}
	}
	return sum;
}

// sumDifferences
/* takes in a reference to an array, an array size, and
the overall mean of the dataset. It should produce a sum of the square of differences
between each value in the dataset and the mean and return this as the result */

template<typename Type>
Type sumDifferences(Type *array, int size, Type overall_mean)
{
	Type sumDifference;
	for (int i = 0; i<size; i++)
	{
		Type differenceSquare = (array[i] - overall_mean) ^ 2;
		if (i == 0)
		{
			sumDifference = differenceSquare;
		}
		else
		{
			sumDifference = sumDifference + differenceSquare;
		}
	}
	return sumDifference;
}



/* master node method */
void coordinator()
{
	int arr[] = {0,4,5,6};
	std::string arr2[] = { "hi", "sup" };

	double arr3[] = { 1.3, 4.5, 6.9, 19.12 };

	printArray(arr, 4);
	printArray(arr2, 2);
	printArray(arr3, 4);

	int summe = 0;
	summe = sum(arr, 4);

	std::string summe2 = "";
	summe2 = sum(arr2, 2);

	double summe3 = 0.0;
	summe3 = sum(arr3, 4);


	std::cout << summe << std::endl;
	std::cout << summe2 << std::endl;
	std::cout << summe3 << std::endl;





}

/* slave node method */
void participant()
{

}



int main(int argc, char** argv) 
{
	MPI_Init(NULL, NULL);
	int iterations = 0;
	int world_size;


	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	
	// master node 
	if(world_rank == 0) 
	{
		coordinator();
	}
	// other nodes
	else
	{
		participant();
	}

	MPI_Finalize();
	return 0;
}





