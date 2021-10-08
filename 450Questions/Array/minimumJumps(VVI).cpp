// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#


#include <iostream>

using namespace std;

int minJumps(int arr[], int n){
    // The number of jumps needed to reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    int maxReach = arr[0]; // stores all time the maximal reachable index in the array.
    int step = arr[0];     // stores the number of steps we can still take
    int jump = 1;          //stores the number of jumps necessary to reach that maximal reachable position.

    /* INITIAL: */
    //    i
    //   mR
    // 0  1  2  3  4  5
    // 1, 4, 3, 2, 6, 7
    
    // jump = 1
    // Step = 1

    /* FINAL: */
    //                i
    //                              mR
    // 0  1  2  3  4  5 ............10
    // 1, 4, 3, 2, 6, 7

    // jump = 2
    // Step = 1

    int i = 1;
    for (i = 1; i < n; i++){
        // Check if we have reached the end of the array
        if (i == n - 1) return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0){
            // we must have used a jump
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach) return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}

int main(){
    int N = 6;
    int arr[] = {1, 4, 3, 2, 6, 7};

        cout << minJumps(arr, N) << endl;

    return 0;
}