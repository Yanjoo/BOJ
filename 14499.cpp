#include <iostream>

using namespace std;

int N, M, K;
int x, y;
int map[20][20];
int d;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[6]; // 상 뒤 우 좌 앞 하
int temp[6];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> x >> y >> K;

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    for (int i=0; i<K; i++)
    {
        cin >> d;

        if (x+dx[d-1]<0 || x+dx[d-1]>=N || y+dy[d-1]<0 || y+dy[d-1] >=M)
            continue;
        
        x = x+dx[d-1];
        y = y+dy[d-1];

        for (int j=0; j<6; j++) 
            temp[j] = dice[j];

        if (d == 1) // 동
        {
            dice[0] = temp[3];
            dice[2] = temp[0];
            dice[3] = temp[5];
            dice[5] = temp[2];
        }
        else if (d == 2) // 서
        {
            dice[0] = temp[2];
            dice[2] = temp[5];
            dice[3] = temp[0];
            dice[5] = temp[3];
        }
        else if (d == 3) // 북
        {
            dice[0] = temp[4];
            dice[1] = temp[0];
            dice[4] = temp[5];
            dice[5] = temp[1];
        }
        else // 남
        {
            dice[0] = temp[1];
            dice[1] = temp[5];
            dice[4] = temp[0];
            dice[5] = temp[4];
        }

        if (map[x][y]) 
        {
            dice[5] = map[x][y];
            map[x][y] = 0;
        }
        else
        {
            map[x][y] = dice[5];
        }
        cout << dice[0] << '\n';
    }

    return 0;
}