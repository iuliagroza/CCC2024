#include <iostream>
#include <fstream>
#include <map>

using namespace std;
ifstream fin("ccc.in");
ofstream fout("ccc.out");

int n;
string path;

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int ipos = 0, jpos = 0;
        int iMin = 0, jMin = 0, iMax = 0, jMax = 0;
        fin >> path;
        for (int j = 0; j < path.length(); j++)
        {
            if (path[j] == 'W')
            {
                ipos--;
                iMin = min(iMin, ipos);
                iMax = max(iMax, ipos);
            }
            else if (path[j] == 'D')
            {
                jpos++;
                jMin = min(jMin, jpos);
                jMax = max(jMax, jpos);
            }
            else if (path[j] == 'S')
            {
                ipos++;
                iMin = min(iMin, ipos);
                iMax = max(iMax, ipos);
            }
            else if (path[j] == 'A')
            {
                jpos--;
                jMin = min(jMin, jpos);
                jMax = max(jMax, jpos);
            }
        }

        int L = iMax - iMin + 1;
        int l = jMax - jMin + 1;

        fout << l << " " << L << "\n";
    }
    return 0;
}