// Lab 5_4.cpp
// Завдання № 5.4. Варіант 30
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 5) Ітераційний спосіб
double S0(const int N)
{
    double s = 0;
    for (int i = 1; i <= N; i++)
        s += (1.0 + (1.0 * i) / N) / (i * i);
    return s;
}

// 4) Рекурсивний підйом, i зростає
double S1(const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (1.0 + (1.0 * i) / N) / (i * i) + S1(N, i + 1);
}

// 3) Рекурсивний підйом, i спадає
double S2(const int N, const int i)
{
    if (i < 1)
        return 0;
    else
        return (1.0 + (1.0 * i) / N) / (i * i) + S2(N, i - 1);
}

// 2) Рекурсивний спуск, i зростає
double S3(const int N, const int i, double t)
{
    t = t + (1.0 + (1.0 * i) / N) / (i * i);
    if (i >= N)
        return t;
    else
        return S3(N, i + 1, t);
}

// 1) Рекурсивний спуск, i спадає
double S4(const int N, const int i, double t)
{
    t = t + (1.0 + (1.0 * i) / N) / (i * i);
    if (i <= 1)
        return t;
    else
        return S4(N, i - 1, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << fixed << setprecision(5);
    cout << "(iter)        S0 = " << S0(N) << endl;
    cout << "(rec up ++)   S1 = " << S1(N, 1) << endl;
    cout << "(rec up --)   S2 = " << S2(N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(N, 1, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;

    return 0;
}

