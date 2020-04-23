/*
int myfunc(int n);
int main()
{
	int n;
	printf("Enter the number of bits :");
	scanf("%d", &n);
	printf("%d", myfunc(n));
}
int myfunc(int n)
{
	if (n == 0)
		return 0;
	else
	{
		int *arr = (int *)malloc(sizeof(int) * (n + 1));
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = 1;
		for (int i = 4; i <= n; i++)
		{
			arr[i] = 2 * arr[i - 1] + pow(2, i - 4) - arr[i - 4];
		}
		return arr[n];
	}
}

#include <stdio.h>
#include <math.h>

long long int threeConsecutiveOnes(int n, long long int *dp)
{
	if (!dp[n] && n >= 3)
	{
		if (n == 3)
		{
			dp[n] = 1;
		}
		else
		{
			dp[n] = (2 * threeConsecutiveOnes(n - 1, dp)) + (long long int)pow(2, n - 4) - threeConsecutiveOnes(n - 4, dp);
		}
	}
	return dp[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	long long int dp[700] = {0};
	printf("%lld\n", threeConsecutiveOnes(n, dp));
	return 0;
}

2)*/

#include <stdio.h>
#include <limits.h>
 

int main()
{
	int t, a, b, c, n;
	scanf("%d", &t);
	while (t--)
	{
		int coins[3];
		for (int i = 0; i < 3; i++)
			scanf("%d", &coins[i]);
		scanf("%d", &n);
		// for(int i=0;i<3;i++)
		// printf("coin: %d\n",coins[i]);
		// printf("started here with n as %d\n",n);
		int v[3][100001];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				v[i][j] = INT_MAX - 2;
				// printf("%d\t",v[i][j]);
			}
			// printf("\n");
		}
		v[0][0] = 0;
		// printf("initially it was the above\n");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (coins[i] > j)
				{
					if (i > 0)
						v[i][j] = v[i - 1][j];
				}
				else
				{
					if (i == 0)
					{
						if (v[i][j - coins[i]] >= (INT_MAX - 4))
							continue;
						v[i][j] = 1 + v[i][j - coins[i]];
					}
					else if (v[i - 1][j] > (1 + v[i][j - coins[i]]))
					{
						v[i][j] = 1 + v[i][j - coins[i]];
					}
					else
					{
						v[i][j] = v[i - 1][j];
					}
				}
			}
		}
		if (v[2][n] != (INT_MAX - 2))
			printf("%d\n", v[2][n]);
		else
			printf("ERROR\n");
		/*int res= minimumCoinBottomUp(n,coins);
if(res==INT_MAX-1)
printf("ERROR\n");
else
printf("%d\n", res);*/
	}
	return 0;
}
