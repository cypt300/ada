o1

35. Search Insert Position



#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int l=0,r=numsSize-1;

    while(l<=r){
        int m=(l+r)/2;

        if(nums[m]==target) return m;
        else if(nums[m]<target) l=m+1;
        else r=m-1;
    }

    return l;
}

int main(){
    int nums[]={1,3,5,6};
    int target=5;
    int n=sizeof(nums)/sizeof(nums[0]);

    printf("%d",searchInsert(nums,n,target));

    return 0;
}