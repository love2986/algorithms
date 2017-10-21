// 2015005632_JANGHYEJEONG
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[k], b[k], arr[n];
    int * c = (int *)malloc(sizeof(int) * (m+1));
    for(int i=0; i<k; i++)
        scanf("%d %d", &a[i], &b[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<=m; i++)
        c[i] = 0;
    for(int i=0; i<n; i++)
        c[arr[i]] += 1;
    for(int i=1; i<=m; i++)
        c[i] = c[i] + c[i-1];
    for(int i=0; i<k; i++){
        int output;
        if(a[i]==0)
            output = c[b[i]];
        else
            output = c[b[i]]-c[a[i]-1];
        printf("%d", output);
        printf("\n");}
    free(c);
    return 0;
}
