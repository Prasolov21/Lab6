#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]){
    float x[6] = {0, 0.9, 1.8, 2.7, 3.6};
    float f[6] = {0, 0.36892, 0.85408, 1.7856, 6.3138};
    float F = 0;
    float X = 1.5;
    float k[4] = {0,0,0,0};
    float h[5] = {0,0,0,0,0};
    float a[5] = {0,0,0,0,0};
    float b[5] = {0,0,0,0,0};
    float c[5] = {0,0,0,0,0};
    float d[5] = {0,0,0,0,0};
    int n = 4;
    double t1 = 1/3;
    double t2 = 2/3;
    for (int i = 1; i < 5; i++){
        h[i] = x[i] - x[i - 1];
    }
    for (int i = 1; i < 5; i++){
        cout << h[i] << " , ";
    }
    cout << " . " << endl;
    //вывести систему с помощью формул 3.13
    k[0] = 2 * (h[1] + h[2]);
    k[1] = h[2];
    k[3] = 3 * (((f[2]-f[1])/h[2])-((f[1]-f[0])/h[1]));
    cout << k[0] << "C2 + " << k[1] << "C3 =" << k[3] << endl;
    int i = 3;
    k[0] = h[i - 1];
    k[1] = 2 * (h[i-1] + h[i]);
    k[2] = h[3];
    k[3] = (3 * (((f[i] - f[i-1]) / h[i]) - ((f[i-1] - f[i-2]) / h[i-1])));
    cout << k[0] << "C2 + " << k[1] << "C3 + " << k[2] << "C4 =" << k[3] << endl;
    i = 4;
    k[0] = h[i - 1];
    k[1] = 2 * (h[i-1] + h[i]);
    k[2] = h[3];
    k[3] = (3 * (((f[i] - f[i-1]) / h[i]) - ((f[i-1] - f[i-2]) / h[i-1])));
    cout << k[0] << "C3 + " << k[1] << "C4 =" << k[3] << endl;
    //решить систему и насти переменные С
    // посчитано вручную:
    c[2] = 0.235;
    c[3] = -0.509;
    c[4] = 3.457;
    //найти переменные a, b, c, d
    for (i = 1; i < 5; i++)
        a[i] = f[i-1];
    for (i =1; i < 5; i++)
        cout << "a[i] = " << a[i] << endl ;

    for (i = 1; i < 4; i++)
        b[i] = ((f[i] - f[i - 1]) / h[i]) - ((0.3333) * h[i] * (c[i+1] + (c[i]*2)));
    for (i =1; i < 4; i++)
        cout << "b[i] = " << b[i] << endl ;
    b[n] = ((f[n] - f[n - 1]) / h[n]) - ((0.6666)*h[n]*c[n]);
    cout << "b[n] = " << b[n] << endl ;

    for (i = 1; i < 4; i++)
        d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
    for (i =1; i < 4; i++)
        cout << "d[i] = " << d[i] << endl ;
    d[n] = 0 - (c[n]/(3 * h[n]));
    cout << "d[n] = " << d[n] << endl ;
    cout << 1/3 << endl ;
    //найти F
    F = a[2] + b[2] * (X - x[1]) + c[2] * pow(X - x[1],2) + d[2] * pow(X - x[1],3);
    cout << "F = " << F << endl ;
    return 0;
}