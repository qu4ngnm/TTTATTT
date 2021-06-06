#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,double a,int b[])
{
	int k;
	for(int i=1;i<=t;i++)
	{
		k=a/(pow(2,(t-i)*w));
		if(k==0)
		{
			b[i] =0;
			cout<<b[i]<<"\t";
			continue;
		}
		else
		{
			b[i]=k;
			cout<<b[i]<<"\t";
			a=a-k*(pow(2,(t-i)*w));
		}
	}
}

int main ()
{
	double a;
	int t,w,m;//a la so can chuyen,t so phan tu cua mang(bac)
	double p; // p la so phan tu
	int b[100];
	cout<<"Nhap a = ";
	cin>>a; //a la so can bieu dien
	cout<<"Nhap so p= ";
	cin>>p;
	cout<<"Nhap so w= ";
	cin>>w;
	m = log2(p);
	t= (m/w)+1;
	cout<<"Cac phan tu mang la: "<<endl;
	chuyenSoSangMang(t,w,a,b);
	
}
