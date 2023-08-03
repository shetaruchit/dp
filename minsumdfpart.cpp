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
bool dp[1002][1002];
int main()
{  
   fast
   memset(dp,false,sizeof(dp));
   ll t=1;
   //cin>>t;
   while(t--)
   {
       ll n;cin>>n;
       vll v(n);
       vin(v);
       ll sum=accumulate(all(v),0ll);
       forn(i,0,n+1)
       {
           dp[i][0]=true;
       }

       forn(i,1,n+1)
       {
           forn(j,1,sum+1)
           {
               if(v[i-1     ]<=j)
               {
                   dp[i][j]=(dp[i-1][j-v[i-1]]||dp[i-1][j]);
               }
               else
                    dp[i][j]=dp[i-1][j];
           }
       }
       vll ans;
       forn(i,0,(sum/2)+1)
       {
           if(dp[n][i])
           ans.pb(i);
       }

       ll mi=INT_MAX;
       for(auto &x:ans)
       {
           mi=min(mi,sum-2*x);
       }

       cout<<mi<<endl;

      
   }
   return 0;
}