#include <iostream>

using namespace std;

int N, T[100][100];
const int miscari[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
int countMiscari = 1;

void generare()
{   
    int i,j;
    cout<<"Da-ti N: ";
    cin>>N;
    for(i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            T[i][j]=0;
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

void pozitia(int i, int j)
{   
    do{
        cout<<"Alege pozitia calului pe tabla(i,j mai mici decat N): ";
        cin>>i>>j;
    }while(i>=N || j>=N);
    T[i][j]=1;
    for(i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

int verifica(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && T[x][y] == 0)
        return 1;
    else
        return 0;
}

int solve(int x, int y, int movei)
{
    if (movei == N * N)
        return 1;

    int k, next_x, next_y;
    for (k = 0; k < 8; k++)
    {
        next_x = x + miscari[k][0];
        next_y = y + miscari[k][1];

        if (verifica(next_x, next_y))
        {
            T[next_x][next_y] = ++countMiscari;

            if (solve(next_x, next_y, movei + 1) == 1)
                return 1;
            else
                T[next_x][next_y] = 0;
        }
    }

    return 0;
}

/*void afisare()
{

}
*/
int main()
{
    int opt, i, j;
    do{
        cout<<"-----Meniu-----"<<endl;
        cout<<"0. Iesire."<<endl;
        cout<<"1. Genenrarea de Tabla initiala."<<endl;
        cout<<"2. Alegerea de pozitie."<<endl;
        cout<<"Alege optiunea: ";
        cin>>opt;
        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            generare();
            break;
        case 2:
            pozitia(i,j);
            break;
        default:
            cout<<"Opiunea aleasa este gresita."<<endl;
            break;
        }
    }while(opt!=0);
    return 0;
}