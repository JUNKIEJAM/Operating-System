#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k;
 
    cout << "Number of processes: ";
    cin >> m;

    cout << "Number of frames: ";
    cin >> n;
    
    vector<int> p(m);
    cout << "Enter the reference string: ";
    for (i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    cout<<endl;

    vector<vector<int>> a(n, vector<int>(m, -1));
    map<int, int> mp;
    for (i = 0; i < m; i++)
    {
        vector<int> op;
        vector<pair<int, int>> c;
        for (auto q : mp)
        {
            c.push_back({q.second, q.first});
        }
        for (int q = i + 1; q < m; q++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[j][i] == p[q])
                {
                    op.push_back(p[q]);
                }
            }
        }
        sort(op.begin(), op.end());
        op.erase(unique(op.begin(), op.end()), op.end());
        bool dontCall = true;
        if (op.size() == n)
        {
            dontCall = false;
        }
        sort(c.begin(), c.end());
        bool hasrun = false;
        for (j = 0; j < n; j++)
        {
            if (a[j][i] == p[i])
            {
                mp[p[i]]++;
                hasrun = true;
                break;
            }
            if (a[j][i] == -1)
            {
                for (k = i; k < m; k++)
                    a[j][k] = p[i];
                mp[p[i]]++;
                hasrun = true;
                break;
            }
        }
        if (j == n || hasrun == false)
        {
            for (j = 0; j < n; j++)
            {
                if (dontCall == true)
                {
                    if (a[j][i] == c[c.size() - 1].second)
                    {
                        mp.erase(a[j][i]);
                        for (k = i; k < m; k++)
                            a[j][k] = p[i];
                        mp[p[i]]++;
                        break;
                    }
                }
                else if (dontCall == false)
                {
                    if (a[j][i] == op[op.size() - 1])
                    {
                        mp.erase(a[j][i]);
                        for (k = i; k < m; k++)
                            a[j][k] = p[i];
                        mp[p[i]]++;
                        break;
                    }
                }
            }
        }
        for (auto q : mp)
        {
            if (q.first != p[i])
            {
                mp[q.first]++;
            }
        }
    }
    int hit = 0;
    vector<int> hitv(m);

    for (i = 1; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i] == a[j][i - 1])
            {
                hit++;
                hitv[i] = 1;
                break;
            }
        }
    }

    cout << "Process: ";
    for (i = 0; i < m; i++)
    {
        cout << p[i] << " ";
    }
    cout << '\n';
    for (i = 0; i < n; i++)
    {
        cout << "Frame" << i + 1 << ":  ";
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == -1)
                cout << "x ";
            else
                cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "\n";
    cout << "Total Page Hits " << hit << '\n'
         << endl;
    cout << "TotalPage Faults " << m - hit << '\n'
         << endl;
    float ratio = hit / m;

    cout << "Page Hit Ratio: " << ratio << endl;
    cout << "Page Fault Ratio: " << 1 - ratio << endl;
    return 0;
}