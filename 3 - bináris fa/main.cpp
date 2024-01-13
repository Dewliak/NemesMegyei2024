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

vector<int> arr(200000,1); // szulobe vezeto el hossza
vector<int> binary_tree(200000,1);
int n,m;
int delta;

vi sol{};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int con = pow(2,n);
    for(int i = 1; i < con;i++){
        //cout << i << endl;
        //cout << i << endl;


        binary_tree[i] = n  - floor(log2(i));
        if(i < 100){
        //cout << i << " - " << binary_tree[i] -1 << endl;
        }
    }

    for(int i=0; i<m;i++){
        int c,h;
        cin >> c >> h;
        delta = h - binary_tree[c];
        //binary_tree[c] -= delta;
        arr[c] = h;

        //cout << "BINARY TREE: " << binary_tree[c] << endl;
        //cout << "INDEX: " << c << endl;
        c = c/2;
        while(c >= 1){
            //cout << "C: " << c << endl;

            //cout << "Head: " << c << " - left child: " << 2*c << " - right child: " << 2*c + 1 << endl;
            //cout << "aMax:  " << arr[2*c]  << " <-> " << arr[2*c+1]  << endl;
            //cout << "bMax:  " <<  binary_tree[2*c] << " <-> " << binary_tree[2*c +1] << endl;
            binary_tree[c] =  max(arr[2*c] + binary_tree[2*c],arr[2*c+1] + binary_tree[2*c +1]);
            c = c/2;
        }
        //cout << "ANS: ";
        sol.PB(binary_tree[1]);
        //cout << binary_tree[1] -1 << endl;
    }

    for(int i=0;i<sol.size();i++){
        cout << sol[i] -1 << endl;
    }






    return 0;
}

/*
16 29
217 10
19513 7
227 68
408 60
15633 41
667 84
3157 61
4 76
9210 52
91 47
1641 47
22704 82
45695 1
3 85
55819 63
6 92
2390 33
8 37
26229 61
1554 82
190 19
2390 38
313 98
7 44
33604 69
34 91
1586 69
4 55
30987 78
*/
