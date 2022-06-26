//
// Created by Süleyman Karakaşoğlu on 16.06.2022.
//

#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int binary_search(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int find_boundary(std::vector<bool> arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] && (mid == 0 || !arr[mid - 1])) return mid;
        else if (arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int first_not_smaller(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    int boundaryIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            right = mid - 1;
            boundaryIndex = mid;
        } else {
            left = mid + 1;
        }
    }

    return boundaryIndex;
}

int find_first_occurence(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    int first_occurence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
          if (arr[mid] == target) {
              first_occurence = mid;
          }
          right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return first_occurence;
}

int square_root(int n) {
    int left = 1;
    int right = n;

    int closest_root = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (mid * mid <= n) {
            closest_root = mid;
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }

    return closest_root;
}

int find_min_rotated(std::vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;
    int last_elem = arr[right];

    int boundary = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= last_elem) {
            boundary = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return boundary;
}

int peak_of_mountain_array(std::vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;

    int max = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            max = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return max;
}

bool is_feasible(std::vector<int> weights, int truck_capacity, int d) {
    int i = 0, current_day = 1, current_weight = 0;

    while (i < weights.size() && current_day <= d) {
        if (current_weight + weights[i] > truck_capacity) {
            current_day++;
            current_weight = 0;
        }

        current_weight += weights[i];
        i++;
    }

    return current_day <= d;
}

int min_max_weight(std::vector<int> weights, int d) {

    int max = 0, sum = 0;

    for (auto i = 0; i < weights.size(); i++) {
        if (max < weights[i]) {
            max = weights[i];
        }

        sum += weights[i];
    }

    int left = max;
    int right = sum;

    int feasible_index = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_feasible(weights, mid, d)) {
            feasible_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return feasible_index;
};

int newspapers_split(std::vector<int> newspapers, int coworkers) {

    int max = 0, sum = 0;

    for (auto i = 0; i < newspapers.size(); i++) {
        if (max < newspapers[i]) {
            max = newspapers[i];
        }

        sum += newspapers[i];
    }

    int left = max;
    int right = sum;

    int minimum_time = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_feasible(newspapers, mid, coworkers)) {
            minimum_time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return minimum_time;
}