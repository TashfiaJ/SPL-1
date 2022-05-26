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

vector < string > conditions;
vector < string > cond_column;
vector < ll > cond_column_no;
vector < string > condval_column;
vector < string > condsign_column;
vector < string > mulcondval;
vector < string >col1; //select column
vector < string > split_table_column; //target table column name
string s3; //table name
	
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

vector < string > parser(string s)
{
	int i=0;
	string a;
	vector < string > parse;
	while(s[i]!='\0')
	{
		if(s[i]==' ' || s[i]==',' || s[i]=='('  ||s[i]==';')
		{
			if(s[i]=='(')
			{
				i++;
				if(a!="" && a!=" ")
					parse.push_back(a);
				a="";
				while(s[i]!=')')
				{
					a+=s[i];
					i++;
				}				
				if(a!="" && a!=" ")
					parse.push_back(a);
				a="";
			}
			else if(s[i]==',' || s[i]==' ')
			{
				if(a!="" && a!=" ")
					parse.push_back(a);
				a="";
			}
		}	
		else
		{
			a+=s[i];
			cout << a;
		}

		i++;
	}
	if(a!="")
		parse.push_back(a);
	
	return parse;
}

void parse(vector <string> list)
{
		ll i=0;
		//if(list[0]!="Select")
		//	return 0;
		i=1;
		
		while(list[i]!="FROM")
		{
			col1.push_back(list[i]);
			i++;
		}
		i++;
		if(i<list.size())
		{
			while(list[i]!="WHERE")
			{
				s3 = list[i];
				i++;
				if(i==list.size())
						break;
			}	
		}
		
		i++;
		if(i<list.size())
		{
			while(i<list.size())
			{
				if(list[i]=="AND" || list[i]=="and") mulcondval.push_back("AND");
				else if(list[i]=="OR" || list[i]=="or" ) mulcondval.push_back("OR");
				else
				{
					conditions.push_back(list[i]);
				}
				i++;
			}	
		}
		//return 1;
}

vector < string > parse_con(string s)
{
	int i=0;
	string a="";
	vector<string > v;
	while(s[i]!='\0')
	{
		if(s[i]=='=' || s[i]=='<' || s[i]=='>' )
		{
				v.push_back(a);
				a="";
				while(s[i]=='=' || s[i]=='<' || s[i]=='>')
				{
					a+=s[i];
					i++;
				}
				v.push_back(a);
				a="";	
		}
		else
		{
			a+=s[i];
			i++;
		}	
	}
	v.push_back(a);
	return v;
}

string rem(string a)
{
	int i=0;
	string tab="";
	while(a[i]!='\0')
	{
		tab+=a[i];
		if(a[i]=='.')tab="";
		i++;
	}
	return tab;
}

vector<string> parse_line(string s)
{
	std::vector<string> v;
	string a;
	int i=0;
	while(s[i]!='\0')
	{	
		if(s[i]==' ')
		{   
		    if(a!="" && a!=" ")
			v.push_back(a);
			a="";
		}
		else
		{
			a+=s[i];
		}	
		i++;		
	}
	if(a!="")
		v.push_back(a);	
	return v;
}

ll ston(string s)
{
	ll i=0,flag=1;
	ll sum=0;
	if(s[i]=='-')
	{
		flag=-1;
		i++;		
	}
	sum=0;
	while(s[i]!='\0')
	{
		sum*=10;
		sum+=s[i]-48;
		i++;
	}
	return sum*flag;
}
bool eval(string s1,string s2,string sign)
{
	int val1,val2;
	int flag=0;
		val1=ston(s1);
		val2=ston(s2);
		if(sign==">")
		{
			if(val1>val2)flag++;			
		}	
		else if(sign=="<")
		{
			if(val1<val2)flag++;			
		}
		else if(sign==">=")
		{
			if(val1>=val2)flag++;			
		}
		else if(sign=="<=")
		{
			if(val1<=val2)flag++;			
		}
		else if(sign=="=")
		{
			if(val1==val2)flag++;			
		}
	return flag;
}

void extract_condition()
{
	int i=0,k=0;
	std::vector<string> v;	
	while(i<conditions.size())
	{
		v=parse_con(conditions[i]);
		//printlist(v);	
		cond_column.push_back(v[0]);
		condsign_column.push_back(v[1]);
		condval_column.push_back(v[2]);

				k=0;
				while(k<split_table_column.size())
				{
					if(split_table_column[k]==rem(v[0]))
						cond_column_no.push_back(k);
					k++;		
				}
		
		i++;
	}
	
}

bool execute_condition ( vector < string > v1 )
{
	int i=0,temp_flag,flag_con;
	string val1 , val2, sign ;
	
	val1=v1[cond_column_no[0]];
	val2=condval_column[0];
	sign=condsign_column[0];
	
	flag_con=eval(val1,val2,sign);		
	//cout<<"flag="<<flag_con<<" "<<val1<<" "<<sign<<" "<<val2<<endl;
	i=1;
	while(i<cond_column.size())
	{
		
		val1=v1[cond_column_no[i]];
		
		val2=condval_column[i];
		sign=condsign_column[i];

		temp_flag=eval(val1,val2,sign);
		if(mulcondval[i-1]=="AND")
			flag_con=flag_con&temp_flag;
		else if(mulcondval[i-1]=="OR")
			flag_con=flag_con|temp_flag;
		i++;
	//	cout<<"flag="<<flag_con<<" "<<val1<<" "<<sign<<" "<<val2<<endl;
	} 
	if(flag_con==1)
		return true;
	else if(flag_con==0)
		return false;
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
        /*vector<string>col1;
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
        cin>>s3;*/
        //input
        string input;
        getline(cin, input);
        parse(parser(input));
        string userName,userID;
        cout<<endl<<"Enter your name : "<<endl;
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
                split_table_column.push_back(colHeader);
                for(int j=0; j<col1.size();j++){
                if (col1[j] == colHeader)
                {
                    cout<<colHeader<<'\t'<<'\t'<<'\t';
                    storeCol1.push_back(i);
                }
                    
                }
                

            }
            
            cout<<endl;
            
            extract_condition();
            
            string colValue, tempRec;
            vector<string> v1;
            bool display;
            for(ll i=0; i< storeNumberOfRows; i++)
            {   v1.clear();
                for(int k=0;k<numOfCol;k++)
                {
                    splitFileRead>>colValue;
                    v1.push_back(colValue);}
             
                if(conditions.size()>0)
					{
						display=execute_condition(v1);
						if(display)
						{
						    for(ll j=0;j<storeCol1.size();j++)
						        cout << v1[storeCol1[j]]<<'\t'<<'\t'<<'\t';
						    cout<<endl;
						}
					}
            }
            
            /*for(int i=0;i<storeNumberOfRows;i++)
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
            }*/

            splitFileRead.close();
        }
     }

     recordFile.close();
     //readSelectRecordFile();
}
