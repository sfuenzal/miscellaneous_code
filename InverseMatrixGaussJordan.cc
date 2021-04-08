#include <iostream>
#include <math.h>
#include <vector> 
#include <stdlib.h>
#include <string>

using namespace std;

class InputMatrix
{
    public:
        InputMatrix () {};
     
        double **initializeMatrix(unsigned int n) 
        {
            double **temp = new double*[n];
            
            for(unsigned int i = 0; i < n; ++i)
            {
                temp[i] = new double[n];
            }
            
            return temp;
        }
        
        void ReadInputMatrix(double **A, unsigned int n)
        { 
            cout << "Please enter the elements of the input matrix: " << endl;

            for (unsigned int i = 0; i < n; ++i)
            {
                for (unsigned int j = 0; j < n; ++j)
                {
                    cout << "A" << "[" << i << "," << j << "]" << " = " << endl;
                    cin >> A[i][j];
                }
            }
        }

        void ShowInputMatrix(double **A, unsigned int n)
        {
            for (unsigned int i = 0; i < n; ++i)
            {
                for (unsigned int j = 0; j < n; ++j)
                {
                   cout << "A" << "[" << i << "," << j << "]" << " = " << A[i][j] << endl;
                }
            }
        }

        virtual ~ InputMatrix () {};
};

class InverseMatrix: public InputMatrix
{
    public:
        InverseMatrix () {};
    
        void AugmentIdentityMatrix(double **A, unsigned int n)
        {
            for (unsigned int i = 0; i < n; ++i)
            {
                for (unsigned int j = 0; j < n; ++j)
                {
                    if (i == j)
                    {
                        A[i][j+n] = 1;
                    }

                    else
                    {
                        A[i][j+n] = 0;
                    }
                }
            }
        }

        void GaussJordanEliminationAugmentedMatrix(double **A, unsigned int n)
        {
            for (unsigned int i = 0; i < n; ++i)
            {
                if (A[i][i] == 0)
                {
                    cout << "Mathematical Error! " << endl;
                }

                for (unsigned int j = 0; j < n; ++j)
                {
                    if (i != j)
                    {
                        double ratio = A[j][i]/A[i][i];

                        for (unsigned int k = 0; k < 2*n; ++k)
                        {
                            A[j][k] = A[j][k] - ratio * A[i][k];
                        }
                    }
                }
            }
        }

        void RowOperationDiagonalEqualsOne(double **A, unsigned int n)
        {
            for (unsigned i = 0; i < n; ++i)
            {
                for (unsigned j = n; j < 2*n; ++j)
                {
                    A[i][j] = A[i][j]/A[i][i];
                }
            }
        }

        void DisplayInverseMatrix(double **A, unsigned int n)
        {
            for (unsigned int i = 0; i < n; ++i)
            {
                for (unsigned int j = n; j < 2*n; ++j)
                {
                    cout << "A^{-1}" << "[" << i  << "," << j - 2 << "]" << " = " << A[i][j] << endl;
                }
            }
        }

    ~ InverseMatrix () {};
};

int main()
{
    InverseMatrix *obj1 = new InverseMatrix();
    
    unsigned int order;
    cout << "Please enter the order of the input matrix (if you enter e.g. two, then the order is 2x2): " << endl;
    cin >> order;
    
    double **A = obj1 -> initializeMatrix(order);

    obj1 -> ReadInputMatrix(A, order);
    obj1 -> ShowInputMatrix(A, order);
    obj1 -> AugmentIdentityMatrix(A, order);
    obj1 -> GaussJordanEliminationAugmentedMatrix(A, order);
    obj1 -> RowOperationDiagonalEqualsOne(A, order);
    cout << "" << endl;
    obj1 -> DisplayInverseMatrix(A, order);
}