#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

struct ARRAY {
    string table_name;
    ll row;
    ll column;
    };
    
string *HEADER;
string *FIELD;

void column_name (ll x)
{
    HEADER = new string [x];
}

void field_value(ll x)
{
    FIELD = new string [x];
}

/* CREATE TABLE table (
   ID int,
   NAME varchar,
   ROLL int ) ;
*/
void create_table()
{   
    string command, table, TABLENAME, str;
    
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
    
    // store table name, total row, total column from file
    // first need to store total table no 
    ifstream ifile;
    
    ifile.open("FileInformation.txt", ios::in);
    
    ll total_table = 0;
    ifile >> total_table;
    
    // close the file
    ifile.close();
    
    //if there is no table then show this message
    if ( total_table == 0)
    {
        cout << " Can't insert the values as there is no table. First create a table.\n";
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
        
        ifile.close();
        
        remove("FileInformation.txt");
        
        ofstream ofile;
        
        ofile.open("FileInformation.txt", ios::app);
        
        ofile << total_table << '\n';
        
        for(ll i=0; i<total_table; i++)
        {   
            if(tableinfo[i].table_name == tablename)
            {
                ofile << tableinfo[i].table_name << " ";
                ofile << tableinfo[i].row + 1 << " ";
                ofile << tableinfo[i].column << " ";
                ofile << endl;
                
            }
            else
            {
                ofile << tableinfo[i].table_name << " ";
                ofile << tableinfo[i].row << " ";
                ofile << tableinfo[i].column << " ";
                ofile << endl;
            }
        }
        
        ofile.close();
        
        ll sum_of_rows = 0;
        
        for (ll i=0; i<total_table; i++)
        {
            sum_of_rows += tableinfo[i].row;
        }
        
        field_value (sum_of_rows);
        
        column_name (total_table);
        
        //storing the information from database
        ifstream ofile;
        
        ifile.open("My_database.txt", ios::in );
        
        string str, table;
        
        ll index = 0; 
        
        for(ll i=0; i<total_table; i++)
        {
            ifile >> table;
            getline(ifile, str);
            getline(ifile, str);
            getline(ifile, HEADER[i]);
            getline(ifile, str);
            
            ll Iindex = 0;
            
            while (Iindex != tableinfo[i].row)
            {
                geline(ifile, field_value[index]);
                index++;
                Iindex++;
            }
            
            if (i != total_table-1 )
            {
                getline(ifile, str);
            }
        }
        
        ifile.close();
        
        remove("My_database.txt");
        
        ofstream ofile;
        
        ofile.open( "My_database.txt", ios::app );
        
        index = 0; 
        
        for(ll i=0; i<total_table; i++)
        {
            ofile << table << endl << endl;
            ofile << HEADER[i] << endl << endl;
            
             Iindex = 0;
            
            while (Iindex != tableinfo[i].row)
            {
                ifile >> field_value[index] << endl;
                index++;
                Iindex++;
            }
            
            if ( table == tablename )
            {
               if(str=="(")
                {
                    while(str!=")")
                        {
                            string comma;
            
                            cin >> str >> comma;
            
                            if(str!=")")
                
                                database << str << "\t";
                            }
        
                            cout << endl;
                } 
            }
            if (i != total_table-1 )
            {
                ofile << endl;
            }
        }
        
        ofile.close();
        
        cout << "Row inserted in" << tablename <<" successfully!" << endl << endl; 
        
        
        
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
