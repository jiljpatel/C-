#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	
	struct student
	{  
	    char first_name[50], last_name[50];
	    char course[100];
	    int section;
	};
	
	struct student j;
	char xfirst_name[50], xlast_name[50];
	long int recsize;
	
	fp=fopen("users.txt","rb+");
	
	if(fp==NULL)
	{
		fp= fopen("users.txt","wb+");
		if(fp==NULL)
		{
			puts("cannot open the file");
			return 0;
		}
	}
	
	recsize = sizeof(j);
	while(1)
	{ system("cls");
	      
	      cout<<"\t\t#######STUDENT DATABASE MANAGEMENT SYSTEM#########";
	      cout<<"\n\n";
	      cout<<"\n\n";
	      cout<<"\n\t\t\t1. Add Records";
	      cout<<"\n\t\t\t2. List Records";
	      cout<<"\n\t\t\t3. Modify Records";
	      cout<<"\n\t\t\t4. Delete Records";
	      cout<<"\n\t\t\t5. Exit Program";
	      cout<<"\n\n";
	      cout<<"\t\t\tSelect Your Choice :-> ";
          fflush(stdin);
		  choice = getche();
		  switch(choice)
	{
	case '1':
		fseek(fp,0,SEEK_END);
		another='Y';
		
		while(another == 'Y' || another == 'y')
		{ 
		    system("cls");
		    cout<<"Enter the First Name : ";
		    cin>>j.first_name;
		    cout<<"Enter the Last Name: ";
		    cin>>j.last_name;
		    cout<<"Enter the course: ";
		    cin>>j.course;
		    cout<<"Enter the section: ";
		    cin>>j.section;
		    fwrite(&j,recsize,1,fp);
		    cout<<"\nAdd Another Record (Y/N): ";
		    fflush(stdin);
		    another = getchar();
		}
		break;
		
	case '2':
		system("cls");
		rewind(fp);
		cout<<"===== view the Records in the database =====";
		cout<<"\n";
		
		while(fread(&j,recsize,1,fp)==1)
		{ 
		     cout<<"\n";
		     cout<<"\n"<<j.first_name<<setw(10)<<j.last_name;
		     cout<<"\n";
		     cout<<"\n"<<j.course<<setw(8)<<j.section;
		}
		cout<<"\n\n";
		system("pause");
		break;
		
	case '3':
	system("cls");
	another = 'Y';
	while (another=='Y' || 'y')	
		{ cout<<"\nEnter the last name of student : ";
		cin>>xlast_name;
		
		rewind(fp);
		while(fread(&j,recsize,1,fp)==1)
		{  if(strcmp(j.last_name,xlast_name)==0)
		{	cout<<"Enter new First name: ";
			cin>>j.first_name;
			cout<<"Enter new last name: ";
			cin>>j.last_name;
			cout<<"Enter the new course: ";
			cin>>j.course;
			cout<<"Enter the new section: ";
			cin>>j.section;
			fseek(fp,recsize,SEEK_CUR);
			fwrite(&j,recsize,1,fp);
		break;
		
		}
		else
		cout<<"Record not found";
		}
		cout<<"\n modify Another Record (Y/N) ";
		fflush(stdin);
		another = getchar();
		 } 	
		 break;
    
	case '4':
	system("cls");
	another = 'Y';
	while (another == 'Y' || another == 'y')		 
	{ 
	cout<<"\n Enter the last name of the student to delete: ";
	cin>>xlast_name;
	
	ft = fopen("temp.dat","wb");
	
	rewind(fp);
	while(fread(&j,recsize,1,fp)==1)
	
	if(strcmp(j.last_name,xlast_name)!=0)
	{ 
	   fwrite(&j,recsize,1,ft);
	}
	fclose(fp);
	fclose(ft);
	remove("users.txt");
	rename("temp.dat","users.txt");
	
	fp = fopen("users.txt","rb+");
	
	cout<<"\n Delete Another Record (Y/N): ";
	fflush(stdin);
	another=getchar();
	
	}
	break;
	
	case '5':
		fclose(fp);
		cout<<"\n\n";
		cout<<"\t\t\t    THANK YOU FOR USING THIS SOFTWARE";
		cout<<"\n\n";
		exit(0);
	}
}
system("pause");
return 0;
}
