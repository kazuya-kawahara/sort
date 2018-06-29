#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if(n <= 1){
        //配列の要素数が0or1の場合何も行わない
    }
    else{
        int i, j, pivot;
        
        pivot = A[0];  //先頭要素をピボットとする
        for(i = j = 1; i < n; i++){
            if(A[i] <= pivot){
                int z = A[j];
                A[j] = A[i];
                A[i] = z;
                j++;
            }
        }
        
        int z = A[j-1];
        A[j-1] = A[0];
        A[0] = z;  //ピボットをピボット以下を寄せ集めた配列の最後尾に移動する
        
        quick_sort(A, j-1);  //ピボット以下を寄せ集めた配列の最後尾(j-1番目)以前の配列(要素数j-2+1)に同様の操作を行う
        quick_sort(A+j, n-j);  //残りについても同様
    }
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
