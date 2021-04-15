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

class InputFunction
{
    public:
        InputFunction () {};

        double FunctionToIntegrate(double x)
        {
            return TMath::Cos(x);
        }

        virtual ~ InputFunction () {};
};

class SimpsonRule: public InputFunction
{
    private:
        double IntegrationValue, StepSize, k;
        unsigned int counter;
    public:
        SimpsonRule () {};

        void SimpsonIntegrator(double LowerLimit, double UpperLimit, unsigned int NumberOfSubintervals)
        {
            StepSize = ( TMath::Abs(LowerLimit - UpperLimit) )/NumberOfSubintervals;
            IntegrationValue = FunctionToIntegrate(LowerLimit) + FunctionToIntegrate(UpperLimit);
            counter = 1;

            do
            {
                k = LowerLimit + counter * StepSize;
                
                if (counter % 2 == 0)
                {
                    IntegrationValue = IntegrationValue + 2*FunctionToIntegrate(k);
                }

                else
                {
                    IntegrationValue = IntegrationValue + 4*FunctionToIntegrate(k);
                } 

                counter = counter + 1;

            } while (counter < NumberOfSubintervals && counter == NumberOfSubintervals);

            IntegrationValue = IntegrationValue * StepSize/3.;

            cout << "Integral Value is = " << IntegrationValue << endl;
        }

        ~ SimpsonRule () {};
};

void SimpsonOneThirdRule()
{
    SimpsonRule *obj1 = new SimpsonRule();
    
    for (unsigned int i = 1; i < 100; ++i)
    {
        cout << "Iteration: " << i << endl; 
        obj1 -> SimpsonIntegrator(-1, 10, i);
    }
}