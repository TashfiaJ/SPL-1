#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

void deleteRow()
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

     if(numOfTables==0)
     {
         cout<<"Can't delete. Create a table  first."<<endl;
     }

     else
     {
        string from,where,row,equ;
        int rowToDelete;
        cin>>from>>s3>>where>>row>>equ>>rowToDelete;

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
        oInfo<<numOfTables<<endl;

        for(int i=0;i<numOfTables;i++)
        {
            if(strArr[i].tableName==s3)
            {
                oInfo<<strArr[i].tableName<<" "<<(strArr[i].numOfRows)-1<< " "<<strArr[i].numCol<<endl;
                needCol=strArr[i].numCol;
            }

            else
            {
                oInfo<<strArr[i].tableName<<" "<<strArr[i].numOfRows<<" "<<strArr[i].numCol<<endl;
            }
        }

        oInfo.close();

        int sum=0;

        for(int i=0;i<numOfTables;i++)
        {
            sum+=strArr[i].numOfRows;
        }

        sum=sum+1;

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
        aFile.open("database.txt", ios::app);

        idx=0;

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
                if(strArr[i].tableName==s3)
                {   
                    if((equ=='=' && stringArr[index][column]==rowToUpdate)||(equ=='<' && stringArr[index][column]<rowToUpdate)||(equ=='>' && stringArr[index][column]>rowToUpdate)){

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
    }

    cout<<endl<<endl<<"Row deleted from "<<s3<<" successfully!"<<endl<<endl;
}

