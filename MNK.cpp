#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]){
    float xi[6] = {-0.9,0,0.9,1.8,2.7,3.6};
    float k[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    float yi[6] = {-0.36892,0,0.36892,0.85408,1.7856,6.3138};
    float a[3] = {0,0,0};
    float f[3] = {0,0,0};
    float F1[3];
    float F2[3];
    float sum;
    float t1,t2,t3;
    int n=5;
    int m=0;
    float OIO;
    k[0][0] = n+1;
    for (int i = 0; i < 6; i++){
        sum += xi[i];
    }
    k[0][1] = sum;
    for (int i = 0; i < 6; i++){
        f[0] += yi[i];
    }
    cout << k[0][0] << " a[0] + " << k[0][1] << " a[1] = " << f[0] << endl;
    sum = 0;

    for (int i = 0; i < 6; i++){
        sum += xi[i];
    }
    k[1][0] = sum;
    sum=0;
    for (int i = 0; i < 6; i++){
        sum += pow(xi[i],2);
    }
    k[1][1] = sum;
    for (int i = 0; i < 6; i++){
        f[1] += yi[i] * xi[i];
    }
    cout << k[1][0] << " a[0] + " << k[1][1] << " a[1] = " << f[1] << endl;

    cout << "a[0] = " << "(f1 / k[0][0]) - ((k[0][1]/k[0][0]+k[1][1])) a[1]" << endl;
    t1=k[0][1];
    t2=k[1][0];
    k[1][0] *= (f[0] / k[0][0]);
    k[0][1] *= -1;
    t3 = k[1][1];
    k[1][1] = ((k[0][1] / k[0][0]) * t2) + k[1][1];
    cout << k[1][0] << " - " << k[1][1] << " a[0] = " << f[1] << endl;
    a[1] =(f[1] - k[1][0]) / k[1][1];
    cout << "a[1] = " << a[1] << endl;
    k[0][1] = t1;
    k[1][1] = t3;
    a[0] = (f[0]/k[0][0])-((k[0][1]*a[1])/k[0][0]);
    cout << (k[0][1]*a[1])/k[0][0] << " , " << f[1]/k[0][0] << endl;
    cout << f[0] << " , " << k[0][0] << " , " << k[0][1] << " , "<< a[1] << endl;
    cout << "a[0] = " << a[0] << endl;
    for (int i = 0; i < 6; i++){
        F1[i] = a[0] + (a[1] * xi[i]);
    } 
    for (int i = 0; i < 6; i++)
        cout << F1[i] <<  " , " << endl;
    for (int i = 0; i < 6; i++){
        OIO += pow(F1[i] - yi[i], 2);
    }
    cout << "число фи =" << OIO << endl;
    k[0][0] = n + 1;
    k[0][1] = 0;
    for (int i = 0; i < 6; i++)
        k[0][1] += xi[i];
    k[1][0] = k[0][1];
    for (int i = 0; i < 6; i++)
        k[0][2] += pow(xi[i],2);
    k[1][1] = k[0][2];
    k[2][0] = k[0][2];
    for (int i = 0; i < 6; i++)
        k[1][2] += pow(xi[i],3);
    k[2][1] = k[1][2];
    for (int i = 0; i < 6; i++)
        k[2][2] += pow(xi[i],4);
        //вывод матрицы
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " , ";
    }
    cout << " . " << endl;
    //подсчет правой матрицы
    for (int i=0; i < 6; i++)
        f[i]=0;
    for (int i=0; i < 6; i++)
            f[0] += yi[i];
    for (int i=0; i < 6; i++)
        f[1] += yi[i]*xi[i];
    for (int i=0; i < 6; i++)
        f[2] += yi[i]*(pow(xi[i],2));
    //вывод правой матрицы
    for (int i=0; i < 3; i++)
        cout << f[i] << " , " << endl;
    //метод гауса
    for (int i = 0; i < 3; i++){
        t1 = k[i][0];
        f[i] /= t1;
        for (int j = 0; j < 3; j++){
            k[i][j] /= t1;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " , ";
    }
    cout << " . " << endl;
    for (int i=0; i < 3; i++)
        cout << f[i] << " , " << endl;
    //второй этап
    for (int i = 1; i < 3; i++){
        for (int j = 0; j < 3; j++){
            k[i][j] -= k[0][j];
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " , ";
    }
    for (int i = 1; i < 3; i++)
        f[i] -= f[0];
    for (int i = 0; i < 3; i++)
        cout << f[i] << endl;
    //третий этап
    for (int i = 1; i < 3; i++){
        t1 = k[i][1];
        f[i] /= t1;
        for (int j = 1; j < 3; j++){
            k[i][j] /= t1;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " , ";
    }
        f[2] -= f[1]; 
    for (int i = 0; i < 3; i++)
        cout << f[i] << endl;
    for (int j = 0; j < 3; j++)
        k[2][j] -= k[1][j];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            cout << k[i][j] << " , ";
    }
    for (int i = 0; i < 3; i++)
        cout << f[i] << endl;
    //четвертый этап
    a[2] = f[2] / k[2][2];
    cout << "a[2]=" << a[2] << endl;
    a[1] = (f[1]-(k[1][2]*a[2]) / k[1][1]);
    cout << "a[1]=" << a[1] << endl;
    a[0] = f[0] - (k[0][1] * a[1]) - (k[0][2] * a[2]);
    cout << "a[0]=" << a[0] << endl;
    //подсчет фи
    OIO = 0;
    for (int i =0; i < 6; i++){
        OIO += pow((a[0] + (a[1] * xi[i]) + (a[2] * pow(xi[i],2))) - yi[i],2);
    }
    cout << OIO << endl;
    return 0;
}