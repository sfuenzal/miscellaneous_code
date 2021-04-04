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

class QuadraticEquation
{
    Double_t a, b, c;
  public:
    void set_values (Double_t, Double_t, Double_t);
    Double_t sol1 () {return (-b + TMath::Sqrt(pow(b,2) - 4*a*c))/(2*a);}
    Double_t sol2 () {return (-b - TMath::Sqrt(pow(b,2) - 4*a*c))/(2*a);}
};

void QuadraticEquation::set_values (Double_t a0, Double_t b0, Double_t c0)
{
    a = a0;
    b = b0;
    c = c0;
}


void QuadraticEquationSolver()
{
    class QuadraticEquation *eq;
    
    Double_t a_coef, b_coef, c_coef;
    cout << "Please enter the coefficients of the quadratic equation (a, b and c): " << endl;
    cin >> a_coef >> b_coef >> c_coef;


    if (TMath::Sqrt(pow(b_coef, 2) - 4*a_coef*c_coef) > 0)
    {
        eq -> set_values(a_coef, b_coef, c_coef);
        cout << "The solutions are: " << "x1 = " << eq -> sol1() << ", " << "x2 = " << eq -> sol2() << endl;
    }

    else if (TMath::Sqrt(pow(b_coef, 2) - 4*a_coef*c_coef) == 0)
    {
        eq -> set_values(a_coef, b_coef, c_coef);
        cout << "The solution is: " << "x = " << eq -> sol1() << endl;
    }

    else
    {
        cout << "There is no real solutions" << endl;
    } 


}