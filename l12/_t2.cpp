#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;

int a[MAXN];
int table[MAXN][LOG];
int lg[MAXN];

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        table[i][0] = a[i];
    }

    lg[1] = 0;
    for(int i=2;i<=n;i++){
        lg[i] = lg[i/2] +1;
    }

    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)<=n; i++){
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }

    cout<<"Ranges to be stored in Sparse Table:\n";
    for(int i=0;i<n;i++){
        for(int j=0;i+(1<<j)<=n;j++){
            cout<<"("<<i<<","<<i+(1<<j)-1<<") ";
        }
        cout<<"\n";
    }

    cout<<"\nStatus of Sparse Table:\n";
    for(int i=0;i<n;i++){
        for(int j=0;i+(1<<j)<=n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    int q;
    cin>>q;

    int qcount = 1;
    while(q--){
        int L,R;
        cin>>L>>R;
        
        int L0 = L-1;
        int R0 = R-1;
        int window = R0-L0+1;
        int j = lg[window];
        
        int ans = min(table[L0][j], table[R0-(1<<j)+1][j]);
        
        int A = L;
        int B = L+(1<<j)-1;
        int C = R-(1<<j)+1;
        int D = R;
        
        cout<<"Query-"<<qcount++<<": Min="<<ans<<" min(["<<A<<","<<B<<"],["<<C<<","<<D<<"])\n";
    }

    return 0;
}