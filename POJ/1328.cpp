/**
    POJ 1328 Radar Installation
    SW Cert. week 6
    Greedy Algorithm

    260k 63ms
    */

#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

static int islands, radiation;
static int cases;
int coords[1005][2];
double range[1005][2];

//int stingy();
void sort(int l);
//double sqrt(int x);

int main()
{
    freopen("1328.in", "r", stdin);
    cin >> islands >> radiation;
    while (!(islands == 0 && radiation == 0))
    {
        cases++;
        int radars = 0;
        double right = 0;
        bool nosolution = false;
        for (int i = 0; i < islands; i++)
        {
            cin >> coords[i][0] >> coords[i][1];
            if (coords[i][1] > radiation || coords[i][1] < 0 || radiation <=0)
            {
                nosolution = true;
            }
        }
        if (nosolution)
        {
            radars = -1;
        }
        else
        {
            for (int i = 0; i < islands; i++)
            {
                double delta = sqrt((double)radiation * radiation - coords[i][1] * coords[i][1]);
                range[i][0] = coords[i][0] - delta;
                range[i][1] = coords[i][0] + delta;
            }
            sort(islands);
            for (int i = 0; i < islands; i++)
            {
                if (i == 0)
                {
                    radars = 1;
                    right = range[i][1];
                }
                else
                {
                    if (range[i][0] > right)
                    {
                        radars++;
                        right = range[i][1];
                    }
                    else
                    {
                        right = right > range[i][1] ? range[i][1] : right;
                    }
                }
            }
        }
        cout << "Case " << cases << ": " << radars << endl;
        cin >> islands >> radiation;
    }
    return 0;
}

void sort(int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (range[i][0] > range[j][0])
            {
                double x = range[i][0], y = range[i][1];
                range[i][0] = range[j][0];
                range[i][1] = range[j][1];
                range[j][0] = x;
                range[j][1] = y;
            }
        }
    }
}

//double sqrt(int x)
//{
//    if (x == 0)
//        return 0;
//    double y = 1.0;
//    double z;
//    do
//    {
//        y = (x / y + y) / 2.0;
//        z = y * y - x;
//    } while (z<-0.0001 || z>0.0001);
//    return y;
//}
