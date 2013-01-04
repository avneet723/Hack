#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	MPI_Comm comm3d, commcorners;
	int myid, nprocs, n1=3, n2=3, n3=3;
	int myid_new, nprocs_new, nbr_up;
	int size[3], periodic[3];
	int coords[3];
	int color, key;
	MPI_Init(&argc, &argv);

	MPI_Comm_rank (MPI_COMM_WORLD, &myid);
	MPI_Comm_size (MPI_COMM_WORLD, &nprocs);
	size[0] = n1; size[1] = n2; size[2] = n3;
	periodic[0] = periodic[1] = periodic[2] = 0;
	MPI_Cart_create (MPI_COMM_WORLD, 3, size, periodic, 1, &comm3d);

	MPI_Comm_rank (comm3d, &myid_new);
	MPI_Comm_size (comm3d, &nprocs_new);

	MPI_Cart_coords(comm3d, myid_new, 3,
			coords);

	if (coords[0] == 0 && coords[1] == 0 && coords[2] == 0) {
		color = 0;
	}
	else if (coords[0] == 0 && coords[1] == 0 && coords[2] == n3-1) {
		color = 0;
	}
	else if (coords[0] == 0 && coords[1] == n2-1 && coords[2] == 0) {
		color = 0;
	}
	else if (coords[0] == 0 && coords[1] == n2-1 && coords[2] == n3-1) {
		color = 0;
	}
	else if (coords[0] == n1-1 && coords[1] == 0 && coords[2] == 0) {
		color = 0;
	}
	else if (coords[0] == n1-1 && coords[1] == 0 && coords[2] == n3-1) {
		color = 0;
	}
	else if (coords[0] == n1-1 && coords[1] == n2-1 && coords[2] == 0) {
		color = 0;
	}
	else if (coords[0] == n1-1 && coords[1] == n2-1 && coords[2] == n3-1) {
		color = 0;
	}
	else {
		color = 1;
	}

	key = 0;

	MPI_Comm_split(comm3d, color, key, &commcorners);
	
	printf("%d: (%d,%d,%d) has a color %d\n", myid_new, coords[0], coords[1], coords[2], color);
	MPI_Finalize();
}
