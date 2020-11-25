// Introduction.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <map>

typedef void(*questionPtr)(void);

using namespace std;
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();
void question11();
void question12();

int main()
{
	std::map<int, questionPtr> functions;
	functions[1] = question1;
	functions[2] = question2;
	functions[3] = question3;
	functions[4] = question4;
	functions[5] = question5;
	functions[6] = question6;
	functions[7] = question7;
	functions[8] = question8;
	functions[9] = question9;
	functions[10] = question10;
	functions[11] = question11;
	functions[12] = question12;
	int choice;
	do
	{
		cout << "Please select a question to view, -1 to exit " << endl;

		cin >> choice;
		cin.ignore(1000, '\n');
		if (functions.find(choice) != functions.end())
		{
			functions[choice]();
		}
		else if (choice != -1)
		{
			cout << "Function not found" << endl;
		}

	} while (choice != -1);

	return 0;
}


void question1()
{
	string fName, lName;
	cout << "Please enter your first name: " << endl;
	getline(cin, fName);
	cout << "Please enter your second name: " << endl;
	getline(cin, lName);
	cout << lName << ", " << fName << endl;

}
void question2()
{
	int age;
	cout << "Please enter your age:" << endl;
	cin >> age;
	if (age < 0)
	{
		cout << "Invalid age" << endl;
	}
	else if (age < 18)
	{
		cout << "You are a child!" << endl;
	}
	else if (age < 65)
	{
		cout << "You are an adult!" << endl;
	}
	else
	{
		cout << "You are a senior citizen!" << endl;
	}
}
void question3()
{
	int choice;
	cout << "Please enter\n1. for Question 1" << endl;
	cout << "2. for Question 2" << endl;
	cin >> choice;
	cin.ignore(1000, '\n');
	switch (choice)
	{
	case 1:
		question1();
		break;
	case 2:
		question2();
		break;
	}

}
void question4()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << left << setw(3) << i << " * " << setw(3) << i << " = " << (i*i) << endl;
	}
}
void question5()
{
	cout << "Square (width = 5; height=5)" << endl;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\n\nRectangle (width = 5; height=10)" << endl;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\n\nTriangle (height=5)" << endl;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5 - (y+1); x++)
		{
			cout << " ";
		}
		for (int x = 0; x < (y*2)+1; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void question6()
{
	char c = CHAR_MAX;
	int i = INT_MAX;
	double d = DBL_MAX;
	cout << (int)c << endl;
	cout << i << endl;
	cout << d << endl;

}
void question7()
{
	char c = CHAR_MAX;
	int i = INT_MAX;
	double d = DBL_MAX;
	cout << sizeof(c) << endl;
	cout << sizeof(i) << endl;
	cout << sizeof(d) << endl;
}
void question8()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << "*";
		}
		cout << "\t";
		for (int x = 0; x < 10; x++)
		{
			cout << "*";
		}
		cout << "\t";
		for (int x = 0; x < 5 - (y + 1); x++)
		{
			cout << " ";
		}
		for (int x = 0; x < (y * 2) + 1; x++)
		{
			cout << "*";
		}
		cout << endl;
	}

}
void question9()
{
	int sqH=15, recH=10, triH=5;
	int max = sqH > recH ? (sqH > triH ? sqH : (recH > triH ? recH : triH)):triH;
	for (int y = 0; y < max; y++)
	{
		if (y >= (max - sqH))
		{
			for (int x = 0; x < sqH; x++)
			{
				cout << "*";
			}
		}
		else
		{
			cout << string(5, ' ');
		}
		cout << "\t";
		if (y >= (max - recH))
		{
			for (int x = 0; x < 10; x++)
			{
				cout << "*";
			}
		}
		else
		{
			cout << string(10, ' ');
		}
		cout << "\t";
		if (y >= (max - triH))
		{
			int start = max - triH;
			for (int x = 0; x < triH - ((y-start) + 1); x++)
			{
				cout << " ";
			}
			for (int x = 0; x < ((y-start) * 2) + 1; x++)
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}
void question10()
{
	string msg;
	cout << "Please enter a message to frame" << endl;
	getline(cin, msg);
	string::size_type stringLength = msg.size();
	string top(stringLength + 4, '*');
	cout << top << endl;
	cout << "* "<<msg<<" *" << endl;
	cout << top << endl;

}
void question11()
{
	string msgs[] = { "Roses are Red,","Violets are Blue,", "Sugar is sweet,", "and so are you and you and you ..." };
	string::size_type logestLength = msgs[0].size();
	for (int i = 1; i < 4; i++)
	{
		if (logestLength < msgs[i].size())
		{
			logestLength = msgs[i].size();
		}
	}
	string top(logestLength + 4, '*');
	cout << top << endl;
	for (string s : msgs)
	{
		string padd(logestLength - s.size(), ' ');
		cout << "* " << s <<padd<< " *" << endl;
	}
	cout << top << endl;
}
void question12()
{
	string msgs[] = { "Roses are Red,","Violets are Blue,", "Sugar is sweet,", "and so are you and you and you ..." };
	string::size_type logestLength = msgs[0].size();
	for (int i = 1; i < 4; i++)
	{
		if (logestLength < msgs[i].size())
		{
			logestLength = msgs[i].size();
		}
	}

	cout << "Left Aligned " << endl;
	string top(logestLength + 4, '*');
	cout << top << endl;
	for (string s : msgs)
	{
		string padd(logestLength - s.size(), ' ');
		cout << "* " << s << padd << " *" << endl;
	}
	cout << top << endl;
	cout << "\n\n";
	cout << "Right Aligned " << endl;
	cout << top << endl;
	for (string s : msgs)
	{
		string padd(logestLength - s.size(), ' ');
		cout << "* " << padd << s << " *" << endl;
	}
	cout << top  << endl;
	cout << "\n\n";
	cout << "Center Aligned " << endl;
	cout << top << endl;
	for (string s : msgs)
	{
		string::size_type diff = logestLength - s.size();
		string paddL(diff/2, ' ');
		string paddR(diff - paddL.size(), ' ');

		cout << "* " << paddL << s << paddR << " *" << endl;
	}
	cout << top << endl;
}
