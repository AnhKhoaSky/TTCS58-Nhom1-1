#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;
int x;
struct NV{
	int MaNV,Luong;
	string Ho, Ten;
}
TimNV, Timluong;

class danhsachNV
{
	private:
		int m;
	public:
	vector <NV> ds;
	void Nhap();
	void Xuat();	
	void sapxep();
	NV timNV();
	NV luonglonnhat();
	NV luongnhonhat();
};

void menu();
void Select();
void Nhap();
void Xuat();
void sapxep();
bool QuayLai();
void LuuKQ(NV TimNV, NV Timluong, danhsachNV DSNV);


int chon;
danhsachNV DSNV;


void menu(){
	cout<< "MENU" <<endl;
	cout<< "1.Nhap ma nhan vien" <<endl;
	cout<< "2.Tim nhan vien" <<endl;
	cout<< "3.Nhan vien co luong cao nhat" <<endl;
	cout<< "4.Nhan vien co luong thap nhat" <<endl;
	cout<< "5.Sap xep nhan vien tang dan" <<endl;
	cout<< "6.Luu ket qua vao file output3.txt" <<endl;
	cout<< "7.Exit" <<endl;
}

bool QuayLai()
{
	int Trove;
	cout<< "nhan 0 de tro ve quay lai" <<endl;
	cin>>Trove;
	if(Trove == 0)
	return true;
	else false;
}

