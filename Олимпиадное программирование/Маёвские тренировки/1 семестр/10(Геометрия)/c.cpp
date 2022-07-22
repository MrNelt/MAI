#include <bits/stdc++.h>



using namespace std;
#define int long long

#define PI 3.1415926535


struct vec3 {
  int x, y, z;
};
struct point {
  int x, y;
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


double square (const vector<point> & fig)
{
	double res = 0;
	for (int i = 0; i < fig.size(); i++)
	{
		point
			p1 = i ? fig[i-1] : fig.back(),
			p2 = fig[i];
		res += (p1.x - p2.x) * (p1.y + p2.y);
	}
	return fabs (res) / 2;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <point> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i].x >> a[i].y;
  }
  cout << square(a) << "\n";
  return 0;
}