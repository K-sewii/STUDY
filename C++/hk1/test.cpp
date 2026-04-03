#include <iostream>
using namespace std;
const int LENGTH = 501;
void Input(int arr[LENGTH][LENGTH], int n, int m)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
}
long long Sum(int arr[LENGTH][LENGTH], int h, int c)
{
    long long sum = 0;
    for (int i = h - 1; i <= h + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
int main()
{
    int t;
    cout << "Test case:";
    cin >> t;
    int arr[LENGTH][LENGTH] = {0};
    while (t--)
    {
        int n, m;
        cout << "Input N,M: ";
        cin >> n >> m;
        Input(arr, n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << Sum(arr, i, j) << " ";
            }
            cout << endl;
        }
    }
    cout << "\n";

    return 0;
}