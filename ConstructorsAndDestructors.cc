#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Variables
{
    protected:
        int n, counter, c;
        double variable;

}; 

class SumOfIntegerNumbers: public Variables
{
    public:
        SumOfIntegerNumbers(int n1)
        {
            n = n1;
        }

        int SumLoop()
        {
            counter = 0;

            for (unsigned int i = 1; i <= n; ++i)
            {
                counter += i;
            }

            return counter;
        }
};

class Functions: public Variables
{
    public:
        Functions (double x1)
        {
            variable = x1;
        }
        
        double FunctionOneExample()
        {
            if (variable > 0)
            {
                return pow(variable, 2);
            }

            else if (variable == 0)
            {
                return pow(variable, -2);
            }

            else if (variable < 0)
            {
                return variable;
            }

            return 0;
        }
};

class WhileLoop: public Variables
{
    public:
        WhileLoop(int c1)
        {
            c = c1;
        }
        
        void LoopExampleBreak()
        {
            counter = 0;
            while (counter < c)
            {
                cout << 2*counter << endl;
                ++counter;
                if (2*counter == 10) {break;}
            } 
        }

        void LoopExampleContinue()
        {
            counter = 0;
            while (counter < c)
            {
                cout << 3*counter << endl;
                ++counter;
                if (3*counter == 9) 
                {
                    ++counter;
                    continue;
                }
            }
        }
};

int main()
{
    int v1;
    cout << "Please enter the number of integer numbers that you want to sum consecutively: " << endl;
    cin >> v1;

    SumOfIntegerNumbers obj1(v1);

    cout << "sum = " << obj1.SumLoop() << endl;

    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

    double v2;
    cout << "Please enter any number to evaluate the function: " << endl;
    cin >> v2;

    Functions obj2(v2);

    cout << obj2.FunctionOneExample() << endl;

    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

    int v3;
    cout << "Please enter any integer number: " << endl;
    cin >> v3;

    WhileLoop obj3(v3);

    obj3.LoopExampleBreak();
    cout << "" << endl;
    obj3.LoopExampleContinue();

}