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
			return max(val[n-1] + knapsack(W-val[n-1],wt,val,n), knapsack(W,wt,val,n-1)); 
		}
	}
}

int main() 
{	
	
}


