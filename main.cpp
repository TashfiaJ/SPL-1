#include<bits/stdc++.h>
#include<fstream>
using namespace std;

string command, table, TABLENAME, str;

struct ARRAY {
    string table_name;
    ll row;
    ll column;
    };


/* CREATE TABLE table (
   ID int,
   NAME varchar,
   ROLL int ) ;
*/
void create_table()
{
    cin >> table >> TABLENAME >> str;
    ofstream database;
    database.open("My_database.txt", ios::app);
    database << endl << TABLENAME << endl;

    if(str=="(")
    {
        while(str!=")")
        {
            string var_type;
            cin >> str >> var_type;
            if(str!=")")
            database << str << "\t";
        }
        cout << endl;
    }
    database.close();
}

/* INSERT INTO table name
   values ( 1, Tash, 1223 ) ;
*/
void insert_table ()
{
    string into, tablename, value, str;
    
    // input into table name values (
    cin >> into;
    cin >> tablename;
    cin >> value;
    cin >> str;
    
    // table name, total row, column row store from file
    // first need to store total table no so open the file
    ifstream ifile;
    
    ifile.open("FileInformation.txt", ios::in);
    
    ll total_table = 0;
    ifile >> total_table;
    
    // close the file
    ifile.close();
    
    //if there is no table then show this message
    if ( total_table == 0)
    {
        cout << " Can't insert the values as there is no table. First create a table\n";
    }
    
    else
    {
        ifstream ifile;
    
        ifile.open("FileInformation.txt", ios::in);
        
        ifile >> total_table;
        
        ARRAY tableinfo[total_table];
        
        //storing table name, total row, total column
        
        for(ll i=0; i<total_table; i++)
        {
            ifile >> tableinfo[i].table_name;
            ifile >> tableinfo[i].row;
            ifile >> tableinfo[i].column;
        }
    }
    
}

int main ()
{
    cout << "Enter the command: ";
    cin >> command;

    if(command == "CREATE")
    {
        create_table();
    }
    else if (command == "INSERT")
    {
        insert_table();
    }
}
