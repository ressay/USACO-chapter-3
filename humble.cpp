/*
ID: bourahl1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;

int main3()
{
    ifstream fin;
    ofstream fout;
    fin.open("humble.in");
    fout.open("humble.out");
    if(fin.is_open())
    {
        int K,N;
        fin >> K >> N;
        int* nums = new int[N+2];
        int S[K],I[K] = {};
        for (int i = 0; i < K; ++i) {
            fin >> S[i];
        }

        nums[0] = 1;
        for (int i = 1; i < N+1; ++i) {
            int min = nums[I[0]]*S[0];
            int k = 0;
            for (int j = 1; j < K; ++j) {
                if(min > nums[I[j]]*S[j])
                {
                    min = nums[I[j]]*S[j];
                    k = j;
                }
            }
            nums[i] = min;
            I[k]++;
            for (int j = 0; j < K; ++j) {
                if(nums[I[j]]*S[j] == min)
                    I[j]++;
            }
//            cout << i << "-min " << min << endl;
        }

        cout << nums[N] << endl;
        fout << nums[N] << endl;
    }
    return 0;
}