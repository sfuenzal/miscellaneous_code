#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TH1F.h"   
#include "TLegend.h"
#include "TFile.h"  
#include "TArrow.h"
#include "TLatex.h"
#include "TMath.h"
#include "TMultiGraph.h"

#include <iostream>
#include <math.h>
#include <vector> 

using namespace std;

class Calculator
{
    protected:
        string operation_name;
        Double_t numbers;
        vector<Double_t> vector_with_numbers;
    public:
        void first_question()
        {
            cout << "Please type the operation that you want to do (sum or multiplication): " << endl;
            cin >> operation_name;
        }
};

class Sum: public Calculator
{
    public:
        void sum_calculator()
        {   
            if (operation_name == "sum")
            {
                cout << "Please enter the numbers that you want to sum: " << endl;
                
                do
                {
                    cin >> numbers;
                    vector_with_numbers.push_back(numbers);
                } while (numbers != 0);

                Double_t counter = 0;
                
                for (UInt_t i = 0; i < vector_with_numbers.size(); ++i)
                {
                    counter += vector_with_numbers[i];
                }

                cout << "Number sum: " << counter << endl;
            }
        }
};

class Multiplication: public Calculator
{
    public:
        void multiplication_calculator()
        {
            if (operation_name == "multiplication")
            {
                cout << "Please enter the numbers that you want to multiply: " << endl;

                do
                {
                    cin >> numbers;
                    vector_with_numbers.push_back(numbers);
                } while (numbers != 1);

                Double_t counter = 1;

                for (UInt_t i = 0; i < vector_with_numbers.size(); ++i)
                {
                    counter *= vector_with_numbers[i];
                }

                cout << "Number multiplication: " << counter << endl;
            }
            
        }
};

void BasicCalculator()
{
    int operation_query;
    cout << "Please enter an integer to select an operation to do: " << endl;
    cin >> operation_query;
    
    Sum object_sum;
    Multiplication object_multiplication;

    if (operation_query == 1)
    {
        object_sum.first_question();
        object_sum.sum_calculator();
    }

    else if (operation_query == 2)
    {
        object_multiplication.first_question();
        object_multiplication.multiplication_calculator();
    }
}
