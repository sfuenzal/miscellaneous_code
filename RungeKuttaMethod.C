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

class InputEquation
{
    private:
        Double_t x, y, z;
        TRandom *r = new TRandom();
    public:
        InputEquation () {};

        Double_t DifferentialEquation(Double_t x, Double_t y)
        {
            return pow(TMath::Sin(x), 2)*y; // dy/dx = f(x,y)
            //return (y*y-x*x)/(y*y+x*x);
        }

        void PlotDifferentialEquation(UInt_t np)	
        {
            TCanvas *c = new TCanvas("c", "Graph2D example", 0, 0, 700, 600);
            TGraph2D *dt = new TGraph2D();

            for (Int_t n = 1; n < np; ++n) 
            {
                x = r -> Rndm(n);
                y = r -> Rndm(n);
                z = pow(TMath::Sin(x), 2)*y;
                dt -> SetPoint(n, x, y, z);
            } 

            gStyle -> SetPalette(55);
            dt -> Draw("surf1");
            dt -> SetTitle("Graph of f(x, y); x; y; f(x, y)");
	    }

        virtual ~ InputEquation () {};
};

class RK4: public InputEquation
{
    private:
        Double_t x0, y0, xn, yn, n, h;
        Double_t k1, k2, k3, k4, k;
        UInt_t counter;
        vector<Double_t> x_axis_solution;
        vector<Double_t> solution_vector;
        TRandom3 r;
    public:
        RK4 () {};

        void InitialConditions(Double_t first_initial_condition, Double_t second_initial_condition, Double_t number_of_steps, Double_t calculation_point)
        {
            x0 = first_initial_condition;
            y0 = second_initial_condition;
            n = number_of_steps;
            xn = calculation_point;
        }
        
        void StepSize()
        {
            h = (xn - x0)/n;
        }

        void RK4Integrator()
        {
            counter = 0;

            do
            {
                k1 = h * DifferentialEquation(x0, y0);
                k2 = h * DifferentialEquation(x0 + h, y0 + k1/2.);
                k3 = h * DifferentialEquation(x0 + h/2., y0 + k2/2.);
                k4 = h * DifferentialEquation(x0 + h, y0 + k3);

                k = (k1 + 2*k2 + 2*k3 + k4)/6.;

                yn = y0 + k;
                x0 = x0 + h;
                y0 = yn;
                counter = counter + 1;

                solution_vector.push_back(yn);
            
            } while (counter < n);
           
            for (UInt_t i = 0; i < solution_vector.size(); ++i)
            {
                cout << solution_vector.at(i) << endl;
            } 
        
        }

        ~ RK4 () {};
};

void RungeKuttaMethod()
{
    RK4 *obj1 = new RK4();

    obj1 -> InitialConditions(0, 1, 100, 0.6);
    obj1 -> StepSize();
    obj1 -> RK4Integrator();
    
    InputEquation *obj2 = new InputEquation();
    obj2 -> PlotDifferentialEquation(10000);
}
