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
        Double_t rmin, rmax;
        vector<Double_t> r, theta;
};

class Plot: public Variables
{
    public:
        void Points()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;
        }
        
        void IntensityProfile()
        {
            TCanvas *CPol = new TCanvas("CPol", "TGraphPolar Examples", 700, 700);
            rmin = 0; rmax = 2*TMath::Pi();
            TF1 *fp1 = new TF1("fplot", "pow(TMath::Sin(x), 2)*pow(TMath::Cos(x), 2)", rmin, rmax);
            
            for (UInt_t ipt = 0; ipt < np; ++ipt)
            {
                r.push_back( ipt*(rmax-rmin)/np + rmin );
                theta.push_back( fp1 -> Eval(r[ipt]) );
            }

            TGraphPolar *grP1 = new TGraphPolar(np, &r[0], &theta[0]);
            grP1 -> SetLineColor(2);
            grP1 -> Draw("AOL"); 
        }
};

void PolarGraph()
{
    Plot obj1;
    obj1.Points();
    obj1.IntensityProfile();
}