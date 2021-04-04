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

class Variables
{
    public:
        Int_t np;
        Double_t A, beta, delta, omega1;
        Double_t xt[np], xdot[np], u[np], w[np];
};


class Plots: public Variables
{
    public:
        void NumberOfPoints()
        {
            cout << "Please enter the number of points to make the plots: " << endl;
            cin >> np;
        }
        
        void FillArrays()
        {
            for (UInt_t t = 0; t < np; ++t)
            {
                xt[t] = A*TMath::Exp(-beta*t)*TMath::Cos(omega1*t - delta);
                xdot[t] = -A*TMath::Exp(-beta*t)*(beta*TMath::Cos(omega1*t - delta) + omega1*TMath::Sin(omega1*t - delta));
                u[t] = omega1*A*TMath::Exp(-beta*t)*TMath::Cos(omega1*t - delta);
                w[t] = -omega1*A*TMath::Exp(-beta*t)*TMath::Sin(omega1*t - delta);
            }
        }
};

void DampedOscillator()
{

}