//********************************************************
//         PROJECT BY:                                   *
//                    Shashank Singh                     *
//                                                       *
//                                                       *
//           CLASS:                                      *
//                 12D                                   *
//********************************************************





//****************Header files included*****************

#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<iostream>
#include<cstdlib>
using namespace std;

//******************** passwd() STARTS ****************

void passwd()
{	char str[20];
	int i=0;
	cout<<"\nEnter the password:";
	while(1)
	{	str[i]=getch();
		cout<<"*";
	if (str[i]==13 || str[i]==27)
		break;
	i++;
	}

	char wd[20];
	ifstream fin("pass.txt");
	fin>>wd;
	str[i]='\0';
	if(strcmp(str,wd)==0)
	{
		cout<<"\n\nYou are an authorized user.";
		cout<<"\n\n\n\n\n\n\t\t\t*--------------*";
		cout<<"\n\t\t\t|   WELCOME    |";
		cout<<"\n\t\t\t*--------------*";
		cout<<"\n\n\n\n\nPress any key to continue...";
		getch();
	}
	else
	{
		cout<<"\n\nYou are an unauthorized user.\n\n\nSORRY!!";
		cout<<"\n\n\n\nPress any key to exit...";
		getch();
		exit(0);
	}
}



//******************** class of which information is stored *****************


class stud
{int admno;
char name[15];
char add[20];
char ph[13];
int marks;






public:
void read()
{ 	do
	{
		int temp;
		cout<<"\nEnter admission no.-";
		cin>>temp;
		if(temp<=0 || temp>=9999)
			cout<<"Please enter the admission no. between 0 and 9999";
		else
		{       int f=0;
			stud s;
			ifstream fin("stu.dat",ios::binary);
			fin.read((char*)&s,sizeof(s));
			while(!fin.eof())
			{	 if(s.red()==temp)
				{	f=1;
					break;
				 }
				 else
					fin.read((char*)&s,sizeof(s));
			 }
			 if(f==0)
			 {       admno=temp;
				break;
			 }
			 else
				cout<<"Admno already exists please try again.";

			 }
			 }while(1);

	do
	{	cout<<"\nEnter name-";

		cin>>name;

		int d=0;
		for(int i=0;name[i];i++)
		if(isdigit(name[i]))
		{
			cout<<"Invalid name,try again.\n";
			d=1;
			break;
		}
		if(d==0)

		{

		if(strlen(name)>14)
			cout<<"Please enter the name with 14 characters only.";
		else
			break;
		}
	}while(1);
	do
	{	cout<<"\nEnter address-";
		cin>>add;
		if(strlen(add)>20)
			cout<<"Please enter the address with 20 characters only.";
		else
			break;
	}while(1);
	do
	{	cout<<"\nEnter phone no.-";
		gets(ph);
		int d=0;
		for(int i=0;ph[i];i++)
		if(isalpha(ph[i]))
		{
			cout<<"Invalid no. Try again.";
			d=1;
			break;
		}
		if(d==0)
		{
			if(strlen(ph)!=8 && strlen(ph)!=10 && strlen(ph)!=11 && strlen(ph)!=13)
				cout<<"Invalid no. Try again.";

			else
				break;
		}
	}while(1);



	do
	{	cout<<"\nEnter marks-";
		cin>>marks;
		if(marks<0 || marks>=101)
			cout<<"Please enter the marks between 0 and 100 only";
		else
			break;
	}while(1);

}
void display()
{
	cout.setf(ios::left);
	cout<<'\n'<<"|"<<"\t"<<setw(8)<<admno;
	cout<<setw(15)<<name;
	cout<<setw(20)<<add;
	cout<<setw(14)<<ph;
	cout<<setw(5)<<marks<<"\t"<<"  |";
}
int red()
{
	return admno;
}
char*red2()
{
	return name;
}
char*red3()
{
	return add;
}
char*red4()
{
	return ph;
}
int red5()
{
	return marks;
}
void change1(char str[])
{
	strcpy(name,str);
}
void change2(char str[])
{
	strcpy(add,str);
}
void change3(char str[])
{
	strcpy(ph,str);
}
void change4(int x)
{
	marks=x;
}
};




//******************* create() STARTS *******************


void create()
{       system("cls");
	char ch;
	stud s1;

		system("cls");
		ofstream fout("stu.dat",ios::binary);
		s1.read();
		fout.write((char*)&s1,sizeof(s1));
		fout.close();
		system("cls");
		cout<<"\nNew File has been created.\n";
		getch();
}


//*********************** app() STARTS *********************



