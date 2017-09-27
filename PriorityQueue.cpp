//2015005632_장혜정
#include <stdio.h>
#include <stdlib.h>

void INSERT(int heap[], int cur){
    while( (cur > 1) && ( (heap[cur] >= heap[(cur/2)]) ) ){ // compare with parent node
        int tmp = heap[cur];
        heap[cur] = heap[(cur/2)];
        heap[(cur/2)] = tmp;
        cur = cur/2;
    }
}
void MAX_HEAPIFY(int heap[], int i, int length){
    int l = 2*i;
    int r = l+1;
    int tmp;
    int largest = i;
    if(l<=length && heap[l]>=heap[i])
        largest = l;
    if(r<=length && heap[r]>=heap[largest])
        largest = r;
    if(largest != i){
        tmp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = tmp;
        MAX_HEAPIFY(heap, largest, length);
    }
}
void RE_HEAPIFY(int heap[], int cur, int len){
    int j = cur;
    while( (cur > 1) && ( (heap[cur] >= heap[(cur/2)]) ) ){ // compare with parent node
        int tmp = heap[cur];
        heap[cur] = heap[(cur/2)];
        heap[(cur/2)] = tmp;
        cur = cur/2;
    }
    MAX_HEAPIFY(heap, j, len); // In MAX_HEAPIFY, the node is compared with the child nodes and if they need swapping, they swap
}
int main(){
    int a[500000];
    int * heap = (int *)malloc(sizeof(int)*(100000));
    int i, p;
    int k=0;
    int heap_index = 1; // heap index starts from 1
    for(i=0; i<500000; i++){
        scanf("%d", &a[i]);
        if (a[i] == 0)
            break;
    }
    p=i+1;
    while(k<i){
        if(a[k] == 1){ // insert
            heap[heap_index] = a[k+1];
            INSERT(heap, heap_index);
            heap_index++;
            k = k+2;
            
        }else if(a[k] == 2){ // extract max
            if(heap_index > 1){
                a[p++] = heap[1];
                heap[1] = heap[--heap_index];
                MAX_HEAPIFY(heap, 1, heap_index-1);
            }
            k = k+1;
            
        }else if(a[k] == 3){ // substitute third int for the element indexed by the second int
            int inc = a[k+1];
            if(inc>=heap_index)
                heap[heap_index-1] = a[k+2];
            else
                heap[inc] = a[k+2];
            RE_HEAPIFY(heap, inc, heap_index-1);
            k = k+3;
            
        }
    }
    for(int j=i+1; j<p; j++){
        printf("%d ", a[j]);
    }
    printf("\n");
    for(int j = 1; j<heap_index; j++){
        printf("%d ", heap[j]);
    }
    free(heap);
    return 0;
}
