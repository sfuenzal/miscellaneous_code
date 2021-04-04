#include <iostream>
#include <vector>

using namespace std;

class Animals
{
    protected:
        string animal_class, animal_name, food;
    public:
        void input()
        {
            cout << "Please select the class of your animal: " << endl;
            cin >> animal_class;
            
            cout << "Please enter the name of your animal: " << endl;
            cin >> animal_name;
        }
};

class Cat: public Animals
{
    public:
        void input_food_cat()
        {
            if (animal_class == "cat")
            {
                cout << "Class: " << animal_class << ". Name of your animal: " << animal_name << endl;
                cout << "Please feed the cat: " << endl;
            
                do
                {
                    cin >> food;

                    if (food == "meat" || food == "fish")
                    {
                        cout << "The cat is happy with that food (meow!)." << endl;
                    }

                    else
                    {
                        cout << "The cat isn't happy with that food (hiiiis!)." << endl;
                        cout << "Please feed the cat with another food: " << endl; 
                    } 
            
                } while (food != "meat" && food != "fish");
            }
        }
};

class Dog: public Animals
{
    public:
        void input_food_dog()
        {
            if (animal_class == "dog")
            {
                cout << "Class: " << animal_class << ". Name of your animal: " << animal_name << endl;
                cout << "Please feed the dog: " << endl;
            
                do
                {
                    cin >> food;

                    if (food == "meat" || food == "milk")
                    {
                        cout << "The dog is happy with that food (woof!)." << endl;
                    }

                    else
                    {
                        cout << "The dog isn't happy with that food (grrrr!)." << endl;
                        cout << "Please feed the dog with another food: " << endl; 
                    } 
            
                } while (food != "meat" && food != "milk");
            }    
        }
};

//class Rabbit: public Animals
//{

//};

int main()
{
    string initial_election;
    cout << "What animal do you want to create? " << endl;
    cin >> initial_election;
    
    if (initial_election == "cat")
    {    
        Cat cat_object;
        cat_object.input();
        cat_object.input_food_cat();
    }

    else if (initial_election == "dog")
    {
        Dog dog_object;
        dog_object.input();
        dog_object.input_food_dog();
    }
    
    return 0;
}
