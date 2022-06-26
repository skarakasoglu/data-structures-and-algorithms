//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>

int MODULO_AMT = 1000000007;

int maximum_score(std::vector<int> arr1, std::vector<int> arr2) {
    int ptr1 = 0, ptr2 = 0;
    int n1 = arr1.size(), n2 = arr2.size();

    long long result = 0;
    long long section_sum1 = 0, section_sum2 = 0;

    while (ptr1 < n1 || ptr2 < n2) {

        if (ptr1 < n1 && ptr2 < n2 && arr1[ptr1] == arr2[ptr2]) {
            result += std::max(section_sum1, section_sum2) + arr1[ptr1];
            section_sum1 = 0;
            section_sum2 = 0;
            ptr1++;
            ptr2++;
        }

        if (ptr1 == n1 || (ptr2 != n2 && arr1[ptr1] > arr2[ptr2])) {
            section_sum2 += arr2[ptr2];
            ptr2++;
        } else {
            section_sum1 += arr1[ptr1];
            ptr1++;
        }
    }

    result += std::max(section_sum1, section_sum2);
    return result % MODULO_AMT;
}

int trapping_rain_water(std::vector<int> elevations) {

    int l = 0, r = 1;
    int total_trapped_water = 0, possible = 0;
    bool trapped = false;
    while (r < elevations.size()) {
        if (elevations[r] < elevations[l]) {
            possible += elevations[l] - elevations[r];
            r++;
            trapped = true;
        } else {
            l++;

            if (trapped) {
                total_trapped_water += possible;
                possible = 0;
                l = r;
                trapped = false;
            }
        }

    }

    return total_trapped_water;
}