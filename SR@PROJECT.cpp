/*
CLASS XII Computer Science Project:
CLT20 PLAYER MANAGEMENT SYSTEM
DEVELOPERS:
Sachin Roy
Abhishek Garg
*/

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>      //also for system("cls");
#include<windows.h>     //for user defined gotoxy() function

void gotoxy(short x, short y) {         //Defining gotoxy
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

using namespace std;
void log();
void menu_s();
void submenu_s();
void submenu_s1();
void submenu_s2();
void loop(int i,int j,int end);
void err_input(int &ch);
void Admin_menu();
void Add();
void Delete();
void Reset();
void Disp_team();
void Modify(char Club_name[]);
void Sort(char Club_name[]);
void Search();
int  ReadFile(char Club_name[]);
void WriteFile(char Club_name[]);
void Sortname(char Club_name[]);
void Searchname();
void Sortprice(char Club_name[]);
void Searchprice();
void Sortskill(char Club_name[]);
void Searchskill();

char ch;

class TEAM
{
 char Pname[30];
 int Skill;
 unsigned long int Price,Min_bid;
 public:
 void Accept();
 void Display(int&);
 unsigned long int R_Price()
 {
  return Price;
 }
 char * R_Pname()
 {
  return Pname;
 }
 int R_Skill()
 {
  return Skill;
 }
};

void log()         //To login into the database
{
 //textcolor(3);
 int ch,i,x;
 char u[20],p[20];
 do
 {
  system("cls");
  i=0;
  gotoxy(15,5);
  cout<<"*****WELCOME TO CLT20 PLAYER MANAGEMENT SYSTEM*****";
  gotoxy(30,10);
  cout<<"Username-";
  cin>>u;
  gotoxy(30,12);
  cout<<"Password-";
  while(1)
  {
   p[i]=getch();
   if(p[i]==char(13))
    break;
   cout<<'*';
   i++;
  }
  p[i]='\0';
  if((!strcmp(p,"CLT20"))&&((!strcmp(u,"ABHISHEK"))||(!strcmp(u,"SACHIN"))))
   x=0;
  else
  {   cout<<"\n\n\t\t*****INVALID INPUT*****";
   x=1;
  }
 }while(x);
 if((!strcmp(p,"CLT20"))&&((!strcmp(u,"ABHISHEK"))||(!strcmp(u,"SACHIN"))))
 {
  gotoxy(60,25);
  cout<<"PLEASE WAIT";
  for(int i=1;i<=4;i++)
  {
   Sleep(800);
   cout<<'.';
  }
 }
}

void menu_s()         //To display main menu of database
{
 system("cls");
 gotoxy(28,4);
 //textcolor(4);
 printf("**************************");
 gotoxy(28,5);
 //textcolor(14);
 cout<<'*';
 printf("CHAMPIONS LEAQGUE TWENTY20");
 cout<<"*\n";
 gotoxy(28,6);
 //textcolor(4);
 printf("**************************\n");
 cout<<"\n 1.Add Players\n\n"
       " 2.View Teams\n\n"
       " 3.Modify Details\n\n"
       " 4.Delete players\n\n"
       " 5.Search\n\n"
       " 6.Reset\n\n"
       " 7.Exit";
 gotoxy(1,24);
 for(int i=0;i<78;i++)
  cout<<'!';
 cout<<endl;
 cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\n";
 gotoxy(1,28);
 for(int i=0;i<78;i++)
   cout<<'!';
}

void submenu_s()         //To display list of teams
{
 system("cls");
 cout<<"\n\nSelect a team:\n\n\n"
       " 1. SYDNEY SIXERS\n\n"
       " 2. MUMBAI INDIANS\n\n"
       " 3. NEW SOUTH WHALES BLUE\n\n"
       " 4. TRINIDAD AND TOBAGO\n\n"
       " 5. CHENNAI SUPER KINGS\n\n"
       " 6. HIGHVELD LIONS\n\n";
 gotoxy(1,24);
 for(int i=0;i<78;i++)
  cout<<'!';
 cout<<endl;
 cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\n";
 gotoxy(1,28);
 for(int i=0;i<78;i++)
  cout<<'!';
}

void submenu_s1()         //To display options for sorting
{
 system("cls");
 cout<<"\n\nSORT BY:\n\n� \n"
       " 1. Name\n\n"
       " 2. Skill\n\n"
       " 3. Price";
 gotoxy(1,24);
 for(int i=0;i<78;i++)
  cout<<'!';
 cout<<endl;
 cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\n";
 gotoxy(1,28);
 for(int i=0;i<78;i++)
  cout<<'!';
}

void submenu_s2()         //To display options for searching
{
 system("cls");
 cout<<"\n\nSEARCH BY:\n\n\n"
       " 1. Name\n\n"
       " 2. Skill\n\n"
       " 3. Price";
 gotoxy(1,24);
 for(int i=0;i<78;i++)
  cout<<'!';
 cout<<endl;
 cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\n";
 gotoxy(1,28);
 for(int i=0;i<78;i++)
  cout<<'!';
}

void loop(int i,int j,int end)         //To display a pattern
{
 for(i;i<=end;i++)
 {
  gotoxy(i,j+1);
  cout<<char(205);
 }
}

void err_input(int&ch)         //Check for valid input
{
 while(!((ch==13)||(ch==32)))
 {
  gotoxy(30,21);
  cout<<" !!!!!INVALID INPUT!!!!!  ";
  ch=getch();
 }
}

void Admin_menu()         //Operates the main menu 
{
 int ch,sel;
 do
 {
  sel=0;
  do
  {
   menu_s();
   loop(1,4,14);
   gotoxy(1,6);
   cout<<char(175);
   loop(1,6,14);
   ch=getch();
   err_input(ch);
   if(ch==13)
    sel=1;
   else if(ch==32)
   {
    menu_s();
    loop(1,6,13);
    gotoxy(1,8);
    cout<<char(175);
    loop(1,8,13);
    ch=getch();
    err_input(ch);
    if(ch==13)
     sel=2;
    else if(ch==32)
    {
     menu_s();
     loop(1,8,17);
     gotoxy(1,10);
     cout<<char(175);
     loop(1,10,17);
     ch=getch();
     err_input(ch);
     if(ch==13)
      sel=3;
     else if(ch==32)
     {
      menu_s();
      loop(1,10,17);
      gotoxy(1,12);
      cout<<char(175);
      loop(1,12,17);
      ch=getch();
      err_input(ch);
      if(ch==13)
       sel=4;
      else if(ch==32)
      {
       menu_s();
       loop(1,12,9);
       gotoxy(1,14);
       cout<<char(175);
       loop(1,14,9);
       ch=getch();
       err_input(ch);
       if(ch==13)
	 sel=5;
       else if(ch==32)
       {
	  menu_s();
	  loop(1,14,8);
	  gotoxy(1,16);
	  cout<<char(175);
	  loop(1,16,8);
	  ch=getch();
	  err_input(ch);
	  if(ch==13)
	   sel=6;
	  else if(ch==32)
	  {
	   menu_s();
	   loop(1,16,7);
	   gotoxy(1,18);
	   cout<<char(175);
	   loop(1,18,7);
	   ch=getch();
	   err_input(ch);
	   if(ch==13)
	    sel=7;
        }
       }
      }
     }
    }
   }
  }while((sel==0)&&(ch==32));
  switch(sel)
  {
   case 1: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(800);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   Add();
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   cout<<endl<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   break;
   case 2: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   Disp_team();
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	   cout<<'!';
	   cout<<endl<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   break;
   case 3: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   char Club_name[15];
	   Modify(Club_name);
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   cout<<endl<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   break;
   case 4: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   Delete();
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   cout<<endl<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   break;
   case 5: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   Search();
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   cout<<endl;
	   cout<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   break;
   case 6: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   system("cls");
	   gotoxy(30,12);
	   cout<<"!CAUTION!";
	   Sleep(650);
	   cout<<"\n!This will erase all the existing data!";
	   Sleep(650);
	   cout<<"\nPress ENTER to continue";
	   gotoxy(1,24);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   cout<<endl;
	   cout<<"Instructions\n";
	   cout<<"ESC-Back to main menu\nPress any other key to EXIT\n";
	   gotoxy(1,28);
	   for(int i=0;i<78;i++)
	    cout<<'!';
	   ch=getch();
	   if(ch==13)
	   {
	    system("cls");
	    Reset();
	    gotoxy(30,12);
        Sleep(1000);
	    cout<<"!Reset Complete!";
	    Sleep(1000);
	    ch=27;
	   }
	   break;
   case 7: gotoxy(25,21);
	   cout<<"PLEASE WAIT";
	   for(int i=1;i<=4;i++)
	   {
	    Sleep(1000);
	    gotoxy(35+i,21);
	    cout<<'.';
	   }
	   system("cls");
	   gotoxy(25,12);
	   cout<<"Are you sure you want to exit?";
	   gotoxy(30,13);
	   cout<<"Press ENTER to confirm";
	   Sleep(600);
	   cout<<"\nPress any other key to go back to the main menu";
	   ch=getch();
	   if(ch==13)
	   {
	    system("cls");
	    gotoxy(30,12);
	    cout<<"Exiting";
	    Sleep(600);
	    cout<<"..";
	    Sleep(600);
	    cout<<"..";
	    exit(0);
	   }
	   else
	    ch=char(27);
	   break;
  }
 }while(ch==char(27));
}

void Add()         //Add players in the teams
{
 int ch1,ch,sel;
 char Club_name[30];
 do
 {
  sel=0;
  do
  {
   submenu_s();
   loop(1,2,17);
   gotoxy(1,4);
   cout<<char(175);
   loop(1,4,17);
   ch=getch();
   err_input(ch);
   if(ch==13)
    sel=1;
   else if(ch==32)
   {
    submenu_s();
    loop(1,4,18);
    gotoxy(1,6);
    cout<<char(175);
    loop(1,6,18);
    ch=getch();
    err_input(ch);
    if(ch==13)
     sel=2;
    else if(ch==32)
    {
     submenu_s();
     loop(1,6,25);
     gotoxy(1,8);
     cout<<char(175);
     loop(1,8,25);
     ch=getch();
     err_input(ch);
     if(ch==13)
      sel=3;
     else if(ch==32)
     {
      submenu_s();
      loop(1,8,23);
      gotoxy(1,10);
      cout<<char(175);
      loop(1,10,23);
      ch=getch();
      err_input(ch);
      if(ch==13)
       sel=4;
      else if(ch==32)
      {
       submenu_s();
       loop(1,10,23);
       gotoxy(1,12);
       cout<<char(175);
       loop(1,12,23);
       ch=getch();
       err_input(ch);
       if(ch==13)       
        sel=5;
       else if(ch==32)
       {
        submenu_s();
        loop(1,12,18);
        gotoxy(1,14);
        cout<<char(175);
        loop(1,14,18);
        ch=getch();
        err_input(ch);
        if(ch==13)
         sel=6;
       }
      }
     }
    }
   }
  }while((sel==0)&&(ch==32));
  switch(sel)
  {
   case 1:strcpy(Club_name,"Sydney.dat");break;
   case 2:strcpy(Club_name,"Mumbai.dat");break;
   case 3:strcpy(Club_name,"new.dat");break;
   case 4:strcpy(Club_name,"Trinidad.dat");break; 
   case 5:strcpy(Club_name,"Chennai.dat");break;
   case 6:strcpy(Club_name,"Highveld.dat");break;
  }
  gotoxy(25,21);
  cout<<"PLEASE WAIT";
  for(int i=1;i<=4;i++)
  {
   Sleep(800);
   gotoxy(35+i,21);
   cout<<'.';
  }
  WriteFile(Club_name);
  gotoxy(10,19);
  cout<<"....Make change to another team ?(Press ENTER)....\n";
  cout<<"....To Go back to Main Menu-Press any other key\n";
  ch1=getch();
  if(ch!=13)
  {
   menu_s();
   Admin_menu();
  }
 }while(ch1==13);
}

void Delete()         //To delete players
{
 int a,x,i,ch,sel,y,pos;
 char Club_name[30];
 char ind[]={char(175),char(175),char(175),'\0'};
 sel=0;
 do
 {
  submenu_s();
  loop(1,2,17);
  gotoxy(1,4);
  cout<<char(175);
  loop(1,4,17);
  ch=getch();
  err_input(ch);
  if(ch==13)
   sel=1;
  else if(ch==32)
  {
   submenu_s();
   loop(1,4,18);
   gotoxy(1,6);
   cout<<char(175);
   loop(1,6,18);
   ch=getch();
   err_input(ch);
   if(ch==13)
    sel=2;
   else if(ch==32)
   {
    submenu_s();
    loop(1,6,25);
    gotoxy(1,8);
    cout<<char(175);
    loop(1,8,25);
    ch=getch();
    err_input(ch);
    if(ch==13)
     sel=3;
    else if(ch==32)
    {
     submenu_s();
     loop(1,8,23);
     gotoxy(1,10);
     cout<<char(175);
     loop(1,10,23);
     ch=getch();
     err_input(ch);
     if(ch==13)
      sel=4;
     else if(ch==32)
     {
      submenu_s();
      loop(1,10,23);
      gotoxy(1,12);
      cout<<char(175); 
      loop(1,12,23);
      ch=getch();
      err_input(ch);
      if(ch==13)
       sel=5;
      else if(ch==32)
      {
       submenu_s();
       loop(1,12,18);
       gotoxy(1,14);
       cout<<char(175);
       loop(1,14,18);
       ch=getch();
       err_input(ch);
       if (ch==13)
        sel=6;
      }
     }
    }
   }
  }
 }while((sel==0)&&(ch==32));
 switch(sel)
 {
  case 1:strcpy(Club_name,"Sydney.dat"); break;
  case 2:strcpy(Club_name,"Mumbai.dat"); break;
  case 3:strcpy(Club_name,"new.dat"); break;
  case 4:strcpy(Club_name,"Trinidad.dat"); break;
  case 5:strcpy(Club_name,"Chennai.dat"); break;
  case 6:strcpy(Club_name,"Highveld.dat"); break;
 }
 do
 {
  gotoxy(25,21);
  cout<<"PLEASE WAIT";
  for(int i=1;i<=4;i++)
  {
   Sleep(800);
   gotoxy(35+i,41);
   cout<<'.';
  }
  int y=ReadFile(Club_name)-3;
  gotoxy(1,24);

  for(i=0;i<78;i++)
   cout<<'!';
  cout<<endl;
  cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\nESC-Home Page\n";
  gotoxy(1,28);
  for(i=0;i<78;i++)
   cout<<'!';
  ch = getch();
  if(ch==char(27))
  {
   menu_s();
   Admin_menu();
  }
  x=y-2,sel=0;
  if(y!=2)
  {
   pos=3;
   gotoxy(1,pos);
   //textcolor(2);
   printf(ind);
   ch=getch();
   //textcolor(4);
   err_input(ch);
   switch(ch)
   {
    case 13: sel=1; break;
    case 32: for(i=2;((i<x+1)&&(sel==0));i++)
	     {
	      ReadFile(Club_name);
	      y=y-3;
	      gotoxy(1,24);
	      for(int i=0;i<78;i++)
	       cout<<'!';
	      cout<<endl;
	      cout<<"\t\t\t\tHELP MENU\n\tSpace-Scroll Down\t\t\tEnter-Select\nESC-Home Page\n";
	      gotoxy(1,28);
	      for(int j=0;j<78;j++)
	       cout<<'!';
	      ch=getch();
	      if(ch==char(27))
	      {
	       menu_s();
	       Admin_menu();
	      }
	      pos++;
	      gotoxy(1,pos);
	      //textcolor(2);
	      printf(ind);
	      ch=getch();
	      //textcolor(4);
	      err_input(ch);
	      if(ch==13)
	      sel=i;
	     }
	     break;
   }
  }
 }while((sel==0)&&(ch==32));
 if(y!=2)
 {
  fstream fil1,fil2;
  TEAM s;
  fil1.open(Club_name,ios::binary|ios::in);
  fil2.open("Temp.dat",ios::binary|ios::out);
  int a=0;
  while(fil1.read((char*)&s,sizeof(s)))
  {
   a++;
   if(sel!=a)
    fil2.write((char*)&s,sizeof(s));
  }
  remove(Club_name);
  fil1.close();
  fil2.close();
  fil1.open("Temp.dat",ios::binary|ios::in);
  fil2.open(Club_name,ios::binary|ios::out);
  while(fil1.read((char*)&s,sizeof(s)))
   fil2.write((char*)&s,sizeof(s));
  fil1.close();
  fil2.close();
  system("cls");
  gotoxy(30,12);
  cout<<"!Player deleted";
  Sleep(1600);
 }
 system("cls");
 gotoxy(15,12);
 cout<<"Choose a different player to delete? (Press ENTER) ";
 gotoxy(27,13);
 cout<<"(Else press any other key)";
 ch=getch();
 if(ch==13)
  Delete();
}

void Reset()         //To delete all data
{
 gotoxy(25,21);
 cout<<"PLEASE WAIT";
 for(int i=1;i<=4;i++)
 {
  Sleep(800);
  gotoxy(35+i,41);
  cout<<'.';
 }
 remove("Sydney.dat");
 remove("Mumbai.dat");
 remove("new.dat");
 remove("Trinidad.dat");
 remove("Chennai.dat");
 remove("Highveld.dat");
}


void Disp_team()         //To display teams
{
 int ch,sel=0;
 char Club_name[30];
 do
 {
  submenu_s();
  loop(1,2,17);
  gotoxy(1,4);
  cout<<char(175);
  loop(1,4,17);
  ch=getch();
  err_input(ch);
  if(ch==13)
   sel=1;
  else if(ch==32)
  {
   submenu_s();
   loop(1,4,18);
   gotoxy(1,6);
   cout<<char(175);
   loop(1,6,18);
   ch=getch();
   err_input(ch);
   if(ch==13)
    sel=2;
   else if(ch==32)
   {
    submenu_s();
    loop(1,6,25);
    gotoxy(1,8);
    cout<<char(175);
    loop(1,8,25);
    ch=getch();
    err_input(ch);
    if(ch==13)
     sel=3;
    else if(ch==32)
    {
     submenu_s();
     loop(1,8,23);
     gotoxy(1,10);
     cout<<char(175);
     loop(1,10,23);
     ch=getch();
     err_input(ch);
     if(ch==13)
      sel=4;
     else if(ch==32)
     {
      submenu_s();
      loop(1,10,23);
      gotoxy(1,12);
      cout<<char(175);
      loop(1,12,23);
      ch=getch();
      err_input(ch);
      if(ch==13)
       sel=5;
      else if (ch==32)
      {
       submenu_s();
       loop(1,12,18);
       gotoxy(1,14);
       cout<<char(175);
       loop(1,14,18);
       ch=getch();
       err_input(ch);
       if(ch==13)
	    sel=6;
      }
     }
    }
   }
  }
 }while((sel==0)&&(ch==32));
 switch(sel)
 {
  case 1:strcpy(Club_name,"Sydney.dat"); break;
  case 2:strcpy(Club_name,"Mumbai.dat"); break;
  case 3:strcpy(Club_name,"new.dat"); break;
  case 4:strcpy(Club_name,"Trinidad.dat"); break;
  case 5:strcpy(Club_name,"Chennai.dat"); break;
  case 6:strcpy(Club_name,"Highveld.dat"); break;
 }
 gotoxy(25,21);
 cout<<"PLEASE WAIT";
 for(int i=1;i<=4;i++)
 {
  Sleep(800);
  gotoxy(35+i,21);
  cout<<'.';
 }
 int y=ReadFile(Club_name);
 if(y!=5)
 {
  gotoxy(1,24);
  for(int i=0;i<78;i++)
  cout<<"!";
  cout<<endl;
  cout<<"\t\tHELP MENU\n\tDo you want to sort this list?(Press's')\nESC-Home Page\n";
  gotoxy(1,28);
  for(int i=0;i<78;i++)
   cout<<"!";
  ch = getch();
  if(ch==char(27))
  {
   menu_s();
   Admin_menu();
  }
  else if(ch == char(115))
   Sort(Club_name);
 }
}
void Modify(char Club_name[])         //To modify details of players
{
 int ch1,ch,sel,p,c;
 sel=0;
 do
 {
  submenu_s();
  loop(1,2,16);
  gotoxy(1,4);
  cout<<char(175);
  loop(1,4,16);
  ch=getch();
  err_input(ch);
  switch(ch)
  {
   case 13: sel=1;break;
   case32: submenu_s();
	  loop(1,4,18);
	  gotoxy(1,6);
	  cout<<char(175);
	  loop(1,6,18);
	  ch=getch();
	  err_input(ch);
	  if(ch==13)
	   sel=2;
	  else if(ch==32)
	  {
	   submenu_s();
	   loop(1,6,24);
	   gotoxy(1,8);
	   cout<<char(175);
	   loop(1,8,24);
	   ch=getch();
	   err_input(ch);
	   if (ch==13)
	    sel=3;
	   else if(ch==32)
	   {
	    submenu_s();
	    loop(1,8,22);
	    gotoxy(1,10);
	    cout<<char(175);
	    loop(1,10,22);
	    ch=getch();
	    err_input(ch);
	    if(ch==13)
	     sel=4;
	    else if(ch==32)
	    {
	     submenu_s();
	     loop(1,10,22);
	     gotoxy(1,12);
	     cout<<char(175);
	     loop(1,12,22);
	     ch=getch();
	     err_input(ch);
	     if(ch==13)
	      sel=5;
	     else if(ch==32)
	     {
	      submenu_s();
	      loop(1,12,17);
	      gotoxy(1,14);
	      cout<<char(175);
	      loop(1,14,17);
	      ch=getch();
	      err_input(ch);
	      if(ch==13)
	       sel=6;
	     }
	    }
	   }
	  }
  }
 }while((sel==0)&&(ch==32));
 switch(sel)
 {
  case 1:strcpy(Club_name,"Sydney.dat");break;
  case 2:strcpy(Club_name,"Mumbai.dat");break;
  case 3:strcpy(Club_name,"New.dat");break;
  case 4:strcpy(Club_name,"Trinidad.dat");break;
  case 5:strcpy(Club_name,"Chennai.dat");break;
  case 6:strcpy(Club_name,"Highveld.dat");break;
 }
 gotoxy(25,21);
 cout<<"PLEASE WAIT";
 for(int i=1;i<=4;i++)
 {
  Sleep(800);
  gotoxy(35+i,21);
  cout<<".";
 }
 TEAM M,s;
 do
 {
  c=0;
  system("cls");
  char pname[30];
  cout<<"\nEnter the name of the player of which you want to change the details-";
  cin>>pname;
  fstream fil1,fil2;
  fil1.open(Club_name,ios::binary|ios::out|ios::in);
  while(!fil1.eof())
  {
   p=fil1.tellg();
   fil1.read((char*)&s,sizeof(s));
   if(!strcmpi(pname,s.R_Pname()))
   {
    cout<<"\nThis player exists\n";
    cout<<"Enter new details of this player else Enter the original details\n";
    M.Accept();
    fil1.seekg(p);
    fil1.write((char*)&M,sizeof(M));
    c=1;
    break;
   }
  }
  fil1.seekg(0);
  fil1.close();
  if(c==0)
   cout<<"Sorry, There is no such player.\n";
  gotoxy(1,20);
  for(int i=0;i<78;i++)
   cout<<'!';
  cout<<"\n To go back to Main Menu-Press Esc key";
  gotoxy(40,22);
  cout<<"\nPress y to modify more records";
  gotoxy(1,24);
  for(int i=0;i<78;i++)
  cout<<'!';
  ch1=getch();
  for(int i=0;i<78;i++)
   cout<<'!';
 }while(ch1=='y'||ch==27);
 if(ch1==27)
  Admin_menu();
}

void Sort(char Club_name[])         //To sort players
{
 int ch,sel=0;
 do
 {
  submenu_s1();
  loop(1,2,8);
  gotoxy(1,4);
  cout<<char(175);
  loop(1,4,8);
  ch=getch();
  err_input(ch);
  if(ch==13)
   sel=1;
  else if(ch==32)
  {
   submenu_s1();
   loop(1,4,9);
   gotoxy(1,6);
   cout<<char(175);
   loop(1,6,9);
   ch=getch();
   err_input(ch);
   if(ch==13)
    sel=2;
   else if(ch==32)
   {
    submenu_s1();
    loop(1,6,9);
    gotoxy(1,8);
    cout<<char(175);
    loop(1,8,9);
    ch=getch();
    err_input(ch);
    if(ch==13)
     sel=3;
   }
  }
 }while((sel==0)&&(ch==32));
 switch(sel)
 {
  case 1: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Sortname(Club_name);
	break;
  case 2: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Sortskill(Club_name);
	break;
  case 3: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Sortprice(Club_name);
	break;
 }
}

void Search()      //To search players
{
 int ch,sel=0;
 do
 {
  submenu_s2();
  loop(1,2,8);
  gotoxy(1,4);
  cout<<char(175);
  loop(1,4,8);
  ch=getch();
  err_input(ch);
  switch(ch)
  {
   case 13: sel=1;break;
   case 32: submenu_s2();
	  loop(1,4,9);
	  gotoxy(1,6);
	  cout<<char(175);
	  loop(1,6,9);
	  ch=getch();
	  err_input(ch);
	  if(ch==13)
	   sel=2;
	  else if(ch==32)
	  {
	   submenu_s2();
	   loop(1,6,9);
	   gotoxy(1,8);
	   cout<<char(175);
	   loop(1,8,9);
	   ch=getch();
	   err_input(ch);
	   if(ch==13)
	    sel=3;
	  }
  }
 }while((sel==0)&&(ch==32));
 switch(sel)
 {
  case 1: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Searchname();
	break;
  case 2: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Searchskill();
	break;
  case 3: gotoxy(25,21);
	cout<<"PLEASE WAIT";
	for(int i=1;i<=4;i++)
	{
	 Sleep(800);
	 gotoxy(35+i,21);
	 cout<<'.';
	}
	Searchprice();
	break;
 }
}

void TEAM::Accept()         //To input values for object of class TEAM
{
 cout<<"Enter player's name: ";
 cin>>Pname;
 cout<<"\nEnter player's skill level(0-100): ";
 cin>>Skill;
 while(Skill<0)
 {
  cout<<"\nInvalid Input";
  cout<<"\nEnter player;s skill level(0-100):";
  cin>>Skill;
 }
 cout<<"\nEnter player's cost(In Million):"<<char(36);
 cin>>Price;
 while(Price<4)
 {
  cout<<"\nInvalid Input";
  cout<<"\nEnter player's cost(In Million):"<<char(36);
  cin>>Price;
 }
 cout<<"\nEnter player's minimum bid value(In Million):"<<char(36);
 cin>>Min_bid;
 while(Min_bid<2)
 {
  cout<<"\nInvalid Input";
  cout<<"\nEnter player's minimum bid value(In Million):"<<char(36);
  cin>>Min_bid;
 }
 cout<<endl;
}

void TEAM::Display(int &y)         //To dislay values for object of class TEAM
{
 gotoxy((15-(strlen(Pname)/2)+3),y);
 cout<<Pname;
 gotoxy(34,y);
 cout<<Skill;
 gotoxy(47,y);
 cout<<char(36)<<Price<<"Millions";
 gotoxy(65,y);
 cout<<char(36)<<Min_bid<<"Millions";
}

int ReadFile(char Club_name[])         //To read files and display data stored in it
{
 system("cls");
 int y=5;
 gotoxy(15,4);
 cout<<"PLAYER";
 gotoxy(33,4);
 cout<<"SKILL";
 gotoxy(49,4);
 cout<<"COST";
 gotoxy(67,4);
 cout<<"MIN BID";
 TEAM  A;
 ifstream fil;
 fil.seekg(0,ios::beg);
 fil.open(Club_name,ios::in|ios::binary);
 while(fil.read((char*)&A,sizeof(A)))
 {
  y++;
  A.Display(y);
 }
 fil.close();
 if(y==5)  // If file doesn't exist
 {
  system("cls");
  gotoxy(31,12);
  cout<<"!Add players first!";
  Sleep(2500);
  system("cls");
 }
 return y;
}

void WriteFile(char Club_name[])         //To write data in the files
{
 int ch,i=0;
 TEAM A,B;
 fstream fil;
 fil.open(Club_name,ios::binary|ios::in);
 while(fil.read((char *)&B,sizeof(B)))
  i++;
 fil.close();
 if(i==15)
 {
  system("cls");
  gotoxy(25,12);
  cout<<"!Maximum players added to the squad!\n";
  gotoxy(28,13);
  cout<<"!Delete players to continue!";
 }
 else
 {
  fil.open(Club_name,ios::app|ios::binary);
  do
  {
   system("cls");
   A.Accept();
   fil.write((char*)&A,sizeof(A));
   i++;
   cout<<"\n\nMore? (Press ENTER)";
   ch=getch();
  }while(ch==13&&i!=15);
  fil.close();
 }
}

void Sortname(char Club_name[])         //To sort players by name in ASCENDING order
{
    system("cls");
    fstream fil;
    fil.open(Club_name, ios::binary|ios::in|ios::out);
    fil.seekg(0, ios::end);
    TEAM pj, pjpl;
    int nor=fil.tellg()/sizeof(pj);
    for(int i=0; i<nor-1; i++)
    {
        for(int j=0; j<nor-i-1; j++)
        {
            fil.seekg(j*sizeof(TEAM));
            fil.read((char*)&pj, sizeof(pj));
            fil.read((char*)&pjpl, sizeof(pjpl));
            if(strcmpi(pj.R_Pname(), pjpl.R_Pname())>0)
            {
                fil.seekp(j*sizeof(TEAM));
                fil.write((char*)&pjpl, sizeof(TEAM));
                fil.write((char*)&pj, sizeof(TEAM));
            }
        }
    }
    fil.close();
    int y=5;
    gotoxy(15,4);
    cout<<"PLAYER";
    gotoxy(33,4);
    cout<<"SKILL";
    gotoxy(49,4);
    cout<<"COST";
    gotoxy(67,4);
    cout<<"MIN BID";
    TEAM  A;
    fstream fil1;
    fil1.open(Club_name,ios::in|ios::binary);
    while(fil1.read((char*)&A,sizeof(A)))
    {
        y++;
        A.Display(y);
    }
    fil1.close();
}

void Searchname()         //To search players by name
{
    system("cls");
    char Club_name[30];
    fstream fil1,fil2;
    char sname[30],substr[30],Actual_string[30];
    TEAM A,B;
    int z=6;
    cout<<"SEARCH FILTER:\n\n"<<endl;
    cout<<"Enter player's name: ";
    cin>>sname;
    system("cls");
    gotoxy(15,4);
    cout<<"PLAYER";
    gotoxy(33,4);
    cout<<"SKILL";
    gotoxy(49,4);
    cout<<"COST";
    gotoxy(67,4);
    cout<<"MIN BID";
    remove("SORT.DAT");
    fil2.open("SORT.DAT",ios::binary|ios::app);
    for(int a=49;a<55;a++)
    {
        switch(a)
        {
            case 49: strcpy(Club_name,"Sydney.dat"); break;
            case 50: strcpy(Club_name,"Mumbai.dat"); break;
            case 51: strcpy(Club_name,"new.dat"); break;
            case 52: strcpy(Club_name,"Trinidad.dat"); break;
            case 53: strcpy(Club_name,"Chennai.dat"); break;
            case 54: strcpy(Club_name,"Highveld.dat"); break;
        }
        fil1.open(Club_name,ios::binary|ios::in|ios::out);
        while(!fil1.eof())
        {
           fil1.read((char*)&A,sizeof(A));
           if(!strcmpi(sname,A.R_Pname()))
            {
                A.Display(z);
                break;
            }
        }
    }
}

void Sortprice(char Club_name[])         //To sort players by price in DESCENDING order
{
    system("cls");
    fstream fil;
    fil.open(Club_name,ios::binary|ios::in|ios::out);
    fil.seekg(0,ios::end);
    TEAM pj,pjp1;
    int nor=fil.tellg()/sizeof(pj);
    for(int i=0;i<nor-1;i++)
    {
        for(int j=0;j<nor-1-i;j++)
        {
            fil.seekg(j*sizeof(TEAM));
            fil.read((char*)&pj,sizeof(pj));
            fil.read((char*)&pjp1,sizeof(pjp1));
            if(pj.R_Price()<pjp1.R_Price())
            {
                fil.seekp(j*sizeof(TEAM));
                fil.write((char*)&pjp1,sizeof(TEAM));
                fil.write((char*)&pj,sizeof(TEAM));
            }
        }
    }
    fil.close();
    int y=5;
    gotoxy(15,4);
    cout<<"PLAYER";
    gotoxy(33,4);
    cout<<"SKILL";
    gotoxy(49,4);
    cout<<"COST";
    gotoxy(67,4);
    cout<<"MIN BID";
    TEAM  A;
    fstream fil1;
    fil1.open(Club_name,ios::in|ios::binary);
    while(fil1.read((char*)&A,sizeof(A)))
    {
        y++;
        A.Display(y);
    }
    fil1.close();
}

void Searchprice()         //To search players by price
{
    system("cls");
    char Club_name[30];
    fstream fil1,fil2;
    unsigned long int max,min,Found=0;
    TEAM A;
    cout<<"SEARCH FILTERS:\n\n";
    cout<<"Enter maximum price: "<<char(36); cin>>max;
    cout<<"Enter minimum price: "<<char(36); cin>>min;
    system("cls");
    remove("SORT.DAT");
    fil2.open("SORT.DAT",ios::binary|ios::app);
    for(int a=49;a<55;a++)
    {
        switch(a)
        {
            case 49: strcpy(Club_name,"Sydney.dat"); break;
            case 50: strcpy(Club_name,"Mumbai.dat"); break; 
            case 51: strcpy(Club_name,"new.dat"); break;
            case 52: strcpy(Club_name,"Trinidad.dat"); break;
            case 53: strcpy(Club_name,"Chennai.dat"); break;
            case 54: strcpy(Club_name,"Highveld.dat"); break;
        }
        fil1.open(Club_name,ios::binary|ios::in);
        while(fil1.read((char*)&A,sizeof(A)))
        {
            if((A.R_Price()>=min)&&(A.R_Price()<=max))
            {
                fil2.write((char*)&A,sizeof(A));
                Found++;
            }
        }
        fil1.close();
    }
    fil2.close();
    char sortarray[]="SORT.DAT";
    if(Found==0)
    {
        system("cls");
        gotoxy(10,30);
        cout<<"!NO RESULTS FOUND!"<<endl;
    }
    else
    {
        system("cls");
        Sortprice(sortarray);
    }
}

void Sortskill(char Club_name[])   //To sort players by skill in DESCENDING order
{
    system("cls");
    fstream fil;
    fil.open(Club_name,ios::binary|ios::in|ios::out);
    fil.seekg(0,ios::end);
    TEAM pj,pjp1;
    int nor=fil.tellg()/sizeof(pj);
    for(int i=0;i<nor-1;i++)
    {
        for(int j=0;j<nor-1-i;j++)
        {
            fil.seekg(j*sizeof(TEAM));
            fil.read((char*)&pj,sizeof(pj));
            fil.read((char*)&pjp1,sizeof(pjp1));
            if(pj.R_Skill()<pjp1.R_Skill())
            {
                fil.seekp(j*sizeof(TEAM));
                fil.write((char*)&pjp1,sizeof(TEAM));
                fil.write((char*)&pj,sizeof(TEAM));
            }
        }
    }
    fil.close();
    int y=5;
    gotoxy(15,4);
    cout<<"PLAYER";
    gotoxy(33,4);
    cout<<"SKILL";
    gotoxy(49,4);
    cout<<"COST";
    gotoxy(67,4);
    cout<<"MIN BID";
    TEAM  A;
    fstream fil1;
    fil1.open(Club_name,ios::in|ios::binary);
    while(fil1.read((char*)&A,sizeof(A)))
    {
        y++;
        A.Display(y);
    }
    fil1.close();
}

void Searchskill()         //To search players by skill
{
    system("cls");
    char Club_name[30];
    fstream fil1,fil2;
    int max,min,Found=0; 
    TEAM A,B;
    cout<<"SEARCH FILTERS:\n\n";
    cout<<"Enter maximum skill(0-100): "; cin>>max;
    cout<<"Enter minimum skill(0-100): "; cin>>min;
    system("cls");
    remove("SORT.DAT");
    fil2.open("SORT.DAT",ios::binary|ios::app);
    for(int a=49;a<55;a++)
    {
        switch(a)
        {
            case 49: strcpy(Club_name,"Sydney.dat"); break;
            case 50: strcpy(Club_name,"Mumbai.dat"); break;
            case 51: strcpy(Club_name,"new.dat"); break;
            case 52: strcpy(Club_name,"Trinidad.dat"); break;
            case 53: strcpy(Club_name,"Chennai.dat"); break;
            case 54: strcpy(Club_name,"Highveld.dat"); break;
        }
        fil1.open(Club_name,ios::binary|ios::in);
        while(fil1.read((char*)&A,sizeof(A)))
        {
            if((A.R_Skill()>=min)&&(A.R_Skill()<=max))
            {
                fil2.write((char*)&A,sizeof(A));
                Found++;
            }
        }
        fil1.close();
    }
    fil2.close();
    char sortarray[]="SORT.DAT";
    if(Found==0)
    {
        system("cls");
        gotoxy(10,30);
        cout<<"!NO RESULTS FOUND!"<<endl;
    }
    else
    {
        system("cls");
        Sortskill(sortarray);
    }
}

int main()
{
    system("cls");
    Sleep(500);
    gotoxy(27,3);
    //textcolor(4);
    cout<<"! CHAMPIONS LEAGUE TWENTY20 !";
    gotoxy(28,5);
    cout<<"! PLAYER MANAGEMENT SYSTEM !";
    Sleep(700);
    //textcolor(2);
    gotoxy(37,6);printf("   _ \n");
    gotoxy(37,7); printf("  | |\n");
    gotoxy(37,8); printf("  | |\n");
    gotoxy(37,9); printf("  | |\n");
    gotoxy(37,10); printf("  | |\n");
    gotoxy(37,11); printf("  - -\n");
    gotoxy(37,12); printf("|     |\n");
    gotoxy(37,13); printf("|     |\n");
    gotoxy(37,14); printf("|     |\n");
    gotoxy(37,15); printf("|  C  |\n");
    gotoxy(37,16); printf("|     |\n");
    gotoxy(37,17); printf("|  L  |\n");
    gotoxy(37,18); printf("|     |\n");
    gotoxy(37,19); printf("|  T  |\n");
    gotoxy(37,20); printf("|     |\n");
    gotoxy(37,21); printf("|  20 |\n");
    gotoxy(37,22); printf("|     |\n");
    gotoxy(37,23); printf("|     |\n");
    gotoxy(37,24); printf(" -----");
    gotoxy(25,25);
    cout<<"PLEASE WAIT";
    for(int i=1;i<=4;i++)
    {
       Sleep(1000);
       gotoxy(36+i,25);
       cout<<'.';
    }
    Sleep(800);
    log();
    Sleep(800);
    //textcolor(4);
    Admin_menu();
    getch();
    return 0;
}