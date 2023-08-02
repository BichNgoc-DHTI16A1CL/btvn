#include<iostream>
#include<string.h>

using namespace std;

class GV{
	private: 
	  char ten[30], bangcap[15], chuyennganh[20];
	  int tuoi;
	  float baclg, lcb;
    public:
      GV(char *ten="", int tuoi=0, char *bangcap="", char chuyennganh[]="", float baclg=0.0, float lcb=0.0){
      	strcpy(this->ten,ten);
      	this->tuoi=tuoi;
      	strcpy(this->bangcap,bangcap);
      	strcpy(this->chuyennganh,chuyennganh);
      	this->baclg=baclg;
      	this->lcb=lcb;
      }
      void Nhap(){
       	 fflush(stdin);
      	 cout<<" Nhap ten giao vien : "; cin.getline(ten,30);
      	 fflush(stdin);
      	 cout<<" Nhap tuoi : ";cin>>this->tuoi;
      	 fflush(stdin);
      	 cout<<" Nhap bang cap : "; cin.getline(this->bangcap,15);
		 cout<<" Nhap chuyen nganh : "; cin.getline(this->chuyennganh,20);
		 cout<<" Nhap bac luong : "; cin>>this->baclg; 
      }
      void Xuat(){
      	cout<<" Ten : "<<this->ten<<endl
      	    <<" Tuoi : "<<this->tuoi<<endl
      	    <<" Bang cap : "<<this->bangcap<<endl
      	    <<" Chuyen nganh : "<<this->chuyennganh<<endl
           <<" Bac luong : "<<this->baclg<<endl
           <<" Luong co ban : "<<this->Lcb();
           
      }
      float Lcb(){
      	return this->baclg * 610;
      }
      void sort_CN(GV a[], int &n){
      	for(int i=0; i<n; i++)
      	{
	      	for( int j=i+1; j<n; j++){
	      		if(strcmp(a[i].chuyennganh, a[j].chuyennganh) == 1)
                    swap(a[i], a[j]);
	      	}
	      	
	      }
      }
           
};
void Nhapds(GV a[], int &n)
{
	cout<<" Nhap danh sach :"<<endl ;
	for(int i=0; i<n; i++ ) 
	{
		cout<<" Nhap thong tin giao vien thu "<<i+1<<endl;
		a[i].Nhap();
	}
}
void Xuatds(GV a[], int &n)
{
	cout<<" Xuat danh sach :"<<endl ;
	for(int i=0; i<n; i++ ) 
	{
		cout<<" Xuat thong tin giao vien thu "<<i+1<<endl;
		a[i].Xuat();
	}
}
void GV_Luong(GV a[], int &n)
{
	cout<<" Xuat danh sach giao vien co luong nho hon 2000\n :"<<endl;
	for(int i=0; i<n; i++ ) 
	{
		if(a[i].Lcb() < 2000){
			a[i].Xuat();
		}
	}
}
int main()
{
	int n=2;
	GV a[2];
	Nhapds(a,n);
	Xuatds(a,n);
	GV_Luong(a,n);
	a[n].sort_CN(a,n);
	cout<<" Danh sach giao vien theo chuyen nganh : ";
    Xuatds(a,n);
	return 0;
}