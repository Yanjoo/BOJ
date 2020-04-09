#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string board[50];
int N, M;
int result = 987654321;

string c1[8] = {"WBWBWBWB", 
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW"};
                
string c2[8] = {"BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB"};

int check1(int x, int y)
{
    int diff = 0;
    for (int i=x; i<x+8; i++)
        for (int j=y; j<y+8; j++)
            if (board[i][j] != c1[i-x][j-y])
                diff++;
    return diff;
}

int check2(int x, int y)
{
    int diff = 0;
    for (int i=x; i<x+8; i++)
        for (int j=y; j<y+8; j++)
            if (board[i][j] != c2[i-x][j-y])
                diff++;
    return diff;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i=0; i<N; i++)
        cin >> board[i];

    for (int i=0; i<=N-8; i++)
        for (int j=0; j<=M-8; j++)
            result = min(result, min(check1(i, j), check2(i,j)));  
       
    cout << result;

    return 0;
}