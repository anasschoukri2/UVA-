#include<bits/stdc++.h>
#define MAXN 10000

using namespace std;int sett[40005];
int findd(int a)
{
	if (a == sett[a]) return a;
	return sett[a] = findd(sett[a]);
}
void join(int a, int b)
{
	a = findd(a);
	b = findd(b);
	if (a == b) return;
	sett[b] = a;
}
int main(){
    int y;
    cin>>y;
    while(y--){
        string u;
        int p,t;
        for(int i=0;i<=300;i++)sett[i]=i;
        cin>>p>>t;
        set<int>op[307];
        cin.ignore();
        
        while(getline(cin,u)&&u!="" ){

            int a=0,b=0,i=0;

            for(i=0;u[i]!=' ';i++){
                a=a*10+(u[i]-'0');
            }
            for(i=i+1;i<u.size();i++){
                b=b*10+(u[i]-'0');
            }
            
            op[a].insert(b);
        }
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                if(op[i]==op[j])join(i,j);
            }
        }
        int ans=0;
        for(int i=1;i<=p;i++)if(sett[i]==i)ans++;
        cout<<ans<<endl;
        if(y)cout<<endl;

    }

}
