/** Avneet Singh Homework 5 - Problem 1 
 *
 * Code verification study using the steady-state manufactured solution given by
 * T(x) = 300 + 200sin(3pix/2L)K, where L= 1m 
 */
#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main(void) {

	// Thermal diffusivity (m^2/s)
	float alpha = 9.71E-5;
	// Evenly spaced grids of following nodes 
	int nodes[6] = {5, 9, 17, 33, 65, 129};
	int length = sizeof(nodes)/sizeof(int);
	int L = 1;
	int x[2] = {0, 1};

	// Boundary Conditions x = 0 and x = 1
	float T_init = 300 + 200 * sin(3*PI*x[0]/(2*L));
	float T_final = 300 + 200 * sin (3*PI*x[1]/(2*L));


	// Generating smooth exact solution
	float Texact_smooth[200];
	float xsmooth[200];
	float dxsmooth = ((float) (x[1] - x[0]))/((float) (200-1));
	for (int iter = 0; iter < 200; iter++) {
		xsmooth[iter] = x[0] + ((float)(iter))/((float)(200 - 1))*L;
		Texact_smooth[iter] = 300 + (float) (200*sin(3*PI*xsmooth[iter]/(2*L)));
		//printf("%f\n", Texact_smooth[iter]);
		printf("%f\n", xsmooth[iter]);
	}

	// Run it for each of the 6 different number of nodes to obtain manufactured values
	for (int i = 0; i < length; i++) {
		int imax = nodes[i];

		printf("\n*********************\n");
		printf("Number of nodes: %i\n", imax);
		printf("*********************\n");

		float x_loc[imax];
		float T[imax];
		float T2[imax];
		float R[imax]; //Iterative Residual
		float Texact[imax];
		float dx = ((float) (x[1] - x[0]))/((float) (imax - 1));
		float dt = ((float) 1/2*dx*dx)/alpha; 
		float L1 = 0.5;
		float L2 = 1; 

		// Initialize the x, T and T2 values
		for (int j = 1; j <= imax; j++) {
			x_loc[j - 1] = x[0] + ((float)(j - 1))/((float) (nodes[i] - 1))*(x[1] - x[0]);	
			printf("%f\n", x_loc[j-1]);
			T[j - 1] = 0;	
			T2[j - 1] = 0;
		}
		T[0] = T_init;
		T[imax - 1] = T_final;
		T2[0] = T_init;
		T2[imax - 1] = T_final;

		for (int n = 1; n < pow(imax, 2); n++) {	
			for (int l = 1; l < imax - 1; l++) {
				T2[l] = dt*((alpha*((float) (T[l+1] - 2*T[l] + T[l - 1]))/(pow(dx,2))) + (alpha * ((float) (450 * pow(PI,2)/pow(L,2) * sin((3*PI*x_loc[l])/(2*L)))))) + T[l];
				R[l] = ((alpha*((float) (T[l+1] - 2*T[l] + T[l - 1]))/(pow(dx,2))) + (alpha * ((float) (450 * pow(PI,2)/pow(L,2) * sin((3*PI*x_loc[l])/(2*L))))));
			}
			for (int k = 0; k < imax; k++) {
				T[k] = T2[k];
			}	
		}

		for (int k = 0; k < imax; k++) {
			Texact[k] = 300 + 200*sin(3*PI*x_loc[k]/(2*L));
			//printf("%f\n", k, T[k]);
			//printf("T[%i %f\n", k, T[k]);
		}	
		printf("\n");
	}
}

