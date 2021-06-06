#include <iostream>
#include <math.h>
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
        e=1;
    }
    else{ e=0;}
    for(int i=t-1;i>0;i--){
        arr[i]=(arr1[i]+arr2[i]+e)%(int)pow(2,w);
        if((arr1[i]+arr2[i]+e)>=0 && (arr[i]==0))
        {
            e=1;
        }
        else {e=0;}
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
    cout<<arr[t];
}
int sosanhMang(int arr[], int arr3[], int t)
{
    for(int i=0;i<t;i++)
    {
        if(arr[i]>arr3[i])
        {
            return 1;
        }
        else {
            return 0;
        }
    }
}


int main(){
    int w,t, arr[100], arr1[100], arr2[100], arr3[100];
    int e;
    int p, a, b;
    cout<<"Nhap t: ";cin>>t;
    cout<<"\nNhap w: ";cin>>w;
    cout<<"\nNhap p: ";
    cin>>p;
    chuyensothanhMang(arr3, t, p, w);
    cout<<"\nNhap a: ";
    cin>>a;
    chuyensothanhMang(arr1, t, a, w);
    cout<<"\nNhap b: ";
    cin>>b;
    chuyensothanhMang(arr2, t, b, w);
    //cout<<"\nTong C=A+B: ";
    /*phepCong(t,w,arr,arr1,arr2);cout<<")]";
    cout<<"\nPhep cong tren Fp la: ";
    if(sosanhMang(arr,arr3, t) == 1)
    {
        phepTru(t,w,arr,arr,arr3);
    }
    cout<<")]";*/
    cout<<"\nHieu C=A-B: ";
    phepTru(t,w,arr,arr1,arr2);cout<<e<<")]";
    cout<<"Phep tru tren Fp la: ";
    if(e == 1)
    {
        phepCong(t,w,arr,arr,arr3);
    }
    cout<<")]";
}
