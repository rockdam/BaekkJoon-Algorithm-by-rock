#include<iostream>
#include<queue>
#include<vector>
//https://blog.naver.com/ndb796?Redirect=Log&logNo=221230944971&from=postView
// ���� ����
//push_back�� �ǹ�
//�׳� �Ϲ� �迭 ��ſ� ����Ʈ�ε� ����� ������ vector�� ���Ŵٰ� ���ø� �ſ�! 
//�⺻������ �׷��� �̷п����� ���� ����Ʈ�� ����� �� �� ���� ȿ������ �������ϴ�. push_back�� �׳� ���� �߰��� �ǹ̿���.
using namespace std;

int nodeNum = 7;
int nodeVisitCheck[7];
vector<int> node[8];

void bfs(int start)
{
    queue<int> que;
    que.push(start);
    nodeVisitCheck[start] = true;
    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        printf("%d ", x);
        for (int i = 0; i < node[x].size(); i++)
        {

            int y = node[x][i];
            if (!nodeVisitCheck[y])
            {
                que.push(y);
                nodeVisitCheck[y] = true;
            }
        }



    }
 }
int main()
{
    node[1].push_back(2);
    node[2].push_back(1);
//1과 2를 연결 
    node[1].push_back(3);
    node[3].push_back(1);

    node[2].push_back(3);
    node[3].push_back(2);
   
    node[2].push_back(4);
    node[4].push_back(2);

    node[2].push_back(5);
    node[5].push_back(2);

    node[4].push_back(5);
    node[5].push_back(4);

    node[6].push_back(7);
    node[7].push_back(6);

    node[3].push_back(6);
    node[6].push_back(3);


    node[3].push_back(7);
    node[7].push_back(3);

    bfs(1);
     
  return 0;
}
