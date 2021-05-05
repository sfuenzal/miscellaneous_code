#include <iostream>

using namespace std;

void InputMatrix(unsigned int n, double **A)
{
	for (unsigned int i = 0; i < n; ++i)
	{
		for (unsigned int j = 0; j < n; ++j)
		{
			cin >> A[i][j];
		}	
	}
}

int main()
{
	int n = 2;
	double A[n][n];

	InputMatrix(n, A);

}
