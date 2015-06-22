/**
 * HUST ACM Contest - Algorithm Practice 1
 * http://acm.hust.edu.cn/vjudge/contest/view.action?cid=80772#overview
 *
 * Elections
 *
 * Description
 * The next in turn elections are to come soon. All the fences are posted with
 * leaflets and the mail boxes are full of throwaways. Cheeky guys are looking
 * at us from TV's and promise to make our life better... And programmer
 * Vasechkin is knee-deep in work. He is to write a program that would calculate
 * the result of voting.
 *
 * Input
 * The first line contains a number of candidates N (1 <= N <= 10,000) and a
 * number of electors M (1 <= M <= 10,000). Then M lines follow, each one
 * contains a number of candidate that the elector voted for. The candidates are
 * numbered with integers from 1 to N.
 *
 * Output
 * Output N lines, The i-th line should contain the percent of electors that
 * voted for the i-th candidate (to within 2 decimals).
 *
 * Sample Input & Output
================================================================================
3 6
1
2
3
2
1
1
--------------------------------------------------------------------------------
50.00%
33.33%
16.67%
================================================================================
 */
#include <iostream>

using namespace std;

#define DEBUG1          1
#define MAX_CANDIDATES  10001

int main () {
#if DEBUG1
    freopen("A.in", "r", stdin);
#endif // DEBUG1
    int candidates = 0, electors = 0;
    int result[MAX_CANDIDATES] = {0};
    int election;
    // scanf("%d %d", &candidates, &electors);
    cin >> candidates >> electors;
    for (int i = 0; i < electors; i++) {
        // scanf("%d", &election);
        cin >> election;
        result[election] += 1;
    }
    for (int i = 1; i <= candidates; i++) {
        printf("%.2f%%\n", (float)result[i] / (float)electors * 100);
        
    }
}
