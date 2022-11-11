#include <bits/stdc++.h>
using namespace std;
 void merge(int *arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
 int L[n1], M[n2];
 for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
 int i, j, k;
  i = 0;
  j = 0;
  k = p;
 while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
 while (i < n1) {
    arr[k] = L[i];
    i++;
k++;
  }
 while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
 void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, left, mid, right);
  }
}
void sortedArray(int n, int *arr){
    for(int i = 0; i<n; i++){
        arr[i] = i+1;
    }
}
 void randomArray(int n, int *arr){
    for(int i = 0; i < n; i++){
        arr[i] = (rand() % 100) + 1;
    }
}
 void reverseSortedArray(int n, int *arr){
    for(int i = n; i>0; i--){
        arr[n-i] = i;
    } }
 int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        auto st = clock();
        sortedArray(n, arr);
        mergeSort(arr, 0, n);
        auto rt = clock() - st;
     cout<<"Merge sort best case with value of n is " << n  << " : " <<(float)(rt)/CLOCKS_PER_SEC << " seconds"<<endl;
         st = clock();
        randomArray(n, arr);
        mergeSort(arr, 0, n);
        rt = clock() - st;
        cout<<"Merge sort average case with value of n is " << n  << " : " << (float)(rt)/CLOCKS_PER_SEC << " seconds"<<endl;
        st = clock();
        reverseSortedArray(n, arr);
        mergeSort(arr, 0 , n);
        rt = clock() - st;
        cout<<"Merge sort worst case with value of n is " << n  << " : " << (float)(rt)/CLOCKS_PER_SEC << " seconds"<<endl;
        }
 return 0;
}
