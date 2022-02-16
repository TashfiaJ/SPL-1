#include<bits/stdc++.h>
#include<fstream>
using namespace std;

string command, table, TABLENAME, str;

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
int main ()
{
    cout << "Enter the command: ";
    cin >> command;

    if(command == "CREATE")
    {
        create_table();
    }
}
