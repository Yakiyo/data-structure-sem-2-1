#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> bits;
int n;

int LSB(int i){
    return (i & (-i));
}

int prefixSum(int i){

    int sum = 0;
    while(i > 0){
        sum += bits[i];
        i -= LSB(i);
    }
    return sum;
}

int rangeQuery(int i, int j){
    return prefixSum(j) - prefixSum(i-1);
}


void buildTree(){
    for(int i=1; i<= n; i++){
        bits.at(i) += arr.at(i);
        int next = i + LSB(i);
        if(next <= n){
            bits.at(next) += bits.at(i);
        }
    }
}

int main(){
    cin>>n;
    arr.resize(n+1);
    bits.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cout<<"Ranges to be stored in the Fenwick Table:"<<endl;
    for(int i=1; i<=n; i++){
        int left = i - LSB(i) + 1;
        cout<<i<< ":("<<left<< ","<< i<< ") ";
    }
    cout<<endl;

    buildTree();

    cout<< "Status of Fenwick Tree (idx: value):"<<endl;
    for(int i=1; i<n; i++){
        cout<<i<<":" <<bits.at(i)<<" ";
    }
    cout<<endl;
    

    int q;
    cin>>q;
    for(int i=1; i<=q; i++){
        int l, r;
        cin>>l>>r;

        int ans = rangeQuery(l, r);

        cout<<"Query-" <<i<<": Sum="<<ans<<" [Tree idx: sum(";
        int temp = r;
        bool first = true;
        while(temp >0){
            if(!first){
                cout<< ",";
            }
            cout<<temp;
            temp-= LSB(temp);
            first= false;
        }
        cout << ")";

        
            cout<<" - sum(";
            temp = l;
            first = true;
            while(temp > 0){
                if(!first){
                cout<< ",";
                }
                cout<<temp;
            temp-= LSB(temp);
            first= false;
            }
            cout << ")";
        

        cout<< "]"<<endl;
    }


    return 0;
}