void app()
{
	stud s1;
	char ch;
	do
	{       ofstream fout("stu.dat",ios::binary|ios::app);
		system("cls");
		s1.read();
		fout.write((char*)&s1,sizeof(s1));
		system("cls");
		cout<<"\nWant to enter more records?(y/n)";
		cin>>ch;
		fout.close();
	}while(ch=='y' || ch=='Y');

}





//********************* disp() STARTS **********************


void disp()
{
	cout<<"*----------------------------- SCHOOL RECORDS ----------------------------*";


	ifstream fin("stu.dat",ios::binary);
	if(!fin)
	{       system("cls");
		cout<<"Empty file !!!";
		cout<<"\n\nPress any key to continue....";getch();
		system("cls");
	}
	else
	{       cout.setf(ios::left);
	cout<<'\n'<<"|"<<"\t"<<setw(8)<<"Admno";
	cout<<setw(15)<<"Name";
	cout<<setw(20)<<"Address";
	cout<<setw(14)<<"Phone no.";
	cout<<setw(5)<<"Marks"<<"\t"<<"  |";
		cout<<"\n*-------------------------------------------------------------------------*";

		stud s1;
		fin.read((char*)&s1,sizeof(s1));
		while(!fin.eof())
		{	s1.display();
			fin.read((char*)&s1,sizeof(s1));
		}
	}
	fin.close();
	cout<<"\n*-------------------------------------------------------------------------*";
}


//************************** del() STARTS *******************



