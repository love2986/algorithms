//2015005632_장혜정
#include <stdio.h>

int main() {
    int n, a[30000], step, temp, min_index;
    scanf("%d %d", &n, &step);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<step; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(a[min_index]>a[j]){
                min_index = j;
            }
        }
        temp = a[min_index];
        a[min_index] = a[i];
        a[i] = temp;
    }
    
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}