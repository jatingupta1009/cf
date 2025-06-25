#include <bits/stdc++.h>
using namespace std;
#define int long long

class segmentTree
{
    public:
    vector<int>tree, lazy;

    segmentTree(int n)
    {
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    public:
    void build(int index, int low, int high, int arr[])
    {
        if(low==high)
        {
            tree[index]= arr[low];
            lazy[index]= 0;
            return;
        }

        int mid= (low+high)/2;
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);

        tree[index]= tree[2*index+1]+ tree[2*index+2];
    }   

    void update(int index, int low, int high, int l, int r, int val)
    {
        //update previous remaining updates and propogate down
        if(lazy[index]!=0)
        {
            tree[index]+= (high-low+1)*(lazy[index]);
            
            if(high!=low)
            {
                lazy[index*2+1]+= lazy[index];
                lazy[index*2+2]+= lazy[index];
            }
            lazy[index]=0;
        }

        //no overlap [l r][low right] or [low high][l r]
        if(r<low || high<l) return;

        //complete overlap [l low high r]
        if(l<=low && high<=r) 
        {
            tree[index]+= (high-low+1)*val;
            if(high!=low)
            {
                lazy[index*2+1]+= val;
                lazy[index*2+2]+= val;
            }
            return;
        }

        //partial
        int mid= (low+high)/2;
        update(2*index+1, low, mid, l, r, val);
        update(2*index+2, mid+1, high, l, r, val);

        tree[index]= tree[index*2+1]+ tree[index*2+2];
    }

    int query(int index, int low, int high, int l, int r)
    {
        //previous update+ propogate down
        if(lazy[index]!=0)
        {
            tree[index]+= (high-low+1)*lazy[index];

            if(low!=high)
            {
                lazy[index*2+1]+= lazy[index];
                lazy[index*2+2]+= lazy[index];
            }

            lazy[index]=0;
        }

        //no overlap [l r][low high] or [low][high][l r]
        if(r<low || high<l) return 0;

        //complete overlap [l low high r]
        if(l<=low && high<=r) return tree[index];

        //partial
        int mid= (low+high)/2;
        int left= query(index*2+1, low, mid, l, r);
        int right= query(index*2+2, mid+1, high, l, r);
        return left+right;
    }
};

void solve()
{
    int n; cin>>n;
    int q; cin>>q;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    segmentTree tree(n);
    tree.build(0, 0, n-1, arr);
    
    while(q--)
    {
        int type; cin>>type;
        if(type==2)
        {
            int k; cin>>k;
            k--;
            cout<<tree.query(0, 0, n-1, k, k)<<endl;
        }
        else
        {
            int l, r, val; cin>>l>>r>>val;
            l--; r--;
            tree.update(0, 0, n-1, l, r, val);
        }
    }


}

signed main()
{
    int t=1; //cin>>t;
    while(t--) solve();
}
