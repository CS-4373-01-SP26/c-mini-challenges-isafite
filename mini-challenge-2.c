/* 2. Implement Archimedes algorithm to estimate pi for inscribed/circumscribed polygons with n sides, 
up to 100, doubling n at each step, and time it. */

#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
	int n;
	float outer_perim;
	float inner_perim;
	float outer_perim_new;
	float inner_perim_new;
	clock_t start, end;
	double time_to_run;

	start = clock();

	// Base case: a triangle
	// Assume a radius of 1 for the circle
	n = 3;
	inner_perim = 3*sqrt(3);
	outer_perim = 6*sqrt(3);

	// Calculate the perimeter of the circle, 2*pi*radius = 2*pi
	while(n <= 100) {
		outer_perim_new = 2 * outer_perim * inner_perim/ (outer_perim + inner_perim);
		inner_perim_new = sqrt(outer_perim_new * inner_perim);

		outer_perim = outer_perim_new;
		inner_perim = inner_perim_new;
		n *= 2;
	};

	end = clock();
	time_to_run = 1000*(double)(end - start)/CLOCKS_PER_SEC; // In milleseconds
	printf("Using %d-sided polygons, the value of pi is between %f and %f. The calculation took %.3f ms.", n/2, inner_perim/2, outer_perim/2, time_to_run);
 	
	return 0;
}
