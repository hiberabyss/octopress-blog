/* 
 * http://blog.csdn.net/yutianzuijin/article/details/11499917
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ToReview

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays1(A, m, B, n);
        return findMedianSortedArrays2(A, m, B, n);
    }

    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        function<int(int*,int,int*,int,int)> findKth = [&](int A[], int m, int B[], int n, int k) {
            if ( m>n ) return findKth(B,n,A,m,k);
            if ( !m ) return B[k-1];
            if ( k == 1 ) return min(A[0], B[0]);
            int la = min(k/2, m);
            int lb = k - la;
            if ( A[la-1] < B[lb-1] ) return findKth(A+la, m-la, B, n, k-la);
            if ( A[la-1] > B[lb-1] ) return findKth(A, m, B+lb, n-lb, k-lb);
            return A[la-1];
        };

        int mid = (m+n+1)/2;
        // cout << "2th: " << findKth(A, m, B, n, 2) <<endl;
        double res = findKth(A, m, B, n, mid);
        if ( !((m+n)&1) ) res = (res + findKth(A,m,B,n,mid+1))/2.0;
        return res;
    }

    // false
    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int m1 = 0;
        int m2 = 0;
        int i = 0; 
        int j = 0;
        for (int k = (m+n)/2; k >= 0; --k ) {
            m1 = m2;
            if ( j==n || (i<m && A[i] <= B[j]) ) m2 = A[i++];
            else m2 = B[j++];
        }
        if ( (m+n)&1 ) return m2;
        return (m1+m2)/2.0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    {
        int A[] = {1,2};
        int B[] = {2};
        int n1 = sizeof(A)/sizeof(*A);
        int n2 = sizeof(B)/sizeof(*B);
        cout << sol.findMedianSortedArrays(A, n1, B, n2 ) <<endl;
    }

    {
        int A[] = {1,2};
        int B[] = {1,1};
        int n1 = sizeof(A)/sizeof(*A);
        int n2 = sizeof(B)/sizeof(*B);
        cout << sol.findMedianSortedArrays(A, n1, B, n2 ) <<endl;
    } 

    {
        int A[] = {2};
        int B[] = {};
        int n1 = sizeof(A)/sizeof(*A);
        int n2 = sizeof(B)/sizeof(*B);
        cout << sol.findMedianSortedArrays(A, n1, B, n2 ) <<endl;
    } 

    return 0;
}
