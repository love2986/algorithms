//2015005632_JANGHYEJEONG
#include <stdio.h>
#include <string.h>
int main(){
    char a[500];
    char b[500];
    char swap[500];
    scanf("%s", a);
    scanf("%s", b);
    int la = strlen(a);
    int lb = strlen(b);
    if(lb > la){
        strcpy(swap, a);
        strcpy(a, b);
        strcpy(b, swap);
    }
    int t[lb+1][la+1];
    int arrow[lb][la]; // ↑ : 1, ← : 2, ↖ : 3
    for(int i=0; i<=la; i++)
        t[0][i] = 0;
    for(int i=1; i<=lb; i++)
        t[i][0] = 0;
    
    for(int i=1; i<=lb; i++){
        for(int j=1; j<=la; j++){
            if(a[j-1] == b[i-1]){
                t[i][j] = t[i-1][j-1] + 1;
                arrow[i-1][j-1] = 3;
                
            }else if(t[i][j-1] <= t[i-1][j]){
                t[i][j] = t[i-1][j];
                arrow[i-1][j-1] = 1;
                
            }else if(t[i-1][j] < t[i][j-1]){
                t[i][j] = t[i][j-1];
                arrow[i-1][j-1] = 2;
            }
        }
    }
    char output[500];
    int i=0;
    while(((lb-1) != 0) && ((la-1) != 0)){
        if(arrow[lb-1][la-1] == 1){
            lb--;
        }else if(arrow[lb-1][la-1] == 2){
            la--;
        }else{
            output[i] = b[lb-1];
            lb--;
            la--;
            i++;
        }
    }
    output[i] = b[lb-1];
    for(int j=i; j>=0; j--)
        printf("%c", output[j]);
    printf("\n");
    return 0;
}

