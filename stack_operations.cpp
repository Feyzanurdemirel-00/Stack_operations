#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class node{
	public:
		int data;
		class node *next;
		class node *prev;
		
};
        class node *alt,*ust;
        
void bos_dolu_kontrol(){
	if(alt==NULL ){//stack boş ise ekrana "stack bos" yazar.
		cout<<"Stack bos!!"<<endl;
		
	}else{//stack boş değil ise "stackte veri var :)" yazar.
		cout<<"Stackte veri var :)"<<endl;
	}
	return;
}        
        
int push(){
	int x;
	cout<<"Stack'e eklemek istediginiz sayiyi giriniz:";
	cin>>x;//stack'e eklemek istedigimiz değeri klavyeden giriyoruz.
	class node *temp=(node*)malloc(1*sizeof(node));//temp için özel bir alan ayırdık.
	temp->data=x;//tempin datası x dedik.
	temp->next= temp->prev= NULL;//başlangıç olarak tempin next ve previne NULL dedik.
	
	if(alt == NULL)	{//stack boş ise ;
		
		alt=ust=temp;//eklenen temp hem üst hem de alt olur.
		cout<<"Tebrikler  "<<x<<"  degeri stack'e eklendi.."<<endl;
	
		return -1;
		
	}
	//eğer stack boş değil ise;
	ust->next=temp;//temp üstün nextine eklenir.
	temp->prev=ust;//bu durumda tempimizin previ üst olur.
	ust=temp;//artık en üstte temp vardır.
	cout<<"Tebrikler  " << x << "  stack'in icine eklendi"<<endl;
	
	return x;
        	
	}
	
int pop(){
	//menüden pop islemini sectigimizde otomatik olarak en üsttekini siler.
	int x;
	
	node *temp=ust;
	x=temp->data;
	if(ust==alt && !ust->data){//stack boş ise ekrana "stack zaten boş yazdırırız"
		cout<<"Stack zaten boş!"<<endl;
		return -1;
		
	}
	
	if(temp==alt){//stackte sadece 1 eleman varsa onu da sildiğimizde stack boşalır.
		ust=alt=NULL;
		cout<<x<<" 'i sildiniz ve stack bosaldi!!"<<endl;
		return -1;
		
	}
	
	//diğer durumlarda
	temp=temp->prev;//temp silinen değerin previne eşittir.
	ust=temp;//bu durumda yeni üst silinen değerin previ yani temptir.
	ust->next=NULL;//üstün nexti null yani boştur.
	temp=temp->next;
	free(temp);	//sonunda temp  çöpe atılır.
	cout<<"Tebrikler  "<< x<<" 'i sildiniz"<<endl;
	cout<<"Stack'in son hali:"<<endl;
	
	
return x;	
}	


void goster(){
	
	node *temp=ust;
	if(ust==alt && !ust->data){
		cout<<"stack boş ,gösterecek bir şey yok!"<<endl;
		return;
	}
	do{
	    
		cout<<"--------------"<<endl;
		cout<<"|"<<temp->data<<"|"<<endl;//tempin datasını gösterir
		cout<<"--------------"<<endl;
		temp=temp->prev;//her seferinde temp=temp->previ yaparak stack'i dolaşır.
	}while(temp!=NULL);
		
return;	
}
	

int main(){
	
	int secim;	

	do{	
	cout<<"                                                         "<<endl;
	cout<<"---------------STACK ISLEMLERI MENUSU--------------------"<<endl;
	cout<<"|1.Stack bos mu, dolu mu?         |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"|2.Stack'e veri ekle              |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"|3.Stack'ten veri sil             |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"|4.Stack tum verileri goster      |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"|5.Cikis                          |"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"Seciminiz nedir?"<<endl;
	cin>>secim;

	
	switch(secim){
		case 1://1'i seçersek stack boş mu dolu mu diye kontrol ettiğimiz, bos_dolu_kontrol fonksiyonu çağrılır.
			bos_dolu_kontrol();
			break;
		
		case 2://2'yi seçersek veri eklemek isteriz ve push fonksiyonu çağrılır.
		     push();
			break;
			
		case 3://3'ü seçersek veri silmek isteriz ve otomatik olarak en üstteki veriyi siler, sonra ise göster fonksiyonunu ekledik, stack'in silme işleminden sonra son halini gösterir.
		    pop();
		    goster();
			break;
			
		case 4://4'ü seçersek stack'in içini olması gereken sırayla gösterir.
		   goster();
		   break;
		   
		case 5:
		    cout<<"Menuden ciktiniz"<<endl;
		    break;
		
			
		default:	
			cout<<"....."<<endl;			
		       			
	}
	
		
	
	
}	while(secim!=5);//bu döngü sayesinde 5'i yani çıkışı seçmediğimiz sürece her işlemden sonra menüyü tekrar göstermeye devam eder. 

return 0;
}
	
