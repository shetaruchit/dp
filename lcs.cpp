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
ll dp[1002][1002];
// ll lcs(string x,string y,ll n,ll m)
// {
//     if(n==0 || m==0)
//     return 0;

//     if(x[n-1]==y[m-1])
//     {
//         return(1+lcs(x,y,n-1,m-1));
//     }
//     else
//     {
//         return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
//     }
// }
int main()
{  
   fast
   memset(dp,-1,sizeof(dp));

   ll t=1;
   //cin>>t;
   while(t--)
   {   
       
       ll n,m;
       string x,y;
       cin>>n>>x;
       cin>>m>>y;

       string ans;
    //    cout<<lcs(x,y,n,m)<<endl;

       forn(i,0,n+1)
       {
           forn(j,0,m+1)
           {
               if(i==0 || j==0)
               dp[i][j]=0;
           }
       }

       forn(i,1,n+1)
       {
           forn(j,1,m+1)
           {
               if(x[i-1]==y[j-1])
               {
                  dp[i][j]=1+dp[i-1][j-1];  
               }
               else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }

       cout<<dp[n][m]<<endl;
  
       ll i=n,j=m;
       while(i>0 && j>0)
       {
           if(x[i-1]==y[j-1])
           {
               ans.pb(x[i-1]);
               i--;j--;
           }
           else
           {
               if(dp[i][j-1]>dp[i-1][j])
               {
                   j--;
               }
               else
               {
                   i--;
               }
           }
       }
        reverse(all(ans));
        cout<<ans<<endl;
      
   }
   return 0;
}