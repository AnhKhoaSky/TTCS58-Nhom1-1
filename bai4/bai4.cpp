#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int n,p, a=0, tong=0,kq=0;
int s[30],tam[30],ketqua[30][30];
 
void DocFile()
{
	fstream t;
	t.open("bai4.txt");
	if(t.is_open())
    {
    	t >> n >>p;
    	for( int i=0;i<n;i++)
    	{
		
    	      t>>s[i];
    	  }
    	  cout<< n<<" "<< p<<endl;
    	  for(int i=0; i< n;i++)
    	  cout<<"gia tri qua:"<< s[i]<<endl;
		}	
		else
		{
			cout<<"khong the doc duoc file: "<<endl;
		}
}
void QuayLui(int a, int tong)
{
	int i;
	for( i=a;i<n;i++)
	{
		if((tong + s[i])<=p)
		{
			tong=tong=s[i];
			tam[i]=1;
			if (tong == p)
			{
				for (int i =0;i<n;i++) 
				{
				ketqua[kq][i]=tam[i];
				}
				kq = kq+1;
			}
			else {
				QuayLui(tong,i+1);
			}
				tong =tong-s[i];
				tam[i] = 0;
			}
		}
}
void Xuat()
{
	int i;
	for (i=0;i<kq;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			cout<<ketqua[i][j]<<" ";
		}
		cout<<endl;
	}
}
void GhiFile() 
{
	fstream t;
	t.open("outbai4.txt",ios::out);
	t<<"Ket Qua la:"<<endl;
	QuayLui(tong,a);
	if (kq==0) 
	{
		cout <<"ko chon duoc"<< endl;
		t<<"ko chon duoc"<<endl;
	}
	else{
			t<<kq<<endl;
			cout<<kq<<endl;
			Xuat();
			for(int i=0;i<kq;i++) 
			{
				for(int j=0;j<n;j++) 
				{
					t<<ketqua[i][j]<<" ";
				}
				t<<endl;
			}
		}
}
int main()
{
	DocFile();
	GhiFile();
}
	
