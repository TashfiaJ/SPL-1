#include<bits/stdc++.h>
#include "create.h"
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
        ifstream iffile;

        iffile.open("My_database.txt", ios::in );

        string str, table;

        ll index = 0;

        for(ll i=0; i<total_table; i++)
        {
            iffile >> table;
            getline(iffile, str);
            getline(iffile, str);
            getline(iffile, HEADER[i]);
            getline(iffile, str);

            ll Iindex = 0;

            while (Iindex != tableinfo[i].row)
            {
                getline(iffile, FIELD[index]);
                index++;
                Iindex++;
            }

            if (i != total_table-1 )
            {
                getline(iffile, str);
            }
        }

        iffile.close();

        remove("My_database.txt");

        ofstream offile;

        offile.open( "My_database.txt", ios::app );

        index = 0;

        for(ll i=0; i<total_table; i++)
        {
            offile << table << endl << endl;
            offile << HEADER[i] << endl << endl;

            ll Iindex = 0;

            while (Iindex != tableinfo[i].row)
            {
                offile << FIELD[index] << endl;
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

                                offile << str << "\t";
                            }

                            cout << endl;
                }
            }
            if (i != total_table-1 )
            {
                offile << endl;
            }
        }

        offile.close();

        cout << "Row inserted in" << tablename <<" successfully!" << endl << endl;


    }

}
