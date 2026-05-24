3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r)
{
    int i=l, j=m+1, k=l, temp[100000];

    while(i<=m && j<=r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while(i<=m) temp[k++] = a[i++];
    while(j<=r) temp[k++] = a[j++];

    for(i=l;i<=r;i++)
        a[i] = temp[i];
}

void mergesort(int a[], int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int n,i,a[100000];
    clock_t start,end;

    printf("Enter n: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        a[i]=rand();   // random numbers

    start=clock();
    mergesort(a,0,n-1);
    end=clock();

    printf("Time taken = %f seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}