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
        Double_t a, b, epsilong;
        vector<Double_t> epsilon, density1, density2, density3, epsilon1, epsilon2, epsilon3;
        TRandom3 r1;
};

class Plot: public Variables
{
    public:
        void FillVectors()
        {
            cout << "Please enter the number of points to make the plot: " << endl;
            cin >> np;

            a = 5;
            b = 2;
            epsilong = 3;

            for (UInt_t i = 0; i < np; ++i)
            {
                epsilon.push_back(r1.Uniform(-7, 7));
            }

            sort(epsilon.begin(), epsilon.end());

            for (UInt_t i = 0; i < np; ++i)
            {
                if (epsilon[i] > epsilong)
                {
                    epsilon1.push_back( epsilon[i] );
                    density1.push_back( a*TMath::Sqrt(epsilon[i] - epsilong) );
                }

                else if (epsilon[i] > 0 && epsilon[i] < epsilong)
                {
                    epsilon2.push_back( epsilon[i] );
                    density2.push_back( 0 );
                }

                else if (epsilon[i] < 0)
                {
                    epsilon3.push_back( epsilon[i] );
                    density3.push_back( b*TMath::Sqrt(-epsilon[i]) );
                }
            }
        }

        void PlotVectors()
        {
            auto *c1 = new TCanvas();
            c1 -> SetGrid();

            TGraph *gr1 = new TGraph (epsilon1.size(), &epsilon1[0], &density1[0]);
            TGraph *gr2 = new TGraph (epsilon2.size(), &epsilon2[0], &density2[0]);
            TGraph *gr3 = new TGraph (epsilon3.size(), &epsilon3[0], &density3[0]);
    
            gr1 -> SetMarkerStyle(21);
            gr1 -> GetXaxis() -> SetLimits(-5, 5);
            gr1 -> GetYaxis() -> SetLimits(-5, 5);
            gr1 -> Draw("AC*");
            
            gr2 -> SetMarkerStyle(22);
            gr2 -> GetXaxis() -> SetLimits(-5, 5);
            gr2 -> GetYaxis() -> SetLimits(-5, 5);
            gr2 -> Draw();

            gr3 -> SetMarkerStyle(23);
            gr3 -> GetXaxis() -> SetLimits(-5, 5);
            gr3 -> GetYaxis() -> SetLimits(-5, 5);
            gr3 -> Draw("CP"); //In order to superimpose delete the A option

            c1 -> Draw();
            
            epsilon.clear();
            epsilon1.clear(); epsilon2.clear(); epsilon3.clear();
            density1.clear(); density2.clear(); density3.clear();
        }
};

void ElectronOccupation()
{
    Plot obj1;
    obj1.FillVectors();
    obj1.PlotVectors();
}