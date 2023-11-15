#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    long long int x;
    cin >> n >> x;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        //Vs so sanh vs chinh no nen ra 45 + 10(ss chinh no) = 55 cap
        for(int j=i; j<n; j++) {
            if(pow(arr[i], 2) + arr[j] == x) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
