#include<my.h>
void hline1()
{
	for(int i=0;i<=79;i++)
	{
		cout<<char(178);
	}
}
void vline1()
{
	for(int i=0;i<=22;i++)
	{
		for(int j=0;j<=1;j++)
		{
			if(j==1)
			{
				cout<<char(178);
				cout<<endl;
			}
		}
	}
}
void hline2()
{

	gotoxy(1,24);
	for(int i=0;i<=79;i++)
	{
		cout<<char(178);
	}

}
void vline2()
{
	for(int i=1;i<=23;i++)
	{
		gotoxy(80,i);
		cout<<char(178);
	}

}
void heading()
{
	gotoxy(30,3);
	cout<<"RP Banking Facility ";
}
void line()
{
	gotoxy(1,5);
	for(int i=0;i<81;i++)
	{
		gotoxy(i,5);
		cout<<char(4);
	}
}

void border()
{
	hline1();
	vline1();
	hline2();
	vline2();
	heading();
	line();
}



class bank
{
	char name[30];
	int accno;
	int age;
	char address[30];
	char phoneno[10];
	float bal;

	public:

	void putdata()
	{

		cout<<setw(2)<<accno;
		cout<<setw(10)<<name;
		cout<<setw(7)<<age;
		cout<<setw(12)<<address;
		cout<<setw(18)<<phoneno;
		cout<<setw(10)<<bal;

	}

	bank()
	{
		bal=0;
	}

	~bank()
	{
		;
	}

	void getdata()
	{
		accno=autogen();
		gotoxy(20,7);
		cout<<"Account No:";
		gotoxy(50,7);
		cout<<accno;
		gotoxy(20,9);
		cout<<"Enter the Age:";
		gotoxy(50,9);
		cin>>age;
			if(age<18)
			{
				deleteag(age);
				gotoxy(20,17);
				cout<<"Under Age ";
				getch();

				goto a;
			}
			else
			{
				;
			}
		gotoxy(20,11);
		cout<<"Enter the Name:";
		gotoxy(50,11);
		gets(name);
		gotoxy(20,13);
		cout<<"Enter your address:";
		gotoxy(50,13);
		gets(address);
		b:
		gotoxy(20,15);
		cout<<"Enter your phone number:";
		gotoxy(50,15);
		gets(phoneno);
			if(strlen(phoneno)!=10)
			{
				gotoxy(20,17);
				cout<<"Not Valid. Enter Again ";
				goto b;
			}
		a:
	}

	void getdata1(int x)
	{
		accno=x;
		gotoxy(20,7);
		cout<<"Account No:";
		gotoxy(50,7);
		cout<<accno;
		gotoxy(20,9);
		cout<<"Enter the Age:";
		gotoxy(50,9);
		cin>>age;
			if(age<18)
			{
				deleteag(age);
				gotoxy(20,17);
				cout<<"Under Age ";
				getch();

				goto y;
			}
			else
			{
				;
			}
		gotoxy(20,11);
		cout<<"Enter the Name:";
		gotoxy(50,11);
		gets(name);
		gotoxy(20,13);
		cout<<"Enter your address:";
		gotoxy(50,13);
		gets(address);
		z:
		gotoxy(20,15);
		cout<<"Enter your phone number:";
		gotoxy(50,15);
		gets(phoneno);
			if(strlen(phoneno)!=10)
			{
				gotoxy(20,17);
				cout<<"Not Valid. Enter Again ";
				goto z;
			}
		y:
	}


	float returnbal()
	{
		return bal;
	}

	float balchng1(float x)
	{
		bal=bal-x;
		return bal;
	}

	float balchng2(float x)
	{
		bal=bal+x;
		return bal;
	}


	int autogen()
	{
		int max=0;
		int c=1;
		bank o;
		ifstream fin;
		fin.open("acc.txt",ios::in|ios::binary);
		while(fin.read((char *)&o,sizeof(o)))
		{
			if(c==1)
			{
				max=o.returnaccno();
			}
			else if(max<o.returnaccno())
			{
				max=o.returnaccno();
			}
			c++;
		}
		fin.close();
		return max+1;
	}




	int returnaccno()
	{
		return accno;
	}

	int returnage()
	{
		return age;
	}



};

void deleteag(int x)
{
	bank o;
	ifstream fin;
	ofstream fout;
	fin.open("acc.txt",ios::in|ios::binary);
	fout.open("tacc.txt",ios::out|ios::binary);
	while(fin.read((char *)&o,sizeof(o)))
	{
		if(x!=o.returnage())
		{
			fout.write((char *)&o,sizeof(o));
		}
	}
	fout.close();
	fin.close();
	remove("acc.txt");
	rename("tacc.txt","acc.txt");
}

