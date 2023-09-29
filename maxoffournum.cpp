#include <iostream>
using namespace std;

int maxoffour(int a, int b, int c, int d) {
    int p = max(a, b);
    int q = max(c, d);
    return max(p, q);
}

int main() {
    int a, b, c, d;
    
    cout << "Enter four integers: ";
    cin >> a >> b >> c >> d;

    cout << "Maximum of four numbers: " << maxoffour(a, b, c, d) << endl;

    return 0;
}
