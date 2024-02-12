// https://www.hackerrank.com/contests/300-bai-code-thieu-nhi/challenges
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;//số lượng testcase

    long long int total[t];//mảng lưu trữ tổng số kẹo mỗi testcase

    for (int i = 0; i < t; i++) {
        long long int n, m;
        /**
         * n là số lượng bữa tiệc
         * m là số kẹo mỗi bữa tiệc
        */
        cin >> n >> m;

        // 1 < n < 10^4
        if (n < 1 || n > 10000) {
            cout << "Invalid value" << endl;
            return 1; 
        }

        // 1 < n < 10^9
        if (m < 1 || m > 1000000000) {
            cout << "Invalid value" << endl;
            return 1; 
        }

        int people[n];
        long long int result = 0;

        for (int j = 0; j < n; j++) {
            cin >> people[j];// là số người tham gia bữa tiệc thứ j trong n bữa tiệc

            // 1 < ai < 10^9
            if (people[j] < 1 || people[j] > 1000000000) {
                cout << "Invalid value" << endl;
                return 1; 
            }

            people[j]++;//  bữa tiệc thứ j sẽ có (j+1) người ăn hết m chiếc kẹo. Là tính cả Jen
            
            if (people[j] > m) { 
                result += m; // nếu số người nhiều hơn số kẹo thì jen sẽ ăn hết, không chia ai cả (vì số kẹo của các bạn cũng không được nhiều hơn jen)
            } else {
                result += ((m / people[j]) + (m % people[j]));
                /*
                 * 3 5
                 * 3 4 5
                 * n = 3
                 * m = 5
                 * 3, 4, 5 lần lượt là số người dự trong n bữa tiệc
                 * 
                 *  (m / people[j]) sẽ được số kẹo của mỗi người bao gồm cả Jen, vd 5 kẹo chia cho 3+1 người thì mỗi người đc 1 chiếc
                 *  (m % people[j]) số kẹo còn dư lại thì Jen sẽ ăn hết 5%4 = 1 
                 *  Vậy Jen ăn hết 1+1 = 2 chiếc kẹo sau bữa tiệc đầu tiên
                 *  Các bữa tiệc sau lần lượt là 1, 5 (5 là do có 5+1=6 người, nhiều hơn số kẹo jen có, nên jen ăn hết)
                 *  Vậy ta được 2 + 1 + 5 = 8 kẹo jen ăn trong n=3 bữa tiệc
                */
            }
        }

        total[i] = result;
    }

    for (int i = 0; i < t; i++) {
        cout << total[i] << endl;
    }

    return 0;
}
