#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
    int i, l, u, pivot;

// 先頭の要素をピボットとする
    pivot = A[0];
    for(i = l = u = 1; i <= n-u; i++){
        if(A[i] < pivot){
            int z = A[l];
            A[l] = A[i];
            A[i] = z;
            l++;
        }
        if(A[i] > pivot){
            int z = A[n-u];
            A[n-u] = A[i];
            A[i] = z;
            u++;
        }
    }
    
    if((l <= k+1)&&(k+1 <= n-u)) return pivot;
    else if(k+1 < l) return quick_select(A+1, l-1, k);
    else if(n-u < k+1) return quick_select(A+(n-u+1), u-1, k-(n-u+1));
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
