// codingtestPreparation.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
vector <vector<bool>> vis; //�ش�ĭ�� �湮 �ߴ°�?
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
	// �⺻��(0)���� �ʱ�ȭ�� 5���� ���Ҹ� ������ vector v�� �����մϴ�.
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

/* vector ����
vector<int> v;
vector <int> v(5,2)
https://blockdmask.tistory.com/70

*/
/*bfs ���� �Ǽ��ϴ� ����
1. �������� �湮���ٴ� ǥ�ø� ������ �ʴ´�.
2. ť�� ���� �� �湮�ߴٴ� ǥ�ø� �ϴ� ��� ť���� ���� ��
�湮�ߴٴ� ǥ�ø� ����� .
3. �̿��� ���Ұ� ������ ��������� ���� üũ�� �߸��ߴ�.

*/
