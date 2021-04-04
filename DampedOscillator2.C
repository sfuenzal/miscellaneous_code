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
    protected:
        Int_t np;
        Double_t A, beta, delta, omega1;
        vector<Double_t> xt, xdot, u, w;
};

class Plots: public Variables
{
    public:
         
        void SetValues_FillVectors(Int_t, Double_t, Double_t, Double_t, Double_t);

        void FillVectors()
        {            
            for (UInt_t t = 0; t < np; ++t)
            {
                xt.push_back(A*TMath::Exp(-beta*t)*TMath::Cos(omega1*t - delta));
            }

            for (UInt_t t = 0; t < np; ++t)
            {
                xdot.push_back(-A*TMath::Exp(-beta*t)*(beta*TMath::Cos(omega1*t - delta) + omega1*TMath::Sin(omega1*t - delta)));
            }

            for (UInt_t t = 0; t < np; ++t)
            {
                u.push_back(omega1*A*TMath::Exp(-beta*t)*TMath::Cos(omega1*t - delta));
            }

            for (UInt_t t = 0; t < np; ++t)
            {
                w.push_back(-omega1*A*TMath::Exp(-beta*t)*TMath::Sin(omega1*t - delta));
            }
        }

        void Spirals()
        {
            auto *c1 = new TCanvas();
            c1 -> SetGrid();

            TGraph *gr1 = new TGraph (np, &xt[0], &xdot[0]);
    
            gr1 -> SetTitle("Phase space damped oscillator");

            gr1 -> GetXaxis() -> SetTitle("x");
            gr1 -> GetXaxis() -> CenterTitle();
            gr1 -> GetYaxis() -> SetTitle("#dot{x}");
            gr1 -> GetYaxis() -> CenterTitle();
    
            gr1 -> Draw();

            c1 -> Draw();

            auto *c2 = new TCanvas();
            c2 -> SetGrid();

            TGraph *gr2 = new TGraph (np, &u[0], &w[0]);
    
            gr2 -> SetTitle("Phase space damped oscillator");

            gr2 -> GetXaxis() -> SetTitle("u");
            gr2 -> GetXaxis() -> CenterTitle();
            gr2 -> GetYaxis() -> SetTitle("w");
            gr2 -> GetYaxis() -> CenterTitle();
    
            gr2 -> Draw();

            c2 -> Draw();
        }
};

void Plots::SetValues_FillVectors (Int_t aux1, Double_t aux2, Double_t aux3, Double_t aux4, Double_t aux5)
{
    np = aux1;
    A = aux2;
    beta = aux3;
    omega1 = aux4;
    delta = aux5;
}

void DampedOscillator2()
{
    Plots plot_object;
    
    Int_t np_set_by_user;
    cout << "Please enter the number of points to make the plots: " << endl;
    cin >> np_set_by_user;
    
    Double_t A_set_by_user = 1.0;
    Double_t beta_set_by_user = 0.2;
    Double_t omega1_set_by_user = 1.0;
    Double_t delta_set_by_user = TMath::Pi()/2.;

    plot_object.SetValues_FillVectors(np_set_by_user, A_set_by_user, beta_set_by_user, omega1_set_by_user, delta_set_by_user);
    plot_object.FillVectors();
    plot_object.Spirals();
}