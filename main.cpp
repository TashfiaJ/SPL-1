#include<bits/stdc++.h>
#include "CREATE.h"
#include "INSERT.h"
#include "SHOW.h"
#include "SELECT.h"
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
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        createtable(command, s1, s2, s3);
    }

    else if (command == "INSERT")
    {
        insert_table();
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
