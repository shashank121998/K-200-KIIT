// Given an array of numbers, find the index of the smallest array element (the pivot), for which the sum of all elements to the left and to the right are equal. The array may not be reordered.
// Ex:
// arr= [1, 2, 3, 4, 6]
//  the sum of the first elements, 1+2+3=6. The value of the last elements is 6.
//  Using zero based indexing, arr[3] = 4 is the pivot between the two sub arrays.
//  The index of the pivot is 3.
// Function Description
// Complete the function balancedSum in the editor below.
// balancedSum has the following parameter(s):
// int arr[n]: an array of integers
// Returns:
// int: an integer representing the index of the pivot.


#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
using vi = vector<int>; 
using pii = pair<int,int>; 
#define f first
#define s second
#define eb emplace_back
#define IO(NAME) cin.tie(0)->sync_with_stdio(0); if(fopen(NAME ".in", "r")) freopen(NAME ".in", "r", stdin), freopen(NAME ".in", "w", stdout); 

int main() {
    IO("");
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int prefsum[n],suffsum[n];
    prefsum[0] = a[0];
    for(int i=1;i<=n;i++){
    	prefsum[i] = a[i] + prefsum[i-1];
    }
    suffsum[n-1] = a[n-1]; 
    for(int i=n-2;i>=0;i--){
    	suffsum[i] = a[i] + suffsum[i+1];
    }
    for(int i=0;i<n;i++){
    	if(suffsum[i]==prefsum[i]){
    		cout<<i<<endl;
    		break;
    	}
    }
    return 0;
}