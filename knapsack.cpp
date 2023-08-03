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

int dp[102][1002];

ll knapsack(vll w,vll v,int wg,int n)
{
   if(n==0 ||wg==0)
   return 0;
   if(dp[n][wg] !=-1)
   return dp[n][wg];

   if(w[n-1]<=wg)
   {
       return dp[n][wg]=max(v[n-1]+knapsack(w,v,wg-w[n-1],n-1),knapsack(w,v,wg,n-1));
   }
   else if(w[n-1]>wg)
   {
       return dp[n][wg]=knapsack(w,v,wg,n-1);
   }
   return -1;
}
int main()
{  
   fast
   memset(dp,-1,sizeof(dp));
   ll t=1;
   //cin>>t;
   while(t--)
   {
       ll n,wg;cin>>n>>wg;
       vll w(n),v(n);
       vin(w);
       vin(v);
       cout<<knapsack(w,v,wg,n)<<endl;

       forn(i,0,n)
       {
        forn(j,0,wg)
        {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
       }
       
   }
   return 0;
}