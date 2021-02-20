
#include <bits/stdc++.h>
using namespace std;

int containerWithMostWater(vector<int> &water) {
    int n = water.size(), i = 0, j = n - 1, maxWater = 0;
    while (i < j) {
        int width = j - i;
        maxWater = max(maxWater, min(water[i], water[j]) * width);
        if (water[i] > water[j]) j--;
        else i++;
    }
    return maxWater;
}

int main() {

    int n = 4;
    vector<int> water = {1, 2, 4, 3};

    cout << containerWithMostWater(water) << endl;

}