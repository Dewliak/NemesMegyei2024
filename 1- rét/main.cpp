#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int>> pipii;

const int INF = 1e9;

vector<int> graph[100001];
vector<bool> arr{};

ll suma =0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans =0;
    int n,k;

    cin >> n >> k;
    for(int i =0; i< n;i++){
        int a;
        cin >> a;
        arr.PB(a);
    }

    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i]){
            suma++;
            if(suma - (k-1) > 0){
                ans += suma - (k-1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