void del()
{       stud s1;
	int num,F=0;
	char ch;
	do
	{

	ifstream fin("stu.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary);
	if(!fin)
	{       system("cls");
		cout<<"\nFile not found.";
		cout<<"\n\nPress any key to continue...";goto c;
	}
	cout<<"\n\nEnter admno to be deleted: ";
	cin>>num;
	fin.read((char*)&s1,sizeof(s1));
	while(!fin.eof())
	{       if(s1.red()==num)
		F=1;
		if(s1.red()!=num)
		{	fout.write((char*)&s1,sizeof(s1));
		}
		fin.read((char*)&s1,sizeof(s1));
	}
	fin.close();
	fout.close();
	remove("stu.dat");
	rename("temp.dat","stu.dat");

	if(F==0)
		cout<<"Record wasn't found or file was Empty!!.";
	else
		cout<<"The selected record has been deleted.";

	cout<<"\n\nWant to delete more records?(y/n)";
	cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<"\n\nPress any key to continue...";
	c:
	getch();


}


//*********************** modify() starts *********************


void modify()
{

	stud s1,s;
	int num,F=0,ch,ma;
	long double pos=0;
	char nam[18],addr[30],phn[13];
	cout<<"\nEnter the admission no. whose information you want to modify:";
	cin>>num;
	fstream fin("stu.dat",ios::binary|ios::in|ios::out);
	fstream f("stu.dat",ios::binary|ios::in|ios::out);
	while(!f.eof())
	{	if(s.red()==num)
		{	F=1;
			break;
		}
		else
			f.read((char*)&s,sizeof(s));
	}
	if(F==0)
	{	cout<<"\nMatch not found";
		cout<<"\nPress any key to continue...";
		goto c;
	}


	system("cls");
	cout<<"1.To change name";
	cout<<"\n2.To change address";
	cout<<"\n3.To change phone no.";
	cout<<"\n4.To change marks.";
	do
	{	cout<<"\n\nEnter choice-";
		cin>>ch;
		if(ch<=0 || ch>=5)
			cout<<"\nPlease enter the choice between 1 to 4 only.";
		else
			break;
	}while(1);


	if(ch==1)
	      do
		{	cout<<"\nEnter name to be replaced with-";
			gets(nam);
			if(strlen(nam)>14)
			cout<<"\nPlease enter the name with 14 characters only.";
			else
				break;
		}while(1);
	else if(ch==2)
		do
		{	cout<<"\nEnter address to be renamed with-";
			gets(addr);
			if(strlen(addr)>20)
			cout<<"\nPlease enter the address with 20 characters only.";
			else
				break;
		}while(1);
	else if(ch==3)
	do
	{	cout<<"\nEnter the phone no. to be replaced with-";
		gets(phn);
		if(strlen(phn)!=8 && strlen(phn)!=10 && strlen(phn)!=11 && strlen(phn)!=13)
			cout<<"\nInvalid no. Try again.";
		else
			break;
	}while(1);
	else if(ch==4)
		do
		{	cout<<"\nEnter marks to be replaced with-";
			cin>>ma;
			if(ma<0 || ma>=101)
			cout<<"\nPlease enter the marks between 0 and 100 only";
			else
				break;
		}while(1);
	if(!fin)
	{	cout<<"\n\nFile Not Found";
		cout<<"\n\nPress any key to continue...";
		goto c;
	}
	else
	{  	pos=fin.tellg();
		fin.read((char*)&s1,sizeof(s1));
		while(!fin.eof())
		{	if(s1.red()==num)
			{       if(ch==1)
					s1.change1(nam);
				else if(ch==2)
					s1.change2(addr);
				else if(ch==3)
					s1.change3(phn);
				else if(ch==4)
					s1.change4(ma);
				cout<<"\nRecord has been modified.";
				cout<<"\n\nPress any key to continue...";
			}

			fin.seekg(pos);
			fin.write((char*)&s1,sizeof(s1));
			pos=fin.tellg();
			fin.read((char*)&s1,sizeof(s1));
		}
	}
	c:
	getch();
}



//********************** search() STARTS *************************


void search()
{
	int ch;
	system("cls");
	cout<<"1.According to admission no\n";
	cout<<"2.According to name\n";
	cout<<"3.According to address\n";
	cout<<"4.According to phone no.\n";
	cout<<"5.According to marks\n";
	cout<<"6.Exit search.\n";
	do
	{
		cout<<"\nEnter choice-";
		cin>>ch;
		if(ch<=0 || ch>=7)
		cout<<"\nPlease enter choice between 1 and 6.";
		else
		break;
	}while(5);
	char str[30];
	int x,count=0;
	stud s;
	ifstream fin("stu.dat",ios::binary);
	if(ch==1)
	{
		cout<<"\nEnter admission no. to be searched for-";
		cin>>x;
	}
	else if(ch==2)
	{
		cout<<"\nEnter name to be searched for-";
		gets(str);
	}
	else if(ch==3)
	{
		cout<<"\nEnter address to be searched for-";
		gets(str);
	}
	else if(ch==4)
	{
		cout<<"\nEnter phone no. to be searched for-";
		gets(str);
	}
	else if(ch==5)
	{
		cout<<"\nEnter marks to be searched for-";
		cin>>x;
	}
	else if(ch==6)
		goto c;

	if(!fin)
	{
		cout<<"\n\nFile not found.";
		goto c;
	}
	else
	{       fin.read((char*)&s,sizeof(s));
		system("cls");
		cout<<"*----------------------------- SEARCH RESULTS ----------------------------*";
		while(!fin.eof())
		{
			if(ch==1)
			{
				if(s.red()==x)
				{	s.display();
					count++;
				}
			}
			else if(ch==2)
			{	if(strcmpi(s.red2(),str)==0)
				{	s.display();
					count++;
				}
			}
			else if(ch==3)
			{
				if(strcmpi(s.red3(),str)==0)
				{	s.display();
					count++;
				}
			}
			else if(ch==4)
			{
				if(strcmpi(s.red4(),str)==0)
				 {	s.display();
					count++;
				 }
			}
			else if(ch==5)
			{	if(s.red5()==x)
				{	s.display();
					count++;
				}
			}
			fin.read((char*)&s,sizeof(s));
		}
		if(count==0)
		cout<<"\n|\t\t\t       No results found        \t\t\t|";
		cout<<"\n*-------------------------------------------------------------------------*";

	}
	c:
	cout<<"\n\nPress any key to continue...";
	getch();
}




//*********************** MAIN() **************************



int main()
{system("cls");
passwd();
int ch;
system("cls");
disp();
while(5)
{
	system("cls");
	disp();
	cout<<"\n\n";
	cout<<"\n\t1.Create  ";
	cout<<"2.Append  ";
	cout<<"3.Modify  ";
	cout<<"4.Delete  ";
	cout<<"5.Search  ";
	cout<<"6.Exit\n";
	cout<<"\nEnter choice-";
		cin>>ch;
	switch(ch)
	{	case 1:create();break;
		case 2:app();break;
		case 3:modify();break;
		case 4:del();break;
		case 5:search();break;
		case 6: system("cls");
			cout<<"\n\n\n\n\n\n\n\t\t\t\t*-------*\n";
			cout<<"\t\t\t\t|  BYE  |\n";
			cout<<"\t\t\t\t*-------*";
			cout<<"\n\n\n\n\n\n\n";
			getch();
			exit(0);
			break;
		default:cout<<"\nPlease enter number between 1 to 6";
			cout<<"\n\n\nPress any key to continue...";
			getch();
	}
}
return 0;
}











