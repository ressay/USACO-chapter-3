/*
ID: bourahl1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;

long long countBits(int n,int k)
{
    long long result = 1;
    long long fn = 1, ck = 1;
    if(!n) return 1;
    if(k>n) k = n;
    for (int i = 1; i <= k; ++i) {
        fn *= n-i+1;
        fn /= i;
        result += fn;
    }
    return result;
}



int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("kimbits.in");
    fout.open("kimbits.out");

    if(fin.is_open())
    {
        int N,L;
        long long I;
        fin >> N >> L >> I;
        string result = "";
        for (int i = 0; i < N; ++i) {
            result += "0";
        }
        if(I==2) result[result.length()-1] = '1';
        if(I <= 2)
        {
            cout << result << endl;
            fout << result << endl;
            return 0;
        }
        I--;
        for (int i = 1; i <= L; ++i) {
            for (int j = 0; j < N; ++j) {
                if(countBits(j+1,L-i+1) > I)
                {
                    I -= countBits(j,L-i+1);
                    result[N-j-1] = '1';
                    break;
                }
            }
            if(I<=0)
                break;
        }
        cout << result << endl;
        fout << result << endl;
    }
    return 0;
}

