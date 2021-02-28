#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
#include<graphics.h>
class employe
{
 int eno;
 char name[20], add[20], post[15];
 float sal;
 public:

 void show();
 void getnew();
 void modify();
 void table();
 int reteno();
 char* retname();
 char* retpost();
 char* retadd();
 float retsal();
 void design();
 void intro();
 void pass();
 int menu();
  void adnewtofile();
  void  modifyrec();
  void  display1();
  void  displayall();
  void  delrecfile();

 };
//**********************************************************
//                 CLASS ENDS
//**********************************************************


//*******************************************************
 //             SHOW RECORD
//*******************************************************
void employe :: show()
{clrscr();
design();
gotoxy(30,3);
cout<<" \3\3\3 EMPLOYEE RECORD \3\3\3 ";
gotoxy(2,6);
cout<<" => EMPLOYEE NO. : "<<reteno()<<endl;
cout<<"  => EMPLOYEE NAME : "<<retname()<<endl;
cout<<"  => POST : "<<retpost()<<endl;
cout<<"  => ADDRESS : "<<retadd()<<endl;
cout<<"  => SALARY : " <<retsal()<<endl;
}

//**********************************************************
//		 NEW RECORD
//**********************************************************

void employe :: getnew()
{ design();
gotoxy(1,8);
cout<<"\n => ENTER THE EMPLOYEE NO. : ";
cin>>eno;
cout<<" => ENTER THE EMPLOYEE NAME : ";
gets(name);
cout<<" => ENTER THE POST : ";
gets(post);
cout<<" => ENTER THE ADDRESS: ";
gets(add);
cout<<" => ENTER THE SALARY : ";
cin>>sal;
cout<<" \n\n!!! RECORD CREATED !!! ";
}
//***********************************************************
//                   UPDATED DETAILS
//***********************************************************

void employe :: modify()
{
gotoxy(25,11);
 cout<<"******* UPDATING RECORD *******";
gotoxy(1,14);
 cout<<"\n\n => ENTER THE UPDATED EMPLOYEE NO. : ";
 cin>>eno;
 cout<<" => ENTER THE UPDATED NAME : ";
 gets(name);
 cout<<" => ENTER THE UPDATED POST : ";
 gets(post);
 cout<<" => ENTER THE UPDATED ADDRESS : ";
 gets(add);
 cout<<" => ENTER THE UPDATED SALARY : ";
 cin>>sal;
 }

//**********************************************************
//             DISPLAY ALL
//**********************************************************

void  employe :: table()
{
  cout<<setw(8)<<reteno()<<setw(17)<<retname()<<setw(19)<<retpost()<<setw(15)<<retadd()<<setw(18)<<retsal()<<endl;
}
//************************************************************
//         RETURN FUNCTIONS
//************************************************************

int employe :: reteno()
{ return(eno);}
char* employe :: retname()
{return(name);}
char* employe :: retpost()
{ return(post);}
char* employe :: retadd()
{  return(add);}
float employe :: retsal()
{ return(sal);}
//**************************************************************
//                  DESIGN
//**************************************************************
void employe :: design()
{int i;
textbackground(8);
textcolor(10);
 for(i=0;i<80;i++)
 { cout<<"\5";
  }
  for(i=0;i<80;i++)
  { gotoxy(i+1,24); cout<<"\5";}
 }
//*************************************************************
//                INTRODUCTION
//*************************************************************
void employe :: intro()
{ clrscr();
 design();
 gotoxy(28,8);
  cout<<"\4\4 EMPLOYEE MANAGEMENT \4\4 \n "<<setw(43)<<" SYSTEM ";
gotoxy(45,15);  cout<<" MADE BY :- TIRTH B. DALWADI \n";
gotoxy(62,16);  cout<<" AND ";
gotoxy(57,17);  cout<<" VISHAL PRASAD ";
gotoxy(2,25);  cout<<" PRESS ANY KEY TO CONTINUE.... ";
  getch();
  clrscr();
  pass();
  }
 void employe :: pass()
{ int w=0,b=0,i;
 char pas[5];
l:clrscr();
design();

			cout<<" * ENTER THE PASSWORD :: ";
			for(i=0;i<5;i++)
			    {   pas[i]=getch();
				cout<<"*";
			      }
			 b=strcmp(pas,"tirth");
//cout<<b;
//getch();
//exit(0);
if(b==50)
{
clrscr();
design();
gotoxy(25,7);      	cout<<"!!!  ACCESS GRANTED  !!! ";

gotoxy(9,25);           cout<<"PRESS ANY KEY TO CONTINUE....";
			getch();
			clrscr();
}
if(b!=50)
{
clrscr();
design();
w++;
if((w>0)&&(w<3))
{	   gotoxy(25,7);    	    cout<<"!!!! WRONG PASSWORD !!!!\n\n ";
	   gotoxy(1,25);	    cout<<"\tPRESS ANY KET TO RETURN ";
				    getch();
				    goto l;
		    }
if(w>=3)
{ gotoxy(25,7);
  cout<<" !!! TOO MANY WRONG ATTEMPTS !!! ";
  getch();
  exit(0);
}
}
}
int employe :: menu()
{ int ch=0;
clrscr();
design();
 gotoxy(1,3);
  cout<<" => 1. ENTER NEW RECORD \n";
  cout<<" => 2. MODIFY A RECORD \n";
  cout<<" => 3. DISPLAY A RECORD \n";
  cout<<" => 4. DISPLAY ALL RECORDS \n";
  cout<<" => 5. DELETE A RECORD \n";
  cout<<" => 6. EXIT "<<"\n\n MAKE YOUR CHOICE  =>  ";
  cin>>ch;


  switch(ch)
 {
   case 1 :  adnewtofile();
		     break;
   case 2 :  modifyrec();
		     break;
   case 3 :  display1();
		     break;
   case 4 :  displayall();
		     break;
   case 5 :  delrecfile();
		     break;
   case 6 :  exit(0);

   default : cout<<" Enter a valid choice ";

 }
}
fstream vt,tv,t;
employe x;

