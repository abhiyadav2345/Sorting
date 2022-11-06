#include <iostream>
#include <ctime>
using namespace std;
//------------------------------------------------------Array creation------------------------------------------
// best case
void bestCase(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
// worst case
void worstCase(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}
// average case
void averageCase(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = rand() % n;
        
        arr[i] = m;
    }
}

void reverseSortedArray(int n, int *arr){
    for(int i = n; i>0; i--){
        arr[n-i] = i;
    } }


//----------------------------------------------------Array creation end---------------------------------------------

int main(){
    
}