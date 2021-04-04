#include <iostream>
#include <math.h>

using namespace std;

double function(double x)
{
	if (x > 0) 
	{
		return pow(x, 2);
	}

	else if (x < 0)
	{
		return pow(x, 3);
	}

	else if (x > 1)
	{
		return pow(x, 3);
	}

	return 0;
}

int main(void)
{
	cout << function(8) << endl;
	return 0;
}
