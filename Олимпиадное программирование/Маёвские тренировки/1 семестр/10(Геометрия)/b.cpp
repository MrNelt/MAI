#include <bits/stdc++.h>



using namespace std;
#define int long long

#define PI 3.1415926535


struct vec3 {
  int x, y, z;
};

// double dot(vec3 a, vec3 b) {
//   return a.x * b.x + a.y * b.y;
// }

// double lene(vec3 a){
//   return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
// }

// double cross(vec3 a, vec3 b){
//   return len({a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x});
// }

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int x1, y1, x2, y2, x3, y3;
    cout << setprecision(10);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vec3 a = {x2 - x1, y2 - y1, 0};
    vec3 b = {x3 - x1, y3 - y1, 0};
    int dot1 = a.x * b.x + a.y * b.y;
    vec3 g = {a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x};
    int dot2 = sqrt(g.x * g.x + g.y * g.y + g.z * g.z);
    cout << atan2(dot2, dot1) << "\n";

  }
  return 0;
}