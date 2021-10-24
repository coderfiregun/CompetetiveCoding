//
// Created by dedic
//


#include "bits/stdc++.h"
using namespace std;


//brute force + two pointer
inline void solve(int tc){

    int n;
    cin>>n;

    string s;
    cin>>s;

    unordered_set<char> us;

    for(auto &c:s){
        us.insert(c);
    }

    int res = n;

    for(auto &c:us){

        int cnt = 0;
        int left=0,right=n-1;

        bool ok = true;
        while(left<right){
            if(s[left]!=s[right]){

                if(s[left]==c){
                    ++left;
                    ++cnt;
                }else if(s[right]==c){
                    --right;
                    ++cnt;
                }else{
                    ok = false;
                    break;
                }

            }else{
                ++left;
                --right;
            }
        }

        if(ok)
        res = min(res,cnt);
    }

    if(res == n){
        cout<<-1<<"\n";
        return;
    }

    cout<<res<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        solve(t);
    }
    return 0;
}