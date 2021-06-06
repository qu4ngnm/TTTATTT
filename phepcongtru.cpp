#include <iostream>
#include<math.h>
using namespace std;
void chuyensothanhMang(int arr[], int t, int a, int w)
{
    int k;
    cout<<"[ ";
    for(int i=1; i<=t;i++)
    {
        k=a/pow(2,(t-i)*w);
        if(k==0){
            arr[i]=0;
            cout<<arr[i]<<" ";
            continue;
        }
        else{
            arr[i]=k;
            cout<<arr[i]<<" ";
            a=a-k*(pow(2,(t-i)*w));
        }
    }
    cout<<" ]";
}
void phepCong(int t, int w,int arr[], int arr1[], int arr2[])
{
    int e;
    int sum = arr1[t]+arr2[t];
    arr[t]= sum % (int)pow(2,w);
    if(sum >=0 && arr[t]==0)
    {
        e=0;
    }
    else{ e=1;}
    for(int i=t-1;i>0;i--){
        arr[i]=(arr1[i]+arr2[i]+e)%(int)pow(2,w);
        if((arr1[i]+arr2[i]+e)>=0 && (arr[i]==0))
        {
            e=0;
        }
        else {e=1;}
    }
    cout<<"["<<e<<", (";
    for(int i=1; i<=t-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[t ];
}
void phepTru(int t, int w,int arr[], int arr1[], int arr2[])
{
    int e;
    int subtraction = arr1[t]-arr2[t];
    arr[t]= subtraction % (int)pow(2,w);
    if(arr[t]<0)
    {
        arr[t]+=pow(2,w);
    }
    else if(subtraction >=0 && arr[t]==0)
    {
        e=0;
    }
    else{e=1;}
    for(int i=t-1;i>0;i--){
        arr[i]=(arr1[i]-arr2[i]-e)%(int)pow(2,w);
        if(arr[i]<=0)
        {
            arr[i]+=pow(2,w);
        }
        else if((arr1[i]-arr2[i])>=0 && arr[i]==0)
        {
            e=0;
        }
        else {e=1;}
    }
    cout<<"["<<e<<", (";
    for(int i=1; i<=t-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[t ];
}

int main()
{
    int w,t, arr[100], arr1[100], arr2[100];
    int e;
    int a, b;
    cout<<"Nhap w: ";cin>>w;
    cout<<"Nhap t: ";cin>>t;
    cout<<"Nhap a: ";
    cin>>a;
    chuyensothanhMang(arr1, t, a, w);
    cout<<"\nNhap b: ";
    cin>>b;
    chuyensothanhMang(arr2, t, b, w);
    cout<<"\nPhep cong 2 so lon A + B = ";
    phepCong(t,w,arr,arr1,arr2);
    cout<<" ]";
    cout<<"\nPhep tru 2 so lon A - B = ";
    phepTru(t,w,arr,arr1,arr2);
    cout<<" ]";
}
