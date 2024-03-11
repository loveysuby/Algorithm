#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll w, h, f, c, x1, y1, x2, y2;
    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

    ll area = (x2 - x1) * (y2 - y1) * (c + 1);
    ll totalArea = w * h;
    ll overlapArea = 0;

    if (f <= x1 || w <= x1 + f)
    {
        overlapArea = 0;
    }
    else
    {
        ll overlapWidth = min(f, x2) - x1;
        if (f > w / 2)
        {
            overlapWidth = min(w, f + x2) - (f + x1);
        }
        overlapArea = overlapWidth * (y2 - y1) * (c + 1);
    }

    cout << totalArea - area - overlapArea;
}