void Select(){
	cout<< "chon yeu cau"<< endl;
 	cin>> chon;
 	switch(chon){
 		case 1:
 			system("cls");
 			DSNV.Nhap();
 			 if(QuayLai())
			   {
                system("cls");
                menu();
                Select();
            	}
			else
			   {
           	    cout << "Exit" << endl;
       			}
            break;
        case 2:
            system("cls");
            TimNV = DSNV.timNV();
            if(TimNV.MaNV) {
                cout << " " << endl;
                cout << "ma nhan vien: " << TimNV.MaNV;
                cout << "\nHo Lot    : " << TimNV.Ho << endl;
                cout << "\nTen       : " << TimNV.Ten << endl;
                cout << "\nLuong     : " << TimNV.Luong << endl;
                cout << " " << endl;
            } else {
                cout << "ko tim thay" << endl;
            }
            if(QuayLai()) {
                system("cls");
                menu();
                Select();
            } else {
                cout << "Exited" << endl;
            }
            break;
		case 3:
            system("cls");
            Timluong = DSNV.luonglonnhat();
            if(Timluong.MaNV) {
                cout << " " << endl;
                cout << "Ma Nhan Vien: " << Timluong.MaNV;
                cout << "\nHo Lot	 : " << Timluong.Ho << endl;
                cout << "\nTen       : " << Timluong.Ten << endl;
                cout << "\nLuong     : " << Timluong.Luong << endl;
                cout << " " << endl;
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(QuayLai()) {
                system("cls");
                menu();
                Select();
            } else {
                cout << "Exited" << endl;
            }
            break;
		case 4:
            system("cls");
            Timluong = DSNV.luongnhonhat();
            if(Timluong.MaNV) {
                cout << " " << endl;
                cout << "Ma Nhan Vien: " << Timluong.MaNV;
                cout << "\nHo Lot	 : " << Timluong.Ho << endl;
                cout << "\nTen       : " << Timluong.Ten << endl;
                cout << "\nLuong     : " << Timluong.Luong << endl;
                cout << " " << endl;
            } else {
                cout << "======================" << endl;
                cout << "ko tim thay" << endl;
            }
            if(QuayLai()) {
                system("cls");
                menu();
                Select();
            } else {
                cout << "Exited" << endl;
            }
            break;	    		    
        case 5:
            	system("cls");
            	DSNV.sapxep();
            cout << "sau khi sap xep" << endl;
                DSNV.Xuat();
            if(QuayLai()) {
                system("cls");
                menu();
                Select();
            } else {
                cout << "Exit" << endl;
            }
            break; 
		case 6:
            LuuKQ(TimNV, Timluong, DSNV);
            if(QuayLai()) {
                system("cls");
                menu();
                Select();
            } else {
                cout << "Exited" << endl;
            }
            break;	   
}
}

void danhsachNV::Nhap()
{
	int i;
	cout<< "Nhap danh sach nhan vien " <<endl;
	cin>> m;
	ds.resize(m);
	for( i=0 ; i<m ; i++)
	{
	cout<<"Nhap ma nhan vien"<<endl;
	fflush(stdin);
	cin>>ds[i].MaNV;
	cout<<"Nhap ho lot"<<endl;
	fflush(stdin);
	getline(cin, ds[i].Ho);
	cout<<"Nhap ten nhan vien"<<endl;
	fflush(stdin);
	getline(cin, ds[i].Ten);
	cout<<"Nhap luong nhan vien"<<endl;
	fflush(stdin);
	cin>>ds[i].Luong;
    }
}

void danhsachNV::Xuat()
{
	int i;
	for (i=0 ;i<m;i++)
	{
	cout<< "\n Nhan vien thu: "<< i+1;
	cout<< "\n Ma nhan vien: "<<ds[i].MaNV;
	cout<< "\n Ten nhan vien: "<<ds[i].Ten;
	cout<< "\n Ho nhan vien: "<<ds[i].Ho;
	cout<< "\n Luong nhan vien: "<<ds[i].Luong;
	cout<< " " <<endl;
    }
}

NV danhsachNV::timNV()
{
    int MaNV;
    cout << "Nhap ma nv can tim: > "; 
	cin >> MaNV;

    bool flag = false;
    for(int i = 0; i < m; i++) 
	{
        if(ds[i].MaNV == MaNV) 
		{
            return ds[i];
        }
    }
    return TimNV;
}
NV danhsachNV::luonglonnhat(){
    if(ds.size()) {
        int Max = ds[0].Luong;
        int key = 0;
        for(int i = 1; i < m; i++) {
            if(ds[i].Luong > Max) {
                Max = ds[i].Luong;
                key = i;
            }
        }
        return ds[key];
    } else {
        return Timluong;
    } 
} 
NV danhsachNV::luongnhonhat(){
    if(ds.size()) {
        int Max = ds[0].Luong;
        int key = 0;
        for(int i = 1; i < m; i++) {
            if(ds[i].Luong < Max) {
                Max = ds[i].Luong;
                key = i;
            }
        }
        return ds[key];
    } else {
        return Timluong;
    } 
} 
void danhsachNV::sapxep() 
{
    for(int i=0 ; i<m - 1; i++)
        for(int j=i + 1; j < m; j++) 
		{
            if(ds[i].Ten.compare(ds[j].Ten) > 0) 
			{
                NV tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }				
}
void LuuFile(danhsachNV DSNV) {
    ofstream fileDSNV;
    fileDSNV.open("dsnv.txt");
    int len = DSNV.ds.size();
    for(int i = 0; i < len; i++) {
        fileDSNV << "======================" << endl;
        fileDSNV << "Ma nhan vien: " << DSNV.ds[i].MaNV << endl;
        fileDSNV << "Ho nhan vien: " << DSNV.ds[i].Ho << endl;
        fileDSNV << "Ten nhan vien: " << DSNV.ds[i].Ten << endl;
        fileDSNV << "Luong nhan vien: " << DSNV.ds[i].Luong << endl;
    }
    fileDSNV.close();
    cout << "\nDa viet toi dsnv.txt\n\n";
}
void LuuKQ(NV TimNV, NV TimLuong, danhsachNV DSNV) {
    fstream KQ;
    KQ.open("output3.txt", ios::app);

    KQ << "ket qua nhan vien: " << endl;
    if(TimNV.MaNV) {
        KQ << "Ma nhan vien: " << TimNV.MaNV;
        KQ << "\nTen nhan vien: " << TimNV.Ten << endl;
        KQ << "\nHo nhan vien: " << TimNV.Ho << endl;
        KQ << "\nLuong nhan vien: " << TimNV.Luong << endl;
        KQ << " " << endl;
    } else {
        KQ << "khong tim thay\n\n";
    }

    KQ << "luong nhan vien cao nhat: " << endl;
    if(TimLuong.MaNV) {
        KQ << "Ma nhan vien: " << Timluong.MaNV;
        KQ << "\nTen nhan vien: " << TimLuong.Ten << endl;
        KQ << "\nHo nhan vien: " << TimLuong.Ho << endl;
        KQ << "\nLuong nhan vien: " << TimLuong.Luong << endl;
        KQ << " " << endl;
    } else {
        KQ << "khong tim thay nhan vien\n\n";
    }
    KQ << "khong tim thay nhan vien: " << endl;
    int tmp = DSNV.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            KQ << "======================" << endl;
            KQ << "Ma nhan vien: " << DSNV.ds[i].MaNV;
            KQ << "\nTen nhan vien: " << DSNV.ds[i].Ten << endl;
            KQ << "\nHo nhan vien: " << DSNV.ds[i].Ho << endl;
            KQ << "\nLuong nhan vien: " << DSNV.ds[i].Luong << endl;
        }
    } else {
        KQ << "khong tim thay nhan vien\n\n";
    }

    KQ.close();
    cout << "\nda luu vao output3.txt\n\n";
}

int main()
{
	menu();
	Select();
}
