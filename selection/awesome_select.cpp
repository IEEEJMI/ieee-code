#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005


int main(){
sp;
ll n,l,r,x;
cin>>n>>l>>r>>x;
ll a[n];
for(int i=0; i<n; ++i)
    cin>>a[i];
ll p=1<<n;
ll ans=0;
for(int i=1; i<p; ++i){
    int z=__builtin_popcount(i);
    if(z<2)continue;
    ll mx=INT_MIN,mn=INT_MAX,sum=0;
    for(int j=0; j<n; ++j)
    if((i>>j)&1){
        sum+=a[j];
        mx=max(mx,a[j]);
        mn=min(mn,a[j]);
    }
   if(mx-mn>=x&&sum>=l&&sum<=r)++ans;
}
cout<<ans;
return 0;}