#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

using ll = long long;
using matrix = vector<vector<ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vb = vector<bool>;

// Formulating 35, Solving 52, success
// 접근 방법 자체가 나쁘지 않지만 회전하는 부분의 구현에서 시간을 많이 잡아 먹음
const int INF = 1e9;
int n;
vector<vvi> arr(8);

// 반시계 방향 회전, 2개 배열을 받아서 대입 
void rot(vvi &ori, vvi &trans) {
    trans = vvi(n); // 배열 크기 초기화 
    int l = n-1;
    for(int i=l; i>=0; --i) {
        for(int j=i; j<n; ++j) {
            trans[l-i].push_back(ori[j][i]);
        }
    }
}
// 시계 방향 회전 
vector<vector<int> > rotate(const vector<vector<int> > &A) {
    int n = (int)A.size();
    vector<vector<int> > ans = vector<vector<int>  > (n); // 백터 크기 초기화
 
    for(int i = 0; i < n; i++) {
        ans[i] = vector<int> (i+1); // 세부 크기 할당
    }
    for(int i = 0; i < n; i++) { // i와 j를 0부터 시작하는 편이 어쩌면 생각이 덜 복잡해 지는 방법
        for(int j = 0; j <= i; j++) {
            ans[i][j] = A[n-1-j][i-j];
        }
    }
    return ans;
}

void oppo(vvi &ori) {
    for(int i=0; i<n; ++i) {
        int l = 0, r = i;
        while(l<r) {
            swap(ori[i][l], ori[i][r]);
            ++l, --r;
        }
    }
}

int check(vvi &arr1, vvi &arr2) {
    int ans = 0;
    for(int i=0; i<n; ++i) 
        for(int j=0; j<=i; ++j) 
            if(arr1[i][j] != arr2[i][j]) ++ans;
    return ans;
}


void solve() {
    cin >> n;
    int ans = INF;
    for(int i=0; i<2; ++i) {
        arr[i] = vvi(n);
        for(int j=0; j<n; ++j) {
            for (int k=0; k<=j; ++k) {
                int t;
                cin >> t;
                arr[i][j].push_back(t);
            }
        }
    }
    rot(arr[0], arr[2]), rot(arr[0], arr[3]);
    oppo(arr[3]);
    ans = min(ans, check(arr[1], arr[2]));
    ans = min(ans, check(arr[1], arr[3]));
    rot(arr[2], arr[4]), rot(arr[2], arr[5]);
    oppo(arr[5]);
    ans = min(ans, check(arr[1], arr[4]));
    ans = min(ans, check(arr[1], arr[5]));
    rot(arr[4], arr[6]), rot(arr[4], arr[7]);
    oppo(arr[7]);
    ans = min(ans, check(arr[1], arr[6]));
    ans = min(ans, check(arr[1], arr[7]));
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}