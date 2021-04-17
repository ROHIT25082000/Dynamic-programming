#include <iostream> 
#include <bits/stdc++.h>

using namespace std; 

int t[100][100]; 

int count(int n, int arr[], int sum)
{
	if(sum == 0)
		return 1; 
	else if(n == 0)
		return 0;
	if(t[n][sum] != -1)
		return t[n][sum]; 
	else
	{
		if(arr[n-1] > sum)
			return t[n][sum] = count(n-1,arr,sum); 
		else 
			return t[n][sum] = count(n-1,arr,sum-arr[n-1]) + count(n-1,arr,sum); 	
	}
}


int main() 
{
	int n; 
	cout << "Enter n: "; 
	cin >> n; 
	int arr[n]; 
	for(int i = 0; i < n; ++i){cin >> arr[i];} 
	int sum; 
	cout << "Enter the sum : "; 
	cin >> sum; 
	memset(t,-1,sizeof(t)); 
	cout << count(n,arr,sum); 
	return 0; 	
}




