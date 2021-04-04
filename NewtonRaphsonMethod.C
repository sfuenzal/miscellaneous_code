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
#include <stdlib.h>
#include <string>

using namespace std;

class Function
{
    private:
        Double_t f;
    public:
        Function () {};
        
        Double_t FunctionDefinition(Double_t x)
        {
            f = pow(x, 2) - 1;
            return f;
        }

        virtual ~Function() {};
};

class FunctionDerivative: public Function
{
    private:
        Double_t h, fprima;
    public:
        FunctionDerivative () {};

        Double_t DefinitionFunctionDerivative(Double_t x)
        {
            h = pow(10, -6);
            fprima = (FunctionDefinition(x + h) - FunctionDefinition(x))/h;
            return fprima;
        }

         ~FunctionDerivative () {};
};

class NewtonRaphson: public FunctionDerivative
{
    private:
        Double_t xnext, xnplus1;
        string aux = "No solution";
    public:
        NewtonRaphson() {};

        Double_t NewtonRaphsonKernel(Double_t x)
        {
            if (DefinitionFunctionDerivative(x) == 0)
            {
                return stod(aux); //convert string to double
            }

            else
            {
                xnext = x - FunctionDefinition(x)/DefinitionFunctionDerivative(x);
                return xnext;
            }
        }

        void NewtonRaphsonIterator(Double_t x, UInt_t n)
        {
            xnplus1 = NewtonRaphsonKernel(x);
            
            cout << "x(" << 1 << ") = " << xnplus1 << endl;

            for (UInt_t i = 0; i < n; ++i)
            {
                xnplus1 = NewtonRaphsonKernel(xnplus1);
                cout << "x(" << i + 2 << ") = " << xnplus1 << endl;
            }
        }

        ~NewtonRaphson() {};
};

void NewtonRaphsonMethod()
{
    Function *obj1 = new Function();
    FunctionDerivative *obj2 = new FunctionDerivative();
    NewtonRaphson *obj3 = new NewtonRaphson();
    
    Double_t x0;
    Int_t iterations;

    cout << "Please enter the initial guess for the solution: " << endl;
    cin >> x0;
    cout << "Please enter the number of iterations: " << endl;
    cin >> iterations;

    cout << "f(x) = " << obj1 -> FunctionDefinition(x0) << endl;
    cout << "f'(x) = " << obj2 -> DefinitionFunctionDerivative(x0) << endl;
    
    obj3 -> NewtonRaphsonIterator(x0, iterations);
}
