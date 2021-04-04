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

Double_t f(Double_t x)
{
    return TMath::Cos(x);
}

Double_t f_plot(Double_t *x, Double_t *param)
{
    return param[0]*TMath::Cos(x[0]);
}

class DerivativeFunction 
{
    Double_t a, b;
  public:
    void set_values (Double_t, Double_t);
    Double_t DerivativeDefinition () {return (f(a) - f(b))/(a - b);}
};

void DerivativeFunction::set_values (Double_t x, Double_t x0)
{
    a = x;
    b = x0;
}

void DerivativeFunction()
{
    class DerivativeFunction *func;

    Double_t initial_value, final_value;
    cout << "Please enter the initial and final value to evaluate the derivative: " << endl;
    cin >> initial_value >> final_value;

    vector<Double_t> x_values_vector;
    vector<Double_t> derivative_vector;

    if (initial_value == 0)
    {
        for (Int_t i = initial_value; i < final_value; ++i)
        {
            func -> set_values(i + i*pow(10, -7) + pow(10, -7), i);
            x_values_vector.push_back(i);
            derivative_vector.push_back(func -> DerivativeDefinition());   
        }
    }

    else
    {
        for (Int_t i = initial_value; i < final_value; ++i)
        {
            func -> set_values(i + i*pow(10, -7), i);
            x_values_vector.push_back(i);
            derivative_vector.push_back(func -> DerivativeDefinition());   
        }  
    }
    
    Float_t x_values_array[x_values_vector.size()];
    Float_t derivative_array[derivative_vector.size()];

    for (Int_t i = 0; i < x_values_vector.size(); ++i)
    {
        x_values_array[i] = x_values_vector[i];
        derivative_array[i] = derivative_vector[i];
    }

    auto *c1 = new TCanvas();
    c1 -> SetGrid();

    TGraph *gr1 = new TGraph (sizeof(x_values_array)/sizeof(x_values_array[0]), x_values_array, derivative_array);
    TF1 *f1 = new TF1("f1", f_plot, initial_value, final_value, 2);
    f1 -> SetParameter(0, 1);
    
    gr1 -> SetTitle("Function and its derivative");
    f1 -> SetTitle("Function and its derivative");

    gr1 -> GetXaxis() -> SetTitle("x");
    gr1 -> GetXaxis() -> CenterTitle();
    f1 -> GetXaxis() -> SetTitle("x");
    f1 -> GetXaxis() -> CenterTitle();

    gr1 -> Draw();
    f1 -> Draw("same");

    c1 -> Draw();

    auto legend = new TLegend(0.9, 0.7, 0.6, 0.9);
    legend -> SetHeader("Legend", "C"); // option "C" allows to center the header
    legend -> AddEntry(f1, "Function", "l");
    legend -> AddEntry(gr1, "Derivative", "l");
    legend -> Draw();

    //cout << "Derivative = " << func -> DerivativeDefinition () << endl;

    //TF1 *f1 = new TF1("func1", "pow(x, 2)", 0, 10);
    //cout << "ROOT implemented derivative = " << f1 -> Derivative(1) << endl;

    //cout <<  f1 -> Derivative(1) -  func -> DerivativeDefinition () << endl;

}
