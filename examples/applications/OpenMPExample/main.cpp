//Example from http://bisqwit.iki.fi/story/howto/openmp/

#include <iostream>
#include <omp.h>
using namespace std;



int main(int argc, char** argv) {

	omp_set_num_threads(4);
	printf("Number of procs: %d\n", omp_get_num_procs());

#pragma omp parallel for
	for (int i = 0; i < 10; i++) {
		printf("We are in thread  number %d and are printing %d\n",
			omp_get_thread_num(), i);
	}
    return 0;
}