void deleteac(int x)
{
	bank o;
	int c=1;
	ifstream fin;
	ofstream fout;
	fin.open("acc.txt",ios::in|ios::binary);
	fout.open("tacc.txt",ios::out|ios::binary);
	while(fin.read((char *)&o,sizeof(o)))
	{
		if(x!=o.returnaccno())
		{
			fout.write((char *)&o,sizeof(o));

		}
		else if(x==o.returnaccno())
		{
			c=0;
		}

	}
	fout.close();
	fin.close();
	remove("acc.txt");
	rename("tacc.txt","acc.txt");
	if(c==0)
	{
		clrscr();
		border();
		gotoxy(25,15);
		cout<<"Record deleted...";
		getch();
		goto h;


	}
	else
	{
		clrscr();
		border();
		gotoxy(25,15);
		cout<<"Record Does Not Exist";
		getch();
		goto h;
	}

	h:
}
void dscr(int j)
{
	clrscr();
	border();
	gotoxy(5,j);
	cout<<"A/C";
	gotoxy(11,j);
	cout<<"Name";
	gotoxy(22,j);
	cout<<"Age";
	gotoxy(32,j);
	cout<<"Address";
	gotoxy(44,j);
	cout<<"Phone";
	gotoxy(60,j);
	cout<<"Balance";
	gotoxy(1,j+1);
	for(int i=2;i<80;i++)
	{
		gotoxy(i,j+1);
		cout<<char(4);
	}


}


void readall()
{
	clrscr();
	border();
	bank o;
	ifstream fin;
	int j=9;
	dscr(7);
	fin.open("acc.txt",ios::in|ios::binary);
	while(fin.read((char *)&o,sizeof(o)))
	{

		gotoxy(5,j);
		o.putdata();
		cout<<endl;
		j++;
	}
	fin.close();
}

void read1r(int x)
{
	bank o;
	int c=0;
	ifstream fin;
	fin.open("acc.txt",ios::in|ios::binary);
	while(fin.read((char *)&o,sizeof(o)))
	{
		if(x==o.returnaccno())
		{
			dscr(7);
			gotoxy(5,9);
			o.putdata();
			c=1;
			goto f;
		}

	}
	f:
	fin.close();
	if(c==0)
	{
		clrscr();
		border();
		gotoxy(10,10);
		cout<<"Record Does Not Exist";
	}
}


void withdraw()
{
	bank o;
	fstream fio;
	int x;
	float amu;
	int c=0;
	fio.open("acc.txt",ios::in|ios::out|ios::binary);
	clrscr();
	border();
	gotoxy(20,7);
	cout<<"Enter the Account No...";
	cin>>x;
	gotoxy(20,9);
	cout<<"Enter the amount to be withdrawed...";
	cin>>amu;
	while(fio.read((char *)&o,sizeof(o)))
	{
		if(x==o.returnaccno())
		{
			c=1;
			if(amu<=o.returnbal())
			{
				o.balchng1(amu);
				fio.seekp(fio.tellg()-sizeof(o),ios::beg);
				fio.write((char *)&o,sizeof(o));
				gotoxy(20,11);
				cout<<"Withdrawed...";
				getch();
				goto d;

			}
			else
			{
				gotoxy(20,11);
				cout<<"Not Enough Balance!!!";
				getch();
				goto d;
			}
		}
	}
	d:
	fio.close();
	if(c==0)
	{
		clrscr();
		border();
		gotoxy(10,10);
		cout<<"Record Does Not Exist";
	}
}


void deposit()
{
	bank o;
	fstream fio;
	int x;
	float amu;
	int c=0;
	fio.open("acc.txt",ios::in|ios::out|ios::binary);
	clrscr();
	border();
	gotoxy(20,7);
	cout<<"Enter the Account No...";
	cin>>x;
	gotoxy(20,9);
	cout<<"Enter the amount to be deposited...";
	cin>>amu;
	while(fio.read((char *)&o,sizeof(o)))
	{
		if(x==o.returnaccno())
		{
			c=1;
			o.balchng2(amu);
			fio.seekp(fio.tellg()-sizeof(o),ios::beg);
			fio.write((char *)&o,sizeof(o));
			gotoxy(20,11);
			cout<<"Deposited...";
			getch();
			goto e;

		}

	}
	e:
	fio.close();
	if(c==0)
	{
		gotoxy(20,11);
		cout<<"Account Does Not Exist...";
		getch();
	}
}







