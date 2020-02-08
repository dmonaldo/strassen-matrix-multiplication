#include <iostream>
#include <fstream>
using namespace std;

const string INPUT_FILE_NAME = "input.txt";

int main() {
    int matrixSize;
    ifstream inputFile;
    inputFile.open(INPUT_FILE_NAME);

    // get the size of the matrix from first line of input file
    if (inputFile.is_open()) {
        string firstLine;
        getline(inputFile, firstLine);
        matrixSize = stoi(firstLine);
    }

    // initialize matrices
    int matrixA[matrixSize*matrixSize];
    int matrixB[matrixSize*matrixSize];

    // populate matrices with values from input file
    if (inputFile.is_open()) {
        int lineCounter = 0;
        int i = 0;
        while (!inputFile.eof()) {
            if (lineCounter < matrixSize * matrixSize) {
                inputFile >> matrixA[i];
                i++;
            } else if (lineCounter == matrixSize * matrixSize) {
                i = 0;
            } else {
                inputFile >> matrixB[i];
                i++;
            }
            lineCounter++;
        }
    }

    inputFile.close();

    return 0;
}
