#include<stdio.h>
int IsAscending(int arr[], int size)
{
    int index = 0;
    int flag = 0;
    int index_to_change = 0;
    for( index = 1 ; index < size - 1 ; index++ )
    {
        if( arr[index] < arr[index-1] && arr[index] < arr[index+1] && arr[index+1] >= arr[index-1] )
        {
            flag++;
            index_to_change = index;
        }
        else if( arr[index] >= arr[index-1] && arr[index] > arr[index+1] && arr[index+1] < arr[index-1] )
        {
            flag++;
            index_to_change = index + 1;
        }
        else if( arr[index] > arr[index-1] && arr[index] > arr[index+1] && arr[index+1] >= arr[index-1] )
        {
            flag++;
            index_to_change = index + 1;
        }
        else if( arr[index] < arr[index-1] && arr[index] <= arr[index+1] && arr[index+1] < arr[index-1] )
        {
            flag++;
            index_to_change = index - 1;
        }
        else if( arr[index] >= arr[index-1] && arr[index] <= arr[index+1] && arr[index+1] >= arr[index-1] )
        {}
        else
        {
            return (0);
        }
    }
    if( flag == 1 || flag == 0 )
    {
        if( index_to_change == 0 )
        {
            arr[0] = arr[1];
        }
        else
        {
            arr[index_to_change] = arr[index_to_change-1];
        }
        flag = 0;
    }
    return !flag;
}
int main()
{
    int n, i, k = 0;
    scanf("%d", &n);
    int a[n];
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d", a + i);
    }
    if(IsAscending(a, n))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}
