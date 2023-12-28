#include <iostream>

using namespace std;

int N, T[100][100];

void afisare()
{
    int i, j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Da-ti N: ";
    cin>>N;
    afisare();
    return 0;
}