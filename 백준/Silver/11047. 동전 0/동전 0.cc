#include <iostream>
using namespace std;

int weight[10];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k <= 0)
            break;
        if (k >= weight[i])
        {
            int count = k / weight[i];
            ans += count;
            k -= weight[i] * count;
        }
    }
    cout << ans;
}