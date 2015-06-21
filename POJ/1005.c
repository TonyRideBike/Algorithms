#include <stdio.h>
#include <stdlib.h>

#define DEBUG1 1

double pi = 3.141592653;

int main()
{

    #if DEBUG1
    freopen("1005.in", "r", stdin);
    #endif // DEBUG1

    int i = 1, n;
    scanf("%d", &n);
    while(i <= n)
    {
        double x, y;
        int year = 1;
        double distance, r = (50 * year * 2) / pi;
        scanf("%lf %lf", &x, &y);
        distance = x * x + y * y;
        while(r < distance)
        {
            year++;
            r = (50 * year * 2) / pi;
        }
        printf("Property %d: This property will begin eroding in year %d.\n", i, year);
        i++;
    }
    printf("END OF OUTPUT.");
    return 0;
}