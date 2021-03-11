// A Dynamic Programming based
// C++ program to partition problem
#include <bits/stdc++.h>
using namespace std;

// Returns true if arr[] can be partitioned
// in two subsets of equal sum, otherwise false
void findPartiion(int arr[], int n)
{
	int sum = 0;
	int i, j;

	// Calculate sum of all elements
	sum=4;

	int part[n + 1][sum + 1];

	// initialize top row as true
	for (i = 0; i <= sum; i++)
		part[0][i] = 0;

	// initialize leftmost column,
	// except part[0][0], as 0
	for (i = 0; i <= n; i++)
		part[i][0] = 1;

	// Fill the partition table in bottom up manner
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= sum; j++) {
			if (j >= arr[i-1])
				part[i][j] = part[i-1][j] +  part[i][j - arr[i - 1]];
			else 
				part[i][j] = part[i-1][j];			
		}
	}

	 // uncomment this part to print table
	for (i = 0; i <= n; i++)
	{
	for (j = 0; j <= sum; j++)
		cout<<part[i][j]<<"\t";
	cout<<endl;
	} 

	return ;//part[sum][n];
}

// Driver Code
int main()
{
	int arr[] = { 1,2,3 };
	int n = 3;
	
	// Function call
	findPartiion(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra

