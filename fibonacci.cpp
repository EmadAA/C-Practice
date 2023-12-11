#include<iostream>
using namespace std;
unsigned long long F[100];
unsigned  long long fib(int n)
{
    if(n<=1)
    {
        return n;
    }

    if(F[n]!= -1)
    {
        return F[n];
    }
    F[n]= fib(n-1)+ fib(n-2);
    return F[n];
}
int main()
{
    for(int i=0; i<100; i++)
    {
        F[i]=-1;
    }
    int n;
    cin>>n;
    unsigned long long result =fib(n);
    cout<<result<<endl;
main();
}


