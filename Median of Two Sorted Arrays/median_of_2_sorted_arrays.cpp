class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        cout<<fixed<<setprecision(5);
        vector<int> ans;
        double val;
        for(auto i:nums1){
            ans.push_back(i);
        }
        for(auto i:nums2){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==1){
            val = (double) ans[0];
        }else if(ans.size() & 1){
            val = (double) ans[ans.size()/2];
        }else if(ans.size() %2 == 0){
            val = (double) (ans[ans.size()/2]+ans[ans.size()/2 - 1])/2;
        }
        return val;
    }
};