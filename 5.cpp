#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }

    //Logic of Selection Sort

    for(int i =0; i<n; i++)
    {
        for(int j =i+1; j<n; j++)
    {
        if(arr[i]>arr[j])
        {
            swap(arr[i],arr[j]);
        }
    }
    }
    cout<<endl<<"Sorted Array :"<<endl ;
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }


}

//This is my favourite code in this course because it's  easy to understand and  write !!
