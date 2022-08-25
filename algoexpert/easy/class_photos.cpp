//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//

#include <vector>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
    // Write your code here.
    std::sort(redShirtHeights.begin(), redShirtHeights.end());
    std::sort(blueShirtHeights.begin(), blueShirtHeights.end());

    bool placeRedsToBackRow = false, placeBluesToBackRow = false;
    if (redShirtHeights[0] > blueShirtHeights[0]) {
        placeRedsToBackRow = true;
    } else if (blueShirtHeights[0] > redShirtHeights[0]) {
        placeBluesToBackRow = true;
    } else return false;

    for (auto i = 0; i < redShirtHeights.size(); i++) {
        auto current_red = redShirtHeights[i];
        auto current_blue = blueShirtHeights[i];

        if (placeRedsToBackRow && current_red <= current_blue) return false;
        if (placeBluesToBackRow && current_blue <= current_red) return false;
    }
    return true;
}
