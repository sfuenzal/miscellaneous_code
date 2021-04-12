#include <iostream>
#include <math.h>
#include <vector> 
#include <stdlib.h>
#include <string>

using namespace std;

class InputMatrixVector
{
    public:
        InputMatrixVector () {};
        
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

        void ReadInputVector(double *B, unsigned int n)
        {
            cout << "Please enter the elements of the input b-vector: " << endl;
            for (unsigned int i = 0; i < n; ++i)
            {
                cout << "b" << "[" << i << "]" << " = " << endl;
                cin >> B[i];
            }
        }

        void ShowInputVector(double *B, unsigned int n)
        {
            for (unsigned int i = 0; i < n; ++i)
            {
                cout << "b" << "[" << i << "]" << " = " << B[i] << endl;
            }
        }

        virtual ~ InputMatrixVector () {};
};

class GaussSeidel: public InputMatrixVector
{
    public:
        GaussSeidel () {};

        void InitialGuess(double *phi, unsigned int n)
        {
            cout << "Please enter the elements of the input phi-vector (guess): " << endl;
            for (unsigned int i = 0; i < n; ++i)
            {
                cout << "phi" << "[" << i << "]" << " = " << endl;
                cin >> phi[i];
            }
        }
        
        void GaussSeidelIntegrator(double *phi, double *B, double **A, unsigned int n)
        {
            double phi_sol[n] = {};
            for (unsigned int i = 0; i < n; ++i)
            {
                double sigma = 0.0;
                for (unsigned int j = 0; i < n; ++j)
                {
                    if (i != j)
                    {
                        sigma = sigma + A[i][j]*phi[j];
                    }
                }
                
                phi_sol[i] = (1/A[i][i])*(B[i] - sigma);  
            }

            for (unsigned int i = 0; i < n; ++i)
            {
                cout << "phi (solution)" << "[" << i << "]" << " = " << phi_sol[i] << endl;
            }
        }

        ~ GaussSeidel () {};
};

int main()
{
    GaussSeidel *obj1 = new GaussSeidel();

    unsigned int order;
    cout << "Please enter the order of the input matrix (if you enter e.g. two, then the order is 2x2): " << endl;
    cin >> order;
    
    double **A = obj1 -> initializeMatrix(order);
    double B[order] = {};
    double phi[order] = {};

    obj1 -> ReadInputMatrix(A, order);
    obj1 -> ShowInputMatrix(A, order);
    obj1 -> ReadInputVector(B, order);
    obj1 -> ShowInputVector(B, order);
    obj1 -> InitialGuess(phi, order);
    obj1 -> GaussSeidelIntegrator(phi, B, A, order);
}
