#include <iostream>
#include <string>

using namespace std;

int main()
{
    int table[26] = { 0 };
    int lines;
    string line;

    cin >> lines;

    lines++;

    while (lines) {
        lines--;
        getline(cin, line);

        for (int index = 0; index < line.length(); index++){
            if ('A' <= line[index] && 'Z' >= line[index]) {
                table[line[index] - 'A'] += 1;
            }
            else if ('a' <= line[index] && 'z' >= line[index]) {
                table[line[index] - 'a'] += 1;
            }
    }
}

    for (int i = 0; i < 26; i++) {
        int maxmium;
        int max_val = 0;
        for (int j = 0; j < 26; j++) {
            if (table[j] > max_val) {
                max_val = table[j];
                maxmium = j;
            }
        }
        if (max_val == 0) break;
        else {
            cout << char('A' + maxmium) << " " << max_val << endl;
            table[maxmium] = 0;
        }
    }
}