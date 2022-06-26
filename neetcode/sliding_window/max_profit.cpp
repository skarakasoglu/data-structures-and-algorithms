//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <vector>

int maxProfit(std::vector<int>& prices) {
    int i = 0, j = i + 1;

    int max_profit = 0;
    while (j < prices.size()) {
        if (prices[j] > prices[i]) {
            max_profit = std::max(max_profit, prices[j] - prices[i]);
        } else {
            i = j;
        }
        j++;
    }

    return max_profit;
}