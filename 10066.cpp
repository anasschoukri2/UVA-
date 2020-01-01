#include <bits/stdc++.h>

using namespace std;
vector<int>a,b;
int dp[1000][1000];
int cnt (int i,int j){
    if(i==a.size()||j==b.size())return 0;
    if(dp[i][j]+1)return dp[i][j];
    return dp[i][j]=max((a[i]==b[j])*(cnt(i+1,j+1)+1),max(cnt(i,j+1),cnt(i+1,j)));
}
int main() {
    int n,m;
    cin>>n>>m;
    int k=1;
    while(n!=0){
    cout<<"Twin Towers #"<<k<<endl;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    dp[i][j]=-1;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a.push_back(p);
    }
       for(int i=0;i<m;i++){
        int p;
        cin>>p;
        b.push_back(p);
    }
    cout<<"Number of Tiles : "<<cnt(0,0)<<endl<<endl;
        cin>>n>>m;
        a.clear();
        b.clear();
        k++;
    }
    return 0;
}
