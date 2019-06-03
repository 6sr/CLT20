# CLT20
The purpose of the program is to create a database of player with their respective “Name”, “Skill” level(out of 100),”price” and
“minimum bid value” of the players of the top  6 Teams in CLT20.

It allows user to:  
	ADD players to the database  
	VIEW entire reams with sorting options 
	MODIFY details of the players
	DELETE players
	SEARCH for players with different search parameters 
	RESET the entire system to start from scratch

The entire program is enveloped with a user-friendly, intuitive interface (with scrollable menus) for easy and seamless execution.

## VALIDATION RULES
This program also consists of some of the validation checks on the variables which are as follows:-
	1. Cost of players should be greater than or equal to $4 Millions
	2. Minimum bid of the players should be greater than or equal to $2 Millions 

## SYNOPSIS

In this project we have used following header files for the following function :-
#include<fstream.h>  (fstream)
#include<conio.h>  (textcolor(),clrscr(),cprintf(),getch())
#include<stdio.h>  (gets(),remove())
#include<string.h>  (strcmp(),strcpy(),strcmpi())
#include<dos.h>  (delay())
#include<stdlib.h>  (exit(0))
There are six binary files for six different teams :-
	sydney.dat
	mumbai.dat
	trinidad.dat
	new.dat
	chennai.dat
	highveld.dat
In this project we have used only one class anmed TEAM
Data Members - char Pname[30],int Skill,unsigned long int Price,Min_bid
Member Functions - void Accept(), void Display(int&), unsigned long int R_Price(), char * R_Pname(), int R_Skill()
UDFs in this project are :-
void log() - To login into the database
void Admin_menu() - Operates the main menu
void menu_s() - Displays main menu of the database
void submenu_s() - Displays list of Teams
void submenu_s1() - Display options for sorting 
void submenu_s2() - Display options for searching
void err_input(int &ch) - Check for valid input
void loop(int i,int j,int end)
void Add() - To add players
void Delete() - To delete players
void Reset() - To delete all data
void Search() - To search players
void Disp_team() - To display teams
void WriteFile(char Club_name[]) - To write file
void ReadFile(char Club_name[]) - To read files
void Searchskill() - To search players by skills
void Searchname() - To search players by name 
void Searchprice() - To search players by price
void Sortskill(char Club_name[]) - To sort players by skills
void Sortname(char Club_name[]) - To sort players by name
void Sortprice(char Club_name[]) - To sort players by price
void Sort(char Club_name[]) - To sort players
void Modify(char Club_name[]) - To modify details of players

