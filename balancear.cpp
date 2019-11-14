#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool comparar(char a,char b)
{
	if(a == '(' && b== ')')
        return true;
	else if(a == '{' && b == '}')
        return true;
	else if(a == '[' && b == ']')
        return true;
    else if(a == '/' && b == '/')
        return true;
	return false;
}

bool balancear(string txt)
{
	stack<char>  A;
	for(int i =0;i<txt.length();i++)
	{
		if(txt[i] == '(' || txt[i] == '{' || txt[i] == '[')
			A.push(txt[i]);
		else if(txt[i] == ')' || txt[i] == '}' || txt[i] == ']')
		{
			if(A.empty() || !comparar(A.top(),txt[i]))
				return false;
			else
				A.pop();
		}
	}
}



int main()
{

	string txt;
	cin>>txt;
	if(balancear(txt)==true)
		cout<<"si cumple";
	else
	{
		cout<<"no cumple";
	}
	
    return 0;
}
