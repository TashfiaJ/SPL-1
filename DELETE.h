#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

ll needCol4;
ll needRow4;
ll deletee=0;

vector < string > split_table_column4;
vector < string > conditions4;
vector < string > cond_column4;
vector < ll > cond_column_no4;
vector < string > condval_column4;
vector < string > condsign_column4;
vector < string > mulcondval4;

struct Array4
{
    string tableName;
    int numOfRows;
    int numCol;
};

Array4 *strArr4;
string *stringArr4;
string *header4;

void structArr4(int n)
{
    strArr4 = new Array4[n];
}


void createStringArr4(int p)
{
    stringArr4 = new string [p];
}

void createHeaderArray4(int p)
{
    header4=new string[p];
}
vector < string > parser4(string s)
{
	int i=0;
	string a;
	vector < string > parse;
	while(s[i]!='\0')
	{
		if(s[i]==' ' || s[i]==',' || s[i]=='('  ||s[i]==';')
		{
			if(s[i]=='(' || s[i]==')')
			{
				i++;
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
		}

		i++;
	}
	if(a!="")
		parse.push_back(a);
	return parse;
}

void parse4(vector <string> listt)
{
		ll i=1;
		
		if(i<listt.size())
		{
			while(i<listt.size())
			{
				if(listt[i]=="AND" || listt[i]=="and") mulcondval4.push_back("AND");
				else if(listt[i]=="OR" || listt[i]=="or" ) mulcondval4.push_back("OR");
				else
				{
					conditions4.push_back(listt[i]);
				}
				i++;
			}
		}

}

vector < string > parse_con4(string s)
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

string rem4(string a)
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

vector<string> parse_line4(string s)
{
	std::vector<string> v;
	string a;
	int i=0;

	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
		    if(a!="" && a!=" "){
			v.push_back(a);
			//cout << a << endl;
			}
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

ll ston4(string s)
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

bool eval4(string s1,string s2,string sign)
{
        int val1,val2,flag=0;
		val1=ston1(s1);
		val2=ston1(s2);
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

void extract_condition4()
{
	int i=0,k=0;
	std::vector<string> v;
	while(i<conditions4.size())
	{
		v=parse_con4(conditions4[i]);
		//printlist(v);
		cond_column4.push_back(v[0]);
		condsign_column4.push_back(v[1]);
		condval_column4.push_back(v[2]);

				k=0;
				while(k<split_table_column4.size())
				{
					if(split_table_column4[k]==rem4(v[0]))
						cond_column_no4.push_back(k);
					k++;
				}

		i++;
	}

}


bool execute_condition4 ( vector < string > v1 )
{
    int i=0,temp_flag,flag_con;
	string val1 , val2, sign ;
	val1=v1[cond_column_no4[0]];
	val2=condval_column4[0];
	sign=condsign_column4[0];

	flag_con=eval1(val1,val2,sign);
	i=1;
	while(i<cond_column4.size())
	{
		val1=v1[cond_column_no4[i]];
		val2=condval_column4[i];
		sign=condsign_column4[i];

		temp_flag=eval4(val1,val2,sign);

		if(mulcondval4[i-1]=="AND")
			flag_con=flag_con&temp_flag;
		else if(mulcondval4[i-1]=="OR")
			flag_con=flag_con|temp_flag;
		i++;
	}
	if(flag_con==1)
		return true;
	else if(flag_con==0)
		return false;
}

void delete_row()
{
    int index;
     int sem;

     string tablee, from;
     string table_name;
     ifstream iInfo;
     iInfo.open("FileInformation.txt", ios::in);
     ll total_table;
     iInfo >> tablee;
     if(tablee=="")
        total_table=0;
     else
        total_table=stoll(tablee);

     iInfo.close();

     int g=0;
     string s3;

     if(total_table==0)
     {
         cout<<"Can't delete. Create a table  first."<<endl;
     }

     else
     {

        cin >> from >> table_name;
        string input;
        getline(cin, input);
        parse4(parser4(input));

        ifstream iInfo;
        iInfo.open("FileInformation.txt", ios::in);
        iInfo>>total_table;

        structArr4(total_table);

        for(int i=0;i<total_table;i++)
        {
            iInfo>>strArr4[i].tableName;
            iInfo>>strArr4[i].numOfRows;
            iInfo>>strArr4[i].numCol;
        }

        iInfo.close();

        remove("FileInformation.txt");

        ofstream oInfo;
        oInfo.open("FileInformation.txt", ios::app);
        oInfo<<total_table<<endl;;
        for(int i=0;i<total_table;i++)
        {
            oInfo<<strArr4[i].tableName<<" "<<strArr4[i].numOfRows<<" "<<strArr4[i].numCol<<endl;

            if(strArr4[i].tableName==table_name)
            {
                needCol4=strArr4[i].numCol;
                needRow4=strArr4[i].numOfRows;
            }
           // cout<<"needcol"<< "   "<<needCol<<endl;
        }

        oInfo.close();
        ll sum=0;

        for(int i=0;i<total_table;i++)
        {
            sum+=strArr4[i].numOfRows;
        }

        createStringArr4(sum);
        createHeaderArray4(total_table);


        string tableName,s;
        ifstream dFile;
        dFile.open("My_database.txt", ios::in);

        ll idx=0;
        for(int i=0;i<total_table;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header4[i]);
            getline(dFile,s);
            if(tableName==table_name)
            {
                string a="";
                ll j=0;
                while(header4[i][j]!='\0')
                {
                   if(header4[i][j]=='\t')
                   {
                       if(a!="")
                        split_table_column4.push_back(a);
                       a="";
                   }
                   else
                   {
                       a+=header4[i][j];
                   }
                   j++;
                }
                if(a!="")
                    split_table_column4.push_back(a);
            }
            int individualIndexTable=0;
            while(individualIndexTable!=strArr4[i].numOfRows)
            {
                getline(dFile,stringArr4[idx]);
                idx++;
                individualIndexTable++;
            }

            if(i!=total_table-1)
            {
                getline(dFile,s);
            }
        }

        dFile.close();
        remove("My_database.txt");

        
        extract_condition4();
        
        ofstream aFile;
        aFile.open("My_database.txt", ios::app);

        idx=0;
        vector < string > v1;
        //cout << stringArr2[0];
        bool display;
        for(int i=0;i<total_table;i++)
        {
            aFile<<strArr4[i].tableName<<endl<<endl;
            aFile<<header4[i]<<endl<<endl;

            int individualIndexTable=0;

            if(strArr4[i].tableName==table_name)
            {

                    for(int x=0;x<needRow4;x++)
                    {
                        v1.clear();
                        string a="";
                        ll j=0;
                        while(stringArr4[idx][j]!='\0')
                        {
                            if(stringArr4[idx][j]=='\t'){
                                if(a!="")v1.push_back(a);
                            a="";}
                            else{
                                a+=stringArr4[idx][j];
                            }
                            j++;
                        }
                        if(a!="")v1.push_back(a);

                        if(conditions4.size()>0)
                            {
                                display = execute_condition4(v1);
                                //cout << display << endl;
                                if(!display)
                                    aFile<<stringArr2[idx]<<endl;
                                else{
                                    
                                    deletee++;
                                }

                            }
                        idx++;
                        //cout<<"s7"<<"  "<<s7<<endl;
                    }


                }

            else
            {
            while(individualIndexTable!=strArr4[i].numOfRows)
            {
                aFile<<stringArr4[idx]<<endl;
                idx++;
                individualIndexTable++;
            }
            }

            if(i!=total_table-1)  aFile<<endl;
        }

        aFile.close();
    }

    cout<<endl<<endl<<"Row deleted in "<<table_name<<" successfully!"<<endl<<endl;
}
