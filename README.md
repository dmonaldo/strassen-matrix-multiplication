# strassen-matrix-multiplication

Strassen's matrix multiplication algorithm is an important technique for performant multiplication of large matrices. This repository implements Strassen's algorithm for square matrices (n x n) where n is a power of 2.

## Installation

Compile with Visual Studio Code by running the `build` task.

Or complie via the command line:
```bash
g++ main.cpp -o strassen.cpp
```

## Usage

Create a file named `input.txt` that follows the structure below. The first line is n size of the matrices.

![](/sample-input.png)

Run the program:
```bash
./strassen.cpp
```

When prompted, type the name of your input file. The program will get the two square matrices from your input file and print the multiplication result to the console. The values of S1 to S10 are also printed to the console when the algorithm observes an n = 2 matrix.

The results will be written to a file named `output.txt`.

## Strassen's algorithm

![](/strassen-steps.png)

Time complexity of simple matrix multiplication: O(n^3)

Time complexity of Strassen's algorithm: O(n^2.808)

### Constraints
Assume that n could be between 1 and 256 (including 1 and 256) and is a power of 2. Size of input matrices are n x n.

## Roadmap
- Implement simple matrix multiplication algorithm for when n < k to improve performance for small matrices
- Add support for n != power of 2 matrices by padding matrices with zeros
- Allow for n > 256 cases

## License
[ISC](https://choosealicense.com/licenses/isc/)
