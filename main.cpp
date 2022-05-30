#include<bits/stdc++.h>
#include "CREATE.h"
#include "INSERT.h"
#include "SHOW.h"
#include "SELECT.h"
#include "UPDATE.h"
#include "DELETE.h"
#include<fstream>
using namespace std;
#define ll long long


int main ()
{
    string command;
    cout << "___________________________Enter the command_______________________" << endl;
    cin >> command;

    if(command == "CREATE")
    {
        string table, table_name, input;
        cin >> table >> table_name >> input;
        createtable(command, table, table_name, input);
    }

    else if (command == "INSERT")
    {
        insert_table();
    }
    
    else if (command == "UPDATE")
    {
        update();
    }
    
    else if (command == "DELETE")
    {
        delete_row();
    }
    
    else if (command == "SELECT")
    {
        select_info();
    }
    
    else if(command == "SHOW")
    {
        string  table;
        cin>>table;
        showTable(table);
    }

    else cout << "Command Invalid!\n";
}
