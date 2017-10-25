//2015005632_JANGHYEJEONG
#include <stdio.h>

int main(){
    int n, time, l_last; // n = # station
    int e1, e2; // entry time
    int x1, x2; // exit time
    scanf("%d", &n);
    scanf("%d %d", &e1, &e2);
    scanf("%d %d", &x1, &x2);
    int a1[n+1], a2[n+1], t1[n], t2[n];
    int s1[n+1], s2[n+1], l1[n+1], l2[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d", &a1[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &a2[i]);
    for(int i=1; i<=(n-1); i++)
        scanf("%d", &t1[i]);
    for(int i=1; i<=(n-1); i++)
        scanf("%d", &t2[i]);
    s1[1] = e1 + a1[1];
    s2[1] = e2 + a2[1];
    for(int i=2; i<=n; i++){
        if(s1[i-1] + a1[i] <= s2[i-1] + t2[i-1] + a1[i]){
            s1[i] = s1[i-1] + a1[i];
            l1[i] = 1;
        }else{
            s1[i] = s2[i-1] + t2[i-1] + a1[i];
            l1[i] = 2;
        }
        if(s2[i-1] + a2[i] <= s1[i-1] + t1[i-1] + a2[i]){
            s2[i] = s2[i-1] + a2[i];
            l2[i] = 2;
        }else{
            s2[i] = s1[i-1] + t1[i-1] + a2[i];
            l2[i] = 1;
        }
    }
    if(s1[n] + x1 <= s2[n] + x2){
        time = s1[n] + x1;
        l_last = 1;
    }else{
        time = s2[n] + x2;
        l_last = 2;
    }
    printf("%d\n", time);
    int l_inc[n+1];
    for(int i=n+1; i>=2; i--){
        if(l_last == 1){
            l_last = l1[i-1];
            l_inc[i-1] = 1;
        }else{
            l_last = l2[i-1];
            l_inc[i-1] = 2;
        }
    }
    for(int i=1; i<=n; i++)
        printf("%d %d\n", l_inc[i], i);
    return 0;
}

