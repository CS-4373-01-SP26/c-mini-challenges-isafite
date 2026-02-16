/* 4. Compare the speed of *,/,sqrt, sin operations/functions. */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main() {
	double num_trials = 1e8;
	clock_t start, end;
	double input1;
	double input2;
	double output;
	double time_to_run;
	double unary_loop_time;
	double binary_loop_time;
	long i;

	// Baseline 1: time for setting up unary operation for loop
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
	}
	end = clock();
	unary_loop_time = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Time per trial to set up unary operation for loop: %.6f ns\n", unary_loop_time/num_trials);

	// Baseline 2: time for setting up binary operation for loop
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
		input2 = lrand48();
	}
	end = clock();
	binary_loop_time = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Time per trial to set up binary operation for loop: %.6f ns\n\n", binary_loop_time/num_trials);

	// Time * operation
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
		input2 = lrand48();
		output = input1 * input2;
	}
	end = clock();
	time_to_run = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Net time per * operation: %.6f ns\n", (time_to_run-binary_loop_time)/num_trials);
	printf("Net time: %.3f ns\n\n", (time_to_run-binary_loop_time));

	// Time / operation
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
		input2 = lrand48();
		output = input1 / input2;
	}
	end = clock();
	time_to_run = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Net time per / operation: %.6f ns\n", (time_to_run-binary_loop_time)/num_trials);
	printf("Net time: %.3f ns\n\n", (time_to_run-binary_loop_time));

	// Time sin() operation
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
		output = sin(input1);	
	}
	end = clock();
	time_to_run = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Net time per sin() operation: %.6f ns\n", (time_to_run-unary_loop_time)/num_trials);
	printf("Net time: %.3f ns\n\n", (time_to_run-unary_loop_time));

	// Time sqrt() operation
	start = clock();
	for (i = 0; i < num_trials; i++) {
		input1 = lrand48();
		output = sqrt(input1);	
	}
	end = clock();
	time_to_run = 1e6*(double)(end - start)/CLOCKS_PER_SEC;	
	printf("Net time per sqrt() operation: %.6f ns\n", (time_to_run-unary_loop_time)/num_trials);
	printf("Net time: %.3f ns\n\n", (time_to_run-unary_loop_time));

	return 0;
}