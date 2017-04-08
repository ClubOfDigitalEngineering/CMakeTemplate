// example from https://gist.github.com/erikzenker/c4dc42c8d5a8c1cd3e5a
#include <iostream>
#include <metis.h>
using namespace std;



int main(int argc, char** argv) {

	const idx_t nVertices = 6;
	const idx_t nEdges = 7;
	const idx_t nWeights = 1;
	idx_t nParts = 2;

	idx_t objval;
	idx_t part[nVertices];


	// Indexes of starting points in adjacent array
	idx_t xadj[nVertices + 1] = { 0,2,5,7,9,12,14 };

	// Adjacent vertices in consecutive index order
	idx_t adjncy[2 * nEdges] = { 1,3,0,4,2,1,5,0,4,3,1,5,4,2 };

	// Weights of vertices
	// if all weights are equal then can be set to NULL
	idx_t vwgt[nVertices * nWeights];


	// int ret = METIS_PartGraphRecursive(&nVertices,& nWeights, xadj, adjncy,
	// 				       NULL, NULL, NULL, &nParts, NULL,
	// 				       NULL, NULL, &objval, part);

	idx_t nV = nVertices;
	idx_t nW = nWeights;
	int ret = METIS_PartGraphKway(&nV, &nW, xadj, adjncy,
		NULL, NULL, NULL, &nParts, NULL,
		NULL, NULL, &objval, part);

	std::cout << ret << std::endl;

	for (unsigned part_i = 0; part_i < nVertices; part_i++) {
		std::cout << part_i << " " << part[part_i] << std::endl;
	}

    return 0;
}
