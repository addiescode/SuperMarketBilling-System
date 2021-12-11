#include<dos.h>
#include<process.h>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
Class product
{
int pno;
char name[50];
float price,qty,tax,dis;
public:
void create_product()
{
cout<<"\n Enter The Product No. of the Product ";
cin>>pno;
cout<<"\n Enter The Name of the Product ";
gets(name);
cout<<"\n Enter The Price of the Product ";
cin>>price;
cout<<"\n Please Enter the Discount (%) ";
cin>>dis;
}
void show_product()
{
cout<<"\nThe Product No. of the Product:"<<pno;
cout<<"\nThe Name of the Product:"<<name;
cout<<"\nThe Price of The Product:"<<price;
cout<<"\nDiscount:"<<dis;
}
int retpno()
{
return pno;
}
float retprice()
{
return price;
}
char* retname()
{
return name;
}

int retdis()
{
return dis;
}
}; 

fstream fp;
product pr;
void write_product()
{
fp.open("Shop.dat",ios::out|ios::app);
pr.create_product();
fp.write((char*)&pr,sizeof(product));
fp.close();
cout<<"\n\nThe Product Has Been Created ";
getch();
}
void display_all()
{

clrscr();

cout<<"\n\n\n\t\t DISPLAY ALL RECORD !!!\n\n";
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
pr.show_product();
cout<<"\n\n====================================\n";
getch();
}
fp.close();
getch();
}

void display_sr(int n)
{
int flag=1;
fp.open("Shop.dat",ios::in);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()==n)
{
clrscr();
pr.show_product();
flag=0 ;
}
}
fp.close();
if(flag==1)
{
cout<<"\n\n record not exist";
}
getch();
}
void update_product()
{
int no,pos,found=0;
clrscr();
cout<<"\n\n\t To Update";
cout<<"\n\n\t Please Enter The Product No. of The Product";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product)) && found==0)
{
if(pr.retpno()==no)
{
pr.show_product();
cout<<"\nPlease Enter The New Details of Product"<<endl;
pr.create_product();
pos=-1*sizeof(pr);
fp.seekp(pos,ios::cur);
fp.write((char*)&pr,sizeof(product));
cout<<"\n\n\t Record Updated";
found=1;
}
}
fp.close();
if(found==0)
cout<<"\n\n Record Not Found ";
getch();
}
void delete_product()
{
int no;
clrscr();
cout<<"\n\n\n\t Delete Record";
cout<<"\n\n Please Enter The product no. of The Product You Want To Delete";
cin>>no;
fp.open("Shop.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retpno()!=no)
{
fp2.write((char*)&pr,sizeof(product));
}}
fp2.close();
fp.close();
remove("Shop.dat");
rename("Temp.dat","Shop.dat");
delay(500);
cout<<"\n\n\tRecord Deleted ..";
getch();
}
void allproduct()
{
clrscr();
fp.open("Shop.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to createFile";
cout<<"\n\n\n Program is closing ....";
getch();
exit(0);
}

cout<<"\n\n\t\tProduct MENU\n\n";
cout<<"====================================================\n";
cout<<"P.NO.\t\tNAME\t\tPRICE\n";
cout<<"====================================================\n";

while(fp.read((char*)&pr,sizeof(product)))
{
cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
}
fp.close();
}


void place_order()
{
allproduct();
int order_arr[50],quan[50],i=0;
float amt,damt,total=0;
char ch='Y';


cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n=============================\n";
do
{
cout<<"\n\nEnter The Product No. Of The Product : ";
cin>>order_arr[i];
cout<<"\n Quantity in number:";
cin>>quan[i];
i++;
cout<<"\n Do You Want To Order Another Product ? (y/n)";
cin>>ch;
}
while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For Placing The Order";
getch();
clrscr();
cout<<"\n\n********************************PAYMENT DETAILS************************\n";
delay(2000);
cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \t Amount After Discount\n";
for(int x=0;x<=i;x++)
{
fp.open("Shop.dat",ios::in);
fp.read((char*)&pr,sizeof(product));
while(!fp.eof())
{
if(pr.retpno()==order_arr[x])
{
amt=pr.retprice()*quan[x];
damt=amt-(amt*pr.retdis()/100);
cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
total+=damt;
}
fp.read((char*)&pr,sizeof(product));
}

fp.close();
}
delay(1500);
cout<<"\n\n\t\t\t\t\t\t\tTOTAL = "<<total;
delay(1000);
cout<<"\n*************************************************************************";
delay(1000);
cout<<"\n\n\t\t THANK YOU";
getch();
}


void Intro()
{
clrscr();



gotoxy(31,9);
cout<<"...SUPER MARKET...";
gotoxy(34,10);
delay(1000);
cout<<"...BILLING...";
gotoxy(37,11);
delay(1000);
cout<<"...SYASTEM...";
gotoxy(16,4);delay(1000);
cout<<"\n================================================================================";
cout<<"....WEL-COME TO SUPER MARKET BILLING SYSTEM (GG MALL)....";
cout<<"\n================================================================================";
 gotoxy(28,14);
 delay(1000);cout<<"\n________________________________________________________________________________";
delay(1000);
cout<<"\n PROJECT MADE BY : 1] Aditya Gujar \t\t Rollno=182324";
delay(1000);

cout<<"\t\t\t\t\t   2]Swapnil Gunke  \t\t Rollno=182325" ;
 cout<<"\n_________________________________________________________________________________";
delay(1000);
cout<<"\n\t COLLAGE NAME : LATTHE EDUCATIONS SOCIETYS POLYTECHNIQUE SANGLI";
textcolor(YELLOW+BLINK);
gotoxy(55,13);
cprintf("\n PRESS ANY KEY");
getch();
}
void admin_menu()
{
clrscr();
char ch2;
 gotoxy(30,3);
cout<<"\n\n\n\t ADMIN MENU";
cout<<"\n\n\t1.CREATE A NEW PRODUCT";
cout<<"\n\n\t2.DISPLAY ALL THE PRODUCTS";
cout<<"\n\n\t3.QUERY ";
cout<<"\n\n\t4.UPDATE PRODUCT";
cout<<"\n\n\t5.DELETE PRODUCT";
cout<<"\n\n\t6.VIEW PRODUCT MENU";
cout<<"\n\n\t7.BACK TO MAIN MENU";
cout<<"\n\n\t PLEASE ENTER YOUR CHOISE FROM (1-7) ";
ch2=getch();
switch(ch2)
{
case'1': clrscr();
write_product();
break;
case'2':
 display_all();
break;
case'3':
int num;
clrscr();
cout<<"\n\n\tPlease Enter The Product No. ";
cin>>num;
display_sr(num);
break;
case'4':
update_product();
break;
case'5':
delete_product();
break;
case'6':
allproduct();
getch();
case'7': break;
default:cout<<"\a";admin_menu();
}
}
void main()
{
char ch;
Intro();
do
{
clrscr();
  textbackground(BLACK);
cout<<"\n\n\n\t  MAIN MENU";
cout<<"\n\n\t01. PLACE YOUR ORDER";
cout<<"\n\n\t02. TOOLS";
cout<<"\n\n\t03. EXIT";
cout<<"\n\n\tPlease Select Your Option (1-3) ";
ch=getche();
switch(ch)
{
case'1': clrscr();
place_order();
getch();
break;
case'2': admin_menu();
break;
case'3':exit(0);
default :cout<<"\a";
}
}while(ch!='3');
}









