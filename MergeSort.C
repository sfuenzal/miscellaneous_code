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

void MergeSort()
{
    Int_t array_size;
    cout << "Please enter the array size: " << endl;
    cin >> array_size;

    vector<Float_t> complete_array;
    Float_t complete_array_elements;

    cout << "Please enter the elements of the complete array: " << endl;
    
    while (complete_array.size() < array_size)
    {
        cin >> complete_array_elements;
        complete_array.push_back(complete_array_elements);
    }

    vector<Float_t> left_array;
    vector<Float_t> right_array;

    for (Int_t i = 0; i < complete_array.size()/2; ++i)
    {
        left_array.push_back(complete_array[i]);
    }

    for (Int_t i = complete_array.size()/2; i < complete_array.size(); ++i)
    {
        right_array.push_back(complete_array[i]);
    }

    cout << "Left array elements: " << endl;

    for(Int_t i = 0; i < left_array.size(); ++i)
    {
        cout << left_array[i] << endl;
    }

    cout << "Right array elements: " << endl;

    for(Int_t i = 0; i < right_array.size(); ++i)
    {
        cout << right_array[i] << endl;
    }

    left_array[left_array.size()] = pow(10, 9); 
    right_array[right_array.size()] = pow(10, 9);

    Int_t i = 0;
    Int_t j = 0;

    cout << "The ordered array is: " << endl;

    for (Int_t k = 0; k < complete_array.size(); ++k)
    {
        if (left_array[i] <= right_array[j])
        {
            complete_array[k] = left_array[i];
            ++i;
        }

        else 
        {
            complete_array[k] = right_array[j];
            ++j;
        }
        
        cout << complete_array[k] << endl;
    }

    

    //for (Int_t i = 0; i < complete_array.size(); ++i)
    //{
      //  cout << complete_array[i] << endl;
    //}

}
