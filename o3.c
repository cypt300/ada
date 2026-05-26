o3

215. Kth Largest Element in an Array









#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int part(int a[],int l,int r){
    int p=a[r],i=l;

    for(int j=l;j<r;j++)
        if(a[j]>p)
            swap(&a[i++],&a[j]);

    swap(&a[i],&a[r]);

    return i;
}

int kth(int a[],int n,int k){
    int l=0,r=n-1;

    while(1){
        int p=part(a,l,r);

        if(p==k-1) return a[p];
        else if(p>k-1) r=p-1;
        else l=p+1;
    }
}

int main(){
    int a[]={3,2,1,5,6,4};

    printf("%d",kth(a,6,2));

    return 0;
}