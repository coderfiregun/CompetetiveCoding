//Author : coder_firegun
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

/************************* Macros *****************************/
#define sint int32_t
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

/**************************************************************/

void fast (void) __attribute__ ((constructor));
void fast (void) { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
} 

inline int mAdd(int a,int b,int m=mod){
    a+=b;
    if(a>=m) return a-m;
    return a;
}

inline int mSub(int a,int b,int m=mod){
    a-=b;
    if(a<0) a+=m;
    else if(a>=m) a-=m;
    return a;
}

inline int mMul(int a,int b,int m=mod){
    return ( (a%m) * (b%m) ) % m;
}

/************************** Debugger **************************************/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(sint t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/****************************************************************/

/****************************Useful Functions************************************/

int power(int x, int y, int p=1e18)
{
    int res = 1;    
 
    x = x % p; 
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

// vector<int> primes;
// bitset<1000005> isPrime;
// void seive(int n=100005){
//     isPrime.set();
//     isPrime[0]=isPrime[1]=0;
//     for(int i=2;i*i<=n;++i){
//         if(isPrime[i]){
//             primes.emplace_back(i);
//             for(int j=i*i;j<=n;j+=i){
//                 isPrime[j] = 0;
//             }
//         }
//     }
// }

vector<int> fact;

void preprocessFactorial(){

    fact.resize(200005);

    fact[0]=1;

    for(int i=1;i<200005;++i)
        fact[i] = mMul(i,fact[i-1]);

}

int mPow(int x,int y, int p=mod)
{
    int res = 1; 
 
    x = x % p; 

    while (y > 0)
    {
     
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 



/********************************************************************/



inline void solve(){

    
    int n,h;
    cin>>n>>h;
    
    int a[n];

    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    sort(a,a+n);

    int m = a[n-1],s=a[n-2];

    int n1 = (int)ceil(double(h+s)/double(m+s));
    int n2 = (int)ceil(double(h)/double(m+s));

    cout<< min( 2*n1-1  , 2*n2  );

}
  
signed main (void) 
{ 
    // seive();
    int t=1; cin>>t;
    for(int i=1;i<=t;++i)
    {
        solve();
        cout<<"\n";
    }
    return 0; 
} 