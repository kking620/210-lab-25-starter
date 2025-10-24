#include <iostream>
#include <iomanip>
#include <algorithm>
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
    auto vStart1 = high_resolution_clock::now();

    vector<string> vTrip;
    string codes;
    while (getline(vFin, codes)) {
        vTrip.push_back(codes);
    }

    auto vEnd1 = high_resolution_clock::now();
    auto vDuration1 = duration_cast<microseconds>(vEnd1 - vStart1);
    vFin.close();

    ifstream lFin("codes.txt");
    auto lStart1 = high_resolution_clock::now();

    list<string> lTrip;
    while (getline(lFin, codes)) {
        lTrip.push_back(codes);
    }

    auto lEnd1 = high_resolution_clock::now();
    auto lDuration1 = duration_cast<microseconds>(lEnd1 - lStart1);
    lFin.close();

    ifstream sFin("codes.txt");
    auto sStart1 = high_resolution_clock::now();

    set<string> sTrip;
     while (getline(sFin, codes)) {
        sTrip.insert(codes);
    }

    auto sEnd1 = high_resolution_clock::now();
    auto sDuration1 = duration_cast<microseconds>(sEnd1 - sStart1);
    sFin.close();

    cout << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set\n";
    cout << "Read" << setw(20) << vDuration1.count() << setw(16) << lDuration1.count() << setw(15) << sDuration1.count() << endl;
    
    auto vStart2 = high_resolution_clock::now();

    sort(vTrip.begin(), vTrip.end());

    auto vEnd2 = high_resolution_clock::now();
    auto vDuration2 = duration_cast<microseconds>(vEnd2 - vStart2);

    auto lStart2 = high_resolution_clock::now();

    lTrip.sort();

    auto lEnd2 = high_resolution_clock::now();
    auto lDuration2 = duration_cast<microseconds>(lEnd2 - lStart2);

    int sDuration2 = -1;

    cout << "Sort" << setw(20) << vDuration2.count() << setw(16) << lDuration2.count() << setw(15) << sDuration2 << endl;

    auto vStart3 = high_resolution_clock::now();

    vTrip.insert(vTrip.begin() + (vTrip.size()/2), "TESTCODE");

    auto vEnd3 = high_resolution_clock::now();
    auto vDuration3 = duration_cast<microseconds>(vEnd3 - vStart3);

    auto lStart3 = high_resolution_clock::now();

    auto lIt = lTrip.begin();
    advance(lIt, (lTrip.size()/2)-1);
    lTrip.insert(lIt, "TESTCODE");

    auto lEnd3 = high_resolution_clock::now();
    auto lDuration3 = duration_cast<microseconds>(lEnd3 - lStart3);

    auto sStart3 = high_resolution_clock::now();

    sTrip.insert("TESTCODE");

    auto sEnd3 = high_resolution_clock::now();
    auto sDuration3 = duration_cast<microseconds>(sEnd3 - sStart3);

    cout << "Sort" << setw(20) << vDuration3.count() << setw(16) << lDuration3.count() << setw(15) << sDuration3.count() << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/