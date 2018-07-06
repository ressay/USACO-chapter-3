/*
ID: bourahl1
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;


int main0()
{
    int mod = 100000000;
    ifstream fin;
    ofstream fout;
    fin.open("fact4.in");
    fout.open("fact4.out");

    if(fin.is_open())
    {
        int N;
        fin >> N;
        long long result = 1;
        for (int i = 2; i <= N; ++i) {
            result *= i;
//            cout << "before % " << result << endl;
            while((result%10) == 0)result /=10;
            result = result%mod;
//            cout << "after % " << result << endl;
        }
        while(result%10 == 0) result/=10;
        result %= 10;
        cout << result << endl;
        fout << result << endl;
    }
    return 0;
}

