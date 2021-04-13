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
#include <string> 

using namespace std;

class InputEquation
{
    public:
        InputEquation () {};

        Double_t EquationToSolve(Double_t x)
        {
            return pow(x, 2) - 2;
        }

        virtual ~ InputEquation () {};
};

class SecantMethodClass: public InputEquation
{
    private:
        Double_t x0, x1, x2;
        Double_t e;
        UInt_t N, counter;
    public:
        SecantMethodClass () {};

        void SecantMethodIntegrator(Double_t initial_guees_1, Double_t initial_guess_2, Double_t error, UInt_t max_iteration)
        {
            x0 = initial_guees_1;
            x1 = initial_guess_2;
            e = error;
            N = max_iteration;

            counter = 1;

            do
            {
                if (EquationToSolve(x0) == EquationToSolve(x1))
                {
                    cout << "Mathematical Error" << endl;
                    break;
                }

                x2 = x1 - (x1 - x0) * EquationToSolve(x1) / (EquationToSolve(x1) - EquationToSolve(x0));
                x0 = x1;
                x1 = x2;
                counter = counter + 1;

                if (counter > N)
                {
                    cout << "Not Convergent" << endl;
                    break;
                }

                cout << "The Solution is: " << x2 << endl;
            
            } while ( EquationToSolve(x2) > e );
            
        }

        ~ SecantMethodClass () {};
};

void SecantMethod()
{
    SecantMethodClass *obj1 = new SecantMethodClass();
    obj1 -> SecantMethodIntegrator(2, 5, 0.001, 100000); 
}