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

void MonteCarloThings()
{
    string auxstring, first_question;
    Int_t number_of_simulations;
    Int_t number_of_simulations_for_plot;

    TRandom3 r1, r2;
    vector<Double_t> x1, x2, x3, x4, x5, x6;
    vector<Double_t> pi_values_vector;
    Double_t pi; 

    cout << "Do you want to make a plot? (type 'yes' or 'no')" << endl;
    cin >> first_question;

    if (first_question == "no")
    {
        cout << "Please enter the number of simulations (until order 10^7) (type -1 to abort): " << endl;

        do 
        {
            cin >> number_of_simulations;

            if (number_of_simulations == -1)
            {
                cout << "Are you sure that you want to abort (type 'yes' or 'no'): " << endl;
                cin >> auxstring;
                if (auxstring == "no")
                {
                    cout << "Continue entering the number of simulations (remember to type -1 if you want to abort): " << endl;
                    cin >> number_of_simulations;
                }
            
                else if (auxstring == "yes")
                {
                    cout << "you have aborted." << endl;
                }
            }

            Int_t counter = 0;

            for (Int_t i = 0; i < number_of_simulations; ++i)
            {
                x1.push_back(r1.Uniform(0, 1)); 
                x2.push_back(r2.Uniform(0, 1));
                x3.push_back(pow(x1[i], 2) + pow(x2[i], 2));
                if (x3[i] <= 1)
                {
                    ++counter;
                }
            }

            pi = 4*((Double_t) counter)/(Double_t) number_of_simulations;

            if (number_of_simulations != -1 || auxstring == "no") cout << "pi = " << pi << endl;
        }

        while (auxstring != "yes");
    }

    else if (first_question == "yes")
    {
        cout << "Please enter the number of simulations to make a plot: " << endl;
        cin >> number_of_simulations_for_plot;

        vector<Int_t> iterations;

        for (Int_t i = 1; i < number_of_simulations_for_plot; ++i)
        {
            iterations.push_back(i);
        }
        
        Int_t k = 1;
        while (k < iterations.size())
        {                    
            Int_t counter = 0;
            Double_t simulations = iterations[k];
            
            for (Int_t i = 0; i < simulations; ++i)
            {
                x1.push_back(r1.Uniform(0, 1));
                x2.push_back(r2.Uniform(0, 1));
                x3.push_back(pow(x1[i], 2) + pow(x2[i], 2));
                if (x3[i] <= 1)
                {
                    ++counter;
                }
            }
        
            pi = 4*((Double_t) counter)/(Double_t) simulations;
            pi_values_vector.push_back(pi);
            ++k;
        }

        Double_t iterations_array[iterations.size()];
        Double_t pi_values_array[pi_values_vector.size()];
        Double_t pi[iterations.size()];
        
        for (Int_t i = 0; i < iterations.size(); ++i)
        {
            iterations_array[i] = iterations[i];
            pi_values_array[i] = pi_values_vector[i];
        }

        for (Int_t i = 0; i < iterations.size(); ++i)
        {
            pi[i] = TMath::Pi();
        }

        auto *c1 = new TCanvas();
        c1 -> SetGrid();

        TGraph *gr1 = new TGraph (sizeof(iterations_array)/sizeof(iterations_array[0]), iterations_array, pi_values_array);
        TGraph *gr2 = new TGraph (sizeof(iterations_array)/sizeof(iterations_array[0]), iterations_array, pi);
        
        gr1 -> Draw();
        gr2 -> Draw("same");

        c1 -> Draw();
    }
}
