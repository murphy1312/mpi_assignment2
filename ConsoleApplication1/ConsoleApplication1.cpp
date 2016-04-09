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
#include <random>


int world_rank;
int world_size;
int *totalArray;

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

// generate random numbers between fMin and fMax
double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}


/* master node method */
void coordinator(int array_size)
{
	srand(1);
	totalArray = new int[array_size];
	for (int i = 0; i < array_size; i++)
	{
		totalArray[i] = fRand(0, 50);
	}

	int size_for_each_node = array_size / world_size;

	int *partition = new int[size_for_each_node];

	// broadcast the partition size
	MPI_Bcast(&size_for_each_node, 1, MPI_INT, 0, MPI_COMM_WORLD);

	// scatter the partitions to each node
	MPI_Scatter(totalArray, size_for_each_node, MPI_INT, partition, size_for_each_node,
		MPI_INT, 0, MPI_COMM_WORLD);


	// MPI_Reduce()

}

/* slave node method */
void participant()
{
	int size = 0;
	// receive partition size
	MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
	int *partition = new int[size];

	// receive the partition of the total array this node works on
	MPI_Scatter(totalArray, size, MPI_INT, partition, size,
		MPI_INT, 0, MPI_COMM_WORLD);
	

}



int main(int argc, char** argv) 
{
	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int array_size = 0;
	// int *totalArray;


	/* get the number of iterations*/
	sscanf_s(argv[1], "%d", &array_size);
	// sscanf_s(argv[2], "%d", &totalArray);

	if(array_size == 0)
	{
		array_size = 120;
	}

	if (!(array_size % world_size == 0))
	{
		if (world_rank == 0)
		{
			std::cout << "Error: array size % world_size-1 != 0" << std::endl;
		}
		MPI_Finalize();
		return 0;
	}

	
	// master node 
	if (world_rank == 0)
	{
		coordinator(array_size);
	}
	// other nodes
	else
	{
		participant();
	}

	MPI_Finalize();
	return 0;
}

/*
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
std::cout << summe3 << std::endl;*/





