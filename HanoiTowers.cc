#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class HanoiTowers
{
    public:
        HanoiTowers () {};

        void HanoiTowerSolver(int disk, int source, int dest, int spare)
        {
           
	        if (source == 0)
            {
                cout << "No movements" << endl;
            }

            else
            {
                HanoiTowerSolver(disk - 1, source, spare, dest);
                cout << "Hola" << endl;
		        HanoiTowerSolver(disk - 1, spare, dest, source);
            }
        }

        virtual ~ HanoiTowers() {};
};

int main()
{
    int disk = 3;
    int source = 5;
    int dest = 0;
    int spare = 0;

    HanoiTowers *obj1 = new HanoiTowers();
    obj1 -> HanoiTowerSolver(disk, source, dest, spare);
}
