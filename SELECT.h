#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

struct ARRAY1 {
    string table_name;
    ll row;
    ll column;
    };

string *HEADER1;
string *FIELD1;

void column_name1 (ll x)
{
    HEADER1 = new string [x];
}

void field_value1(ll x)
{
    FIELD1 = new string [x];
}

void selectInfo()
{
    string checker;
    string from,s3;
    int numOfTables;

    cin>>checker;

    ofstream recordFile;
    recordFile.open("selectRecord.txt", ios :: app);

    if(checker=="*")
    {
        cin>>from>>s3;

        string userName,userID;

        cout<<endl<<"Enter your name : "<<endl;
        getline(cin,userName);
        getline(cin,userName);
        cout<<"Enter user ID : "<<endl;
        cin>>userID;

        recordFile<<endl<<endl<<userName<<endl;
        recordFile<<userID<<endl;

        recordFile<<endl<<"Checked "<<s3<<endl<<endl;

        ifstream iInfo;
        iInfo.open("info.txt", ios::in);
        iInfo>>numOfTables;
        iInfo.close();

        int g=0;

        if(numOfTables==0)
        {
            cout<<"Can't Select. Create a table  first."<<endl;
        }
