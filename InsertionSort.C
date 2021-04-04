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

void InsertionSort()
{
    Int_t array_size;
    cout << "Please enter the number of elements of the array: " << endl;
    cin >> array_size;
    
    vector<Float_t> input_array;
    Float_t elements, key;
    Int_t i, j;

    cout << "Please enter the elements of the array: " << endl;

    while (input_array.size() < array_size)
    {
        cin >> elements;
        input_array.push_back(elements);
    }

    for (j = 1; j < input_array.size(); ++j)
    {
        key = input_array[j];
        i = j - 1;
        while (i > -1 && input_array[i] > key)
        {
            input_array[i+1] = input_array[i];
            --i;
        }
        input_array[i+1] = key;
    }    
    
    cout << "The sorted array is: " << endl;

    for (Int_t k = 0; k < input_array.size(); ++k)
    {
        cout << input_array[k] << endl;
    }
    

}
