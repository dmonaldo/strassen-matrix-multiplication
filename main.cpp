#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

const string OUTPUT_FILE_NAME = "output.txt";

// add two matrices
void add(vector< vector<int> > &matrixA, 
         vector< vector<int> > &matrixB, 
         vector< vector<int> > &matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// subtract two matrices
void sub(vector< vector<int> > &matrixA, 
        vector< vector<int> > &matrixB, 
        vector< vector<int> > &matrixC, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }   
}

// write matrix to output file
void writeToFile(vector< vector<int> > &matrixC, unsigned int mSize) {
    ofstream outputFile;
    outputFile.open(OUTPUT_FILE_NAME);
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            outputFile << matrixC[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();
}

// print a matrix to the console
void printMatrix(vector< vector<int> > &matrix, unsigned int mSize) {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// recursive strassen matrix multiplier
void strassenR(vector< vector<int> > &matrixA,
            vector< vector<int> > &matrixB,
            vector< vector<int> > &matrixC,
            int mSize) {

    // recursive base case
    if (mSize == 1) {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return;
    }
    else {
        int newMSize = mSize / 2;
        vector<int> innerVector(newMSize, 0);

        vector< vector<int> > submatrixA11(newMSize, innerVector);
        vector< vector<int> > submatrixA12(newMSize, innerVector);
        vector< vector<int> > submatrixA21(newMSize, innerVector);
        vector< vector<int> > submatrixA22(newMSize, innerVector);

        vector< vector<int> > submatrixB11(newMSize, innerVector);
        vector< vector<int> > submatrixB12(newMSize, innerVector);
        vector< vector<int> > submatrixB21(newMSize, innerVector);
        vector< vector<int> > submatrixB22(newMSize, innerVector);

        vector< vector<int> > submatrixC11(newMSize, innerVector);
        vector< vector<int> > submatrixC12(newMSize, innerVector);
        vector< vector<int> > submatrixC21(newMSize, innerVector);
        vector< vector<int> > submatrixC22(newMSize, innerVector);

        vector< vector<int> > s1(newMSize, innerVector);
        vector< vector<int> > s2(newMSize, innerVector);
        vector< vector<int> > s3(newMSize, innerVector);
        vector< vector<int> > s4(newMSize, innerVector);
        vector< vector<int> > s5(newMSize, innerVector);
        vector< vector<int> > s6(newMSize, innerVector);
        vector< vector<int> > s7(newMSize, innerVector);
        vector< vector<int> > s8(newMSize, innerVector);
        vector< vector<int> > s9(newMSize, innerVector);
        vector< vector<int> > s10(newMSize, innerVector);

        vector< vector<int> > p1(newMSize, innerVector);
        vector< vector<int> > p2(newMSize, innerVector);
        vector< vector<int> > p3(newMSize, innerVector);
        vector< vector<int> > p4(newMSize, innerVector);
        vector< vector<int> > p5(newMSize, innerVector);
        vector< vector<int> > p6(newMSize, innerVector);
        vector< vector<int> > p7(newMSize, innerVector);

        vector< vector<int> > matrixAResult(newMSize, innerVector);
        vector< vector<int> > matrixBResult(newMSize, innerVector);

        // divide matrices
        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                submatrixA11[i][j] = matrixA[i][j];
                submatrixA12[i][j] = matrixA[i][j + newMSize];
                submatrixA21[i][j] = matrixA[i + newMSize][j];
                submatrixA22[i][j] = matrixA[i + newMSize][j + newMSize];

                submatrixB11[i][j] = matrixB[i][j];
                submatrixB12[i][j] = matrixB[i][j + newMSize];
                submatrixB21[i][j] = matrixB[i + newMSize][j];
                submatrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
            }
        }

        // Calculating p1 to p7:
        add(submatrixA11, submatrixA22, s5, newMSize); // a11 + a22 = s5
        add(submatrixB11, submatrixB22, s6, newMSize); // b11 + b22 = s6
        strassenR(s5, s6, p1, newMSize); // p1 = (a11+a22) * (b11+b22)

        add(submatrixA21, submatrixA22, s3, newMSize); // a21 + a22 = s3
        strassenR(s3, submatrixB11, p2, newMSize); // p2 = (a21+a22) * (b11)

        sub(submatrixB12, submatrixB22, s1, newMSize); // b12 - b22 = s1
        strassenR(submatrixA11, s1, p3, newMSize); // p3 = (a11) * (b12 - b22)

        sub(submatrixB21, submatrixB11, s4, newMSize); // b21 - b11 = s4
        strassenR(submatrixA22, s4, p4, newMSize); // p4 = (a22) * (b21 - b11)

        add(submatrixA11, submatrixA12, s2, newMSize); // a11 + a12 = s2
        strassenR(s2, submatrixB22, p5, newMSize); // p5 = (a11+a12) * (b22)

        sub(submatrixA21, submatrixA11, s9, newMSize); // a21 - a11 = s9 IS THIS CORRECT???
        add(submatrixB11, submatrixB12, s10, newMSize); // b11 + b12 = s10
        strassenR(s9, s10, p6, newMSize); // p6 = (a21-a11) * (b11+b12)

        sub(submatrixA12, submatrixA22, s7, newMSize); // a12 - a22 = s7
        add(submatrixB21, submatrixB22, s8, newMSize); // b21 + b22 = s8
        strassenR(s7, s8, p7, newMSize); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:
        add(p3, p5, submatrixC12, newMSize); // c12 = p3 + p5
        add(p2, p4, submatrixC21, newMSize); // c21 = p2 + p4

        add(p1, p4, matrixAResult, newMSize); // p1 + p4
        add(matrixAResult, p7, matrixBResult, newMSize); // p1 + p4 + p7
        sub(matrixBResult, p5, submatrixC11, newMSize); // c11 = p1 + p4 - p5 + p7

        add(p1, p3, matrixAResult, newMSize); // p1 + p3
        add(matrixAResult, p6, matrixBResult, newMSize); // p1 + p3 + p6
        sub(matrixBResult, p2, submatrixC22, newMSize); // c22 = p1 + p3 - p2 + p6

        // group into matrixC
        for (int i = 0; i < newMSize ; i++) {
            for (int j = 0 ; j < newMSize ; j++) {
                matrixC[i][j] = submatrixC11[i][j];
                matrixC[i][j + newMSize] = submatrixC12[i][j];
                matrixC[i + newMSize][j] = submatrixC21[i][j];
                matrixC[i + newMSize][j + newMSize] = submatrixC22[i][j];
            }
        }
    }
}

