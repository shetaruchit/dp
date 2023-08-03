#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vp vector<pi>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define forni(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int,int>
#define mall map<ll,ll>
#define gu(a,s) get<a>(s)
#define tin tuple<ll,ll,ll>
#define ter(x,y,z) ((x)?y:z)
#define deb1(x) cout<<#x<<" "<<x<< "\n"
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n"
#define deb3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<"\n"
#define vin(a) for(auto &x:a) cin>>x
#define vout(a) for(auto x:a) cout<<x<<" ";cout<<endl
//<----------------------------------------------------------------------------------------------------------------------------------------------->

const ll maxn = 3e5 + 5;
const ll max_val = 2e5 + 10;
ll mod = 1e9 + 7;

//<----------------------------------------------------------------------------------------------------------------------------------------------->
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif 
unordered_map<string ,bool> m;
bool solve(string a,string b)
{
    if(a.compare(b)==0)
    return true;
    if(a.length()<=1)
    return false;
    string key=a;
    key.pb(' ');
    key.append(b);
    if(m.find(key)!=m.end())
    return m[key];
    bool f=false;

    ll n=a.size();
    for(ll i=1;i<=n-1;i++)
    {
        if( ( solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) )
            || (solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i))  )
          )
          {
              f=true;
              break;
          }
  
          
    }
  
    return m[key]=f;
}

int main()
{  
   fast
   m.clear();
   ll t=1;
   //cin>>t;
   while(t--)
   {
       string a,b;
       cin>>a>>b;
       if(solve(a,b))
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl; 
      
   }
   return 0;
}