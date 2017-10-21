// 2015005632_JANGHYEJEONG
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, m; // n is the length of set A // m is the length of set B
    int output = 0;
    int * c = (int *)malloc(sizeof(int)*100001);    
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);
    for(int i=0; i<=100000; i++)
        c[i]=0;
    for(int i=0; i<n; i++)
        c[a[i]]+=1;
    for(int i=0; i<m; i++)
        c[b[i]]+=1;
    for(int i=0; i<=100000; i++){
        if(c[i]>=2)
            output+=1;
    }
    printf("%d", output);
    return 0;
}
