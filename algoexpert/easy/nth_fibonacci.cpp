//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
using namespace std;

int getNthFib(int n) {
    if (n == 1) return 0;

    int prev = 0, cur = 1;
    for (int i = 2; i < n; i++) {
        int next = cur + prev;
        prev = cur;
        cur = next;
    }

    return cur;
}
