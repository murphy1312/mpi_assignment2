// ConsoleApplication1.cpp
// use monte carlo to calculate pi
/** simple program to test the MPI stuff to see if it works **/
/** includes **/
#include "stdafx.h"
#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <cmath>


int world_rank;

/* master node method */
void coordinator()
{
		
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