// call recursive function
void strassen(vector< vector<int> > &matrixA, 
              vector< vector<int> > &matrixB, 
              vector< vector<int> > &matrixC, unsigned int mSize) {
    strassenR(matrixA, matrixB, matrixC, mSize);
}

int main() {
    unsigned int matrixSize;
    ifstream inputFile;
    string inputFileName;

    // get the file name from user
    cout << "Input file name: ";
    cin >> inputFileName;
    inputFile.open(inputFileName);

    // get the size of the matrix from first line of input file
    if (inputFile.is_open()) {
        string firstLine;
        getline(inputFile, firstLine);
        matrixSize = stoi(firstLine);
    }

    // validate matrix size constraints
    if (matrixSize < 1 || matrixSize > 256) {
        cout << endl << "ERROR: n must be between 1 and 256 (including 1 and 256)" << endl;
        return 0;
    } else if (ceil(log2(matrixSize)) != floor(log2(matrixSize))) {
        cout << endl << "ERROR: n must be a power of 2" << endl;
        return 0;
    }

    // initialize matrices
    vector< vector<int> > matrixA;
    vector< vector<int> > matrixB;
    vector< vector<int> > matrixC(matrixSize, vector<int> (matrixSize, 0));
    vector<int> rowVector(matrixSize);

    // populate matrices with values from input file
    if (inputFile.is_open()) {
        int lineCounter = 0;
        int row = 0;
        while (!inputFile.eof()) {
            if (lineCounter < matrixSize) {
                matrixA.push_back(rowVector); // add a new row,
                for (int col = 0; col < matrixSize; col++) {
                    inputFile >> matrixA[row][col];
                }
                row++; // Keep track of actual row 
            } else if (lineCounter == matrixSize) {
                row = 0;
            } else {
                matrixB.push_back(rowVector); // add a new row,
                for (int col = 0; col < matrixSize; col++) {
                    inputFile >> matrixB[row][col];
                }
                row++; // Keep track of actual row 
            }
            lineCounter++;
        }
    }
    inputFile.close();

    strassen(matrixA, matrixB, matrixC, matrixSize);

    cout << endl << "MATRIX A" << endl;
    printMatrix(matrixA, matrixSize);

    cout << endl << "MATRIX B" << endl;
    printMatrix(matrixB, matrixSize);

    cout << endl << "MATRIX C" << endl;
    printMatrix(matrixC, matrixSize);

    writeToFile(matrixC, matrixSize);

    return 0;
}