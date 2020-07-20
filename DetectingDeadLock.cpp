#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int countOfR;
    cout<<"Enter the no. of resources : ";
    cin>>countOfR;
    int instance[countOfR],available[countOfR];
    for(int i=0;i<countOfR;i++)
    {
        cout<<"\nEnter the maximum instance of R["<<i<<"] : ";
        cin>>instance[i];
        available[i] = instance[i];
    }
    int countOfP;
    cout<<"\nEnter the  no. of processes : ";
    cin>>countOfP;
    int allocation[countOfP][countOfR];
    for(int i=0;i<countOfP;i++)
    {
        cout<<"\nEnter the resource alocation for P["<<i<<"] : ";
        for(int j=0;j<countOfR;j++)
        {
            cout<<"\nFor Resource R["<<j<<"] : ";
            cin>>allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }
    int maxAllocation[countOfP][countOfR];
    for(int i=0;i<countOfP;i++)
    {
        cout<<"\nEnter the max resource alocation for P["<<i<<"] : ";
        for(int j=0;j<countOfR;j++)
        {
            cout<<"\nMax demand of Resource R["<<j<<"] : ";
            cin>>maxAllocation[i][j];
        }
    }
    cout<<"\n\nEntered Data\n";
    cout<<"\nTotal no. of resources are : "<<countOfR<<endl;
    for(int i=0;i<countOfR;i++)
        cout<<"R["<<i<<"]"<<" "<<instance[i]<<endl;
    cout<<"\nTotal no. of processes are : "<<countOfP<<endl;
    for(int i=0;i<countOfP;i++)
        cout<<"P["<<i<<"]"<<" ";
    cout<<"\nAllocated Resource Matrix\n";
    for(int i=0;i<countOfP;i++)
    {
        cout<<"P["<<i<<"] : ";
        for(int j=0;j<countOfR;j++)
        {
            cout<<allocation[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nMaximum Resource Matrix\n";
    for(int i=0;i<countOfP;i++)
    {
        cout<<"P["<<i<<"] : ";
        for(int j=0;j<countOfR;j++)
        {
            cout<<maxAllocation[i][j]<<" ";
        }
        cout<<endl;
    }
    int need[countOfP][countOfP];
    for(int i=0;i<countOfP;i++)
    {
        for(int j=0;j<countOfR;j++)
        {
            need[i][j] = maxAllocation[i][j]-allocation[i][j];
        }
    }
    cout<<"\nNeed Resource Matrix\n";
    for(int i=0;i<countOfP;i++)
    {
        cout<<"P["<<i<<"] : ";
        for(int j=0;j<countOfR;j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Now to check whether the above state"<<endl;
    cout<<"is SAFE or UNSAFE"<<endl;
    cout<<"Please press any key to continue"<<endl;
    getch();

    bool finish[countOfP] = {0};
    int safeSeq[countOfP];
    int work[countOfR];
    for(int i=0;i<countOfR;i++)
        work[i] = available[i];
    int count=0;
    while(count<countOfP)
    {
        bool found = false;
        for(int i=0;i<countOfP;i++)
        {
            if(finish[i] == 0)
            {
                int j;
                for(j=0;j<countOfR;j++)
                {
                    if(need[i][j]>work[j])
                        break;
                }
                if(j ==  countOfR)
                {
                    for(int k=0;k<countOfR;k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(found == false)
        {
            cout<<"\nSystem is not in safe state";
            return 0;
        }
    }
    for(int i=0;i<countOfP;i++)
        cout<<safeSeq[i]<<" ";
    return 0;
}
