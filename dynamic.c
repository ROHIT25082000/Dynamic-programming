#include<stdio.h>
#include<stdlib.h>

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
        if(k == -1)
            printf("ERROR\n");
        else 
            printf("%d\n",k);
    }
}

int minimumCoins(int a, int b, int c, int w)
{
    int arr[3][10001];
    int coins[3];
    coins[0] = a;
    printf("%d ",coins[0]);
    coins[1] = b;
    printf("%d ",coins[1]);
    coins[2] = c;
    printf("%d \n",coins[2]);
    // starter code 
    arr[0][0] = -1;
    for(int j = 1; j<= w; j++)
    {
        if(j % coins[0] == 0)
        {
            arr[0][j] = j / coins[0];
        }
        else 
        {
            arr[0][j] = -1;
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
            else if(j == coins[i])
            {
                arr[i][j] = 1;
            }
            else 
            {
                int x = arr[i-1][j];
                int y = 1 + arr[i][j-coins[i]];
                if(x == -1 && y==0) // not possible by both 
                {
                    arr[i][j] = -1;
                }
                if(x == -1 && y>0)
                {
                    arr[i][j] = y;  // one sided
                }
                if(x > 0 && y==0)
                {
                    arr[i][j] = x;
                }
                if(x > 0 && y>0)
                {
                    arr[i][j] = min(x,y);
                }
            }
        }
    }
    // the table 
    printf("The table is the \n\n");
    for(int i=0; i<3; i++)
    {
        for(int j = 0; j<= w; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }


    return arr[2][w];
}




































