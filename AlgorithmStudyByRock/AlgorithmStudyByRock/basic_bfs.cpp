#include<iostream>
#include<queue>
#include<vector>

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
        printf("%d", x);
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
    //1�� 2�� �����մϴ�.
    node[1].push_back(3);
    node[3].push_back(1);
    //1�� 3�� �����մϴ�.
    node[2].push_back(3);
    node[3].push_back(2);
    //2�� 3�� �����մϴ�.
    node[2].push_back(4);
    node[4].push_back(2);
    //2�� 4�� �����մϴ�.
    node[2].push_back(5);
    node[5].push_back(2);
    //2�� 5�� �����մϴ�.

    node[4].push_back(5);
    node[5].push_back(4);
    //4�� 5�� �����մϴ�.
    node[6].push_back(7);
    node[7].push_back(6);
    //6�� 7�� �����մϴ�.

    node[3].push_back(6);
    node[6].push_back(3);
    //3�� 6�� �����մϴ�.


    node[3].push_back(7);
    node[7].push_back(3);
   //3�� 7�� �����մϴ�.
    bfs(1);
     
  return 0;
}