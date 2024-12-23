#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double fExact(double x)
{
    return (0.25 * log((1 + x) / (1 - x))) + (0.5 * atan(x));
}

double powerSeriesN(double x, int n)
{
    if (n == 0)
        return x; // Первый член ряда

    double prevTerm = powerSeriesN(x, n - 1);
    return prevTerm + pow(x, 4 * n + 1) / (4 * n + 1);
}

double powerSeriesE(double x, double e, double term = 0, int n = 0)
{
    double currentTerm = pow(x, 4 * n + 1) / (4 * n + 1);
    if (fabs(currentTerm) <= e)
        return term + currentTerm;

    return powerSeriesE(x, e, term + currentTerm, n + 1);
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
        double Sn = powerSeriesN(x, n);
        double Se = powerSeriesE(x, e);
        double y = fExact(x);

        cout << "x= " << x << " Sn = " << Sn << " Se = " << Se << " y = " << y << endl;
    }

    return 0;
}
