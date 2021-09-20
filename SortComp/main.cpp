/*
 * Quick comparion between the run time of insert sort and merge sort.
 * This program shows that when the input size n is small, a slow algorithm
 * such as insertion sort will perform better than a more efficient algorithm
 * such as merge sort. However, there is a cross-over point where the
 * merge sort starts to output perform insertion sort.
 */
#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * Run time of insertion sort.
 */
double isort(int n)
{
    double c1 = 5; // Some constant

    return c1 * n * n;
}

/*
 * Run time of merge sort.
 */
double msort(int n)
{
    double c1 = 20; // Some constant

    double res = log2(n);

    return c1 * n * res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i = 1; i < 25; i++)
    {
        int r1 = isort(i);
        int r2 = msort(i);
        cout << "n = " << setw(2) << i << "\t\t";
        cout << "r1 = " << setw(4) << r1 << "\tr2 = " << setw(4) << r2 << endl;
    }

    return a.exec();
}
