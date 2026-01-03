#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define ll long long

#define debug(arr) for(auto ele:arr){ cout<<ele<<" ";}


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll mod=1e9+7;  //prime number

class cmp{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};

ll ceil0(ll a, ll b) {
    return a/b + ((a^b)>0 && a%b);
}

string DecToBin(int n){
    string ans="";
    while(n>0){
        ans+=to_string(n%2);
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector <int> sieve(int n)
{
	vector <int> prime;
	vector <int> sie(n+1,1);
	for(int i=2;i*i<=n;i++)
	{
		if(sie[i]==0)continue;
		for(int j=2*i;j<=n;j+=i)
			sie[j]=0;
	}
	for(int i=2;i<=n;i++)
		if(sie[i])
			prime.push_back(i);
	return prime;
}

bool isInt(double n){
    int f=ceil0(n,1.0);
    if(f==n) return true;
    return false;

}

int lcm(int a,int b){
    int pro=a*b;
    int gcd=__gcd(a,b);
    return a*b/gcd;
}

vector<int>v;

void solve(){
    int n; cin>>n;
    cout<<v[n-1]<<endl;

    
    

            
}

//precomputation is a bliss
signed main(){
    for(int i=1;i<=2*100000;i++){
        int n=i;
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        v.push_back(sum);
    }
    for(int i=1;i<=2*100000;i++)
    v[i]+=v[i-1];

    fastio;
    int t=1; cin>>t;
    while(t--)
        solve();
} 
