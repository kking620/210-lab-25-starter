#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int CODES_SZ = 20000;

int main() {
    ifstream vFin("codes.txt");
    auto vStart = high_resolution_clock::now();

    vector<string> vTrip;
    string codes;
    while (getline(vFin, codes)) {
        vTrip.push_back(codes);
    }

    auto vEnd = high_resolution_clock::now();
    auto vDuration = duration_cast<milliseconds>(vEnd - vStart);
    vFin.close();

    ifstream lFin("codes.txt");
    auto lStart = high_resolution_clock::now();

    list<string> lTrip;
    while (getline(lFin, codes)) {
        lTrip.push_back(codes);
    }

    auto lEnd = high_resolution_clock::now();
    auto lDuration = duration_cast<milliseconds>(lEnd - lStart);
    lFin.close();

    ifstream sFin("codes.txt");
    auto sStart = high_resolution_clock::now();

    set<string> sTrip;
     while (getline(sFin, codes)) {
        sTrip.insert(codes);
    }

    auto sEnd = high_resolution_clock::now();
    auto sDuration = duration_cast<milliseconds>(sEnd - sStart);
    sFin.close();

    cout << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set\n";
    cout << "Read" << setw(20) << vDuration.count() << setw(16) << lDuration.count() << setw(15) << sDuration.count() << endl;
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/