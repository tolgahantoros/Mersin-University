#include<iostream>
 
using namespace std;
 
int main()
{
    int i,j,n=9,loc,temp,min;
    
    int a[9] = {7,3,5,8,2,9,4,15,6};
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    cout<<"\nSýralý liste\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 system("PAUSE");
    return 0;
}