//***********************************************************
//		 ADD A RECORD
//***********************************************************

 void employe :: adnewtofile()
{ char c;
 do
 { clrscr();
   x.design();
   gotoxy(30,3); cout<<" \3\3\3 ENTERING NEW RECORD \3\3\3 \n\n\n";
    t.open("EMPLOYEMANAGE.txt",ios::app|ios::binary);
    x.getnew();
    t.write((char*)&x,sizeof(x));
     t.close();
     cout<<" \n\n => DO YOU WANT TO ENTER MORE (y/n) ? ";
      cin>>c;
      clrscr();
 }while(c!='n');

 if(c=='n')
{menu();}
 }
//***************************************************************
//                DELETE RECORD
//***************************************************************

void employe :: delrecfile()
{clrscr();
x.design();
 employe v;
int deno;
char found = 'Y';
   gotoxy(3,3); cout<<"\n => ENTER THE EMPLOYEE NO. :: ";
    cin>>deno;
    vt.open("EMPLOYEMANAGE.txt",ios::in| ios::out|ios::binary);
    tv.open("temp.txt",ios::out);
    while(vt.read((char*)&x,sizeof(x)))
    {
	 if(x.reteno()!=deno)
	    {
	    tv.write((char*)&x,sizeof(x));
	      }
	 else
	   {
	      found = 'N';
	     }
     }
gotoxy(25,10);
     if(found =='Y')
      { cout<<" !!! RECORD NOT FOUND !!! ";
	  }
     else
      {  cout<<" !!! RECORD DELETED !!!";
	  }
      vt.close();
      tv.close();
remove("EMPLOYEMANAGE.txt");
rename("temp.txt","EMPLOYEMANAGE.txt");
gotoxy(3,25); cout<<" \3 PRESS ANY KEY TO GO BACK TO MAIN MENU.... ";
getch();
menu();
}

//*******************************************************************
//	      DISPLAY A RECORD
//*******************************************************************

void employe :: display1()
{clrscr();
 x.design();
 int deno , flag=0;
    vt.open("EMPLOYEMANAGE.txt",ios::in|ios::binary);
    gotoxy(3,3);
    cout<<"\n => ENTER THE EMPLOYEE NO. :: ";
    cin>>deno;

     if(!vt)
     {
       cout<<" !!! FILE NOT FOUND !!! ";
       }
     else
     {
       while( vt.read((char*)&x,sizeof(x)))
	  {
	   if(x.reteno()==deno)
	       { x.show();
		 flag=1;
		 }

	     }
       }
 if (flag==0)
   {
     cout<<" !!! RECORD NOT FOUND !!! ";
    }
 vt.close();
gotoxy(3,25); cout<<" \3 PRESS ANY KEY TO GO BACK TO MAIN MENU.... ";
getch();
menu();
}

//*******************************************************************
//             DISPLAY ALL
//*******************************************************************
 void employe :: displayall()
{clrscr();
textbackground(8);
textcolor(10);
 int i;
  for(i=0;i<80;i++)
   {
     gotoxy(i+1,4);
     cout<<"=";
      }
     gotoxy(32,5);
     cout<<" EMPLOYEE RECORDS ";
  for(i=0;i<80;i++)
   {
     gotoxy(i+1,6);
     cout<<"=";
     }
  gotoxy(2,8);   cout<<" EMPLOYEE NO. "<<setw(17)<<" EMPLOYEE NAME "<<setw(13)<<"POST"<<setw(15)<<"ADDRESS"<<setw(16)<<"SALARY"<<"\n\n";

   vt.open("EMPLOYEMANAGE.txt",ios::in|ios::binary);
   vt.seekg(ios::beg);
   vt.read((char*)&x,sizeof(x));
   while(vt.read((char*)&x,sizeof(x)))
   {
     x.table();
   }
   vt.close();
gotoxy(3,25);   cout<<" \3 PRESS ANY KEY TO GO BACK TO MAIN MENU.... ";
   getch();
   clrscr();
menu();
}
//********************************************************
//                  MODIFY RECORD
//********************************************************

void employe :: modifyrec()
{clrscr();
x.design();
char found = 'n';
int deno,f=0;
gotoxy(3,4);
 cout<<" ENTER THE EMPLOYEE NUMBER : ";
 cin>>deno;
 vt.open("EMPLOYEMANAGE.txt",ios::in|ios::out|ios::binary);
 while(vt.read((char*)&x,sizeof(x)))
 {
   if(x.reteno()==deno)
   {
    x.show();
    x.modify();
    vt.seekg(f*sizeof(x),ios::beg);
    vt.write((char*)&x,sizeof(x));
    found='y';
   }
   f++;

 }
 vt.close();
 if(found=='y')
 { cout<<"\n\n !!! RECORD UPDATED !!! ";
 }
 else
 { cout<<"\n\n !!!RECORD NOT FOUND !!! ";
 }
 getch();
menu();
}

void main()
{ clrscr();
 x.design();
 x.intro();
 x.menu();
 getch();
 }





























































