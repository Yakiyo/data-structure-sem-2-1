#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int cnt;
int maxs=1;
int find(vector<int> &parent, int item)
{
    if (parent[item] == item)
    {
        return parent[item];
    }
    return parent[item] = find(parent, parent[item]);
}
void union_op(int p, int q, vector<int> &parent, vector<int> &size)
{
    p = find(parent, p);
    q = find(parent, q);
    if(p!=q){
        if (size[p] <= size[q])
        {
            parent[p] = q;
            size[q]+=size[p];
            if(maxs<size[q]){
                maxs=size[q];
            }
        }
        else
        {
            parent[q] = p;
            size[p]+=size[q];
            if(maxs<size[p]){
                maxs=size[p];
            }
        }
        cnt--;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> size(n+1, 1);
    cnt=n;
    for (int i = 1; i <= n; i++)
    {
        parent[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_op(a, b, parent, size);
        cout<<cnt<<" "<<maxs<<endl;
    }
    return 0;
}
