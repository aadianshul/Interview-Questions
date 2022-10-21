class Solution {
public:
    int fun(vector<int>&v,int i){
        int prev2,prev1,cur;
        prev1=cur=v[0];
        for(int i=1;i<v.size();i++){
            int res1 = prev1;
            int res2 = v[i];
            if(i>1)
                res2 += prev2;
            cur = max(res1,res2);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1)
                temp1.push_back(nums[i]);
            if(i!=0)
                temp2.push_back(nums[i]);
        }
        int m = temp1.size();
        return max(fun(temp1,m-1),fun(temp2,m-1));
    }
};
