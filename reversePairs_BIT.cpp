class Solution {
public:
    int N;
    int bit[100005];
    int sum(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+= bit[i];
            i-= (i&(-i));
        }
        return ans;
    }

    void update(int i, int x)
    {
        while(i<=N)
        {
            bit[i]+= x;
            i+= (i&(-i));
        }
    }
    int reversePairs(vector<int>& nums) {
        memset(bit, 0, sizeof(bit));

        //cordinate compress first
        int n= nums.size();
        map<long long, int>mpp;
        for(auto ele: nums) 
        {
            long long a= ele*1ll;
            long long b= ele*2ll;
            mpp[a]=0;
            mpp[b]=0;
        }

        int counter=1;
        for(auto &ele: mpp) ele.second= counter++;
        N= counter;
        
        vector<int>a(n+10);
        for(int i=0; i<n; i++) a[i+1]= mpp[nums[i]];

        int ans=0;
        for(int i=1; i<=n; i++) 
        {
            long long t=2ll*nums[i-1];
            ans+= sum(N)-sum(mpp[t]);
            update(a[i], 1);
        }
        return ans;
    }
};
