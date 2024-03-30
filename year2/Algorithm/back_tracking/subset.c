#include <stdio.h>

void print_sol(int set[], int x[], int n) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d ", set[i - 1]);
        }
    }
    printf("\n");
}

void subset_sum(int set[], int x[], int l, int r, int target) {
    if (l == r) {
        int sum = 0;
        for (int i = 1; i <= r; i++) {
            if (x[i] == 1) {
                sum += set[i - 1];
            }
        }
        if (sum == target) {
            print_sol(set, x, r);
        }
    } else {
        x[l + 1] = 1;
        subset_sum(set, x, l + 1, r, target);
        x[l + 1] = 0;
        subset_sum(set, x, l + 1, r, target);
    }
}

int main() {
    int set[] = {25, 10, 9, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int x[n + 1] = {0};
    int target = 36;
    subset_sum(set, x, 0, n, target);
    return 0;
}