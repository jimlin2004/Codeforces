#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
    模擬會失敗，正確作法是先用一遍的時間計算遊戲最後的最高分M
    然後檢查每一輪當有玩家的分數出現不低於M且最後他得到M分
    那他就是最後贏家
*/

unordered_map<string, int> finalScoreBoard;
unordered_map<string, int> scoreBoard;

vector<pair<string, int>> history;

int main()
{
    int n;
    cin >> n;
    int M = -0x3f3f3f3f;
    string winner;
    string player;
    int gain;
    for (int i = 0; i < n; ++i)
    {
        cin >> player >> gain;
        history.emplace_back(player, gain);
        finalScoreBoard[player] += gain;
    }
    // 迭代一遍找最高的M
    for (auto& p: finalScoreBoard)
        M = max(M, p.second);
    // 找出贏家
    for (auto& line: history)
    {
        int& score = scoreBoard[line.first];
        score += line.second;
        if (score >= M)
        {
            if (finalScoreBoard[line.first] == M)
            {
                winner = line.first;
                break;
            }
        }
    }

    cout << winner << '\n';
    return 0;
}