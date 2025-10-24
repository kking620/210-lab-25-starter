#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int CODES_SZ = 20000;

int main() {
    list<string> lTrip;
    set<string> sTrip;

    ifstream fin("codes.txt");
    string codes[CODES_SZ];
    int i = 0;
    while (fin >> codes[i++]);
    fin.close();

    auto start = high_resolution_clock::now();

    vector<string> vTrip;
    for (int i = 0; i < CODES_SZ; i++) {
        vTrip.push_back(codes[i]);
    }



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/