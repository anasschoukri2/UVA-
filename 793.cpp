#include<bits/stdc++.h>
using namespace std;
class Disjointset{
    public :
    int father[100009];
    int Rank[100009];
    void Initialize(int n){
        for(int i=1;i<=n;i++){
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
        //cout<<Find(a)<<" "<<Find(b)<<endl;
        return Find(a)==Find(b);
    }

};

int main(){
    //freopen("a1.in","r",stdin);
    //freopen("a1.out","w",stdout);
    int n;
    int x;
    cin>>n;
    cin>>x;
    char c;
    cin>>c;
    while(n--){
    Disjointset Set ;
    Set.Initialize(x+4);
     //cout<<n<<endl;
    int yes=0,no=0;
    //cout<<c<<endl;
    while(isalpha(c)){
        int a,b;
        cin >> a >> b ;
        if(c=='c'){
            Set.Union_compressed(a,b);
        }
        else if(c=='q'){
            Set.same_set(a,b)?yes++:no++;
        }

        if(cin>>c)continue;
        else {
            cout<<yes<<","<<no<<endl;
            return 0;
        }
    }
    x=c-'0';

    while(cin>>c){
        if(isalpha(c))break;
        x*=10;
        x+=c-'0';

    }
    cout<<yes<<','<<no<<endl<<endl;
    }
    return 0;

}
