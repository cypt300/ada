o2

278. First Bad Version



#include<stdio.h>

int bad=4;

int isBadVersion(int x){
    return x>=bad;
}

int firstBadVersion(int n){
    int l=1,r=n;

    while(l<r){
        int m=l+(r-l)/2;

        if(isBadVersion(m))
            r=m;
        else
            l=m+1;
    }

    return l;
}

int main(){
    printf("%d",firstBadVersion(5));

    return 0;
}