#include <bits/stdc++.h>



using namespace std;
#define int long long

struct vec{
    double x, y, z = 0;
};
 
vec operator+ (vec a, vec b){
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
 
vec operator- (vec a, vec b){
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
 
vec operator* (double n, vec a){
    return {a.x * n, a.y * n, a.z * n};
}
 
bool operator== (vec a, vec b){
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
 
double scalar(vec a, vec b){
    return a.x * b.x + a.y * b.y;
}
 
vec vectors_product(vec a, vec b){
    return {a.y * b.z - a.z * b. y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
 
double len_vec(vec a){
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
 
double angle(vec a, vec b){
    return atan(len_vec(vectors_product(a, b)) / scalar(a, b));
}
 
double d(vec a, vec p, vec q){
    return fabs(len_vec(vectors_product(p - a, q - a)) / 2 / len_vec(p-q) * 2);
}

double d_otrez(double x0, double y0, double x1, double y1, double x2, double y2){
    vec PA = {x0 - x1, y0 - y1, 0};
    vec PQ = {x2 - x1, y2 - y1, 0};
    vec QA = {x0 - x2, y0 - y2, 0};
    vec QP = {x1 - x2, y1 - y2, 0};
    if (scalar(PA, PQ) >= 0 && scalar(QA, QP) >= 0){
        return len_vec(vectors_product(PA, PQ)) / len_vec(PQ);
    }
    double d1 = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    double d2 = sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));
    return min(d2, d1);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(15);
    int t;
    cin >> t;
    for (int g = 0; g < t; g++){ 
        double x0, y0, x1, y1, x2, y2;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        cout << d_otrez(x0, y0, x1, y1, x2, y2) << "\n";
    }
    return 0;
}