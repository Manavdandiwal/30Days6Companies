/*
Find total number of Squares in a N*N chessboard

Example:
Input: N = 3
Output: 13

Ans is going to be sum of pow(i, 2) where i will be from i to N
1^2 + 2^2 ... + N^2 = N * (N + 1) * (2 * N + 1) / 6 is the ans
*/

int solve(int N)
{
    return N * (N + 1) / 2 * (2 * N + 1) / 3;
}