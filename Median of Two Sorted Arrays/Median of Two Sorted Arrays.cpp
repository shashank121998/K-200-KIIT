#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
#define max(a, b) (a>b?(a):(b))
#define min(a, b) (a<b?(a):(b))
double MO2(int a, int b)
{
    return ( a + b ) / 2.0;
}
double MO3(int a, int b, int c)
{
    return (double)( a + b + c - max(a, max(b, c)) - min(a, min(b, c)));
}
double MO4(int a, int b, int c, int d)
{
    return ( a + b + c + d - max(a, max(b, max(c, d))) - min(a, min(b, min(c, d))) ) / 2.0;
}
double Single(int *arr, int n)
{
   if( n == 0 )
   {
       return (double)-1;
   }
   if(!( n & 1 ))
   {
       return (double)( arr[n/2] + arr[n/2-1] ) / 2;
   }
   return (double)arr[n/2];
}
double solve(int *a, int n, int *b, int m)
{
    if( n == 0 )
    {
        return Single(b, m);
    }
    if( n == 1 )
    {
        if( m == 1 )
        {
            return MO2(a[0], b[0]);
        }
        if( m & 1 )
        {
            return MO2(b[m/2], MO3(a[0], b[m/2-1], b[m/2+1]));
        }
        return MO3(b[m/2], b[m/2-1], a[0]);
    }
    else if( n == 2 )
    {
        if( m == 2 )
        {
            return MO4(a[0], a[1], b[0], b[1]);
        }
        if( m & 1 )
        {
            return MO3(b[m/2], max(a[0], b[m/2-1]), min(a[1], b[m/2+1]));
        }
        return MO4(b[m/2], b[m/2-1], max(a[0], b[m/2-2]), min(a[1], b[m/2+1]));
    }
    if( a[( n - 1 ) >> 1] <= b[( m - 1 ) >> 1] )
    {
        return solve(a + ( ( n - 1 ) >> 1 ), n/2 + 1, b, m - ( ( n - 1 ) >> 1 ));
    }
    return solve(a, n/2 + 1, b + ( ( n - 1 ) >> 1 ), m - ( ( n - 1 ) >> 1 ));
}
double findMedianSortedArrays(int *a, int n, int *b, int m)
{
    if( n > m )
    {
        return solve(b, m, a, n);
    }
    return solve(a, n, b, m);
}
int main()
{
    int n, m, i;
    printf("Enter the Length of First Array : ");
    scanf("%d", &n);
    printf("Enter the Length of Second Array : ");
    scanf("%d", &m);
    int a[n], b[m];
    printf("Enter the Elements in the First Array :\n");
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d", a + i);
    }
    printf("Enter the Elements in the Second Array :\n");
    for( i = 0 ; i < m ; i++ )
    {
        scanf("%d", b + i);
    }
    qsort(a, n, sizeof(int), comp);
    qsort(b, m, sizeof(int), comp);
    printf("Median of the Two Sorted Arrays is : %lf", findMedianSortedArrays(a, n, b, m));
    return 0;
}
