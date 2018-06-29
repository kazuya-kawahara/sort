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
        int i, l, u, pivot;
        
        pivot = A[0];  //先頭要素をピボットとする
        for(i = l = 1; i < n; i++){
            if(A[i] < pivot){
                int z = A[l];
                A[l] = A[i];
                A[i] = z;
                l++;
            }
        }
        for(i = u = 1; i <= n-l; i++){
            if(A[n-i] > pivot){
                int z = A[n-u];
                A[n-u] = A[n-i];
                A[n-i] = z;
                u++;
            }
        }
        
        int z = A[l-1];
        A[l-1] = A[0];
        A[0] = z;  //ピボットをピボット以下を寄せ集めた配列の最後尾に移動する
        
        quick_sort(A, l-1);  //ピボット未満を寄せ集めた配列の最後尾(j-1番目)より前の配列(要素数j-2+1)に同様の操作を行う
        quick_sort(A+(n-u+1), u-1);  //ピボットを超過する要素を寄せ集めた配列の先頭(n-u+1番目)以降の配列に同様の操作を行う
        //l-1番目からn-u番目は全てピボットと等しい値なので何も行わない
    }
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
