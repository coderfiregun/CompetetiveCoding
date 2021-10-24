//
// Created by dedic
//


#include "bits/stdc++.h"
using namespace std;

//greedily reducing bigger ones

inline void solve(int tc){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);


    c %= 2;

    if(c){

        //now we can make diff any way we use 2
        if(a&1)
            printf("%d\n",0);
        else printf("%d\n",1);

    }else{

        if(a&1)
            printf("%d\n",1);
        else printf("%d\n",0);

    }

}

int main(){

    int tc;
    cin>>tc;

    for(int t=1;t<=tc;++t){
        solve(t);
    }
    return 0;
}