#include <iostream>
#include <fstream>
#include <map>

using namespace std;
ifstream fin("ccc.in");
ofstream fout("ccc.out");

pair<int, int> countInit(string path)
{
    int isol = 0, jsol = 0;
    int iMin = isol;
    int jMin = jsol;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == 'A')
        {
            jsol--;
            jMin = min(jMin, jsol);
        }
        else if (path[i] == 'D')
        {
            jsol++;
            jMin = min(jMin, jsol);
        }
        else if (path[i] == 'W')
        {
            isol--;
            iMin = min(iMin, isol);
        }
        else if (path[i] == 'S')
        {
            isol++;
            iMin = min(iMin, isol);
        }
    }
    return {iMin, jMin};
}

int main()
{
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int l = 0, L = 0;
        char mat[1005][1005];
        int cnt[1005][1005];
        string path = "";

        fin >> l >> L;
        fin.get();
        for (int j = 0; j < L; j++)
        {
            for (int k = 0; k < l; k++)
            {
                fin >> mat[j][k];
            }
            fin.get();
        }
        fin >> path;

        for (int j = 0; j < L; j++)
        {
            for (int k = 0; k < l; k++)
            {
                cnt[j][k] = 0;
            }
        }

        pair<int, int> coord = countInit(path);
        int ipos = abs(coord.first);
        int jpos = abs(coord.second);

        bool ok = true;
        if (ipos < 0 || ipos > L || jpos < 0 || jpos > l)
        {
            fout << "INVALID\n";
            ok = false;
        }

        // fout << ipos << " " << jpos << "\n";
        if (ok)
        {
            cnt[ipos][jpos]++;
            for (int j = 0; j < path.length() && ok; j++)
            {
                if (mat[ipos][jpos] == 'X')
                {
                    fout << "INVALID\n";
                    ok = false;
                }
                if (path[j] == 'W')
                {
                    ipos--;
                    if (ipos < 0 || ipos > L || jpos < 0 || jpos > l)
                    {
                        fout << "INVALID\n";
                        ok = false;
                    }

                    if (ok)
                    {
                        cnt[ipos][jpos]++;
                    }
                }
                else if (path[j] == 'D')
                {
                    jpos++;
                    if (ipos < 0 || ipos > L || jpos < 0 || jpos > l)
                    {
                        fout << "INVALID\n";
                        ok = false;
                    }

                    if (ok)
                    {
                        cnt[ipos][jpos]++;
                    }
                }
                else if (path[j] == 'S')
                {
                    ipos++;
                    if (ipos < 0 || ipos > L || jpos < 0 || jpos > l)
                    {
                        fout << "INVALID\n";
                        ok = false;
                    }

                    if (ok)
                    {
                        cnt[ipos][jpos]++;
                    }
                }
                else if (path[j] == 'A')
                {
                    jpos--;
                    if (ipos < 0 || ipos > L || jpos < 0 || jpos > l)
                    {
                        fout << "INVALID\n";
                        ok = false;
                    }

                    if (ok)
                    {
                        cnt[ipos][jpos]++;
                    }
                }
            }

            if (ok)
            {
                /*fout << L << " " << l << "\n";
                for (int j = 0; j < L; j++)
                {
                    for (int k = 0; k < l; k++)
                    {
                        fout << cnt[j][k] << " ";
                    }
                    fout << "\n";
                }*/
                for (int j = 0; j < L && ok; j++)
                {
                    for (int k = 0; k < l && ok; k++)
                    {
                        if (cnt[j][k] != 1 && mat[j][k] != 'X')
                        {
                            fout << "INVALID\n";
                            ok = false;
                        }
                    }
                }

                if (ok)
                {
                    fout << "VALID\n";
                }
            }
        }
    }
    return 0;
}