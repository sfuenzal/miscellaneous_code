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

//Multilevel Inheritance

class Variables
{
    protected:
        Int_t np, turns;
        Double_t alpha, omega, radii, coef;
        vector<Double_t> r, phi, Ex1, Ey1, Ex2, Ey2, E1, E2, rr1, rr2;
        TRandom3 r1, r2, r3;
};

class FillVectors: public Variables
{
    public:
        FillVectors()
        {
            cout << "Please enter the number of points to fill the vectors: " << endl;
            cin >> np;

            for (UInt_t i = 0; i < np; ++i)
            {
                r.push_back(r1.Uniform(0.001, 20));
            }

            for (UInt_t i = 0; i < np; ++i)
            {
                phi.push_back(r2.Uniform(0, 2*TMath::Pi()));
            }

            sort(r.begin(), r.end());
            sort(phi.begin(), phi.end());
        }
};

class ElectricFieldLines: public FillVectors
{
    public:
        ElectricFieldLines()
        {
            turns = 100;
            coef = 1;
            radii = 5;
            
            for (UInt_t i = 0; i < np; ++i)
            {
                if (r[i] < radii)
                {
                    Ex1.push_back( 0.5*turns*coef*r[i]*TMath::Cos(i)*TMath::Sin(phi[i]) );
                    Ey1.push_back( -0.5*turns*coef*r[i]*TMath::Cos(i)*TMath::Cos(phi[i]) );
                }

                else
                {
                    Ex2.push_back( 0.5*coef*turns*pow(radii, 2)*(1/r[i])*TMath::Cos(i)*TMath::Sin(phi[i]) );
                    Ey2.push_back( -0.5*coef*turns*pow(radii, 2)*(1/r[i])*TMath::Cos(i)*TMath::Cos(phi[i]) );
                }
            }

            for (UInt_t i = 0; i < np; ++i)
            {
                if (r[i] < radii)
                {
                    rr1.push_back(r[i]);
                    E1.push_back( 0.5*turns*r[i] );
                }

                else 
                {
                    rr2.push_back(r[i]);
                    E2.push_back( 0.5*turns*(1/r[i])*pow(radii, 2) );
                }
            }

            auto *c1 = new TCanvas();
            c1 -> SetGrid();

            TGraph *gr1 = new TGraph (Ex1.size(), &Ex1[0], &Ey1[0]);
            TGraph *gr2 = new TGraph (Ex2.size(), &Ex2[0], &Ey2[0]);
    
            gr1 -> SetMarkerStyle(22);
            gr1 -> Draw("AP");
            
            gr2 -> SetMarkerStyle(22);
            gr2 -> Draw("P"); //In order to superimpose delete the A option

            c1 -> Draw();

            auto *c2 = new TCanvas();
            c2 -> SetGrid();

            TGraph *gr3 = new TGraph (E1.size(), &rr1[0], &E1[0]);
            TGraph *gr4 = new TGraph (E2.size(), &rr2[0], &E2[0]);
    
            gr3 -> SetMarkerStyle(21);
            gr3 -> GetXaxis() -> SetLimits(0, 20);
            gr3 -> Draw("AC*");
            
            gr4 -> SetMarkerStyle(22);
            gr4 -> GetXaxis() -> SetLimits(0, 20);
            gr4 -> Draw("CP"); //In order to superimpose delete the A option

            c2 -> Draw();
        }
};

void SolenoidElectricField()
{
    ElectricFieldLines obj1;
}