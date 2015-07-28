#include <stdio.h>
#include <stdlib.h>

#define DEBUG1 1

int main()
{

    #if DEBUG1
    freopen("1004.in", "r", stdin);
    #endif // DEBUG1

    float sum = 0.0, input = 0.0;
    int n;
    for(n=0; n<12; n++)
    {
        scanf("%f", &input);
        sum += input;
    }
    sum /= 12;
    //sum += 0.005;
    printf("$%.2f", sum);
    return 0;
}