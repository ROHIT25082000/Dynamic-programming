#include<stdio.h>
#include<stdlib.h>
#define MAX_INT 200000000
int minimumCoins(int a,int b,int c,int w);

int min(int a ,int b)
{
    if(a > b)
        return b;
    else 
        return a;
}

int main()
{
    int k;
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {   
        int a,b,c,w;
        scanf("%d%d%d%d",&a,&b,&c,&w);
        
        k = minimumCoins(a,b,c,w);
        if(k == MAX_INT)
            printf("ERROR\n");
        else 
            printf("%d\n",k);
    }
}
int minimumCoins(int a, int b, int c, int w)
{
    int arr[10001];
    int coins[3];
    coins[0] = a;
    coins[1] = b;
    coins[2] = c; 
    arr[0] = 0;
    for(int i = 1; i <= w ; i++)
    {
        arr[i] = MAX_INT; 
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(coins[i] > j);
            else 
            {
                if(coins[i] == j)
                {
                    arr[j] = 1;
                }
                else if(j > coins[i])
                {
                    arr[j] = min(arr[j], 1+arr[j - coins[i]]);
                }
            }
        }
    }
    return arr[w];
}





 /*for(int j = 1; j<= w; j++)
    {
        if(j % coins[0] == 0)
        {
            arr[0][j] = j / coins[0];
        }
        else 
        {
            arr[0][j] = MAX_INT;
        }
    }
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 0; j<= w ; j++)
        {
            if(coins[i] > j)
            {
                arr[i][j] = arr[i-1][j];
            }
            else if(coins[i] == j)
            {
                arr[i][j] = 1;
            }
            else if(j > coins[i])
            {
                int x = arr[i-1][j];
                int y = 1 + arr[i][j - coins[i]];
                arr[i][j] = min(x,y);
            }
        }
    }*/






























