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

class Plotting
{
    protected:
        Double_t x, y, z, u, v, theta, phi, R;
        Int_t np, counter;
        TCanvas *c = new TCanvas("c", "Graph2D example", 0, 0, 700, 600);
        TGraph2D *dt = new TGraph2D();
        TRandom *r = new TRandom();
        TRandom3 r1, r2, r3;
};


class Plot1: public Plotting
{
    public:
        void output_plot_1()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;
        
            for (Int_t n = 1; n < np; ++n) 
            {
                x = r -> Rndm(n);
                y = r -> Rndm(n);
                z = 2/TMath::Pi()*TMath::ATan( TMath::Sin(TMath::Pi()*y)/TMath::SinH(TMath::Pi()*x) );
                dt -> SetPoint(n, x, y, z);
            } 

            gStyle -> SetPalette(55);
            dt -> Draw("surf1");
            dt -> SetTitle("Electrostatic potential due to two infinite grounded metal plates; x/a; y/a; V/V_{0}"); 
        }
};

class Plot2: public Plotting
{
    public:
        void output_plot_2()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;
            
            counter = 0;
            
            for (Int_t n = 1; n < np; ++n) 
            {
                x = r -> Rndm(n);
                y = r -> Rndm(n);
                z = (4/TMath::Pi())*((1/(2*counter+1))*TMath::CosH((2*counter+1)*TMath::Pi()*x)/TMath::CosH((2*counter+1)*TMath::Pi()) )*TMath::Sin((2*counter+1)*TMath::Pi()*y) ;
                dt -> SetPoint(n, x, y, z);
                ++counter;
            } 

            gStyle -> SetPalette(55);
            dt -> Draw("surf1");
            dt -> SetTitle("Electrostatic potential due to metal strips; x/a; y/a; V/V_{0}"); 
        }
};

class Plot3: public Plotting
{
    public:
        void output_plot_3()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;

            for (Int_t n = 0; n < np; ++n)
            {
                u = r1.Uniform(0, 2*TMath::Pi() - pow(10, -9)*2*TMath::Pi());
                v = r2.Uniform(-1, 1);
                x = (1 + (v/2.)*TMath::Cos(u/2.))*TMath::Cos(u);
                y = (1 + (v/2.)*TMath::Cos(u/2.))*TMath::Sin(u);
                z = (v/2.)*TMath::Sin(u/2);
                dt -> SetPoint(n, x, y, z);
            }

            gStyle -> SetPalette(55);
            dt -> Draw("pcol");
            //dt -> Draw("surf1");
            //dt -> Draw("surf3");
            //dt -> Draw("surf4");
            dt -> SetTitle("Mobius strip; x; y; z");
        }
};

class Plot4: public Plotting
{
    public:
        void output_plot_4()
        {
            cout << "Please enter the number of points: " << endl;
            cin >> np;

            for (Int_t n = 1; n < np; ++n)
            {
                theta = r1.Uniform(0, TMath::Pi());
                phi = r2.Uniform(0, 2*TMath::Pi() - pow(10, -9)*2*TMath::Pi());
                R = r3.Uniform(0, 2);
                x = R*TMath::Sin(theta)*TMath::Cos(phi);
                y = R*TMath::Sin(theta)*TMath::Sin(phi);
                z = R*TMath::Cos(theta);
                dt -> SetPoint(n, x, y, z);
            }

            gStyle -> SetPalette(55);
            //dt -> Draw("pcol");
            //dt -> Draw("surf1");
            //dt -> Draw("surf3");
            dt -> Draw("surf4");
            dt -> SetTitle("Sphere; x; y; z");
        }
};

void ElectrostaticsPotentials()
{

    int question;
    cout << "What plot do you want to make? " << endl;
    cin >> question;
    
    Plot1 plot_object_1;
    Plot2 plot_object_2;
    Plot3 plot_object_3;
    Plot4 plot_object_4;
    
    if (question == 1) plot_object_1.output_plot_1();
    else if (question == 2) plot_object_2.output_plot_2();
    else if (question == 3) plot_object_3.output_plot_3();
    else if (question == 4) plot_object_4.output_plot_4();
   
}