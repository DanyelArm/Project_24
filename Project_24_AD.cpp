#include <iostream>
#include <iomanip>

using namespace std;

int N, T[100][100];
const int miscari[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};//Variabila cu toate miscarile calului pe o tabla de sah
int start_x = -1, start_y = -1;//Variabile pentru a memora pozitia initiala a calului(globale deoarece sunt folosite in mai multe functii)

//Functia de generare a tablei initiind cu 0 pe unde nu a trecut calul
void generare()
{   
    int i, j;
    do
    {
        cout << "Da-ti N(cond.: >0, !=2, !=3, !=4): ";
        cin >> N;
    } while(N <= 0 || N == 2 || N == 3 || N == 4);
    for(i = 0; i < N; i++)
    {
        cout << "|";
        for (j = 0; j < N; j++)
        {
            T[i][j] = 0;
            cout << setw(3) << T[i][j] << " |";
        }
        cout << endl;//Afisam cum arata tabla initiala
    }
}

//Functia de pozitie a calului unde alegem pozitia initiala a calului
void pozitia(int i, int j)
{   
    do{
        cout << "Alege pozitia calului pe tabla(i,j mai mici decat N): ";
        cin >> i >> j;
    }while(i >= N || j >= N);
    T[i][j] = 1;//Prima pozitie a sa mereu va fi 1 socotita ca prima miscare a sa
    for(i = 0; i < N; i++)
    {
        cout << "|";
        for (j = 0;j < N; j++)
        {
            cout << setw(3) << T[i][j] << " |";
        }
        cout << endl;//Afisam cum arata tabla cu pozitia initiala a calului
    }
}

//Functie pentru a verifica daca se poate de facut miscare
int verifica(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && T[x][y] == 0)//Verifica daca pozitia se afla pe tabla generata si la fel daca este egala cu 0 adica calul inca nu a trecut prin ea
        return 1;
    else
        return 0;
}

int solve(int x, int y, int movei)
{
    if (movei == N * N)
        return 1;

    int k, next_x, next_y;
    for (k = 0; k < 8; k++)//Mergem pe toate miscarile calului
    {
        next_x = x + miscari[k][0];
        next_y = y + miscari[k][1];

        if (verifica(next_x, next_y))//Verifica daca pozitia indeplineste cazurile puse din functia Verifica(..,..)
        {
            T[next_x][next_y] = movei + 1;//Memoram pozitia
            if (solve(next_x, next_y, movei + 1) == 1)//Verificam daca avem o pozitie urmatoare
                return 1;
            else
                T[next_x][next_y] = 0;//Daca nu avem o pozitie urmatoare valida o initializam din nou cu 0 
        }
    }

    return 0;
}

void afisare()
{
    int countMiscari = 1;//Contor de a afisa miscarea calului pe tabla
    T[start_x][start_y] = countMiscari++;
    if (solve(start_x, start_y, 1) == 1)//Verifica daca functia a gasit un drum pentru cal
    {
        cout << "Solutia gasita" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "|";
            for (int j = 0; j < N; j++)
            {
                cout << setw(3) << T[i][j] << " |";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Nu exista solutie." << endl;
    }//Daca nu avem solutie nu mai afisam nici tabla
}

int main()
{
    int opt;
    do{
        cout << "-----Meniu-----" << endl;
        cout << "0. Iesire." << endl;
        cout << "1. Genenrarea de Tabla initiala." << endl;
        cout << "2. Alegerea de pozitie." << endl;
        cout << "3. Afisare rezolvarii turului de cal." << endl;
        cout << "Alege optiunea: ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            generare();
            break;
        case 2:
            pozitia(start_x, start_y);
            break;
        case 3:
            afisare();
            break;
        default:
            cout << "Opiunea aleasa este gresita." << endl;
            break;
        }
    }while(opt != 0);//Meniul creat pentru generarea si afisare de cazurile date de utilizator
    return 0;
}