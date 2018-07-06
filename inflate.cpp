/*
ID: bourahl1
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;

class cat
{
public:
    int mins,pts;
    cat(int mins, int pts) : mins(mins), pts(pts) {}

    cat() {}
};

int compare (const void * a, const void * b)
{
    return ( ((cat*)a)->mins - ((cat*)b)->mins );
}

int main2()
{
    ifstream fin;
    ofstream fout;
    fin.open("inflate.in");
    fout.open("inflate.out");
    if(fin.is_open())
    {
        int M,N;
        fin >> M >> N;
        int best[M+1] = {};
        cat cats[N];
        for (int i = 0; i < N; ++i) {
            fin >> cats[i].pts >> cats[i].mins;
        }

        qsort(cats,N,sizeof(cat),compare);

        for (int i = 1; i <= M; ++i) {
            best[i] = best[i-1];
            for (int j = 0; j < N; ++j) {
                if(cats[j].mins > i)
                    break;
                if(best[i] < best[i-cats[j].mins]+cats[j].pts)
                    best[i] = best[i-cats[j].mins]+cats[j].pts;
            }
        }

        cout << best[M] << endl;
        fout << best[M] << endl;
    }
    return 0;
}