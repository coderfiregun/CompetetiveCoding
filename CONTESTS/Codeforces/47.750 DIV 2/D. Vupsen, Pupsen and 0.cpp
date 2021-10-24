//
// Created by dedic
//


#include "bits/stdc++.h"
using namespace std;

void getAns(vector<pair<int,int>> &v){

    assert(v.size()%2==0);

    int left=0,right=v.size()-1;

    int cnt = 0;
    while(left<=right){
        int sign1 = v[left].first > 0;
        int sign2 = v[right].first > 0;

        int a = v[left].first;
        int b = v[right].first;

        int g = __gcd(abs(a),abs(b));

        v[left].first = -1*b/g;
        v[right].first = a/g;

        ++left,--right;
    }
}

vector<pair<int,int>> hardAns(pair<int,int> &a,pair<int,int> &b,pair<int,int> &c) {
    vector<int> ans;

    int g = __gcd(__gcd(abs(a.first), abs(b.first)), abs(c.first));

    int x = a.first;
    int y = b.first;
    int z = c.first;


    a.first = (-1*z)/g;
    b.first = (-1*z)/g;
    c.first = (x+y)/g;


    return {a,b,c};
}

bool cmp(const pair<int,int> &p1,const pair<int,int> &p2){
    return p1.second < p2.second;
}

inline void solve(int tc){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);

    for(int i=0;i<n;++i){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(begin(a),end(a));

    if(a.size() % 2 == 0){
        getAns(a);
    }else{

        assert(a.size() >= 3);



        pair<int,int> num1 = a.back();    a.pop_back();
        pair<int,int> num2 = a.back();    a.pop_back();
        pair<int,int> num3 = a.back();    a.pop_back();

        vector<pair<int,int>> pans;
        //some work to do
        if(num1.first + num2.first != 0)
         pans = hardAns(num1,num2,num3);
        else if(num3.first + num2.first != 0){
            pans = hardAns(num3,num2,num1);
        }else if(num3.first + num1.first != 0){
            pans = hardAns(num3,num1,num2);
        }
        getAns(a);

        for(auto &c:a) pans.emplace_back(c);
        a = pans;
    }

    sort(begin(a),end(a),cmp);

    for(auto &c:a){
        cout<<c.first<<" ";
    }

    cout<<"\n";

}

int main(){

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        solve(t);
    }
    return 0;
}