#include<bits/stdc++.h>

using namespace std;

int n, m ;

struct Item
{
    int obj;
    double PBW;
};

bool comparePBW(Item one, Item two)
{
    if(one.PBW > two.PBW)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void greedyKnapsack()
{
    int profit[n];
    int weight[n];
    for  (int i =0; i<n; i++)
    {
        cin>>profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    Item pBw[n];

    for (int i = 0; i < n; i++)
    {
        pBw[i].obj = i;
        pBw[i].PBW = double(profit[i]) /  double(weight[i]) ;
        sort(pBw, pBw+n, comparePBW);
    }

    double X[n];
    memset(X,0,sizeof(X)) ;
    double RW = double(m);  //  RW means remaining Weight

    for (int i = 0; i < n; i++)
    {
        if(RW>0)
        {
            if (RW >= weight[pBw[i].obj])
            {
                RW = RW - weight[pBw[i].obj];
                X[pBw[i].obj] = 1;
            }
            else
            {
                X[pBw[i].obj] = RW / weight[pBw[i].obj];
                RW = 0;
            }
    }
    }
    double MP =  0; // MP = maxprofit
    for (int i = 0; i < n; i++)
    {
        MP = MP + X[i] * double (profit[i]);

    }
    cout<<MP<<endl;

    cout<<"Selected Object";

    for (int i = 1; i <= n; i++)
    {
        if(X[i]>0)
        {
            cout<<i<<" ";
        }

    }


}

int main()
{
    cin>>n>>m;
    greedyKnapsack();

    return 0;
}













