#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int ary[10][10],completed[10],n,cost=0;

int least(int c);
void takeInput()
{
    int i,j;

    printf("Enter the number of villages: ");
    scanf("%d",&n);

    printf("\nEnter the Cost Matrix\n");

    for(i=0;i < n;i++)
    {
        printf("\nEnter Elements of Row: %d\n",i+1);

        for( j=0;j < n;j++)
            scanf("%d",&ary[i][j]);

        completed[i]=0;
    }

    printf("\n\nThe cost list is:");

    for( i=0;i < n;i++)
    {
        printf("\n");

        for(j=0;j < n;j++)
            printf("\t%d",ary[i][j]);
    }
}

void mincost(int city)
{
    int i,ncity;
    cout<<endl<<"city= "<<city<<endl;

    completed[city]=1;

    printf("%d--->",city+1);
    cout<<endl;
    ncity=least(city);
    cout<<endl<<"ncity= "<<ncity<<endl;
    if(ncity==999)
    {
        ncity=0;
        printf("%d",ncity+1);
        cost+=ary[city][ncity];
        cout<<"cost_mincost"<<cost<<endl;
        return;
    }

    mincost(ncity);
}

int least(int c)
{
    int i,nc=999;
    int min=999,kmin;

    for(i=0;i < n;i++)
    {
        if((ary[c][i]!=0)&&(completed[i]==0))
            if(ary[c][i]+ary[i][c] < min)
            {
                min=ary[i][c]+ary[c][i];
                kmin=ary[c][i];
                nc=i;
                cout<<i<<" "<<c<<" "<<ary[i][c]<<" "<<ary[c][i]<<" "<<min<<" "<<kmin<<" "<<cost<<endl;
            }
    }

    if(min!=999)
        cost+=kmin;
    cout<<"cost_least"<<cost<<endl;

    return nc;
}

int main()
{
    takeInput();

    printf("\n\nThe Path is:\n");
    mincost(0); //passing 0 because starting vertex

    printf("\n\nMinimum cost is %d\n ",cost);

    return 0;
}
