#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pair<int,int>> pipii;

const int INF = 1e9;
set<int> ans{};
vector<int> graph[10001];
    int n,m,k;
vector<bool> visited(10001,false);
vector<bool> get_back(10001,false);

bool DFS(int source){
    visited[source] = true;
    bool flag = false;
    for(auto i: graph[source]){

        if(get_back[i] || i == k){
            get_back[source] = true;
            flag = true;
            ans.insert(source);

        }

        if(!visited[i]){
            bool a;
            a = DFS(i);
            if(!flag){
                flag = a;
            }
        }
    }
    if(flag){
        get_back[source] = true;
        ans.insert(source);
    }
    return flag;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    cin >> n >> m >> k;

    for(int i=0;i<m;i++){
        int u,v;
        //cout << "i: " << i << " - ";
        cin >> u >> v;
        graph[u].PB(v);
        //cout << endl;
    }
    set<int> p{};


    bool x;
    x = DFS(k);
    bool flag = false;

    set<int> ans2{};


    for(auto i: ans){
        ans2.insert(k);
        if(get_back[i]){
            for(auto k : graph[i]){
            ans2.insert(k);
        }
        }

    }

    cout << ans2.size() -1<< endl;


    for(auto i: ans2){
        if(i == k){
            continue;
        }
        if(flag){
            cout << " ";
        }
        else{
            flag = true;
        }
        cout << i;

    }
    cout << endl;
    return 0;
}
