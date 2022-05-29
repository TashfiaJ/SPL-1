#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define ll long long

ll needCol;
ll needRow;
vector < string > updates;
vector < pair < ll, string > > updatesValue;
vector < string > split_table_column1;
vector < string > target_table_row[100];
vector < string > conditions1;
vector < string > cond_column1;
vector < ll > cond_column_no1;
vector < string > condval_column1;
vector < string > condsign_column1;
vector < string > mulcondval1;

struct Array2
{
    string tableName;
    int numOfRows;
    int numCol;
};

Array2 *strArr2;
string *stringArr2;
string *header2;

void structArr2(int n)
{
    strArr2 = new Array2[n];
}


void createStringArr2(int p)
{
    stringArr2 = new string [p];
}

void createHeaderArray2(int p)
{
    header2=new string[p];
}

/*UPDATE Customers
SET ContactName=Alfred , City=Frankfurt
WHERE CustomerID = 1; */

vector < string > parser1(string s)
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

void parse1(vector <string> listt)
{
		ll i=1;
		if(i<listt.size())
		{
			while(listt[i]!="WHERE")
			{
				updates.push_back(listt[i]);
				i++;
				if(i==listt.size())
						break;
			}
		}
		i++;
		if(i<listt.size())
		{
			while(i<listt.size())
			{
				if(listt[i]=="AND" || listt[i]=="and") mulcondval1.push_back("AND");
				else if(listt[i]=="OR" || listt[i]=="or" ) mulcondval1.push_back("OR");
				else
				{
					conditions1.push_back(listt[i]);
				}
				i++;
			}
		}

}

vector < string > parse_con1(string s)
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

string rem1(string a)
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

vector<string> parse_line1(string s)
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

ll ston1(string s)
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

bool eval1(string s1,string s2,string sign)
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

void extract_condition1()
{
	int i=0,k=0;
	std::vector<string> v;
	while(i<conditions1.size())
	{
		v=parse_con1(conditions1[i]);
		//printlist(v);
		cond_column1.push_back(v[0]);
		condsign_column1.push_back(v[1]);
		condval_column1.push_back(v[2]);

				k=0;
				while(k<split_table_column1.size())
				{
					if(split_table_column1[k]==rem1(v[0]))
						cond_column_no1.push_back(k);
					k++;
				}

		i++;
	}

}

void extract_column()
{
	int i=0,k=0;
	std::vector<string> v;
	string column_name, sign, column_value;
	while(i<updates.size())
	{
		v=parse_con1(updates[i]);
		column_name=v[0];
		sign=v[1];
		column_value=v[2];

				k=0;
				while(k<split_table_column1.size())
				{
					if(split_table_column1[k]==v[0])
						updatesValue.push_back({k, column_value});
					k++;
				}

		i++;
	}

}

bool execute_condition1 ( vector < string > v1 )
{
    int i=0,temp_flag,flag_con;
	string val1 , val2, sign ;
	val1=v1[cond_column_no1[0]];
	val2=condval_column1[0];
	sign=condsign_column1[0];

	flag_con=eval1(val1,val2,sign);
	i=1;
	while(i<cond_column1.size())
	{
		val1=v1[cond_column_no1[i]];
		val2=condval_column1[i];
		sign=condsign_column1[i];

		temp_flag=eval(val1,val2,sign);

		if(mulcondval1[i-1]=="AND")
			flag_con=flag_con&temp_flag;
		else if(mulcondval[i-1]=="OR")
			flag_con=flag_con|temp_flag;
		i++;
	}
	if(flag_con==1)
		return true;
	else if(flag_con==0)
		return false;
}

