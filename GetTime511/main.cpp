#include <QCoreApplication>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <cmath>
using namespace std;

class CurrentTime {
    std::chrono::high_resolution_clock m_clock;

public:
    uint64_t milliseconds();
    uint64_t microseconds();
    uint64_t nanoseconds();
};

uint64_t CurrentTime::milliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
              (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::microseconds()
{
    return std::chrono::duration_cast<std::chrono::microseconds>
              (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::nanoseconds()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>
              (m_clock.now().time_since_epoch()).count();
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CurrentTime current_time;

    uint64_t start1 = current_time.milliseconds();
    uint64_t start2 = current_time.microseconds();
    uint64_t start3 = current_time.nanoseconds();

    double dd;

    for (int i = 0; i < 100000; ++i) {
        dd = pow(135, 27);
        dd = sqrt(dd)*sqrt(dd);
    }

    uint64_t end1 = current_time.milliseconds();
    uint64_t end2 = current_time.microseconds();
    uint64_t end3 = current_time.nanoseconds();

    cout << dd << endl;
    cout << "Milliseconds: "   << (end1 - start1)
         << ", microseconds: " << (end2 - start2)
         << ", nanoseconds: "  << (end3 - start3)
         << ".\n";

    return a.exec();
}
