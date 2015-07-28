#include <stdio.h>
#include <stdlib.h>

#define DEBUG1 1

int main()
{
    #if DEBUG1
    freopen("1003.in", "r", stdin);
    #endif // DEBUG1

    float length = 0;
    scanf("%f", &length);
    while (length != 0.0)
    {
        float sum = 0.0;
        int n = 1;
        while(n > 0)
        {
            sum = sum + (1.0/(n+1.0));
            if(sum > length)
                break;
            n++;
        }
        printf("%d card(s)\n", n);

        scanf("%f", &length);
    }

    return 0;
}