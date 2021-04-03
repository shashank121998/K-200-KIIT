// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
     int cnt = 0;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
          a[i] = a[j] - 1;
          cnt++;
        }
      }
    }
    if(cnt == 1 || cnt == 0){
      return cout<<"true"<<endl,0;
    }else{
      return cout<<"false"<<endl,0;
    }
}