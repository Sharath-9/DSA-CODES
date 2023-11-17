#include<stdio.h>
#define max 9999
int min(int a,int b)
{
    return (a>b)?b:a;
}
int coin_min(int coin[],int n,int num)
{
    
    /*if(n==0)
        return 0;*/
    if(n==0 && num !=0)
    {
        return max;
    }
    else if(num==0)
        return 0;
    else if(coin[n-1]<=num)
        return min((1+coin_min(coin,n,num-coin[n-1])),coin_min(coin,n-1,num));
    else
        return coin_min(coin,n-1,num);
}

int main()
{
    int n,num;
    printf("\n enter the no of coins ");
    scanf("%d",&n);
    int coin[n];
    printf("\nenter the value of coins");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
    }
    printf("\nEnter the sum value :");
    scanf("%d",&num);
    int result=coin_min(coin,n,num);
    printf("%d are min no of ways",result);
    return 0;
}


