#include <iostream>
#include <vector>
#include <string>

using namespace std;


class HeroInformation
{
    private:
        string hero_name;

    protected:
        int hero_race;
        string hero_race_string;
    
    public:        
        void InputHeroInformation()
        {
            cout << "Please enter the name of your hero: " << endl;
            cin >> hero_name;

            cout << "Plese select the race of your hero (1: Orc, 2: Human, 3: Undead, 4: Night Elves): " << endl;
            cin >> hero_race;
        }

        void DisplayHeroInformation()
        {
            cout << "Name of your hero: " << hero_name << endl;

            if (hero_race == 1) {cout << "Race of your hero: " << "Orc" << endl;}
            
            else if (hero_race == 2) {cout << "Race of your hero: " << "Human" << endl;}

            else if (hero_race == 3) {cout << "Race of your hero: " << "Undead" << endl;}

            else if (hero_race == 4) {cout << "Race of your hero: " << "Night Elves" << endl;}
        }
};

class InitialResources: public HeroInformation
{
    protected:
        vector<int> resources = {100, 100, 100, 100};
        vector<string> name_resources = {"wood", "gold", "stone", "food"};
    
    public:
        void DisplayInitialResources()
        {
            cout << "Your initial resources are: " << endl;

            for (unsigned int i = 0; i < resources.size(); ++i)
            {
                cout << name_resources[i] << " = " << resources[i] << endl;
            }    
        }
};

class Buildings: public HeroInformation
{
    private:
        vector<string> name_of_buildings_orcs = {"Orc Burrow", "War Mill", "Barracks", "Watch Tower"};
        vector<string> name_of_buildings_humans = {"Farm", "Blacksmith", "Barracks", "Scout Tower"};
        vector<string> name_of_buildings_undeads = {"Ziggurat", "Graveyard", "Crypt", "Nerubian Tower"};    
        vector<string> name_of_buildings_night_elves = {"Ziggurat", "Graveyard", "Crypt", "Nerubian Tower"};
    public:
        
        Buildings(int c1) {hero_race = c1;}
        
        void ShowPossibleBuildings()
        {
            if (hero_race == 1)
            {
                for (unsigned int i = 0; i < name_of_buildings_orcs.size(); ++i)
                {
                    cout << name_of_buildings_orcs[i] << endl;
                }
            }

            else if (hero_race == 2)
            {
                for (unsigned int i = 0; i < name_of_buildings_humans.size(); ++i)
                {
                    cout << name_of_buildings_humans[i] << endl;
                }
            }

            else if (hero_race == 3)
            {
                for (unsigned int i = 0; i < name_of_buildings_undeads.size(); ++i)
                {
                    cout << name_of_buildings_undeads[i] << endl;
                }
            }

            else if (hero_race == 4)
            {
                for (unsigned int i = 0; i < name_of_buildings_night_elves.size(); ++i)
                {
                    cout << name_of_buildings_night_elves[i] << endl;
                }
            }
        }
};

int main()
{
    HeroInformation obj1;
    obj1.InputHeroInformation();
    obj1.DisplayHeroInformation();
    
    InitialResources obj2;
    obj2.DisplayInitialResources();
    
    int display_constructions_constant;
    cout << "What constructions do you want to display (1: Orc, 2: Human, 3: Undead, 4: Night Elves)?" << endl;
    cin >> display_constructions_constant;
    
    Buildings obj3(display_constructions_constant);
    obj3.ShowPossibleBuildings();
}