
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
unordered_map<string,ll> m;
string key(ll i,ll j,bool istrue)
{
    string temp=to_string(i);
    temp.pb(' ');
    temp+=to_string(j);
    temp.pb(' ');
    temp+=to_string(istrue);
    return temp;
}
ll solve(string s,ll i,ll j,bool istrue)
{
    if(i>j)
    return false;
    if(i==j)
    {
        if(istrue==true)
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    
    string temp=key(i,j,istrue);

    if(m.find(temp)!=m.end())
    return m[temp];

    ll ans=0;
    for(ll k=i+1;k<=j-1;k+=2)
    {
        ll lt,lf,rt,rf;
        string temp=key(i,k-1,true);
        if(m.find(temp)!=m.end())
        {
            lt=m[temp];
        }
        else
        {  
            lt=solve(s,i,k-1,true);
            m[temp]=lt;
        }
        string temp1=key(k+1,j,true);
        if(m.find(temp1)!=m.end())
        {
            rt=m[temp1];
        }
        else
        {
             rt=solve(s,k+1,j,true);
             m[temp1]=rt;
        }
        string temp2=key(i,k-1,false);
        if(m.find(temp2)!=m.end())
        {
            lf=m[temp2];
        }
        else
        {
            lf=solve(s,i,k-1,false);
             m[temp2]=lf;

        }
        string temp3=key(k+1,j,false);
        if(m.find(temp3)!=m.end())
        {
            rf=m[temp3];
        }
        else
        {
           rf=solve(s,k+1,j,false);
           m[temp3]=rf;

        }
        
        if(s[k]=='&')
        {
            if(istrue==true)
            {
                ans+=lt*rt;
            }
            else
            {
                ans+=(lt*rf)+(lf*rt)+(lf*rf);
            }
        }
        else if(s[k]=='|')
        {
            if(istrue==true)
            {
                ans+=(lt*rf)+(lf*rt)+(lt*rt);
            }
            else
            {
                ans+=lf*rf;
            }
        }
        else if(s[k]=='^')
        {
            if(istrue==true)
            {
                ans+=lt*rf+lf*rt;
            }
            else
            {
                ans+=lf*rf+lt*rt;
            }
        }
        // deb2(ans,k);
    }

    return ans;
}

int main()
{  
   fast
    m.clear();
   ll t=1;
   //cin>>t;
   while(t--)
   {
       ll n;
       string s;
       cin>>n>>s;
       
       cout<<solve(s,0,n-1,true)<<endl;
      
   }
   return 0;
}