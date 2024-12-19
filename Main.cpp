#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f_exact(double x) 
{
    return (0.25 * log((1 + x) / (1 - x))) + (0.5 * atan(x));
}

double power_series_n(double x, int n) 
{
    return x + pow(x, 4 * n + 1) / (4 * n + 1);
}

double power_series_e(double x, double e) 
{
    double sum = x;
    double term;
    int n = 1;
    do 
    {
        term = pow(x, 4 * n + 1) / (4 * n + 1);
        sum += term;
        n++;
    } while (fabs(term) > e);
    return sum;
}

int main() 
{
    double a = 0.1;
    double b = 0.8;
    int k = 10;
    int n = 3;
    double e = 0.0001;
    double step = (b - a) / k;

    cout << fixed << setprecision(6);
    for (double x = a; x <= b; x += step) 
    {
        double Sn = power_series_n(x, n);
        double Se = power_series_e(x, e);
        double y = f_exact(x);

        cout << "x= " << x << " Sn = " << Sn << " Se = " << Se << " y = " << y << endl;
    }

    return 0;
}