void update()
{
     int index;
     int sem;

     string tablee;
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
         cout<<"Can't update. Create a table  first."<<endl;
     }

     else
     {

        cin >> table_name;
        string input;
        getline(cin, input);
        parse1(parser1(input));
        //string  where,row,equ;
        //int rowToUpdate;
        //cin>>s3>>where>>row>>equ>>rowToUpdate;

        ifstream iInfo;
        iInfo.open("FileInformation.txt", ios::in);
        iInfo>>total_table;

        structArr2(total_table);

        for(int i=0;i<total_table;i++)
        {
            iInfo>>strArr2[i].tableName;
            iInfo>>strArr2[i].numOfRows;
            iInfo>>strArr2[i].numCol;
        }

        iInfo.close();

        remove("FileInformation.txt");

        ofstream oInfo;
        oInfo.open("FileInformation.txt", ios::app);
        oInfo<<total_table<<endl;;
        for(int i=0;i<total_table;i++)
        {
            oInfo<<strArr2[i].tableName<<" "<<strArr2[i].numOfRows<<" "<<strArr2[i].numCol<<endl;

            if(strArr2[i].tableName==table_name)
            {
                needCol=strArr2[i].numCol;
                needRow=strArr2[i].numOfRows;
            }
           // cout<<"needcol"<< "   "<<needCol<<endl;
        }

        oInfo.close();

        ll sum=0;

        for(int i=0;i<total_table;i++)
        {
            sum+=strArr2[i].numOfRows;
        }

        createStringArr2(sum);
        createHeaderArray2(total_table);


        string tableName,s;
        ifstream dFile;
        dFile.open("My_database.txt", ios::in);

        ll idx=0;
        for(int i=0;i<total_table;i++)
        {
            dFile>>tableName;
            getline(dFile,s);
            getline(dFile,s);
            getline(dFile,header2[i]);
            getline(dFile,s);
            if(tableName==table_name)
            {
                string a="";
                ll j=0;
                while(header2[i][j]!='\0')
                {
                   if(header2[i][j]=='\t')
                   {
                       if(a!="")
                        split_table_column1.push_back(a);
                       a="";
                   }
                   else
                   {
                       a+=header2[i][j];
                   }
                   j++;
                }
                if(a!="")
                    split_table_column1.push_back(a);
            }
            int individualIndexTable=0;
            while(individualIndexTable!=strArr2[i].numOfRows)
            {
                getline(dFile,stringArr2[idx]);
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


        extract_condition1();


        ofstream aFile;
        aFile.open("My_database.txt", ios::app);

        idx=0;
        vector < string > v1;
        //cout << stringArr2[0];
        bool display;
        for(int i=0;i<total_table;i++)
        {
            aFile<<strArr2[i].tableName<<endl<<endl;
            aFile<<header2[i]<<endl<<endl;

            int individualIndexTable=0;

            if(strArr2[i].tableName==table_name)
            {

                    for(int x=0;x<needRow;x++)
                    {
                        v1.clear();
                        string a="";
                        ll j=0;
                        while(stringArr2[idx][j]!='\0')
                        {
                            if(stringArr2[idx][j]=='\t'){
                                if(a!="")v1.push_back(a);
                            a="";}
                            else{
                                a+=stringArr2[idx][j];
                            }
                            j++;
                        }
                        if(a!="")v1.push_back(a);

                        if(conditions1.size()>0)
                            {
                                display = execute_condition1(v1);
                                //cout << display << endl;
                                if(!display)
                                    aFile<<stringArr2[idx]<<endl;
                                else{
                                    for(int y=0; y< needCol; y++)
                                    {
                                        aFile<<updates[y]<<'\t'<<'\t'<<'\t';
                                    }
                                    aFile<<endl;
                                }

                            }
                        idx++;
                        //cout<<"s7"<<"  "<<s7<<endl;
                    }


                }

            else
            {
            while(individualIndexTable!=strArr2[i].numOfRows)
            {
                aFile<<stringArr2[idx]<<endl;
                idx++;
                individualIndexTable++;
            }
            }

            if(i!=total_table-1)  aFile<<endl;
        }

        aFile.close();
    }

    cout<<endl<<endl<<"Row updated in "<<table_name<<" successfully!"<<endl<<endl;
}
