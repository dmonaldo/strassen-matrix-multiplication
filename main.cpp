#include <iostream>
#include <fstream>
#include <typeinfo> 
using namespace std;

const string INPUT_FILE_NAME = "input.txt";

//
void strassenR(int *&matrixA, int *&matrixB, int *&matrixC) {
    int arraySize = sizeof(matrixA) / sizeof(matrixA[0]);

    if (arraySize == 2) {
        cout << "yee";
    } else {
        int S[10];

        S[0] = matrixB[1] - matrixB[3];
        S[1] = matrixA[0] + matrixA[1];
        S[2] = matrixA[2] + matrixA[3];
        S[3] = matrixB[2] - matrixB[0];
        S[4] = matrixA[0] + matrixA[3];
        S[5] = matrixB[0] + matrixB[3];
        S[6] = matrixA[1] - matrixA[3];
        S[7] = matrixB[2] + matrixB[3];
        S[8] = matrixA[0] - matrixA[2];
        S[9] = matrixB[0] + matrixB[1];

        int P[7];
        // P[0] = (matrixA[0] * matrixB[1]) - (matrixA[0] * matrixB[3]);
        // P[1] = (matrixA[0] * matrixB[3]) + (matrixA[1] * matrixB[3]);
        // P[2] = (matrixA[2] * matrixB[0]) + (matrixA[3] * matrixB[0]);
        // P[3] = (matrixA[3] * matrixB[2]) - (matrixA[3] * matrixB[0]);
        // P[4] = (matrixA[0] * matrixB[0]) + (matrixA[0] * matrixB[3]) + (matrixA[3] * matrixB[0]) + (matrixA[3] * matrixB[3]);
        // P[5] = (matrixA[1] * matrixB[2]) + (matrixA[1] * matrixB[3]) - (matrixA[3] * matrixB[2]) - (matrixA[3] * matrixB[3]);
        // P[6] = (matrixA[0] * matrixB[0]) + (matrixA[0] * matrixB[1]) - (matrixA[2] * matrixB[0]) - (matrixA[2] * matrixB[1]);

        P[0] = matrixA[0] * S[0];
        P[1] = S[1] * matrixB[3];
        P[2] = S[2] * matrixB[0];
        P[3] = matrixA[3] * S[3];
        P[4] = S[4] * S[5];
        P[5] = S[6] * S[7];
        P[6] = S[8] * S[9];


        matrixC[0] = P[4] + P[3] - P[1] + P[5];
        matrixC[1] = P[0] + P[1];
        matrixC[2] = P[2] + P[3];
        matrixC[3] =  P[4] + P[0] - P[2] - P[6];

        for (int i = 0; i < 7; i++) {
            cout << P[i] << endl;
        }
        cout << endl;
        for (int i = 0; i < 4; i++) {
            cout << matrixC[i] << endl;
        }
    }
    
}

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
    int *matrixA = new int[4];
    int *matrixB = new int[matrixSize*matrixSize];
    int *matrixC = new int[matrixSize*matrixSize]; //output

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

    strassenR(matrixA, matrixB, matrixC);
// cout << matrixA[0];
    return 0;
}