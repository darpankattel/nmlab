#include<iostream>
#include<cmath>
using namespace std;
//Global Variables
float** a;
float* x;
float* y;
int d;
int no_of_datas;

void inputData()
{
    cout<<"Enter the choice of degree of Polynomial.\t"<<endl;
    cin>>d;
    a=new float*[d+1];
    for(int i=0; i<=d; i++)
    {
        a[i]=new float[d+2];
    }
    cout<<"Enter the number of data's to be entered.\t";
    cin>>no_of_datas;
    if(no_of_datas>d && d>0)
    {
        x=new float[no_of_datas];
        y=new float[no_of_datas];
        for(int i=0; i<no_of_datas; i++)
        {
            cout<<"Enter the value of x["<<i<<"]\t"<<endl;
            cin>>x[i];
            cout<<"Enter the value of y["<<i<<"]\t"<<endl;
            cin>>y[i];
        }
    }
    else
    {
        cout<<"No. of datas must be greater than degree";
        return;
    }
}
void matrixConstruction()
{
    for(int i=0; i<d+1; i++)
    {
        for(int j=0; j<d+2; j++)
        {
            float sum=0;
            if(j!=d+1)
            {
                for(int k=0; k<no_of_datas; k++)
                {
                    sum+=pow(x[k],i+j);
                }
            }
            else
            {
                for(int k=0; k<no_of_datas; k++)
                {
                    sum+=pow(x[k],i)*y[k];
                }
            }
            a[i][j]=sum;
        }
    }
}
void DisplayMat()
{
    for(int i=0; i<d+1; i++)
    {
        for(int j=0; j<d+2; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void diagonalization()
{
    int n=d+1;
    for(int j=0; j<n; j++)
    {
        if(abs(a[j][j])<=0.000005)
        {
            cout<<"Error. The value of denominator is zero.";
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(i!=j)
            {
                float temp=a[i][j]/a[j][j];
                for(int k=0; k<n+1; k++)
                {
                    a[i][k]=a[i][k]-(temp*a[j][k]);
                }
            }
        }
    }
}
void output()
{
    int n=d+1;
    for(int i=0; i<n; i++)
    {
        cout<<"C["<<i+1<<"]="<<a[i][n]/a[i][i]<<endl;
    }
}
int main()
{
    inputData();
    matrixConstruction();
    DisplayMat();
    diagonalization();
    output();
    return 0;
}
