#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 2; i <= n; i++)
        ans = (ans + k) % i;
    cout << ans + 1 << endl;
    return 0;
}
