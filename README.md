Implement Strassen’s algorithm in C++ or Python. Your code should get two square matrices (of any size) from a file and prints the multiplication result. The file format is as follows:

![](/sample-input.png)

![](/strassen-steps.png)

Assume that n could be between 1 and 256 (including 1 and 256) and is a power of 2. In addition to creating the output file, your code should also print the values of S1 to S10 on the monitor when the size of the input matrix is n = 2. Note that since the algorithm is recursive, even with larger matrices, when the algorithm observes n = 2 should print the values of S’s on the monitor.