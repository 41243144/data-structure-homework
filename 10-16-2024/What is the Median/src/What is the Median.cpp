#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<long long> table;
    long long number;

    while (cin >> number) {
        auto it = lower_bound(table.begin(), table.end(), number);
        table.insert(it, number);

        auto table_len = table.size();

        if (table_len % 2) {
            cout << table[table_len / 2] << endl;
        }
        else {
            cout << (table[table_len / 2] + table[table_len / 2 - 1]) / 2 << endl;
        }
    }
}
