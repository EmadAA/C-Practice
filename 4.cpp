#include<bits/stdc++.h>
using namespace std;


int node,edge;
int graph[101][101];
int Visit[1001];

vector<int>Graph[101];


void bfs(int start)
{

    queue<int> q;
    cout<<start<<" ";
    Visit[start]=1;
    q.push(start);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        for (int i = 1; i <= node; i++)
        {
            if(Visit[i]==0 && graph[a][i]!=0)
            {
                cout<<i<<" ";
                q.push(i);
                Visit[i]=1;
            }
        }

    }


}



void dfs(int start)
{
    Visit[start] = 1;
    cout << start << " ";
    stack<int> Sta;
    Sta.push(start);

    while (!Sta.empty())
    {
        int x = Sta.top();
        Sta.pop();

        for (int j = 0; j < Graph[x].size(); j++)
        {
            int node = Graph[x][j];

            if (Visit[node] == 0)
            {
                Visit[node] = 1;
                cout << node << " ";
                Sta.push(node);
            }
        }
    }
}





int main()
{


    int u,v,startNode;

    cout<<endl<<"Input Nodes and Edges  number" ;
    cout<<"Now input the graph value"<<endl ;

    cin>>node>>edge;

    for (int i = 1; i <= edge; i++)
    {
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
        Graph[u].push_back(v);
        Graph[v].push_back(u);

    }



    char input;
    cout<<"Now, B for BFS  and  D for DFS"<<endl;
    cin>>input;
    cout<<"Enter The Starting Node :"<<endl;

    cin>>startNode;
    if(input=='B')
    {

        bfs(startNode);
    }
    if(input=='D')
    {

        dfs(startNode);
    }
    return 0;
}
