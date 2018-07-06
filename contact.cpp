/*
ID: bourahl1
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
#include "vector"
#include "math.h"

using namespace std;


int main5()
{
    ifstream fin;
    ofstream fout;
    fin.open("contact.in");
    fout.open("contact.out");

    if(fin.is_open())
    {
        int A,B,N;
        fin >> A >> B >> N;
        int** sums = new int*[B+1];
        for (int i = 0; i < B+1; ++i) {
            sums[i] = new int[1<<B];
            for (int j = 0; j < (1<<B); ++j) {
                sums[i][j] = 0;
            }
        }
        int a[B+1] = {};
        bool first = true;
        while (true)
        {
            string s;
            fin >> s;
//            cout << s << endl;
            if(fin.eof())
                break;

            for (int i = A; i <= B; ++i) {

                int mask = (1 << i) -1;
                if(i > s.size() && first)
                    break;
                if(first) {
                    for (int j = 0; j < i; ++j) {
                        a[i] += (s[j] - '0') << (i - j - 1);
                    }
                    sums[i][a[i] & mask]++;
                }

                for (int j = i*first; j < s.size(); ++j) {
                    a[i] = (a[i]<<1) + (s[j]-'0');
                    sums[i][a[i] & mask]++;
                }
            }
            first = false;
            if(fin.eof())
                break;
        }

//        for (int i = A; i <= B; ++i) {
//            cout << i << endl;
//            for (int j = 0; j < (1<<B); ++j) {
//                if(sums[i][j] != 0)
//                    cout << sums[i][j] << " ";
//            }
//            cout << endl;
//        }

        for (int i = 0; i < N; ++i) {
            int max = 0;
            vector<int> k;
            vector<int> svI;
            for (int j = A; j <= B; ++j) {
                for (int l = 0; l < (1<<B); ++l) {
                    if(max < sums[j][l])
                    {
                        max = sums[j][l];
                        k.clear();
                        svI.clear();
                        svI.push_back(j);
                        k.push_back(l);
                    }
                    else if(max == sums[j][l])
                    {
                        svI.push_back(j);
                        k.push_back(l);
                    }
                }
            }
            if(!max)
                break;
            fout << max << endl;
            fout << bitset<32>(k[0]).to_string().substr(32-svI[0],svI[0]);
            if(k.size() == 1)
                fout << endl;
            sums[svI[0]][k[0]] = 0;

            for (int m = 1; m < k.size(); ++m) {

                fout << " " << bitset<32>(k[m]).to_string().substr(32-svI[m],svI[m]);
                sums[svI[m]][k[m]] = 0;

                if((((m+1)%6) == 0) && m < k.size()-1) {
//                    fout << " m is " << m << " " ;
                    fout << endl << bitset<32>(k[++m]).to_string().substr(32 - svI[m], svI[m]);
                    sums[svI[m]][k[m]] = 0;
                }
                if(m == k.size()-1)
                    fout << endl;
            }
        }

    }
    return 0;
}