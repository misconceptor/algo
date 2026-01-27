#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n; 
    cin >> n;
    vi a(n+1), b(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }

    vector<vi> dp(n+1,vi(n+1));
    vi ans1,ans2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j]){
                if(dp[i-1][j-1]+1 > dp[i][j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
            }
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }

    int i=n,j=n;
    while(i>0 && j>0){
        if(a[i] == b[j]){
            if(dp[i][j] == 1 + dp[i-1][j]){
                ans1.pb(i);
                ans2.pb(j);
                --i,--j;
            }
        } else if(dp[i-1][j] >= dp[i][j-1]){
            --i;
        } else --j;
    }

    cout<<dp[n][n]<<endl;
    for(int i=ans1.size()-1;i>=0;--i){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;

    for(int i=ans2.size()-1;i>=0;--i){
        cout<<ans2[i]<<' ';
    }
    cout<<endl;

    return 0;
}
