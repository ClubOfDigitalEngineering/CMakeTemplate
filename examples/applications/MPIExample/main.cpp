#include <iostream>
#include <mpi.h>

using namespace std;



int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank, numProc;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);

	printf("MyRank: %d, Number of processes: %d\n", rank, numProc);


	MPI_Finalize();
    return 0;
}
