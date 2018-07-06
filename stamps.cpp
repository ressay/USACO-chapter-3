/*
ID: bourahl1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;


int main6()
{
    ifstream fin;
    ofstream fout;
    fin.open("stamps.in");
    fout.open("stamps.out");

    if(fin.is_open())
    {
        int K,N;
        fin >> K >> N;
        int stamps[N];
        int max = 0;
        for (int i = 0; i < N; ++i) {
            fin >> stamps[i];
            if(max < stamps[i])
                max = stamps[i];
        }
        int* sequence = new int[max*K+1];
        for (int i = 0; i <= max*K; ++i) {
            sequence[i] = 0;
        }
        for (int i = 0; i < N; ++i) {
            sequence[stamps[i]] = 1;
        }

        if(!sequence[1])
        {
            cout << "0" << endl;
            fout << "0" << endl;
        }

        int count = 1;
        for (int i = 2; i < max*K+1; ++i) {
            for (int j = 0; j < N; ++j) {
                if(i-stamps[j] > 0 && (!sequence[i] || sequence[i-stamps[j]] + 1 < sequence[i]))
                    sequence[i] = sequence[i-stamps[j]] + 1;
            }
            if(!sequence[i] || sequence[i] > K)
                break;
            count++;
        }

        cout << count << endl;
        fout << count << endl;
    }
    return 0;
}