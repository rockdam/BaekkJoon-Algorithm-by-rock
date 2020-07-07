// codingtestPreparation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
void initBox(int m, int n);
void bfsBox(int x, int y);
void serachBox();
#define X first;
#define Y second;
vector <vector<int>> box;
queue<pair<int, int>> Q;
int testCase;
int m, n, k;
int x, y;
int snakeNum = 0;
vector<int> result;
vector <vector<bool>> vis; //해당칸을 방문 했는가?
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	cin >> testCase;

	for (int i = 0;i < testCase;i++)
	{
		cin >> m >> n >> k;
		initBox(m, n);
		for (int i = 0;i < k;i++)
		{
			cin >> x >> y;

			box[x][y] = 1;


		}


		serachBox();


		box.clear();
		vis.clear();
		result.push_back(snakeNum);

		snakeNum = 0;



	}
	for (int i = 0;i < result.size();i++)
	{

		cout << result[i];
		printf("\n");
	}


	return 0;
}
void initBox(int m, int n)
{

	vector<int> element(n);
	// 기본값(0)으로 초기화된 5개의 원소를 가지는 vector v를 생성합니다.
	vector<bool> elementBool(n);
	for (int i = 0;i < n;i++)
	{
		elementBool[i] = false;

	}

	for (int i = 0;i < m;i++)
	{
		box.push_back(element);
		vis.push_back(elementBool);
	}




}
void serachBox()
{

	for (int i = 0;i < m;i++)
	{

		for (int j = 0;j < n;j++)
		{

			if (box[i][j] && !vis[i][j])bfsBox(i, j);
		}
	}
}
void bfsBox(int x, int y)
{


	Q.push({ x,y });
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4;dir++)
		{

			int nx = (cur.first + dx[dir]);
			int ny = (cur.second + dy[dir]);
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || box[nx][ny] != 1)continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });

		}
	}
	snakeNum++;


}

/* vector 사용법
vector<int> v;
vector <int> v(5,2)
https://blockdmask.tistory.com/70

*/
/*bfs 사용시 실수하는 유형
1. 시작점에 방문헀다는 표시를 남기지 않는다.
2. 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때
방문했다는 표시를 남겼다 .
3. 이웃한 원소가 범위를 벗어났는지에 대한 체크를 잘못했다.

*/
