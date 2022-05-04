#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

struct ARRAY2 {
    string table_name;
    ll row;
    ll column;
    };

string *HEADER2;
string *FIELD2;
ARRAY2 *strArr;

void column_name2 (ll x)
{
    HEADER2 = new string [x];
}

void field_value2(ll x)
{
    FIELD2 = new string [x];
}

void structArr(ll n)
{
    strArr = new ARRAY2[n];
}

void select_info()
{
    string checker;
    string from,s3;
    ll numOfTables;

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
        iInfo.open("FileInformation.txt", ios::in);
        string s;
        iInfo >> s;
        if(s=="")
            numOfTables=0;
        else numOfTables=stoll(s);
        iInfo.close();

        int g=0;

        if(numOfTables==0)
        {
            cout<<"Can't Select. Create a table  first."<<endl;
        }

        else
        {
            ifstream iInfo;
            iInfo.open("FileInformation.txt", ios::in);
            iInfo>>numOfTables;

            structArr(numOfTables);

            for(int i=0;i<numOfTables;i++)
            {
                iInfo>>strArr[i].table_name;
                iInfo>>strArr[i].row;
                iInfo>>strArr[i].column;
            }

            iInfo.close();

            remove("FileInformation.txt");

            ofstream oInfo;
            oInfo.open("FileInformation.txt", ios::app);
            oInfo<<numOfTables<<endl;;

            for(ll i=0;i<numOfTables;i++)
            {
                oInfo<<strArr[i].table_name<<" "<<strArr[i].row<<" "<<strArr[i].column<<endl;
            }

                oInfo.close();

                ll sum=0;

                for(ll i=0;i<numOfTables;i++)
                {
                    sum+=strArr[i].row;
                }
                
                field_value2 (sum);

                column_name2 (numOfTables);

                string tableName,s;

                ifstream dFile;
                dFile.open("My_database.txt", ios::in);

                int idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    dFile>>tableName;
                    getline(dFile,s);
                    getline(dFile,s);
                    getline(dFile,HEADER2[i]);
                    getline(dFile,s);

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].row)
                    {
                        getline(dFile,FIELD2[idx]);
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)
                    {
                        getline(dFile,s);
                    }
                }

                dFile.close();

                remove("My_database.txt");

                ofstream aFile;
                aFile.open("My_database.txt", ios::app);

                idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    int backUpIdx=idx;
                    if(strArr[i].table_name==s3)
                    {
                        cout<<endl<<endl<<strArr[i].table_name<<endl<<endl;
                        cout<<HEADER2[i]<<endl<<endl;

                        int individualIndexTable=0;

                        while(individualIndexTable!=strArr[i].row)
                        {
                            cout<<FIELD2[idx]<<endl;
                            individualIndexTable++;
                            idx++;
                        }
                    }

                    idx=backUpIdx;

                    aFile<<strArr[i].table_name<<endl<<endl;
                    aFile<<HEADER2[i]<<endl<<endl;

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].row)
                    {
                        aFile<<FIELD2[idx]<<endl;
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)  aFile<<endl;
                }

                aFile.close();
        }
    }
    else
    {
        vector<string>col1;
        string userName,userID, tempx;
        tempx=checker;
        col1.push_back(checker);
        
        while(1)
        {
            cin >> tempx;
            if(tempx=="FROM")
                break;
            col1.push_back(tempx);
        }
        cin>>s3;


        cout<<endl<<"Enter your name : "<<endl;
        getline(cin,userName);
        getline(cin,userName);
        cout<<"Enter user ID : "<<endl;
        cin>>userID;

        recordFile<<endl<<endl<<userName<<endl;
        recordFile<<userID<<endl;

        recordFile<<endl<<"Checked from "<<s3<<endl<<endl;

        ifstream iInfo;
        iInfo.open("FileInformation.txt", ios::in);
        string s;
        iInfo >> s;
        if(s=="")
            numOfTables=0;
        else numOfTables=stoll(s);
        
        iInfo.close();

        int g=0;

        if(numOfTables==0)       
        {
            cout<<"Can't update. Create a table  first."<<endl;
        }

        else
        {
            ifstream iInfo;
            iInfo.open("FileInformation.txt", ios::in);
            iInfo>>numOfTables;

            structArr(numOfTables);
            int numOfCol;
            for(int i=0;i<numOfTables;i++)
            {
                iInfo>>strArr[i].table_name;
                iInfo>>strArr[i].row;
                iInfo>>strArr[i].column;
                if(s3==strArr[i].table_name)
                {
                    numOfCol=strArr[i].column;
                }
            }

            iInfo.close();

            remove("FileInformation.txt");

            ofstream oInfo;
            oInfo.open("FileInformation.txt", ios::app);
            oInfo<<numOfTables<<endl;;

            for(ll i=0;i<numOfTables;i++)
            {
                oInfo<<strArr[i].table_name<<" "<<strArr[i].row<<" "<<strArr[i].column<<endl;
            }

            oInfo.close();

            ll sum=0;

            for(ll i=0;i<numOfTables;i++)
            {
                sum+=strArr[i].row;
            }
                
            field_value2 (sum);

            column_name2 (numOfTables);

            string tableName,s;

            ifstream dFile;
            dFile.open("My_database.txt", ios::in);

             int idx=0;

                for(int i=0;i<numOfTables;i++)
                {
                    dFile>>tableName;
                    getline(dFile,s);
                    getline(dFile,s);
                    getline(dFile,HEADER2[i]);
                    getline(dFile,s);

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].row)
                    {
                        getline(dFile,FIELD2[idx]);
                        idx++;
                        individualIndexTable++;
                    }

                    if(i!=numOfTables-1)
                    {
                        getline(dFile,s);
                    }
                }

                dFile.close();

                remove("My_database.txt");

                ofstream aFile;
                aFile.open("My_database.txt", ios::app);

            idx=0;
            int storeNumberOfRows=0;

            for(int i=0;i<numOfTables;i++)
            {
                int backUpIdx=idx;
                if(strArr[i].table_name==s3)
                {
                    cout<<endl<<endl<<strArr[i].table_name<<endl<<endl;

                    ofstream  splitFile;
                    splitFile.open("Split.txt");

                    splitFile<<HEADER2[i]<<endl;

                    int individualIndexTable=0;

                    while(individualIndexTable!=strArr[i].row)
                    {
                        splitFile<<FIELD2[idx]<<endl;
                        individualIndexTable++;
                        idx++;
                    }

                    splitFile.close();

                    storeNumberOfRows=strArr[i].row;
                }

                idx=backUpIdx;

                aFile<<strArr[i].table_name<<endl<<endl;
                aFile<<HEADER2[i]<<endl<<endl;

                int individualIndexTable=0;

                while(individualIndexTable!=strArr[i].row)
                {
                    aFile<<FIELD2[idx]<<endl;
                    idx++;
                    individualIndexTable++;
                }

                if(i!=numOfTables-1)
                    aFile<<endl;
            }

            aFile.close();

            ifstream splitFileRead;
            splitFileRead.open("Split.txt");

            string colHeader;
            
            vector<ll>storeCol1;
            for(int i=0;i<numOfCol;i++)
            {
                splitFileRead>>colHeader;
                for(int j=0; j<col1.size();j++){
                if (col1[j] == colHeader)
                {
                    cout<<colHeader<<'\t'<<'\t'<<'\t';
                    storeCol1.push_back(i);
                }
                    
                }
                

            }

            cout<<endl;

            string colValue;
            
            for(int i=0;i<storeNumberOfRows;i++)
            {
                for(int j=0;j<numOfCol;j++)
                {
                    splitFileRead>>colValue;
                    for(int k =0; k<storeCol1.size(); k++){
                    if (storeCol1[k]==j)
                    {
                        cout<<colValue<<'\t'<<'\t'<<'\t';
                    }
                    }
                    
                }
                cout<<endl;
            }

            splitFileRead.close();
        }
     }

     recordFile.close();
     //readSelectRecordFile();
}
