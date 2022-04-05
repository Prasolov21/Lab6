#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]){
    float x[6] = {1, 1.5, 2, 2.5, 3};
    float y[6] = {0, 0.40547, 0.69315, 0.91629, 1.0986};
    float y1l, y1r, y1, y2;
    float X = 2;
    //левостороннюю
    y1l = (y[2] - y[1]) / (x[2] - x[1]);
    cout << "y1l = " << y1l << endl;
    //правостороннюю
    y1r = (y[3] - y[2]) / (x[3] - x[2]);
    cout << "y1r = " << y1r << endl;
    //вычисляем первую производную по формуле
    y1 = y1l + (((y1r - y1l)/(x[3]-x[1])) * (2 * 0.2 - x[1] - x[2]));
    cout << "y1 = " << y1 << endl;
    //находим производную со вторым порядком точности
    y2 = 2 * ((y1r - y1l)/(x[3]-x[1]));
    cout << "y2 = " << y2 << endl;
    return 0;
}