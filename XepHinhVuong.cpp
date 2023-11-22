#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int arr[t];
    for(int i=0; i<t; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<t; i++) {
        //Lấy ra số lớn nhất chia hết cho arr[i]
        int res = sqrt(arr[i]);
        while (arr[i] % res != 0)
        {
            res--;
        }
        // In ra 
        cout << res << " " << arr[i]/res << endl;
    }
 
    return 0;
}
