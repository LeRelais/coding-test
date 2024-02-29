#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int dp[152][152];
    for (int i = 0; i <= 150; i++) {
        for (int j = 0; j <= 150; j++) {
            dp[i][j] = 99999999;
        }
    }
    int max_alp_req = 0, max_cop_req = 0;
    for (int i = 0; i < problems.size(); i++) {
        max_alp_req = max(max_alp_req, problems[i][0]);
        max_cop_req = max(max_cop_req, problems[i][1]);
    }

    alp = min(alp, max_alp_req);
    cop = min(cop, max_cop_req);

    dp[alp][cop] = 0;

    for (int i = 0; i <= 150; i++) {
        for (int j = 0; j <= 150; j++) {
            if (i < max_alp_req)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j < max_cop_req)
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            for (int k = 0; k < problems.size(); k++) {
                if (i >= problems[k][0] && j >= problems[k][1]) {
                    int ny = min(i + problems[k][2], max_alp_req);
                    int nx = min(j + problems[k][3], max_cop_req);
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j] + problems[k][4]);
                }

            }
        }
    }
    return dp[max_alp_req][max_cop_req];
}