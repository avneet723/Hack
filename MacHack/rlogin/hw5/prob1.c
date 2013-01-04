/** Avneet Singh Homework 5 - Problem 1 
 *
 * Code verification study using the steady-state manufactured solution given by
 * T(x) = 300 + 200sin(3pix/2L)K, where L= 1m 
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141593

float sum_array(float*, int);
void print_array(float*, int, char*);
float square_sum_array(float*, int);
float max_array(float*, int); 
int length_array(float*);


int main(void) {

	// Thermal diffusivity (m^2/s)
	float alpha = 9.71E-5;
	int nodes[6] = {5, 9, 17, 33, 65, 129};
	//int nodes[1] = {9};
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
	}
	//print_array(xsmooth, 200, "xsmooth");
	//print_array(Texact_smooth, 200, "Texact_smooth");

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
		float a = 0.44;
		float dx = ((float) (x[1] - x[0]))/((float) (imax - 1));
		float dt = ((float) a*dx*dx)/alpha; 
		// Initialize the x, T and T2 values
		for (int j = 1; j <= imax; j++) {
			x_loc[j - 1] = x[0] + ((float)(j - 1))/((float) (nodes[i] - 1))*(x[1] - x[0]);	
			T[j - 1] = 0;	
			T2[j - 1] = 0;
		}
		T[0] = T_init;
		T[imax - 1] = T_final;
		T2[0] = T_init;
		T2[imax - 1] = T_final;

		print_array(x_loc, imax, "x_loc");

		// Initial norm values
		float L1n = 0.5;
		float L2n = 1; 
		int counter = 0;
		float L1[100000000];
		float L2[100000000];
		float Linf[100000000];

		//while (fabsf(L2n - L1n)/L2n > 0.000001) {
		while (L2n > 10E-6) {
		//while ((L2n > 10E-4) && (fabsf(L2n - L1n)/L2n > 0.000001)) {

			for (int l = 1; l < imax - 1; l++) {
				T2[l] = dt*((alpha*((float) (T[l+1] - 2*T[l] + T[l - 1]))/(pow(dx,2))) + (alpha * ((float) (450 * pow(PI,2)/pow(L,2) * sin((3*PI*x_loc[l])/(2*L)))))) + T[l];
				R[l] = ((alpha*((float) (T[l+1] - 2*T[l] + T[l - 1]))/(pow(dx,2))) + (alpha * ((float) (450 * pow(PI,2)/pow(L,2) * sin((3*PI*x_loc[l])/(2*L))))));
			//	printf("Tm = %f, Res = %f\n", T2[l], T[l]);
			}
			for (int k = 0; k < imax; k++) {
				T[k] = T2[k];
			}
			L1[counter] = sum_array(R, imax)/imax;
			L2[counter] = pow(square_sum_array(R, imax)/imax, 0.5);
			Linf[counter] = max_array(R, imax);

			//L1n = L2n;
			L1n = L1[counter];
			L2n = L2[counter];
			//printf("L2n = %f\n", L2n);
		//	printf("abs(L2n-L1n)/L2n = %f\n", fabsf(L2n - L1n)/L2n);


			counter++;
		}

		print_array(T, imax, "Manufactured T");

		for (int k = 0; k < imax; k++) {
			Texact[k] = 300 + 200*sin(3*PI*x_loc[k]/(2*L));
		}	
		}
	}

	float sum_array(float a[], int num_elements) {
		int i; 
		float sum=0;
		for (i=0; i<num_elements; i++)
		{
			sum = sum + a[i];
		}
		return(sum);
	}

	void print_array(float a[], int num_elements, char* name) {
		int i;
		printf("%s\n", name);
		for(i=0; i<num_elements; i++)
		{
			printf("%f\n", a[i]);
		}
		printf("\n");
	}

	float square_sum_array(float a[], int num_elements) {
		int i; 
		float sum = 0.0;
		for (i=0; i<num_elements; i++)
		{
			sum = sum + pow(a[i],2);
		}
		return(sum);
	}

	int length_array(float a[]) {
		printf("Size of a: %d\n", sizeof(a));
		return sizeof(a)/sizeof(float);
	}

	float max_array(float a[], int num_elements){
		int i; 
		float max=-32000;
		for (i=0; i<num_elements; i++)
		{
			if (a[i]>max)
			{
				max=a[i];
			}
		}
		return(max);
	}

