#include<iostream>
#include<string.>

using namespace std;

class Nguoi{
	private:
		char ten[25];
		int nam;
	public:
	   void nhap(){
   		  cout<<" Nhap ho ten : ";
   		  fflush(stdin);
   		  cin.getline(ten,25);
   		  cout<<" Nhap nam sinh : "; cin>>nam;
   	        }
   	  void xuat(){
  	   	cout<<" Ten : "<<ten<<endl
  	   	    <<" Nam sinh : "<<nam<<endl;
  	   }
};
class Thisinh : public Nguoi{
	int SBD;
	float dtoan, dli, dhoa;
	public:
	    void nhap(){
	   	this->Nguoi::nhap();
   		  cout<<" Nhap so bao danh : ";   cin>>SBD;
   		  cout<<" Nhap diem mon toan : "; cin>>dtoan;
   		  cout<<" Nhap diem mon li : "; cin>>dli;
          cout<<" Nhap diem mon hoa : "; cin>>dhoa;
   	}
   	  void xuat(){
  	   	Nguoi::xuat();
  	   	cout<<" SBD : "<<SBD<<endl
  	   	    <<" Diem toan : "<<dtoan<<endl
  	   	    <<" Diem li : "<<dli<<endl
  	   	    <<" Diem hoa : "<<dhoa<<endl;
  	   }
  	   float Tongdiem(){
   	  	  return this->dtoan+dli+dhoa;
   	  }
   	  int get_SBD(){
  	   	return this->SBD;
  	   }
  	   float get_dtoan(){
  	   	return this->dtoan;
  	   }
  	   float get_dli(){
  	   	return this->dli;
  	   }
  	   float get_dhoa(){
  	   	return this->dhoa;
  	   }
};
void Nhapds(Thisinh a[], int n)
{
	cout<<"\n\t\tNhap danh sach cac thi sinh : "<<endl;
	for(int i=0; i<n; i++){
		cout<<" Thi sinh thu "<<i+1<<endl;
		a[i].nhap();
	}
}
void Xuatds(Thisinh a[], int n)
{
	cout<<"\n\t\tDanh sach cac thi sinh : "<<endl;
	for(int i=0; i<n; i++){
		cout<<"Thong tin thi sinh thu "<<i+1<<endl;
		a[i].xuat();
	}
}
void Sx(Thisinh a[], int n)
{
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
		  if(a[i].Tongdiem() < a[j].Tongdiem())
		  {
  			swap(a[i],a[j]);
  		}
	}
}
void Timkiem(Thisinh a[], int n)
{
	int x;
	cout<<" Nhap so bao danh cua thi sinh can tim : "; cin>>x; 
	for(int i=0; i<n; i++){
		if(a[i].get_SBD() == x )
		  a[i].xuat();
        else 
          cout<<" Khong co thi sinh ban can tim! "<<endl;
	}
}
void Thongke(Thisinh a[], int n)
{
	int dem=0;
	for(int i=0; i<n; i++)
	{
		if(a[i].get_dtoan() >= 5 & a[i].get_dli() >= 5 & a[i].get_dhoa() >= 5  )
		dem++;
	}
	cout<<" Phan tram so thi sinh dat yeu cau : "<<(float)dem/n*100<<"%"<<endl;
}
int main(){
	int n;
	cout<<" Nhap so luong thi sinh : "; cin>>n;
	Thisinh a[n];
	Nhapds(a,n);
	cout<<" \n\t\tDanh sach thi sinh co tong diem ba mon tang dan : "<<endl;
	Xuatds(a,n);
	cout<<"\n\t\t Thong tin thi sinh can tim la : "<<endl;
	Timkiem(a,n);
	Thongke(a,n);
	return 0;
}