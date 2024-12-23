#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Вычисление точного значения функции
double exactFunction(double x)
{
    return (0.25 * log((1 + x) / (1 - x))) + (0.5 * atan(x));
}

// Вычисление ряда с заданным числом членов (рекурсивно)
double calculateSeriesByN(double x, int n)
{
    if (n == 0)
        return x; // Первый член ряда

    double prevTerm = calculateSeriesByN(x, n - 1);
    double currentTerm = pow(x, 4 * n + 1) / (4 * n + 1);
    return prevTerm + currentTerm;
}

// Вычисление ряда с заданной точностью (рекурсивно)
double calculateSeriesByE(double x, double tolerance, double term = 0, int n = 0)
{
    double currentTerm = pow(x, 4 * n + 1) / (4 * n + 1);
    if (fabs(currentTerm) <= tolerance)
        return term + currentTerm;

    return calculateSeriesByE(x, tolerance, term + currentTerm, n + 1);
}

int main()
{
    const double start = 0.1;
    const double end = 0.8;
    const int steps = 10;
    const int maxTerms = 3;
    const double tolerance = 0.0001;
    const double stepSize = (end - start) / steps;

    cout << fixed << setprecision(6);
    cout << "  x        Sn         Se         y" << endl;
    cout << "-------------------------------------" << endl;

    for (double x = start; x <= end; x += stepSize)
    {
        double seriesByN = calculateSeriesByN(x, maxTerms);
        double seriesByE = calculateSeriesByE(x, tolerance);
        double exactValue = exactFunction(x);

        cout << setw(7) << x
            << setw(10) << seriesByN
            << setw(10) << seriesByE
            << setw(10) << exactValue << endl;
    }

    return 0;
}
