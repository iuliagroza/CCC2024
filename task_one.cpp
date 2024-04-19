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
        map<char, int> cnt;
        fin >> path;
        for (int j = 0; j < path.length(); j++)
        {
            cnt[path[j]]++;
        }

        fout << cnt['W'] << " " << cnt['D'] << " " << cnt['S'] << " " << cnt['A'] << "\n";
    }
    return 0;
}