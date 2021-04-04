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
        vector<Double_t> AlphaBeta, angles, Transmited, Reflected;
        TRandom3 r1;
};

class FresnelEquations: public Variables
{
    public:
        void FillVectors()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;

            for (UInt_t i = 0; i < np; ++i)
            {
                angles.push_back(r1.Uniform(0, TMath::Pi()/2.));
            }
            
            sort(angles.begin(), angles.end());
            
            for (UInt_t i = 0; i < np; ++i)
            {
                AlphaBeta.push_back( TMath::Sqrt( 2.25 - pow(TMath::Sin(angles[i]), 2) )/TMath::Cos(angles[i]) ); 
            }

            sort(AlphaBeta.begin(), AlphaBeta.end());

            for (UInt_t i = 0; i < np; ++i)
            {
                Transmited.push_back( 2/(1 + AlphaBeta[i]) );
            }

            for (UInt_t i = 0; i < np; ++i)
            {
                Reflected.push_back( TMath::Abs( (1 - AlphaBeta[i])/(1 + AlphaBeta[i]) ) );
            }
        }

        void Plot()
        {
            auto *c1 = new TCanvas();
            c1 -> SetGrid();

            TGraph *gr1 = new TGraph (Transmited.size(), &angles[0], &Transmited[0]);
            TGraph *gr2 = new TGraph (Reflected.size(), &angles[0], &Reflected[0]);
    
            gr1 -> SetMarkerStyle(21);
            gr1 -> GetXaxis() -> SetLimits(0, TMath::Pi()/2);
            gr1 -> Draw("AC*");
            
            gr2 -> SetMarkerStyle(22);
            gr2 -> GetXaxis() -> SetLimits(0, TMath::Pi()/2);
            gr2 -> Draw("CP"); //In order to superimpose delete the A option

            c1 -> Draw();

            angles.clear();
            AlphaBeta.clear();
            Transmited.clear();
            Reflected.clear();
        }
};

void BrewsterAngle()
{
    FresnelEquations obj1;
    obj1.FillVectors();
    obj1.Plot();
}