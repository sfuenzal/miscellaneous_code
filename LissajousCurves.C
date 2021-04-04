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

void LissajousCurves()
{
    Int_t N;
    cout << "Please enter the number of simmulation that you want to consider: " << endl;
    cin >> N;
    
    Double_t omegax = 1;
    Double_t omegay = 3/2.;
    Double_t A = 1;
    Double_t B = 2;
    Double_t alpha = TMath::Pi();
    Double_t beta = TMath::Pi()/3.;
    
    vector<Double_t> xt;
    vector<Double_t> yt;

    for (UInt_t t = 0; t < N; ++t)
    {
        xt.push_back(A*TMath::Cos(omegax*t - alpha));
        yt.push_back(B*TMath::Sin(omegay*t - beta));
    }

    Double_t xt_array[xt.size()];
    Double_t yt_array[yt.size()];

    for (UInt_t t = 0; t < N; ++t)
    {
        xt_array[t] = xt[t];
    }

    for (UInt_t t = 0; t < N; ++t)
    {
        yt_array[t] = yt[t];
    }

    xt.clear();
    yt.clear();

    auto *c1 = new TCanvas();
    c1 -> SetGrid();
    
    TGraph *gr1 = new TGraph (N, xt_array, yt_array);
    gr1 -> SetTitle("LissajousCurves");

    gr1 -> GetXaxis() -> SetTitle("x");
    gr1 -> GetXaxis() -> CenterTitle();
    gr1 -> GetYaxis() -> SetTitle("y");
    gr1 -> GetYaxis() -> CenterTitle();

    gr1 -> Draw();
    c1 -> Draw();
    
    c1 -> Print("conchetumare.png");

    
}
