#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,6};
    int sum=0, left=0, right=0, pivot=INT_MAX, pivIndex = -1;
    int size= sizeof(arr)/sizeof(arr[0]);
    for(int i=0 ; i<size ; i++)
        sum+=arr[i];
    for(int i=0 ; i<size ; i++)  
    {
        if(i==0)
            left = 0;
        else
            left+=arr[i-1];
        right = sum-left-arr[i];
        if(left==right)
        {
            if(pivot>arr[i])
            {
                pivot = arr[i]; 
                pivIndex = i;
            }
        }
    }

    cout<<pivIndex<<endl;
    return 0;
}
