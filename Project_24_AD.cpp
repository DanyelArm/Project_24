#include <iostream>

using namespace std;

int N, T[100][100];

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

void pozitia()
{   
    int i,j;
    do{
        cout<<"Alege pozitia calului pe tabla(i,j mai mici decat N): ";
        cin>>i>>j;
    }while(i>=N || j>=N);
    T[i][j]=2;
    for(i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int opt;
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
            pozitia();
            break;
        default:
            cout<<"Opiunea aleasa este gresita.";
            break;
        }
    }while(opt!=0);
    return 0;
}