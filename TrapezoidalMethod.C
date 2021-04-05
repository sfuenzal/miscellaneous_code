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
            f = pow(x, 2);
            return f;
        }

        virtual ~Function () {};
};

class TrapezoidalMethodIntegration: public Function
{
    private:
        Double_t steps, counter, meanfunctions, sumfunctions, integral;
        vector<Double_t> intervalvector;
    public:
        TrapezoidalMethodIntegration () {};
        
        void TrapezoidalIntegration(Double_t a, Double_t b, UInt_t N)
        {
            steps = TMath::Abs(a - b)/N;
            counter = a;

            intervalvector.push_back(counter);

            for (UInt_t i = 0; i < N; ++i)
            {
                counter += steps;
                intervalvector.push_back(counter);
            }
              
            meanfunctions = ( FunctionDefinition(intervalvector[0]) + FunctionDefinition(intervalvector[intervalvector.size()]) )/2;
            
            sumfunctions = 0;

            for (UInt_t i = 1; i < intervalvector.size() - 1; ++i)
            {
                sumfunctions += FunctionDefinition(intervalvector[i]);
            }
        
            integral = steps*(sumfunctions + meanfunctions);

            cout << integral << endl; 
        }
        
        ~TrapezoidalMethodIntegration () {};
};


void TrapezoidalMethod()
{
    TrapezoidalMethodIntegration *obj1 = new TrapezoidalMethodIntegration();
    
    Double_t lowerlimit, upperlimit;
    UInt_t subintervals;

    cout << "Please enter the lower limit and the upper limit of the integral to evaluate: " << endl;
    cin >> lowerlimit >> upperlimit;

    cout << "Please enter the number of subintervals: " << endl;
    cin >> subintervals;

    obj1 -> TrapezoidalIntegration(lowerlimit, upperlimit, subintervals);
}