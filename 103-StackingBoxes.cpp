#include <bits/stdc++.h>
using namespace std;
int n, d;
int dp[848];
int path[400];
bool visited[4000];
bool f(vector<int> a, vector<int> b)
{
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] >= b[i])
            return false;
    }
    return true;
}
int cnt(vector<int> b[100])
{
    int ans = (n > 0);
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (f(b[i], b[j])&&dp[j]<dp[i]+1) {
                dp[j] = max(dp[j], dp[i] + 1);
                path[j]=i;
                ans = max(dp[j], ans);
            }
        }
    }
    return ans;
}
int main()
{

    cin >> n;
    while(!cin.fail()){
    cin >> d;
    vector<int> b[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            b[i].push_back(a);
        }
        b[i].push_back(i);
        sort(b[i].begin(), b[i].end() - 1);
    }
    sort(b, b + n);
    int ans=cnt(b);
    cout<<ans<<endl;
    int i;
    for(i=0;i<n;i++)
        if(dp[i]==ans) 
            break;
    int x=i;
    stack<int >s;
    s.push(b[x][b[x].size()-1]+1);
    
    while(x){
        ans--;
        x=path[x];
        if(dp[x]==ans)
        s.push(b[x][b[x].size()-1]+1);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cin>>n;
    }
}
