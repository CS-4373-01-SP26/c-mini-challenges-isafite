Isabelle Fite
February 8, 2025
CS-4373 High Performance Computing

# C-mini-challenges

1. $a.$ For the Hello, NAME challenge, I used an argument from the command line because I wanted to learn how to work with command line arguments in C. b. Memory for the string is dynamically allocated since the length of the name isn't known at compile time. 

2. a. I timed my program with clock() from time.h. b. I didn't notice any issues with convergence, but looking at the output of clock, I'm at the limit of clock's precision. So for this short of a runtime, I will only be able to get one significant figure this way. 

3. a. I read in the file line by line, allocating static memory for 32 chars for each line. After determining the size of the matrix from the first line, I allocated memory statically for the exact size int matrix needed. When loading and accesing my matrix, I iterated through the elements in each row before moving to the next row. b. The only challenge in reading in the file was to learn how to handle and parse files in C. c. I didn't notice anything special about the actual computation. d. I used clock() for timing, like mini challenge 2. 

4. **a.** Since clock() does not have the necessary precision, I set up a for loop for each operation to time a large number of calculations, and then averaged the results. I used lrand48() to generate random numbers for the operations to act on. To account for the effects of loop overhead and random number generation, I calculated baseline times of running the loop and generating the random numbers without performing any operation, and then subtracted those from the results. b. Double multiplication ended up around 3 times faster than double division, although int multiplication was around the same speed as int division. The difference makes sense, as int division truncates its result. Sqrt() surprisingly was the fastest, at around 60% the time of multiplication, while sin() was the slowest at 200 times the time of multiplication.

5. 