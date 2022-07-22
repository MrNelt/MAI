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
double f(double x, double y, double xp, double yp, double xb, double yb){
    return sqrt((xp - x) * (xp - x) + (yp - y) * (yp - y)) + sqrt((xb - x) * (xb - x) + (yb - y) * (yb - y));
}


// double findx(double y, double x1, double y1, double x2, double y2){
//     //
//}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int xp, yp, xt1, yt1, xt2, yt2, xt3, yt3;
    cout << setprecision(15);
    cin >> xp >> yp;
    cin >> xt1 >> yt1;
    cin >> xt2 >> yt2;
    cin >> xt3 >> yt3;
    int m;
    cin >> m;
    for (int m0 = 0; m0 < m; m0++){
        int xb, yb;
        cin >> xb >> yb;
        double eps = 0.0000001;
        double lx = min(xt1, xt2);
        double rx = max(xt1, xt2);
        double ly, ry;
        if ((xt1 - xt2) * (yt1 - yt2) >= 0){
            ly = min(yt1, yt2);
            ry = max(yt1, yt2);
        }
        else {
            ly = max(yt1, yt2);
            ry = min(yt1, yt2);
        }
        while (rx - lx > eps || abs(ry - ly) > eps) {
            double m1x = lx + (rx - lx) / 3, m2x = rx - (rx - lx) / 3;
            double m1y = ly + (ry - ly) / 3, m2y = ry - (ry - ly) / 3;
            if (-f(m1x, m1y, xb, yb, xp, yp) < -f(m2x, m2y, xb, yb, xp, yp)){
                lx = m1x;
                ly = m1y;
            }
            else{
                rx = m2x;
                ry = m2y;
            }
        }
        double xa1 = (lx + rx) / 2;
        double ya1 = (ly + ry) / 2;
        double d1 = f(xa1, ya1, xb, yb, xp, yp);

        lx = min(xt1, xt3);
        rx = max(xt1, xt3);
        if ((xt3 - xt1) * (yt3 - yt1) >= 0){
            ly = min(yt1, yt3);
            ry = max(yt1, yt3);
        }
        else {
            ly = max(yt1, yt3);
            ry = min(yt1, yt3);
        }
        while (rx - lx > eps || abs(ry - ly) > eps) {
            double m1x = lx + (rx - lx) / 3, m2x = rx - (rx - lx) / 3;
            double m1y = ly + (ry - ly) / 3, m2y = ry - (ry - ly) / 3;
            if (-f(m1x, m1y, xb, yb, xp, yp) < -f(m2x, m2y, xb, yb, xp, yp)){
                lx = m1x;
                ly = m1y;
            }
            else{
                rx = m2x;
                ry = m2y;
            }
        }
        double xa2 = (lx + rx) / 2;
        double ya2 = (ly + ry) / 2;
        double d2 = f(xa2, ya2, xb, yb, xp, yp);



        lx = min(xt3, xt2);
        rx = max(xt3, xt2);
        if ((xt3 - xt2) * (yt3 - yt2) >= 0){
            ly = min(yt3, yt2);
            ry = max(yt3, yt2);
        }
        else {
            ly = max(yt3, yt2);
            ry = min(yt3, yt2);
        }
        while (abs(rx - lx) > eps || abs(ry - ly) > eps) {
            double m1x = lx + (rx - lx) / 3, m2x = rx - (rx - lx) / 3;
            double m1y = ly + (ry - ly) / 3, m2y = ry - (ry - ly) / 3;
            if (-f(m1x, m1y, xb, yb, xp, yp) < -f(m2x, m2y, xb, yb, xp, yp)){
                lx = m1x;
                ly = m1y;
            }
            else{
                rx = m2x;
                ry = m2y;
            }
        }
        double xa3 = (lx + rx) / 2;
        double ya3 = (ly + ry) / 2;
        double d3 = f(xa3, ya3, xb, yb, xp, yp);

        if (d1 <= d2 && d1 <= d3){
            cout << xa1 << " " << ya1 << "\n";
        }
        else if (d2 <= d1 && d2 <= d3){
            cout << xa2 << " " << ya2 << "\n";
        }
        else {
            cout << xa3 << " " << ya3 << "\n";
        }
        //cout << d1 << " " << d2 << " " << d3 <<  " " << f(0, 1.5, xp, yp, xb, yb) << " " << "\n";
        // cout << f(0, 1.5, xp, yp, xb, yb) << "\n";
        // cout << f(1.66, 2.33, xp, yp, xb, yb) << "\n";
    }

    return 0;
}