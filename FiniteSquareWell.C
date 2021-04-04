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

class Plots
{
    public:
        void CaseOne()
        {
            auto *c1 = new TCanvas();
            c1 ->  SetGrid();

            TF1 *PlotFunctionCaseOne_1 = new TF1("Plot function case one", "x*TMath::Tan(x)", 0, 1.5);
            PlotFunctionCaseOne_1 -> SetLineColor(4);
            PlotFunctionCaseOne_1 -> SetLineStyle(1);
            PlotFunctionCaseOne_1 -> Draw();
            PlotFunctionCaseOne_1 -> GetXaxis() -> SetTitle("#xi");
            PlotFunctionCaseOne_1 -> GetXaxis() -> CenterTitle();
            PlotFunctionCaseOne_1 -> GetYaxis() -> SetTitle("#eta");
            PlotFunctionCaseOne_1 -> GetXaxis() -> CenterTitle();

            for (UInt_t i = 1; i <= 3; ++i)
            {
                TF1 *PlotFunctionCaseOne_2 = new TF1("Plot function case one", "pow([0], 2) - pow(x, 2)", 0, i);
                PlotFunctionCaseOne_2 -> SetParameter(0, i);
                PlotFunctionCaseOne_2 -> SetLineColor(i);
                PlotFunctionCaseOne_2 -> SetLineStyle(1);
                PlotFunctionCaseOne_2 -> Draw("same");
                PlotFunctionCaseOne_2 -> GetXaxis() -> SetTitle("#xi");
                PlotFunctionCaseOne_2 -> GetXaxis() -> CenterTitle();
                PlotFunctionCaseOne_2 -> GetYaxis() -> SetTitle("#eta");
                PlotFunctionCaseOne_2 -> GetXaxis() -> CenterTitle();
            }
        }

         void CaseTwo()
        {
            auto *c2 = new TCanvas();
            c2 ->  SetGrid();

            TF1 *PlotFunctionCaseTwo_1 = new TF1("Plot function case two", "-x*TMath::Cos(x)/TMath::Sin(x)", 0.3, 3);
            PlotFunctionCaseTwo_1 -> SetLineColor(4);
            PlotFunctionCaseTwo_1 -> SetLineStyle(1);
            PlotFunctionCaseTwo_1 -> Draw();
            PlotFunctionCaseTwo_1 -> GetXaxis() -> SetTitle("#xi");
            PlotFunctionCaseTwo_1 -> GetXaxis() -> CenterTitle();
            PlotFunctionCaseTwo_1 -> GetYaxis() -> SetTitle("#eta");
            PlotFunctionCaseTwo_1 -> GetXaxis() -> CenterTitle();

            Int_t i = 1;
            while( i <= 3)
            {
                TF1 *PlotFunctionCaseTwo_2 = new TF1("Plot function case two", "pow([0], 2) - pow(x, 2)", 0, i);
                PlotFunctionCaseTwo_2 -> SetParameter(0, i);
                PlotFunctionCaseTwo_2 -> SetLineColor(i);
                PlotFunctionCaseTwo_2 -> SetLineStyle(1);
                PlotFunctionCaseTwo_2 -> Draw("same");
                PlotFunctionCaseTwo_2 -> GetXaxis() -> SetTitle("#xi");
                PlotFunctionCaseTwo_2 -> GetXaxis() -> CenterTitle();
                PlotFunctionCaseTwo_2 -> GetYaxis() -> SetTitle("#eta");
                PlotFunctionCaseTwo_2 -> GetXaxis() -> CenterTitle();
                ++i;
            }
        }
};

void FiniteSquareWell()
{
    Plots obj1;
    obj1.CaseOne();
    obj1.CaseTwo();
}
