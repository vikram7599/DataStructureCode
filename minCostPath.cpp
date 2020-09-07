#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_cost(int **input, int **output, int si, int sj, int ei, int ej)
{
    if (si==ei && sj==ej)
        return input[si][sj];

    int option1 = INT_MAX, option2 = INT_MAX, option3 = INT_MAX;

    if (si>ei || sj>ej)
    return INT_MAX;

    if(output[si][sj] != -1){
        return output[si][sj];
    }

    
    option1 = min_cost(input, output, si+1, sj, ei, ej);
    
    option2 = min_cost(input, output, si, sj+1, ei, ej);
    
    option3 = min_cost(input, output, si+1, sj+1, ei, ej);

    output[si][sj] = input[si][sj] + min(option1, min(option2, option3));
    return input[si][sj] + min(option1, min(option2, option3));
}

int main()
{
    int i=0,j=0;
    int** input = new int*[3];
    int** output = new int*[3];
    for (i=0; i<3; i++)
    {
        input[i] = new int[3];
        output[i] = new int[3];
    }
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            cin>>input[i][j];
        }
    }
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            output[i][j] = -1;
        }
    }
    int cost = min_cost(input, output, 0, 0, 2, 2);
    cout<<cost<<endl;
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
    delete [] input;
    delete [] output[0];
    delete [] output[1];
    delete [] output[2];
    delete [] output;
}
