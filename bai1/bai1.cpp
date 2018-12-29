#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

string s,c;

void NhapChuoi();
void Khoangtrang();
void Proper();
void Soluong();
void Ghifile();

bool TroVeMenu(){
	int trove;
	cout<<" nhan 0 de tro ve menu: "<<endl;
	cin>>trove;
	if(trove==0)
	return true;
	else false;
}

void showmenu()
{
	cout<< "1.Nhap Chuoi: "<<endl;
	cout<< "2.Bo cac khoang trang: "<<endl;
	cout<< "3.Chuan hoa chuoi dang Proper: "<<endl;
	cout<< "4.Thong ke so luong cac ky tu chu cai co trong chuoi: "<<endl;
	cout<< "5.Ghi lai vao file output1.txt" <<endl;
}

void Menu() 
{
	showmenu();
	int chon;
	cout<<"Chon yeu cau :"<<endl;
	cin>> chon;
	switch(chon)
	{
		case 1:
		system("cls");
		NhapChuoi();
        if(TroVeMenu())
		{
			system("cls");
			Menu();
		}
		 else
		 {
		 	cout<<"Exited" <<endl;
		 }
		  break; 
		case 2:
		system("cls");
		Khoangtrang();
		if(TroVeMenu())
		{
		 	system("cls");
		 	Menu();
		}
		 else
		 {
		 	cout<<"Exited" <<endl;
		 }
		case 3:
		system("cls");
		Proper();
		if(TroVeMenu())
		{
		 	system("cls");
		 	Menu();
		}
		 else
		 {
		 	cout<<"Exited" <<endl;
		 }
		case 4:
		system("cls");
		Soluong();
		if(TroVeMenu())
		{
		 	system("cls");
		 	Menu();
		}
		 else
		 {
		 	cout<<"Exited" <<endl;
		 }
		case 5:
		system("cls");
		Ghifile();
		if(TroVeMenu())
		{
		 	system("cls");
		 	Menu();
		}
		 else
		 {
		 	cout<<"Exited" <<endl;
		 }	 	 	 	
	} 
}
	
void NhapChuoi()
{
	cout<<"Nhap chuoi: ";
	fflush(stdin);
	getline(cin, s);
}

void Khoangtrang()
{
	//xoagiua
	int m=s.length();
	for(int i=0; i < m; i++)
	{
		if(s[i]==' ' && s[i+1]==' ')
		{
			for(int j= i; j< m; j++ )
			{
				s[j]=s[j+1];
			}
			m--;
			i--;
		}
		}
	//xoadau
	int i = 0;
	if(s[i] == ' ')
	{
		s.erase(s.begin()+i);
		}
	//xoacuoi
	i = m;
	if(s[i] == ' ')	
	{
		s.erase(s.begin()+i);
		}		
	cout<< s << endl<< "cac khoang trang da duoc xoa "<<endl;
	showmenu();	
}

void Proper()
{
    int cdai=s.length();
        if(isalnum(s[0]));
       s[0] = toupper(s[0]);
    for(int i = 0;i <= cdai ; i++)
	{
    	if(s[i]==' '&&isalnum(s[i+1]))
       s[i+1] = toupper(s[i+1]);
	}
	cout<< s << endl<< "chuoi da duoc chuan hoa "<<endl;
	c= s;
	showmenu();
}
void Soluong()
{
	int tong;
	tong = 0;
	for(int i=0; i < s.length();i++)
	{
	   if(isalnum(s[i]))
	      tong=tong+1;
    }
    cout<<"tong cac ky tu trong chuoi "<<tong <<endl;
    showmenu();
}
void Ghifile()
{
	ofstream luu;
	luu.open("output1.txt");
	luu << s;
	luu.close();
}
int main()
{
	Menu();
	system("pause");
}
