#include <iostream>
#define max 4
#define INF 99999

//#include <conio.h>

using namespace std;

void floyds(int b[][max])

{

    int i, j, k;

    for (k = 0; k < max; k++)

    {

        for (i = 0; i < max; i++)

        {

            for (j = 0; j < max; j++)

            {

                if ((b[i][k] * b[k][j] != 0) && (i != j))

                {

                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))

                    {

                        b[i][j] = b[i][k] + b[k][j];

                    }

                }

            }

        }

    }

    for (i = 0; i < max; i++)

    {

        cout<<"\nMinimum Cost With Respect to Node:"<<i+1<<endl;

        for (j = 0; j < max; j++)

        {

            cout<<b[i][j]<<"\t";

        }

 

    }
    printf("\n");

}

int main()

{

 
              
    int b[max][max] = { {0,   INF, -2, INF}, 
                        { 4,  0,  3,INF}, 
                        {INF, INF, 0,   2}, 
                        {INF,-1, INF, 0} 
                      };

    floyds(b);

    //getch();

}