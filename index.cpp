#include <bits/stdc++.h>
using namespace std;

// Function to check if all chefs have been able to claim all the ingredients they need without causing a deadlock
bool isDeadlockFree(int n, int r, vector<vector<int>> &maximum)
{
    vector<vector<int>> allocated(n, vector<int>(r, 0));
    vector<int> available(r, 0);
    vector<vector<int>> need(n, vector<int>(r, 0));
    vector<int> work = available;

    // Calculate the need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }

    // Calculate the total number of jars of each ingredient currently available
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < n; i++)
        {
            available[j] += maximum[i][j];
        }
    }

    // Loop until all chefs have been able to claim all the ingredients they need without causing a deadlock
    while (true)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (workAvailable(i, need, work))
            {
                found = true;
                allocateResources(i, allocated, need, work, available);
                if (all_of(need[i].begin(), need[i].end(), [](int i)
                           { return i <= 0; }))
                {
                    break;
                }
            }
        }
        if (!found)
        {
            return false;
        }
        if (all_of(available.begin(), available.end(), [](int i)
                   { return i <= 0; }))
        {
            return true;
        }
    }
}


int main()
{
    int n, r;
    cout << "Enter the number of chefs: ";
    cin >> n;
    cout << "Enter the maximum number of jars of each ingredient that each chef may need: ";
    cin >> r;
}