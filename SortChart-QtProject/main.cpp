/*
 * This program compares the running time between insertion sort and merge sort.
 * The running time are plotted in line charts. It demonstrates that when the input
 * size is small, insertion sort outperforms merge sort. But there is always a cross-over
 * point where merge sort starts to outperform insertion sort.
 *
 * Students can vary the constants which can represent the difference in overhead of
 * different sorting algorithms as well as possilby the difference between the
 * running speed of different machines that are used to execute the algorithms.
 *
 * In short, no matter how large the overhead is and how different the machine speed can
 * be, there is always such "cross-over" point that merge sort is better.
 * */

#include "mainwindow.h"
#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <iostream>
#include <cmath>

using namespace std;
QT_CHARTS_USE_NAMESPACE

// Parameters to be tweaked.
const double C1 = 5; // Constant for Insertion Sort
const double C2 = 5000; // Constant for Merge Sort
const int N = 50000; // Size of input

/*
 * Run time of insertion sort.
 */
double isort(int n)
{
    // double c1 = 5; // Some constant

    return C1 * n * n;
}

/*
 * Run time of merge sort.
 */
double msort(int n)
{
    // double c1 = 20; // Some constant

    double res = log2(n);

    return C2 * n * res;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineSeries *isrt = new QLineSeries();
    QLineSeries *msrt = new QLineSeries();

    isrt->setName("Insertion Sort");
    msrt->setName("Merge Sort");
    isrt->append(0, 0);
    msrt->append(0, 0);

    for (int i=1; i <= N; i++)
    {
        double r1 = isort(i);
        double r2 = msort(i);
        isrt->append(i, r1);
        msrt->append(i, r2);
    }

    QChart *chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->addSeries(isrt);
    chart->addSeries(msrt);
    chart->createDefaultAxes();
    chart->setTitle("Run time comparison");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    MainWindow w;
    w.setCentralWidget(chartView);
    w.resize(800,600);
    w.show();

    return a.exec();
}
