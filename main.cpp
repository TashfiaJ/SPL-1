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
