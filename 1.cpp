#include<bits/stdc++.h>//Preprocessor Command/Detector
#include <iostream>

using namespace std ;// Using Declaration
int n;
// Bubble sort Start
void bubble_sort(int Arr[])
{
    for(int i=0; i<n; i++)
    {
        for(int j =0; j<n-1-i; j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                int temp = Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
    }
}

// Insertion sort Start

void insert_sort(int Arr[])
{
    for(int i=1; i<n; i++)
    {
        int temp = Arr[i];
        int j=i-1;
        while(j>=0 && Arr[j]>temp)
        {
            Arr[j+1]= Arr[j];
            j--;
        }
        Arr[j+1] = temp;
    }
}

// Selection sort Start


void select_sort(int ARR[])
{
    for(int i =0;  i<n; i++)
    {
        for(int j =i+1; j<n; j++)
        {
            if(ARR[i]>ARR[j])
            {
                swap(ARR[i],ARR[j]);
            }
        }
    }
}

// Quick sort Start

//This part is for partition
int Partition(int arr[], int l, int h)
{
    int pi = arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(arr[i]<= pi)
        {
            i++;
        }
        while(arr[j]> pi)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

//this is sorting

void quick_sort(int arr[], int l, int h)
{
    if(l<h)
    {
        int j= Partition(arr,l,h);
        quick_sort( arr, l, j-1);
        quick_sort( arr, j+1, h);

    }
}


// Merge sort Start


void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second half
        mergeSort(arr, l, m); //first half
        mergeSort(arr, m + 1, r); //second half

        // Merge the sorted half
        Merge(arr, l, m, r);
    }
}







int main() //main function
{
    cin>>n;
    int arrB[n],arrS[n],arrI[n],arrQ[n],arrM[n];

    cout<<"Enter the array for Bubble sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cin>>arrB[i];
    }
    cout<<"Enter the array for Selection sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cin>>arrS[i];
    }
    cout<<"Enter the array for Indertion sort: "<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>arrI[i];
    }
    cout<<"Enter the array for Quick sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cin>>arrQ[i];
    }
    cout<<"Enter the array for Merge sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cin>>arrM[i];
    }


    bubble_sort(arrB);

    cout<<"This is the result of Bubble sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cout<<arrB[i]<<" ";
    }
    cout<<endl;
    select_sort(arrS);
    cout<<"This is the result of selection sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cout<<arrS[i]<<" ";
    }
    cout<<endl;

    quick_sort(arrQ,0,n-1);
    cout<<"This is the result of Quick sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cout<<arrQ[i]<<" ";
    }
    cout<<endl;

    insert_sort(arrI);
    cout<<"This is the result of Insertion sort: "<<endl;
    for(int i =0;  i<n; i++)
    {
        cout<<arrI[i]<<" ";
    }
    cout<<endl;

    cout<<"This is the result of Merge sort: "<<endl;

    mergeSort(arrM, 0, n - 1);
    for(int i =0;  i<n; i++)
    {
        cout<<arrM[i]<<" ";
    }

    cout<<endl;


    return 0;// means program successfully executed

}

