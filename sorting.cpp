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

void reverseSortedArray(int n, int *arr)
{
    for (int i = n; i > 0; i--)
    {
        arr[n - i] = i;
    }
}

//----------------------------------------------------Array creation end---------------------------------------------

//---------------------------------------------------Insertion Sort-------------------------------------------------

/* Algo

*/
void insertsort(int *arr, int len)
{

    for (int j = 1; j < len; j++)
    {
        int key = arr[j];

        int i = j - 1;

        while (i >= 0 && arr[i] > key)
        {

            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

//---------------------------------------------------Insertion Sort End-------------------------------------------------

//---------------------------------------------------Selection Sort-------------------------------------------------
/* Algo

*/
void selectionSort(int *array, int size)
{
    int i, j, imin;
    for (i = 0; i < size - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[imin])
                imin = j;
        swap(array[i], array[imin]);
    }
}

//---------------------------------------------------Selection Sort End-------------------------------------------------

//---------------------------------------------------Merge Sort-------------------------------------------------
/* Algo

*/
void merge(int *arr, int p, int q, int r)
{
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
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//---------------------------------------------------Merge Sort End-------------------------------------------------

//---------------------------------------------------Radix Sort-------------------------------------------------
/* Algo

*/
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
//---------------------------------------------------Radix Sort End-------------------------------------------------

//--------------------------------------------------Bubble Sort-------------------------------------------------
/* Algo

*/

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

//---------------------------------------------------Bubble Sort End-------------------------------------------------

int main()
{

    clock_t t;

    int len, opt;
    cout << "-----------------------------Array Sorting-----------------------------\n";

    int arr[50000];

    cout << "****************************SELECT FROM OPTION.****************************\n";
    cout << "1. Insertion Sort\n2. Selection Sort\n3. Merge Sort\n4.Radix Sort\n5. Bubble Sort\nEnter 1/2/3/4/5: ";

    cin >> opt;

    switch (opt)
    {
        //-----------------------------------------------------Insertion Sort--------------------------------
    case 1:
        //------------------------------------Size of Array 50000-------------------------------------------
        cout << "Size of Array : 50000" << endl;
        cout << "Best, Average and Worst Case for insertion sort" << endl;

        /* Best Case*/
        bestCase(arr, 50000);
        t = clock();
        insertsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for best case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 50000);
        t = clock();
        insertsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Average case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 50000);
        t = clock();
        insertsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Worst case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 25000-------------------------------
        cout << "\nSize of Array : 25000" << endl;
        cout << "Best, Average and Worst Case for insertion sort" << endl;

        /* Best Case*/
        bestCase(arr, 25000);
        t = clock();
        insertsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for best case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 25000);
        t = clock();
        insertsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Average case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 25000);
        t = clock();
        insertsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Worst case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------ Size of Array 10000---------------------------------------
        cout << "\nSize of Array : 10000" << endl;
        cout << "Best, Average and Worst Case for insertion sort" << endl;

        /* Best Case*/
        bestCase(arr, 10000);
        t = clock();
        insertsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for best case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 10000);
        t = clock();
        insertsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Average case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 10000);
        t = clock();
        insertsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Worst case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        // ---------------------------------------------------Size of Array 5000-----------------------------------------
        cout << "\nSize of Array : 5000" << endl;
        cout << "Best, Average and Worst Case for insertion sort" << endl;

        /* Best Case*/
        bestCase(arr, 5000);
        t = clock();
        insertsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for best case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 5000);
        t = clock();
        insertsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Average case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 5000);
        t = clock();
        insertsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Worst case in insertion sort: " << (float)t / CLOCKS_PER_SEC << endl;

        break;
        //--------------------------------------------------insertion Sort End-------------------------------------------------
        //---------------------------------------------------Selection Sort-------------------------------------------------
    case 2:
        //------------------------------------Size of Array 50000-------------------------------------------
        cout << "Size of Array : 50000" << endl;
        cout << "Best, Average and Worst Case for Selection sort" << endl;

        /* Best Case*/
        bestCase(arr, 50000);
        t = clock();
        selectionSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for best case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 50000);
        t = clock();
        selectionSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Average case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 50000);
        t = clock();
        selectionSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Worst case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 25000-------------------------------
        cout << "\nSize of Array : 25000" << endl;
        cout << "Best, Average and Worst Case for Selection sort" << endl;

        /* Best Case*/
        bestCase(arr, 25000);
        t = clock();
        selectionSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for best case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 25000);
        t = clock();
        selectionSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Average case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 25000);
        t = clock();
        selectionSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Worst case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 10000-------------------------------
        cout << "\nSize of Array : 10000" << endl;
        cout << "Best, Average and Worst Case for Selection sort" << endl;

        /* Best Case*/
        bestCase(arr, 10000);
        t = clock();
        selectionSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for best case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 10000);
        t = clock();
        selectionSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Average case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 10000);
        t = clock();
        selectionSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Worst case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 5000-------------------------------
        cout << "\nSize of Array : 5000" << endl;
        cout << "Best, Average and Worst Case for Selection sort" << endl;

        /* Best Case*/
        bestCase(arr, 5000);
        t = clock();
        selectionSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for best case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 5000);
        t = clock();
        selectionSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Average case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 5000);
        t = clock();
        selectionSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Worst case in Selection sort: " << (float)t / CLOCKS_PER_SEC << endl;
        break;

        //---------------------------------------------------Selection Sort end-------------------------------------------------

        //---------------------------------------------------Merge Sort-------------------------------------------------
    case 3:
        //------------------------------------Size of Array 50000-------------------------------------------
        cout << "Size of Array : 50000" << endl;
        cout << "Best, Average and Worst Case for Merge sort" << endl;

        /* Best Case*/
        bestCase(arr, 50000);
        t = clock();
        mergeSort(arr, 0, 50000);
        t = clock() - t;
        cout << "time taken for best case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 50000);
        t = clock();
        mergeSort(arr, 0, 50000);
        t = clock() - t;
        cout << "time taken for Average case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 50000);
        t = clock();
        mergeSort(arr, 0, 50000);
        t = clock() - t;
        cout << "time taken for Worst case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 25000-------------------------------
        cout << "\nSize of Array : 25000" << endl;
        cout << "Best, Average and Worst Case for Merge sort" << endl;

        /* Best Case*/
        bestCase(arr, 25000);
        t = clock();
        mergeSort(arr, 0, 25000);
        t = clock() - t;
        cout << "time taken for best case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 25000);
        t = clock();
        mergeSort(arr, 0, 25000);
        t = clock() - t;
        cout << "time taken for Average case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 25000);
        t = clock();
        mergeSort(arr, 0, 25000);
        t = clock() - t;
        cout << "time taken for Worst case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 10000-------------------------------
        cout << "\nSize of Array : 10000" << endl;
        cout << "Best, Average and Worst Case for Merge sort" << endl;

        /* Best Case*/
        bestCase(arr, 10000);
        t = clock();
        mergeSort(arr, 0, 10000);
        t = clock() - t;
        cout << "time taken for best case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 10000);
        t = clock();
        mergeSort(arr, 0, 10000);
        t = clock() - t;
        cout << "time taken for Average case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 10000);
        t = clock();
        mergeSort(arr, 0, 10000);
        t = clock() - t;
        cout << "time taken for Worst case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 5000-------------------------------
        cout << "\nSize of Array : 5000" << endl;
        cout << "Best, Average and Worst Case for Merge sort" << endl;

        /* Best Case*/
        bestCase(arr, 5000);
        t = clock();
        mergeSort(arr, 0, 5000);
        t = clock() - t;
        cout << "time taken for best case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 5000);
        t = clock();
        mergeSort(arr, 0, 5000);
        t = clock() - t;
        cout << "time taken for Average case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 5000);
        t = clock();
        mergeSort(arr, 0, 5000);
        t = clock() - t;
        cout << "time taken for Worst case in Merge sort: " << (float)t / CLOCKS_PER_SEC << endl;

        break;
        //---------------------------------------------------Merge Sort End-------------------------------------------------

        //---------------------------------------------------Radix Sort-------------------------------------------------

    case 4:
        //------------------------------------Size of Array 50000-------------------------------------------
        cout << "Size of Array : 50000" << endl;
        cout << "Best, Average and Worst Case for Radix sort" << endl;

        /* Best Case*/
        bestCase(arr, 50000);
        t = clock();
        radixsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for best case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 50000);
        t = clock();
        radixsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Average case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 50000);
        t = clock();
        radixsort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Worst case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 25000-------------------------------
        cout << "\nSize of Array : 25000" << endl;
        cout << "Best, Average and Worst Case for Radix sort" << endl;

        /* Best Case*/
        bestCase(arr, 25000);
        t = clock();
        radixsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for best case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 25000);
        t = clock();
        radixsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Average case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 25000);
        t = clock();
        radixsort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Worst case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 10000-------------------------------
        cout << "\nSize of Array : 10000" << endl;
        cout << "Best, Average and Worst Case for Radix sort" << endl;

        /* Best Case*/
        bestCase(arr, 10000);
        t = clock();
        radixsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for best case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 10000);
        t = clock();
        radixsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Average case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 10000);
        t = clock();
        radixsort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Worst case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 5000-------------------------------
        cout << "\nSize of Array : 5000" << endl;
        cout << "Best, Average and Worst Case for Radix sort" << endl;

        /* Best Case*/
        bestCase(arr, 5000);
        t = clock();
        radixsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for best case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 5000);
        t = clock();
        radixsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Average case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 5000);
        t = clock();
        radixsort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Worst case in Radix sort: " << (float)t / CLOCKS_PER_SEC << endl;

        break;

        //---------------------------------------------------Radix Sort End-------------------------------------------------

        //---------------------------------------------------Bubble Sort-------------------------------------------------
    case 5:
        //------------------------------------Size of Array 50000-------------------------------------------
        cout << "Size of Array : 50000" << endl;
        cout << "Best, Average and Worst Case for Bubble sort" << endl;

        /* Best Case*/
        bestCase(arr, 50000);
        t = clock();
        bubbleSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for best case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 50000);
        t = clock();
        bubbleSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Average case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 50000);
        t = clock();
        bubbleSort(arr, 50000);
        t = clock() - t;
        cout << "time taken for Worst case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 25000-------------------------------
        cout << "\nSize of Array : 25000" << endl;
        cout << "Best, Average and Worst Case for Bubble sort" << endl;

        /* Best Case*/
        bestCase(arr, 25000);
        t = clock();
        bubbleSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for best case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 25000);
        t = clock();
        bubbleSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Average case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 25000);
        t = clock();
        bubbleSort(arr, 25000);
        t = clock() - t;
        cout << "time taken for Worst case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 10000-------------------------------
        cout << "\nSize of Array : 10000" << endl;
        cout << "Best, Average and Worst Case for Bubble sort" << endl;

        /* Best Case*/
        bestCase(arr, 10000);
        t = clock();
        bubbleSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for best case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 10000);
        t = clock();
        bubbleSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Average case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 10000);
        t = clock();
        bubbleSort(arr, 10000);
        t = clock() - t;
        cout << "time taken for Worst case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        //------------------------------------------------------- Size of Array 5000-------------------------------
        cout << "\nSize of Array : 5000" << endl;
        cout << "Best, Average and Worst Case for Bubble sort" << endl;

        /* Best Case*/
        bestCase(arr, 5000);
        t = clock();
        bubbleSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for best case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Average*/
        averageCase(arr, 5000);
        t = clock();
        bubbleSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Average case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        /* Worst */
        worstCase(arr, 5000);
        t = clock();
        bubbleSort(arr, 5000);
        t = clock() - t;
        cout << "time taken for Worst case in Bubble sort: " << (float)t / CLOCKS_PER_SEC << endl;

        break;
        //---------------------------------------------------Bubble Sort End-------------------------------------------------
    default:

        break;
    }
}