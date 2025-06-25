#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
    public:
    vector<int>seg;
    segmentTree(int n)
    {
        seg.resize(4*n+1);
    }

    void build(int index, int low, int high, int arr[])
    {
        if(low==high)
        {
            seg[index]= arr[low];
            return;
        }

        int mid= (low+high)/2;

        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);

        seg[index]= min(seg[2*index+1], seg[2*index+2]);
    }

    int query(int index, int low, int high, int l, int r)
    {
        //no overlap [low high][l r] or [l r][low high]
        if(high<l || r<low) return INT_MAX;


        //complete overlap [l low right hi]
        if(l<=low && high<=r) return seg[index];

        //partial overlap
        int mid= (low+high)/2;
        int left= query(index*2+1, low, mid, l, r);
        int right= query(index*2+2, mid+1, high, l, r);
        return min(left, right);
    }

    void update(int index, int low, int high, int queryindex, int val)
    {
        if(low==high)
        {
            seg[index]= val;
            return;
        }

        int mid= (low+high)/2;
        if(queryindex<=mid)
        {
            //left jana hai
            update(index*2+1, low, mid, queryindex, val);
        }
        else
        {
            //right
            update(index*2+2, mid+1, high, queryindex, val);
        }

        seg[index]= min(seg[2*index+1], seg[2*index+2]);
    }
};

void solve()
{
    int n; cin>>n;
    int q; cin>>q;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    //int seg[4*n];
    //for(int i=0; i<4*n; i++) seg[i]=-1;
    segmentTree tree(n);
    tree.build(0, 0, n-1, arr);

    //for(int i=0; i<4*n; i++) cout<<seg[i]<<" "; cout<<endl;

    while(q--)
    {
        int type; cin>>type;
        if(type==2)
        {
                
            int l,r; cin>>l>>r;
            l--; r--;

            cout<<tree.query(0, 0, n-1, l, r)<<endl;
        }
        else
        {
            int k, u; cin>>k>>u;
            k--;
            tree.update(0, 0, n-1, k, u);
        }
    }
}

int main()
{
    int t=1; //cin>>t;
    while(t--) solve();
}