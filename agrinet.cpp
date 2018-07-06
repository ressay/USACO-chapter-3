/*
ID: bourahl1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;


int main1()
{
    ifstream fin;
    ofstream fout;
    fin.open("agrinet.in");
    fout.open("agrinet.out");
    if(fin.is_open())
    {
        int N;
        fin >> N;
        int adj[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                fin >> adj[i][j];
            }
        }
        int minCost = 0;
        vector<int> v;
        bool done[N] = {};
        done[0] = true;
        v.push_back(0);
        while (v.size()!=N)
        {
            int m = 200000;
            int summet = -1;
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < N; ++j) {
                    if(v[i]!=j && !done[j] && adj[v[i]][j] < m)
                    {
                        m = adj[v[i]][j];
                        summet = j;
                    }
                }
            }
            minCost += m;
            v.push_back(summet);
            done[summet] = true;
        }

        cout << minCost << endl;
        fout << minCost << endl;
    }
    return 0;
}