/**
    POJ 1068 Parencodings
    SW Cert. Week 1

    132k 0ms
    */

#include <stdio.h>
#include <stdlib.h>

#define debug1 1
#define debug2 1

int main() {
#if debug1
    freopen("1068.in", "r", stdin);
    //freopen("1068.out", "w", stdout);
#endif // debug 1
    int cases = 0;
    scanf("%d", &cases);
    while (cases--) {
        int n = 0;
        int p[20] = { 0 };
        int w[20] = { 0 };
        int parentheses[40] = { 0 };
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        int pos = 0;    // mark for rounds
        int parent_pos = 0;      // index of parentheses[]
        for (int i = 0; i < n; i++) {
            parent_pos = pos;
            while (parent_pos < pos + p[i] - (i == 0 ? 0 : p[i - 1])) {    // prevent p[-1]
                parentheses[parent_pos++] = 1;
            }
            parentheses[parent_pos++] = -1;
            pos = parent_pos;
        }
#if debug1
        // check the parentheses array
        for (int i = 0; i < 2 * n; i++)
            printf("%2d ", parentheses[i]);
        printf("\n");
#endif

        pos = 0;
        for (parent_pos = 0; parent_pos < 2 * n; parent_pos++) {    // scan the parenthese array
            if (parentheses[parent_pos] == 1) {
                continue;
            }
            int count = 0;
            int sum = parentheses[parent_pos];
            for (int j = parent_pos - 1; j >= 0; j--) {
                if (parentheses[j] == 1)
                    count++;
                sum += parentheses[j];
                if (sum == 0) {
                    w[pos++] = count;
                    count = 0;
#if debug2
                    for (int w_pos = 0; w_pos < n; w_pos++) {
                        printf("%d ", w[w_pos]);
                    }
                    printf("\n");
#endif
                    break;
                }
            }
        }
        for (int w_pos = 0; w_pos < n; w_pos++) {
            printf("%d ", w[w_pos]);
        }
        printf("\n");
    }
    return 0;
}
