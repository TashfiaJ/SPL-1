#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

/* CREATE TABLE table (
   ID int,
   NAME varchar,
   ROLL int ) ;
*/

void createtable(string command, string table, string TABLENAME, string str)
{
    ifstream infofile;
    infofile.open("FileInformation.txt");
    ll total_table, total_column;
    infofile >> total_table;
    cout << total_table;
    infofile.close();
    if(total_table == 0)
    {
       ofstream database;
       database.open("My_database.txt", ios::app);
       database << TABLENAME << endl << endl;

       ofstream tableshowing;
       tableshowing.open("Table_Showing.txt", ios::app);

       tableshowing << TABLENAME << '\t';

       if(str=="(")
       {
           string s1;
           cin >> str >> s1;
           while(str!=")")
           {
               total_column++;
               database << str << "\t\t\t";
               tableshowing << str << '\t' << s1 << '\t';
               cin >> str >> s1;
           }
       }
       cout<<43;
       tableshowing << "." << endl;
       tableshowing.close();
       database << endl << endl;
       remove("FileInformation.txt");
       database.close();
       database.open("FileInformation.txt", ios::app);
       database << total_table+1 << endl;
       database<< TABLENAME <<'\t' << 0 << '\t' << total_column << endl;
       database.close();

       cout << endl << endl << "Table created successfully!" << endl << endl;
    }
}
