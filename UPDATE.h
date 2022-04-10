#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

void updateRow()
{
     string s6,s7,s8,s9,input;
     int i1,i2;

     int index;
     int sem;
     int numOfTables;

     ifstream iInfo;
     iInfo.open("info.txt", ios::in);
     iInfo>>numOfTables;
     iInfo.close();

     int g=0;
     string s3;

     if(numOfTables==0)
     {
         cout<<"Can't update. Create a table  first."<<endl;
     }

     else
     {
        string  where,row,equ,rowToUpdate;
        cin>>s3>>where>>row>>equ>>rowToUpdate;

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

            if(strArr[i].tableName==s3)
            {
                needCol=strArr[i].numCol;
            }
           // cout<<"needcol"<< "   "<<needCol<<endl;
        }

        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        createStringArr(sum);
        if(sum==0)
        {
            createHeaderArray(2);
        }

        else
        {
            createHeaderArray(sum);
        }

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
        aFile.open("database.txt");

        idx=0;
        
        ll column;

        for(int i=0;i<numOfTables;i++)
        {
            aFile<<strArr[i].tableName<<endl<<endl;
            aFile<<header[i]<<endl<<endl;
            
            if(strArr[i].tableName==s3 && header[i]==row)
            {
                column = i;
            }

            int individualIndexTable=0;

            while(individualIndexTable!=strArr[i].numOfRows)
            {
                if(strArr[i].tableName==s3 ) stringArr[index][column]==rowToUpdate)
                {   
                    if((equ=='=' && stringArr[index][column]==rowToUpdate)||(equ=='<' && stringArr[index][column]<rowToUpdate)||(equ=='>' && stringArr[index][column]>rowToUpdate)){
                    int i1,i2;
                    string c,s7,s9;

                    cin>>c>>s7>>s9;
                    aFile<<s7<<'\t'<<'\t'<<'\t';

                    for(int y=0;y<needCol-1;y++)
                    {
                        cin>>s7>>s9;
                        aFile<<s7<<'\t'<<'\t'<<'\t';
                        //cout<<"s7"<<"  "<<s7<<endl;
                    }

                    aFile<<endl;

                    idx++;
                    individualIndexTable++;
                }}

                else
                {
                    aFile<<stringArr[idx]<<endl;
                    idx++;
                    individualIndexTable++;
                }
            }

            if(i!=numOfTables-1)  aFile<<endl;
        }

        aFile.close();
    }

    cout<<endl<<endl<<"Row updated in "<<s3<<" successfully!"<<endl<<endl;
}
