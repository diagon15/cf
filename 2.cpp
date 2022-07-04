/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* a[])
{
    //Write code here
    int n;
    cin >> n;
    int room = 1;

    auto contains = [&](string str) -> bool {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '2') return true;
            if (i + 1 < str.size() and str[i] == '1'
                and str[i + 1] == '4') return true;
        }

        return false;
    };


    while (--n) {
        ++room;
        while (contains(to_string(room))) {
            ++room;
        }

    }
    cout << room << endl;
    return 0;
}
