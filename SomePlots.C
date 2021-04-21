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

class Variables
{
    protected:
        TRandom3 r;
        vector<double> k_vector, radial_vector, x_axis, y_axis, angles;
    public:
        Variables () {};
        virtual ~ Variables () {};
};

class Hearts: public Variables
{
    public:
        Hearts () {};

        void TridimensionalHearth()
        {
            TF3 *heart = new TF3("Heart", "pow(pow(x, 2) + (9/4.)*pow(y, 2) + pow(z, 2) - 1 , 3) - pow(x, 2)*pow(z, 3) - (9/200.)*pow(y, 2)*pow(z, 3)", -2, 2, -2, 2, -2, 2);
            heart -> Draw();
            heart -> SetTitle("3D Heart; x; y; z");
        }

        void TwoDimensionalHearth(unsigned int points)
        {
            for (unsigned int i = 0; i < points; ++i)
            {
                angles.push_back(r.Uniform(0, 2*TMath::Pi()));
            }

            sort(angles.begin(), angles.end());

            for (unsigned int i = 0; i < angles.size(); ++i)
            {
                x_axis.push_back(16*pow(TMath::Sin(angles[i]), 3));
                y_axis.push_back(13*TMath::Cos(angles[i]) - 5*TMath::Cos(2*angles[i]) - 2*TMath::Cos(3*angles[i]) - TMath::Cos(4*angles[i]));
            } 

            auto *c1 = new TCanvas();
            c1 -> SetGrid();

            TGraph *gr1 = new TGraph (angles.size(), &x_axis[0], &y_axis[0]);
            gr1 -> SetMarkerColor(2);
            gr1 -> SetLineColor(2);
            gr1 -> Draw();
            gr1 -> SetTitle("2D Hearth; x; y");

            angles.clear();
            x_axis.clear();
            y_axis.clear();
        }

        ~ Hearts () {};
};

class MaurerRose: public Variables
{
    public:
        MaurerRose () {};

        void MaurerRosePlot(unsigned int points, unsigned int n, unsigned int d)
        {
            for (unsigned int i = 0; i < points; ++i)
            {
                angles.push_back(r.Uniform(0, 360));
            }

            sort(angles.begin(), angles.end());

            auto *c1 = new TCanvas();
            c1 -> SetGrid();
            
            for (unsigned int i = 0; i < angles.size(); ++i)
            {
                k_vector.push_back(angles[i] * d * TMath::Pi()/180.);
                radial_vector.push_back(300*TMath::Sin(n * k_vector[i]));
                x_axis.push_back(radial_vector[i]*TMath::Cos(k_vector[i]));
                y_axis.push_back(radial_vector[i]*TMath::Sin(k_vector[i]));
            }

            TGraph *gr1 = new TGraph (angles.size(), &x_axis[0], &y_axis[0]);
            gr1 -> SetMarkerColor(2);
            gr1 -> SetLineColor(2);
            gr1 -> Draw();
            gr1 -> SetTitle("Maurer Rose; x; y");

            k_vector.clear();
            radial_vector.clear();
            x_axis.clear();
            y_axis.clear();

            for (unsigned int i = 0; i < angles.size(); ++i)
            {
                k_vector.push_back(angles[i] * TMath::Pi()/180.);
                radial_vector.push_back(300*TMath::Sin(n * k_vector[i]));
                x_axis.push_back(radial_vector[i]*TMath::Cos(k_vector[i]));
                y_axis.push_back(radial_vector[i]*TMath::Sin(k_vector[i]));
            }

            TGraph *gr2 = new TGraph (angles.size(), &x_axis[0], &y_axis[0]);
            gr2 -> SetMarkerColor(2);
            gr2 -> SetLineColor(4);
            gr2 -> Draw("SAME");

            k_vector.clear();
            radial_vector.clear();
            x_axis.clear();
            y_axis.clear();
        }
        
         ~ MaurerRose () {};
};

void SomePlots()
{
    Hearts *obj1 = new Hearts();
    obj1 -> TridimensionalHearth();
    obj1 -> TwoDimensionalHearth(1000);

    MaurerRose *obj2 = new MaurerRose();
    obj2 -> MaurerRosePlot(80000, 6, 200);
}