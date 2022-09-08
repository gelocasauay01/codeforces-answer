#include<bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int length, int toFind) {
    int high = length;
    int low = 0;
    int numberOfStores = 0;

    while(high >= low) {
        int mid = (high + low) / 2;
        if(toFind >= arr[mid]){
            numberOfStores = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return numberOfStores;
}

int main(int argv, char** argc) {
    ios::sync_with_stdio();
    cin.tie(0);
    int n, q;

    cin >> n; 
    int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x+n);

    cin >> q;
    int answers[q];
    for(int i = 0; i < q; i++ ) {
        int current;
        cin >> current;
        if(current < x[0]) answers[i] = 0;
        else if(current >= x[n-1]) answers[i] = n;
        else answers[i] = binSearch(x, n, current);
    }

    for(int i = 0; i < q; i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}