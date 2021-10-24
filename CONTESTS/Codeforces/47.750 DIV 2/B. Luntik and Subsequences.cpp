//
// Created by dedic
//


#include "bits/stdc++.h"
using namespace std;
using ll = long long;


inline void solve(int tc){

    int n;
    scanf("%d",&n);

    int cnt1=0,cnt0=0;

    while(n--){
        int x;
        scanf("%d",&x);
        if(x==0){
            ++cnt0;
        }else if(x==1){
            ++cnt1;
        }
    }

    ll ans = cnt1 * (1LL << cnt0);

    printf("%lld\n",ans);

}

int main(){

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        solve(t);
    }
    return 0;
}