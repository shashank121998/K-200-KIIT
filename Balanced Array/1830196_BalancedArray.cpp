/*
Given an array of numbers, find the index of the smallest array element 
(the pivot), for which the sum of all the elements to the left and right are equal.
The array may not be reordered.

if arr = [1, 2, 3, 4, 6]
    - the sum of the first elements, 1 + 2 + 3 = 6. The value of the last element is 6.
    - using 0-based indexing, arr[3] = 4, is the pivot between the two subarrays.
    - the index of the pivot is 3.

Function Description:
    parameters: array, sizeOfArray
    returns: integer representing the index of pivot, -1 if not found.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int balancedSum(int a[], int n) {
    int sumL = 0, sumR = 0;
    
    for(int i = 0; i < n; ++i) {
        sumL += a[i];
    }

    for(int i = n-1; i >= 0; --i) {
        sumL -= a[i];
        sumR += a[i];

        if(sumL - a[i-1] == sumR) {
            return i-1;
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout <<  balancedSum(a, n) << endl; 
    }

    return 0;
}