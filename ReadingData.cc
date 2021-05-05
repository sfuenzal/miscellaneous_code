#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadingFileVariables
{
    protected:
        //file variables
        ifstream inFile1, inFile2;
        string aux_string;
        //items
        double numbers_items;
        string strings_items;
        //vectors to store elements
        vector<double> numbers_vector;
        vector<string> strings_vector;
        //counters
        int counter_numbers;
        int counter_strings;
    public:
        ReadingFileVariables() {};
        virtual ~ ReadingFileVariables() {};
};

class ReadingFile: public ReadingFileVariables
{
    public:
        ReadingFile () {};
        
        void OpenFileOne(string aux_string)
        {
            inFile1.open(aux_string);
        }
        
        void CheckForErrorOne()
        {
            if(inFile1.fail())
            {
                cerr << "Error opening the file :(" << endl; //Error message
                exit(1);
            }
        }
        
        void ReadTheElementsOfTheFileNumbers()
        {
            counter_numbers = 0;
            
            while (!inFile1.eof())
            {
                inFile1 >> numbers_items;
                numbers_vector.push_back(numbers_items);
                ++counter_numbers;

                //inFile1 >> strings_items;
                //strings_vector.push_back(strings_items);
                //++counter_strings;
            }

            cout << counter_numbers << " Number items found!" << endl;  
            //cout << counter_strings << " String items found!" << endl;
        }

        void ShowTheElementsOfTheFileNumbers()
        {
            for (int i = 0; i < numbers_vector.size(); ++i)
            {
                cout << numbers_vector.at(i) << endl;
            }

            //for (int i = 0; i < strings_vector.size(); ++i)
            //{
                //cout << strings_vector.at(i) << endl;
            //}
        }

        void CloseFileOne(){inFile1.close();}

        ~ ReadingFile () {};
};

int main()
{
    ReadingFile *File1 = new ReadingFile();
    string NameOfFile = "reading.txt"; //Name of our data set that is located in our local storage drive

    File1 -> OpenFileOne(NameOfFile);
    File1 -> CheckForErrorOne();
    File1 -> ReadTheElementsOfTheFileNumbers();
    File1 -> ShowTheElementsOfTheFileNumbers();
    File1 -> CloseFileOne();

    return 0;
}
