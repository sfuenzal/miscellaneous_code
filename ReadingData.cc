#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadingFileVariables
{
    protected:
        ifstream inFile;
        string aux_string;
        int int_numbers_items;
        float float_numbers_items;
        double double_numbers_items;
        vector<int> int_numbers_vector;
        int counter;
};

class ReadingFile: public ReadingFileVariables
{
    public:
        void SetValuesOpenFile(string);
        
        void OpenFile()
        {
            inFile.open(aux_string);
        }
        
        void CheckForError()
        {
            if(inFile.fail())
            {
                cerr << "Error opening the file :(" << endl; //Error message
                exit(1);
            }
        }
        
        void ReadTheElementsOfTheFile()
        {
            counter = 0;
            
            while (!inFile.eof())
            {
                inFile >> int_numbers_items;
                int_numbers_vector.push_back(int_numbers_items);
                ++counter;
            }

            cout << counter << " items found!" << endl;

        }
        
        void ShowTheElementsOfTheFile()
        {
            for (int i = 0; i < int_numbers_vector.size(); ++i)
            {
                cout << int_numbers_vector[i] << endl;
            }
        }
        
        void CloseFile(){inFile.close();}
};

void ReadingFile::SetValuesOpenFile (string aux)
{
    aux_string = aux;
}

int main()
{
    ReadingFile File1;
    string NameOfFile = "reading.txt"; //Name of our data set that is located in our local storage drive

    File1.SetValuesOpenFile(NameOfFile);File1.OpenFile();
    File1.CheckForError();
    File1.ReadTheElementsOfTheFile();
    File1.ShowTheElementsOfTheFile();
    File1.CloseFile();

    return 0;
}
