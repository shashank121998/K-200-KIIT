#include<stdio.h>
int findElement(int *a, int n)
{
    int right_sum = 0, left_sum = 0, i, j;
    for( i = 0, j = n - 1 ; i < j ; i++, j-- )
    {
        left_sum += a[i];
        right_sum += a[j];
        while( left_sum < right_sum && i < j )
        {
            i++;
            left_sum += a[i];
        }
        while( right_sum < left_sum && i < j )
        {
            j--;
            right_sum += a[j];
        }
    }
    if( left_sum == right_sum && i == j )
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n, i;
    printf("Enter the Length of the Array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Array Elements :\n");
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d", a + i);
    }
    printf("The Required Index of the Array Element is = %d", findElement(a, n));
    return 0;
}
