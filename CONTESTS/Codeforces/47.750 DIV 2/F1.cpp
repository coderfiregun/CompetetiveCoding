#include "bits/stdc++.h"
using namespace std;

const int MXN = 512, INF = 1e5;

void solve(int tc){

	int n;
	cin>>n;
	vector<int> a(n);

	for(auto &c:a) cin>>c;

	vector<int> dp(MXN,INF);

	dp[0] = 0;	//we can always make o by not taking any


	for(int i=0;i<n;++i){

		vector<int> currdp = dp;

		for(int j=0;j<MXN;++j){
			if(dp[a[i]^j] < a[i])
				currdp[j] = min(currdp[j],a[i]);
		}

		dp = currdp;
	}



	vector<int> ans;
	for(int i=0;i<MXN;++i){
		if(dp[i] < INF) ans.emplace_back(i);
	}

	cout<< (int) ans.size() << "\n";

	for(auto &c:ans){
		cout<<c<<" ";
	}

}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc=1;
    for(int t=1;t<=tc;++t){
    	solve(t);
    }

    return 0;
}