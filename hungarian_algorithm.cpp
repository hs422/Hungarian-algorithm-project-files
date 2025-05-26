#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();

int hungarian(const vector<vector<int>>& costMatrix, vector<int>& assignment) {
    int n = costMatrix.size(), m = costMatrix[0].size();
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    assignment.resize(n);
    for (int j = 1; j <= m; ++j)
        if (p[j] > 0)
            assignment[p[j] - 1] = j - 1;
    return -v[0];
}

int main() {
    vector<vector<int>> costMatrix = {
        {9, 11, 14, 11, 7},
        {6, 15, 13, 13, 10},
        {12, 13, 6, 8, 8},
        {11, 9, 10, 12, 9},
        {7, 12, 14, 10, 14}
    };

    vector<int> assignment;
    int cost = hungarian(costMatrix, assignment);

    cout << "Minimum cost: " << cost << endl;
    for (int i = 0; i < assignment.size(); ++i)
        cout << "Task " << i + 1 << " assigned to Worker " << assignment[i] + 1 << endl;

    return 0;
}
