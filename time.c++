#include<iostream>
using namespace std;
class time{
	private :
		int hour;
		int min;
		int sec;
		public:
			thetimeis();
			timeinsec(); 
};

time :: thetimeis(){
	cout<<"Enter  time :";
	cout<<"\n1.hour? : ";
	cin>>hour;
    cout<<"\n2.minutes? : ";
    cin>>min;
	cout<<"\n3.seconds? : ";
	cin>>sec;
	cout<<"Entered time ="<<hour<<":"<<min<<":"<<sec;
	}
time :: timeinsec(){

	int i,j,k;
	i=hour*3600;
	j=min*60;
	k=sec*1;
	cout<<"\n\ntotal time in sec : "<<""<<i+j+k;
	
}

main()
{ time t1;
 t1.thetimeis();
 t1.timeinsec();
}