void newacc()
{
	bank o;
	up:
	clrscr();
	border();
	ofstream store("acc.txt",ios::app|ios::binary);
	o.getdata();
	store.write((char *)&o,sizeof(o));
	store.close();
	again:
	int ch;
	gotoxy(10,17);
	cout<<"Do you want add another record Yes(1)/No(0) ";
	gotoxy(70,17);
	cin>>ch;
	if(ch==0)
	{
		goto down;
	}
	else if(ch==1)
	{
		goto up;
	}
	else
	{
		gotoxy(25,20);
		cout<<"Choice Not Valid. Enter Again ";
		goto again;
	}
	down:



}


void balenq()
{
	bank o;
	clrscr();
	border();
	int x;
	int c=0;
	gotoxy(20,7);
	cout<<"Enter the Account No...";
	cin>>x;
	ifstream fin;
	fin.open("acc.txt",ios::in|ios::binary);
	while(fin.read((char *)&o,sizeof(o)))
	{
		if(x==o.returnaccno())
		{
			c=1;
			gotoxy(20,9);
			int b=o.returnbal();
			cout<<"Your Current Balance is..."<<b;
			getch();
			goto e;
		}

	}
	e:
	fin.close();
	if(c==0)
	{
		gotoxy(20,7);
		cout<<"Account Does Not Exist...";
		getch();
	}
}





void  details()
{
	bank o;
	clrscr();
	border();
	int x;
	gotoxy(25,13);
	cout<<"Enter the Account No:";
	gotoxy(50,13);
	cin>>x;
	read1r(x);
	getch();


}

void modify(int x)
{
	bank o;
	fstream fio;
	fio.open("acc.txt",ios::in|ios::out|ios::binary);
	while(fio.read((char *)&o,sizeof(o)))
	{
		if(o.returnaccno()==x)
		{
			clrscr();
			border();
			o.getdata1(x);
			fio.seekp(fio.tellg()-sizeof(o),ios::beg);
			fio.write((char *)&o,sizeof(o));
		}
	}
	gotoxy(25,17);
	cout<<"Record Updated...";
	fio.close();
}

void main()
{
	up:
	clrscr();
	border();
	gotoxy(4,7);
	cout<<"1.New Account";
	gotoxy(27,7);
	cout<<"2.Transactions";
	gotoxy(50,7);
	cout<<"3.Details";
	gotoxy(70,7);
	cout<<"4.Delete";
	gotoxy(4,10);
	cout<<"5.Modify";
	gotoxy(27,10);
	cout<<"6.All Acc. Holders";
	gotoxy(50,10);
	cout<<"7.Balance Enquiry";
	gotoxy(70,10);
	cout<<"8.Exit";
	gotoxy(55,22);
	cout<<"Enter your choice...";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		newacc();
		goto up;
	}
	else if(choice==2)
	{
		c:
		clrscr();
		border();
		gotoxy(10,10);
		cout<<"1.Deposit";
		gotoxy(35,10);
		cout<<"2.Withdrawal";
		gotoxy(60,10);
		cout<<"3.Main Menu";
		gotoxy(28,13);

		int ch;
		cout<<"Enter your choice...";
		cin>>ch;
		if(ch==1)
		{
			deposit();
			goto up;
		}
		else if(ch==2)
		{
			withdraw();
			goto up;
		}
		else if(ch==3)
		{
			goto up;
		}
		else
		{
			gotoxy(32,17);
			cout<<"Invalid Choice";
			getch();
			goto c;
		}


	}

	else if(choice==3)
	{
		details();
		goto up;
	}
	else if(choice==4)
	{
		clrscr();
		border();
		int x;
		gotoxy(25,15);
		cout<<"Enter the Account No...";
		cin>>x;
		deleteac(x);
		goto up;

	}
	else if(choice==5)
	{
		clrscr();
		border();
		int x;
		gotoxy(25,13);
		cout<<"Enter the Account No...";
		cin>>x;

		modify(x);
		getch();
		goto up;
	}
	else if(choice==6)
	{
		readall();
		getch();
		goto up;
	}
	else if(choice==7)
	{
		balenq();
		goto up;
	}
	else if(choice==8)
	{
		clrscr();
		gotoxy(36,12);
		cout<<"Thank You";
		getch();
		goto exit;
	}
	else
	{
		gotoxy(35,10);
		cout<<"Invalid Choice"<<endl;
		gotoxy(35,12);
		cout<<"Enter again";
		gotoxy(75,22);
		goto up;
	}
	exit:

}
