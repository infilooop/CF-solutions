    #include <bits/stdc++.h>
     
    using namespace std;
    #define etm cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n'
    #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define ll long long
    #define pb push_back
    #define eb emplace_back
    #define stp setprecision(20)
     
    #define MOD 1000000007
    #define MOD2 998244353
    #define ld long double
    #define inf 5e18
    #define PI 3.1415926535  
    #define all(x) x.begin(),x.end()
    #define rall(x) x.rbegin(),x.rend()
    #define fi first
    #define se second
    #define show(w, size) for(ll i=0;i<size;i++) cout<<w[i]<<" ";
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    using namespace std;
    #define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
     
    ll pow_m(ll x,ll y,ll m=MOD) {
        x%=m;
        ll res=1;
        while(y){
            if(y&1)res*=x;
            res%=m;y>>=1;
            x*=x;x%=m;
        }
        return res;
    }
     
    ll gcd(ll a,ll b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
     
    bool kthBit(ll n,ll k){
        if(n&(1<<(k-1)))return true;
        else return false;
    }
     
     
    ll modInverse(ll a,ll m){return pow_m(a,m-2,m);}
     
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
     
    ll inverse(ll i){
        if(i==1)return 1;
        return(MOD-((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
    }
     
    const ll N=10000007;
    vector<bool> primes(N+1,true);
    vector<ll> primeNumbers;
     
    void eren(){
        primes[0]=false;primes[1]=false;
        for(ll i=2;i*i<=N;i++){
            if(primes[i]){
                for(ll j=i*i;j<=N;j+=i)primes[j]=false;
            }
        }
        for(ll i=1;i<1000001;i++){
            if(primes[i])primeNumbers.pb(i);
        }
    }
     
    int32_t main()
    {
        fastio;
        eren();
        //ofstream cout ("output.txt");
        //ifstream cin ("input.txt");
        ll tt=1,deku=7546893208976;
        //cin>>tt;
        for(int it=0;it<tt;it++){
            string s,t;cin>>s>>t;
            ll k,n=s.length();cin>>k;
            set<ll> hentai;
            for(ll i=0;i<n;i++){
                ll cnt=0,val=0;
                for(ll j=i;j>=0;j--){
                    if(t[s[j]-'a']=='0')cnt++;
                    if(cnt>k)break;
                    val=((val*26)%deku+(s[j]-'a'+1))%deku;
                    hentai.insert(val);
                }
            }
            cout<<hentai.size()<<"\n";
            //cout<<"Case #"<<it+1<<": "<<solve(R+1)-solve(L)<<endl;
        }
        return 0;
    }
     
    /*
    ID: shubham144
    TASK: subset
    LANG: C++                 
    */
    /* LANG can be C++11 or C++14 for those more recent releases */
