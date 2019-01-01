#include<bits/stdc++.h>
using namespace std;
class Disjointset{
    public :
    int father[1009];
    int Rank[1009];
    void Initialize(int n){
        for(int i=0;i<n;i++){
            father[i]=i;
            Rank[i]=0;
        }
    }
    int Find(int x){
        if(father[x]==x)return x;
        return Find(father[x]);
    }
    int Find_compress(int x){
        if(father[x]==x)return x;
        return father[x]=Find(father[x]);
    }
    void Union_rank(int a,int b){
        int ra=Find(a);
        int rb=Find(b);
        if(Rank[ra]>Rank[rb])father[rb]=ra;
        else {
                father[ra]=rb;
                if(Rank[ra]==Rank[rb])
                    Rank[rb]++;
        }
    }
    void Union_compressed(int tobefather,int b){
        int a=tobefather;
        int ra=Find(a);
        int rb=Find(b);
        father[rb]=ra;
    }
    int count_sets(int n){
        int ans=0;
        for(int i=0;i<=n;i++){
            if(father[i]==i)ans++;
        }
        return ans;
    }
    bool  same_set(int a,int b){
        return Find(a)==Find(b);
    }

};

int main(){
    //freopen("a1.in","r",stdin);
    //freopen("a1.out","w",stdout);
    int n;
    cin>>n;
    cin.ignore();
    cin.ignore();
    while(n--){
        string s;
        char c;
        getline(cin,s);
        c=s[0];
        //cout<<c<<endl;

        Disjointset Set;
        Set.Initialize((int)(c-'A')+1);

        while(getline(cin,s)){
          if(s.empty())break;
          //cout<<s[0]<<" "<<s[1]<<endl;
        int x=s[0]-'A';
        int y=s[1]-'A';
        Set.Union_compressed(x,y);
        }
        cout<<Set.count_sets((int)(c-'A'))<<endl;
        if(n>0)cout<<endl;
    }
    return 0;

}
