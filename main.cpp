#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
using namespace std;

const string INPUT_FILE_NAME = "input4.txt";


void strassenR(vector< vector<int> > &matrixA,
            vector< vector<int> > &matrixB,
            vector< vector<int> > &matrixC,
            int mSize) {

    if (mSize > 2) {
        int newMSize = mSize / 2;
        cout << "newMSize " << newMSize << endl;

        vector<vector<int> > submatrixA11( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixA12( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixA21( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixA22( newMSize , vector<int> (newMSize, 0));

        vector<vector<int> > submatrixB11( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixB12( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixB21( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixB22( newMSize , vector<int> (newMSize, 0));

        vector<vector<int> > submatrixC11( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixC12( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixC21( newMSize , vector<int> (newMSize, 0));
        vector<vector<int> > submatrixC22( newMSize , vector<int> (newMSize, 0));

        // vector< vector<int> > 
        //     submatrixA11(newMSize, 0), submatrixA12(newMSize, 0), submatrixA21(newMSize, 0), submatrixA22(newMSize, 0),
        //     submatrixB11(newMSize, 0), submatrixB12(newMSize, 0), submatrixB21(newMSize, 0), submatrixB22(newMSize, 0),
        //       submatrixC11(newMSize, 0), submatrixC12(newMSize, 0), submatrixC21(newMSize, 0), submatrixC22(newMSize, 0),
        //     p1(newMSize, 0), p2(newMSize, 0), p3(newMSize, 0), p4(newMSize, 0), 
        //     p5(newMSize, 0), p6(newMSize, 0), p7(newMSize, 0),
        //     aResult(newMSize, 0), bResult(newMSize, 0);

        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                submatrixA11[i][j] = matrixA[i][j];
                submatrixA12[i][j] = matrixA[i][j + newMSize];
                submatrixA21[i][j] = matrixA[i + newMSize][j];
                submatrixA22[i][j] = matrixA[i + newMSize][j + newMSize];

                // cout << endl << "submatrixA" << endl;
                // cout << submatrixA11[i][j] << endl;
                // cout << submatrixA12[i][j] << endl;
                // cout << submatrixA21[i][j] << endl;
                // cout << submatrixA22[i][j] << endl;

                submatrixB11[i][j] = matrixB[i][j];
                submatrixB12[i][j] = matrixB[i][j + newMSize];
                submatrixB21[i][j] = matrixB[i + newMSize][j];
                submatrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
            }
        }

        cout << endl << "submatrixA11" << endl;
        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                cout << submatrixA11[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "submatrixB11" << endl;
        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                cout << submatrixB11[i][j] << " ";
            }
            cout << endl;
        }

        strassenR(submatrixA11, submatrixB11, submatrixC11, newMSize);
        strassenR(submatrixA12, submatrixB12, submatrixC12, newMSize);
        strassenR(submatrixA21, submatrixB21, submatrixC21, newMSize);
        strassenR(submatrixA22, submatrixB22, submatrixC22, newMSize);

        cout << endl << "submatrixC11" << endl;
        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                cout << submatrixC11[i][j] << " ";
            }
            cout << endl;
        }
        // Grouping the results obtained in a single matrix:
        for (int i = 0; i < newMSize ; i++) {
            for (int j = 0 ; j < newMSize ; j++) {
                matrixC[i][j] = submatrixC11[i][j];
                matrixC[i][j + newMSize] = submatrixC12[i][j];
                matrixC[i + newMSize][j] = submatrixC21[i][j];
                matrixC[i + newMSize][j + newMSize] = submatrixC22[i][j];
            }
        }

    } else {
        int S[10];
        S[0] = matrixB[0][1] - matrixB[1][1];
        S[1] = matrixA[0][0] + matrixA[0][1];
        S[2] = matrixA[1][0] + matrixA[1][1];
        S[3] = matrixB[1][0] - matrixB[0][0];
        S[4] = matrixA[0][0] + matrixA[1][1];
        S[5] = matrixB[0][0] + matrixB[1][1];
        S[6] = matrixA[0][1] - matrixA[1][1];
        S[7] = matrixB[1][0] + matrixB[1][1];
        S[8] = matrixA[0][0] - matrixA[1][0];
        S[9] = matrixB[0][0] + matrixB[0][1];

        int P[7];
        P[0] = matrixA[0][0] * S[0];
        P[1] = S[1] * matrixB[1][1];
        P[2] = S[2] * matrixB[0][0];
        P[3] = matrixA[1][1] * S[3];
        P[4] = S[4] * S[5];
        P[5] = S[6] * S[7];
        P[6] = S[8] * S[9];

        matrixC[0][0] = P[4] + P[3] - P[1] + P[5];
        matrixC[0][1] = P[0] + P[1];
        matrixC[1][0] = P[2] + P[3];
        matrixC[1][1] = P[4] + P[0] - P[2] - P[6];
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
    vector< vector<int> > matrixA;
    vector< vector<int> > matrixB;
    vector< vector<int> > matrixC( matrixSize , vector<int> (matrixSize, 0));
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

    strassenR(matrixA, matrixB, matrixC, matrixSize);

    cout << endl << "MATRIX A" << endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "MATRIX B" << endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "MATRIX C" << endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    inputFile.close();

    return 0;
}