//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
    std::unordered_map<std::string, int> team_points;
    auto maximum_point_it = team_points.end();
    for (auto i = 0; i < competitions.size(); i++) {
        auto winner_team_index = 1 - results[i];
        auto winner_team_point_insert_it = team_points.insert({competitions[i][winner_team_index], 3});
        if (!winner_team_point_insert_it.second) {
            winner_team_point_insert_it.first->second += 3;
        }

        if (maximum_point_it == team_points.end() || maximum_point_it->second < winner_team_point_insert_it.first->second) {
            maximum_point_it = winner_team_point_insert_it.first;
        }
    }

    return maximum_point_it->first;
}