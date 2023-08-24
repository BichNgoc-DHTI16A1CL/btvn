#include<iostream>

using namespace std;

class DG{
	private:
		char ma[10], tensach[20], tg[30], ngthue[20];
		int tuoi, ngaythue, ngaytra;	
   public:
      virtual void nhap(){
		cout<<"Nhap ma sach : ";
		fflush(stdin);
		cin.getline(ma,10);
		cout<<"Nhap ten sach : ";
		fflush(stdin);
		cin.getline(tensach,20);
		cout<<"Nhap ten tac gia : ";
		fflush(stdin);
		cin.getline(tg,30);
		cout<<"Nhap ten nguoi thue : ";
		fflush(stdin);
		cin.getline(ngthue,20);
		cout<<"Nhap tuoi : ";
		cin>>tuoi;
		cout<<"Nhap ngay thue : ";
		cin>>ngaythue;
		cout<<"Nhap ngay tra : ";
		cin>>ngaytra;
		
	}
	 virtual void xuat(){
	 	cout<<"  -Ma sach : "<<ma<<endl
	 	    <<"  -Ten sach : "<<tensach<<endl
	 	    <<"  -Ten tac gia : "<<tg<<endl
	 	    <<"  -Ten nguoi thue : "<<ngthue<<endl
		    <<"  -Tuoi : "<<tuoi<<endl
			<<"  -Ngay thue : "<<get_ngaythue()<<endl
			<<"  -Ngay tra : "<<ngaytra<<endl;
	}
	int get_ngaythue(){
		return this->ngaythue;
	}
	int get_ngaytra(){
		return this->ngaytra;
	}
	int Songaymuon(){
		return this->get_ngaytra() - get_ngaythue();
	}
	char* get_tg(){
		return this->tg;
	}
	//true:noitru || false:ngoaitru
	virtual bool kieu_DG() = 0;
};
class  DG_treem : public DG{
	char nggh[20];
	public:
	void nhap(){
	DG::nhap();
		cout<<" Nhap ten nguoi giam ho : ";
		fflush(stdin);
		cin.getline(nggh,20);
     }
 	void xuat(){
		DG::xuat();
		cout<<"  -Nguoi giam ho : "<<nggh<<endl
		    <<"  -Thanh tien : "<<Thanhtien()<<endl;
	}
	int Thanhtien(){
		return this->Songaymuon()*2000;
	}
	bool kieu_DG(){
		return true;
	}	
};
class DG_nglon : public DG{
 	int tt, cmt;
	public:
	void nhap(){
	DG::nhap();
		cout<<"Nhap so chung minh thu : ";
		cin>>cmt;
     }
 	void xuat(){
		DG::xuat();
		cout<<"  -CMT : "<<cmt<<endl
		    <<"  -Thanh tien : "<<TT()<<endl;
	}
	int TT(){
		return this->get_ngaythue()*3000;
	}
	bool kieu_DG(){
		return false;
	}
};
class QL {
	private:
	   DG *a[100];
	   int n;
    public:
      void Nhap_ds(){
      	cout<<" Nhap so luong doc gia co trong danh sach"<<endl;
      	cin>>n;
      	
      	cout<<" Nhap danh sach "<<n<<" doc gia "<<endl;
      	for(int i=0; i<n; i++){
	      	cout<<"\t-Bang lua chon : "<<endl
	      	    <<"\t1.Doc gia tre em : "<<endl
	      	    <<"\t2.Doc gia nguoi lon : "<<endl
	      	    <<"\t\tMoi nhap lua chon : "<<endl;
	      	    int lc; cin>>lc;
	      	    while(lc < 1 || lc > 2)
	      	    {
    	      		cout<<"\t\tLua chon khong dung! Moi nhap lai!";
    	      		cin>>lc;
    	      	}
    	      	if(lc==1){
	      	    	a[i] = new DG_treem();
	      	    }
	      	    else{
    	      		a[i] = new DG_nglon();
    	      	}
    	      	a[i]->nhap();
	      }
      	
      }
      void Xuat_ds(){
      	cout<<" Xuat danh sach "<<n<<" doc gia "<<endl;
      	for(int i=0; i<n; i++){
	      	cout<<" Xuat thong tin doc gia "
	      	    <<(a[i]->kieu_DG() ? " tre em" : "nguoi lon")
	      	    <<" thu "<<i+1<<endl;
	      	a[i]->xuat();
	      }
      }  
   	    /*
void Tongtt(){
	      	int s=0;
	      	for(int i=0; i<n; i++){
		       	s = a[i]->Thanhtien() + a[i]->TT();
		      }
	      	cout<<" Tong tien cua ca 2 loai doc gia : "<<s<<endl;
		    }*/
       void SX(){
       	cout<<" Danh sach theo ten tu A->Z la : "<<endl;
       	  for(int i=0; i<n; i++){
       	  	for(int j=i+1; j<n; j++){
	  	       	if(strcmp(a[i]->get_tg(), a[j]->get_tg()) == 1)
  	       	   swap(a[i], a[j]);
	  	       } 
				 a[i]->xuat();     	
  	       } 	       
       }
};
int main()
{
	QL *a = new QL();
	a->Nhap_ds();
	a->Xuat_ds();
//	a->Tongtt();
	a->SX();
	return 0;
}
