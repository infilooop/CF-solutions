#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
using namespace std;
#define etm cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define pb push_back
#define eb emplace_back
#define stp setprecision(16)
 
#define MOD 1000000007
#define MOD2 998244353
#define ld long double
#define inf 1e18
#define PI 3.1415926535  
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fi first
#define se second
#define show(w, size) for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define Robin tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
 
 
ll Power(ll x,ll y,ll m=MOD){
    x%=m;
    ll res=1;
    while(y>0){
        if(y&1)res*=x;
        res%=m;y>>=1;
        x*=x;x%=m;
    }
    return res;
}
 
ll modInverse(ll a,ll m){return Power(a,m-2,m);}
 
ll bin_coff(ll n,ll k,ll m){
    vector<vector<ll>> ans(n+1,vector<ll>(k,0));
    for(ll i=0;i<n+1;i++){
        for(ll j=0;j<min(i,k)+1;j++){
            if(j==0||j==i)ans[i][j]=1;
            else ans[i][j]=ans[i-1][j-1]%m+ans[i-1][j]%m;
        }
    }
    return ans[n][k]%m;
}
 
vector<ll> fact(200005);
 
ll BoaHancock(ll n,ll r,ll p){ // for calculating nCr
    if(r==0)return 1;
    return (((fact[n]*modInverse(fact[r],p))%p)*(modInverse(fact[n-r],p)%p))%p;
}
 
ll inverse(ll i){
    if(i==1)return 1;
    return(MOD-((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
const ll NN=10000007;
vector<bool> primes(NN+1,true);
 
void eren(){
    primes[0]=false;primes[1]=false;
    for(ll i=2;i*i<=NN;i++){
        if(primes[i]){
            for(ll j=i*i;j<=NN;j+=i)primes[j]=false;
        }
    }
}
 
void dfs(vector<vector<ll>>&adj,ll source,ll par,vector<ll>&dist){
    dist[source]=dist[par]+1;
    for(auto child:adj[source]){
        if(child!=par)dfs(adj,child,source,dist);
    }
}
 
int32_t main()
{
    fastio;eren();
    fact[0]=1;
    for(ll i=1;i<200005;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    //ofstream cout ("output.txt");
    //ifstream cin ("input.txt");
    ll tt=1;//cin>>tt;
    for(int it=0;it<tt;it++){
        ll n,a,b;cin>>n;
        vector<vector<ll>>adj(n+1);
        for(ll i=1;i<n;i++){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vector<ll>dist(n+1,0);
        dfs(adj,1,0,dist);
        ll len=0,maxxIdx=1,ans=0;
        for(ll i=1;i<=n;i++){
            if(dist[i]>len){
                len=dist[i];
                maxxIdx=i;
            }
        }
        dist=vector<ll>(n+1,0);
        dfs(adj,maxxIdx,0,dist);
        for(ll i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        cout<<ans-1<<"\n";
        //cout<<"Case #"<<it+1<<": ";
    }
    return 0;
}
 
 
/*
ID: shubham144
TASK: subset
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
