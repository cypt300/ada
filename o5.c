o5

122. Best Time to Buy and Sell Stock II







#include<stdio.h>

int maxProfit(int a[],int n){

    int p=0;

    for(int i=1;i<n;i++)
        if(a[i]>a[i-1])
            p+=a[i]-a[i-1];

    return p;
}

int main(){

    int a[]={7,1,5,3,6,4};

    printf("%d",maxProfit(a,6));

    return 0;
}