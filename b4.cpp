#include<iostream>
#include<string.h>

using namespace std;

class GV{
	private:
	   char ht[30], bc[15], cn[20];
	   int t;
	   float bl;
    public:
       GV(char *ht="",  int t=0, char *bc="", char *cn="", float bl=0){
       	strcmp(this->ht,ht);
       	this->t=t;
       	strcmp(this->bc,bc);
       	strcmp(this->cn,cn);
       	this->bl=bl;
       }
    ~GV(){}
     friend istream& operator >> ( istream& in, GV &a){
     	fflush(stdin);
     	cout<<" Nhap ten : "; in.getline(a.ht,30);
     	fflush(stdin);
     	cout<<" Nhap tuoi : "; in>>a.t;
     	fflush(stdin);
     	cout<<" Nhap bang cap : "; in.getline(a.bc,15);
     	cout<<" Nhap chuyen nganh : "; in.getline(a.cn,20);
     	fflush(stdin);
     	cout<<" Nhap bac luong : "; in>>a.bl; 
     	
     	return in;
        }
      friend ostream& operator << ( ostream& out, GV a){
      	out<<" -Ten : "<<a.ht<<endl
      	   <<" -Tuoi : "<<a.t<<endl
      	   <<" -Bang cap : "<<a.bc<<endl
      	   <<" -Chuyen nganh : "<<a.cn<<endl
      	   <<" -Bac luong : "<<a.bl<<endl
      	   <<" -Luong co ban : "<<a.LCB()<<endl; 
   	   return out;
      }
      float LCB(){
      	return this->bl*610;
      }
      bool operator == ( GV a){
      	return strcmpi(this->bc,a.bc) == 0;
      }
      char* get_bc(){
      	return this->bc;
      }
};
void Nhap_ds(GV a[], int &n)
{
	cout<<" Nhap thong tin giang vien : "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<" Nhap thong tin giang vien thu "<<i+1<<endl;
		cin>>a[i];
	}
}
void Xuat_ds(GV a[], int n){
	cout<<" Thong tin giang vien vua nhap la : "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<" Thong tin giang vien thu "<<i+1<<endl;
		cout<<a[i];
	}
}
void Sapxep(GV a[], int n)
{
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
		   if(strcmp(a[i].get_bc(), a[j].get_bc()) == 1)
		      swap(a[i], a[j]);
	}
	
}
int main(){
	int n=2;
	GV a[2];
	Nhap_ds(a,n);
	Xuat_ds(a,n);
	cout<<" Danh sach giao vien sap xep theo bang cap : "<<endl;
	Sapxep(a,n);
    Xuat_ds(a,n);
    return 0;
}