//2015005632_장혜정
#include <stdio.h>

void MAX_HEAPIFY(int a[], int i, int length){
    int l = 2*i+1, tmp;
    int r = l+1;
    int largest = i;
    if(l<=length-1 && a[l]>a[i])
        largest = l;
    if(r<=length-1 && a[r]>a[largest])
        largest = r;
    if(largest != i){
        tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        MAX_HEAPIFY(a, largest, length);
    }
}
void HEAP_SORT(int a[], int n){
    int tmp = a[n];
    a[n] = a[0];
    a[0] = tmp;
    MAX_HEAPIFY(a, 0, n-1);
}
void BUILD_MAX_HEAP(int a[], int n){
    for(int i=n/2-1; i>=0; i--){
        MAX_HEAPIFY(a, i, n);
    }
}
int main(){
    int n, a[100000], k;
    scanf("%d %d", &n, &k);
    if(k>n)
        k=n;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    BUILD_MAX_HEAP(a, n);
    for(int i=0; i<k; i++){
        HEAP_SORT(a, n-1);
        n--;
    }
    for(int i=n+k-1; i>=n; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    return 0;
}