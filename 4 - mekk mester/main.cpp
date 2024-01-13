#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int>> pipii;

const int INF = 1e9;

int m1 = 0;
int m2 = 0;
int ans = 0;

vector<int> m1_arr{};
vector<int> m2_arr{};

vector<pair<int,pair<int,int>>> arr{};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,h;
    cin >> n >> h;


    for(int i =0; i< n;i++){
        int k,v;
        cin >> k >> v;

        arr.PB(MP(v,MP(k,i+1))); // v,k;
    }

    sort(arr.begin(),arr.end());
    /*
    cout << "SORTED: " << endl;
    for(auto i: arr){
        cout << i.first << " " << i.second.first <<  " - " << i.second.second << endl;
    }
    */

    for(auto i: arr){

        if(i.second.first > m1){
            m1 = i.first;
            ans++;
            m1_arr.PB(i.second.second);
            continue;
        }
        if(i.second.first > m2){
            m2 = i.first;
            ans++;
            m2_arr.PB(i.second.second);
            continue;
        }
    }
    cout << "ANS: ";
    cout << m1_arr.size() << " " << m2_arr.size() << endl;

    for(int i =0; i < m1_arr.size();i++){
        if(i != 0){
            cout << " ";
        }
        cout << m1_arr[i];
    }
    cout << endl;
    cout << "FIA: ";
    cout << endl;
    for(int i=0;i< m2_arr.size();i++){
        if(i !=0){
            cout << " ";
        }
        cout << m2_arr[i];
    }
    cout << endl;
    return 0;
}
