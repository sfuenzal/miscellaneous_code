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

void Multiplication()
{
    Int_t answer;
    cout << "Please enter 0 or 1: " << endl;
    cin >> answer;

    if (answer == 0)
    {
        Int_t n, m;
        cout << "Please enter two integer numbers: " << endl;
        cin >> n >> m;

        Int_t multiplication_result = 0;

        for (Int_t i = 0; i < m; ++i)
        {
            multiplication_result += n;
        }
    
        cout << "The multiplication of the two numbers is: " << multiplication_result << endl;
    }

    else if (answer == 1)
    {
        Int_t n, m;
        cout << "Please enter two integer numbers: " << endl;
        cin >> n >> m;

        Int_t aux_counter = 0;
        Int_t multiplication_result = 0;

        do
        {
            multiplication_result += n;
            ++aux_counter;
        } 
        
        while (aux_counter < m);

        cout << "The multiplication of the two numbers is: " << multiplication_result << endl;
        
    }
    
   
}