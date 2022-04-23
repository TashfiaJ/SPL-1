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
                else
        {
            ifstream iInfo;
            iInfo.open("info.txt", ios::in);
            iInfo>>numOfTables;

            structArr(numOfTables);

            for(int i=0;i<numOfTables;i++)
            {
                iInfo>>strArr[i].tableName;
                iInfo>>strArr[i].numOfRows;
                iInfo>>strArr[i].numCol;
            }

            iInfo.close();

            remove("info.txt");

            ofstream oInfo;
            oInfo.open("info.txt", ios::app);
            oInfo<<numOfTables<<endl;;

            for(int i=0;i<numOfTables;i++)
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
            }

                oInfo.close();

                int sum=0;

                for(int i=0;i<numOfTables;i++)
                {
                    sum+=strArr[i].numOfRows;
                }

                createStringArr(sum);

                if(sum==0)
                    createHeaderArray(2);
                else
                    createHeaderArray(sum);

                string tableName,s;

                ifstream dFile;
                dFile.open("database.txt", ios::in);

                int idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    dFile>>tableName;
                    getline(dFile,s);
                    getline(dFile,s);
                    getline(dFile,header[i]);
                    getline(dFile,s);

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].numOfRows)
                    {
                        getline(dFile,stringArr[idx]);
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)
                    {
                        getline(dFile,s);
                    }
                }

                dFile.close();

                remove("database.txt");

                ofstream aFile;
                aFile.open("database.txt", ios::app);

                idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    int backUpIdx=idx;
                    if(strArr[i].tableName==s3)
                    {
                        cout<<endl<<endl<<strArr[i].tableName<<endl<<endl;
                        cout<<header[i]<<endl<<endl;

                        int individualIndexTable=0;

                        while(individualIndexTable!=strArr[i].numOfRows)
                        {
                            cout<<stringArr[idx]<<endl;
                            individualIndexTable++;
                            idx++;
                        }
                    }

                    idx=backUpIdx;

                    aFile<<strArr[i].tableName<<endl<<endl;
                    aFile<<header[i]<<endl<<endl;

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].numOfRows)
                    {
                        aFile<<stringArr[idx]<<endl;
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)  aFile<<endl;
                }

                aFile.close();
        }
    }
