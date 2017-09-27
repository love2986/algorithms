// 2015005632_장혜정
#include <stdio.h>

int main() {
    int n, key, a[30000];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<n; i++){
        key = a[i];
        for(int j=i-1; j>=0; j--){
            if(a[j]<key){
                a[j+1] = a[j];
            }else{
                break;}
            a[j]=key;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}