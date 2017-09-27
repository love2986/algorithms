//2015005632_장혜정
#include <stdio.h>
#include <stdlib.h>
void MERGE(int a[], int left, int mid, int right){
    int * temparr = (int *)malloc(sizeof(int) * (right-left+1));
    int sec_mid = mid+1;
    int i;
    int index_temp=0;
    int index_a = left;
    
    while(left<=mid && sec_mid<=right){
        temparr[index_temp++] = (a[left] > a[sec_mid]) ? a[left++] : a[sec_mid++];
    }
    if(left > mid){
        for(i=sec_mid; i<=right; i++){
            temparr[index_temp] = a[i];
            index_temp++;
        }
    }else{
        for(i=left; i<=mid; i++){
            temparr[index_temp] = a[i];
            index_temp++;
        }
    }
    for(i=index_a; i<=right; i++){
        a[i] = temparr[i-index_a];
    }
    free(temparr);
}
void MERGE_SORT(int a[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        MERGE_SORT(a, left, mid);
        MERGE_SORT(a, mid+1, right);
        MERGE(a, left, mid, right);
    }
}

int main() {
    int n, a[100000];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    MERGE_SORT(a, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
}