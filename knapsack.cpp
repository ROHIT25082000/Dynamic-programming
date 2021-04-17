#include <iostream> 

using namespace std; 


static int t[10][10] = {-1};
int knapsack(int W, int wt[], int val[], int n) 
{
	if(n == 0 || W == 0)
		return 0; 
	else
	{	
		if(t[n][W] != -1){
			return t[n][W];
		}
		if(wt[n-1] > W){
			return t[n][W] = knapsack(W,wt,val,n-1); 
		}
		else { 
			return max(val[n-1] + knapsack(W-val[n-1],wt,val,n-1), knapsack(W,wt,val,n-1)); 
		}
	}
}

int main() 
{	
	int wt[] = {1, 3, 4, 5, 8}; 
	int val[] = {1, 3, 22, 9, 7}; 
	int W = 14;
	int n = 5;  

	cout << "The maximum profit : " << knapsack(W,wt,val,n); 
	
	return 0; 	
}


