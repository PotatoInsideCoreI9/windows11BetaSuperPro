#include <iostream>
#include <ctime>
#include<random>
#include <fstream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//string GetStando(int N1)
//{
//    ifstream source("Database.txt", ofstream::app);
//    ifstream source2("Names2.txt", ofstream::app);
//    vector<string> names1, names2;
//    if (!source.is_open())
//    {
//        cout << "error" << endl;
//        return "error";
//    }
//    while (!source.eof())
//    {
//        string buff;
//        getline(source, buff);
//        names1.push_back(buff);
//    }
//    if (!source2.is_open())
//    {
//        cout << "error" << endl;
//        return "error";
//    }
//    while (!source2.eof())
//    {
//        string buff;
//        getline(source2, buff);
//        names2.push_back(buff);
//    }
//    string fullname = names1[N1] + names2[rand() % names2.size()];
//    source.close();
//    source2.close();
//    return fullname;
//}
//
//void main()
//{
//    cout << GetStando(0) << endl;
//}

//class part
//{
//	vector<int> human;
//	vector<int> machine;
//	int WinConf = 0, WinConfHuman = 0;
//	
//public:
//
//	part()
//	{
//		
//		for (int i = 0; i < 2; i++)
//		{
//			int buf = rand() % 7;
//			cout << "human: " << buf << endl;
//			human.push_back(buf);
//			buf = rand() % 7;
//			cout << "machine: " << buf << endl;
//			machine.push_back(buf);
//		}
//	}
//	bool Playpart()
//	{
//		for (int i = 0; i < 2; i++)
//		{
//			WinConf += machine[i];
//			WinConfHuman += human[i];
//		}
//		cout << "machine sum: " << WinConf << endl;
//		cout << "human sum: " << WinConfHuman << endl;
//		if (WinConf > WinConfHuman)
//			return 1;
//		else if (WinConfHuman > WinConf)
//			return 0;
//	}
//	vector<int> GetHuman()
//	{
//		return human;
//	}
//	vector<int> GetMachine()
//	{
//		return machine;
//	}
//};

class Field
{
protected:
	vector<vector<int>> field;
	vector<vector<int>> Mycoordinats;
	bool previosIsFill(int pos, int pos1)
	{
		if (pos != 0 && pos1 != 0)
		{
			if (field[pos - 1][pos1 - 1] == 1)
			{
				//cout << "yeah" << endl;
				return 1;
			}
			else
				return 0;
		}
		return 0;
	}

	vector<vector <int>>getfield()
	{
		return field;
	}

public:
	Field()
	{
		for (int i = 0; i < 3; i++)
			field.push_back({0,0,0});
	}

	void setX(int pos,int pos1)
	{
		field[pos][pos1] = 1;
	}

	void setO(int pos, int pos1)
	{
		field[pos][pos1] = 2;
	}

	bool check()
	{
		int count = 0;
		
			for (int j = 0; j < 3; j++)
			{
				if (field[0][j] == 1 || field[0][j]==2)
					count++;			
			}
			if (count == 3)
			{
				cout << "yes combo" << endl;
				return 1;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (field[1][j] == 1 || field[1][j] == 2)
					count++;
			}
			if (count == 3)
			{
				cout << "yes combo" << endl;
				return 1;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (field[2][j] == 1 || field[2][j] == 2)
					count++;
			}
			if (count == 3)
			{
				cout << "yes combo" << endl;
				return 1;
			}
		count = 0;
		for (int i = 0; i < field.size(); i++)
			if (field[i][0] == 1 || field[i][0] == 2)
				count++;
		if (count == 3)
		{
			cout << "yes combo" << endl;
			return 1;
		}
		count = 0;
		for (int i = 0; i < field.size(); i++)
			if (field[i][1] == 1 || field[i][1] == 2)
				count++;
		if (count == 3)
		{
			cout << "yes combo" << endl;
			return 1;
		}
		count = 0;
		for (int i = 0; i < field.size(); i++)
			if (field[i][2] == 1 || field[i][2] == 2)
				count++;
		if (count == 3)
		{
			cout << "yes combo" << endl;
			return 1;
		}
		count=0;
		int j = 0;
		bool first = 0;
		for (int i = 0; i < 3; i++)
		{
			if (first)
			{
				if (field[i][j] == 1 && field[i][j++] == 1 || field[i][j] == 2 && field[i][j++] == 2)
					count++;
			}
			else if (field[i][0]==1 && !first || field[i][0] == 2 && !first)
			{
				count++;
				first = true;
				j++;
			}
		}
		if (count == 3)
		{
			cout << "yes combo" << endl;
			return 1;
		}
		count = 0;
		j = 2;
		first = 0;
		for (int i = 0; i < 3; i++)
		{
			if (first)
			{
				if (field[i][j] == 1 && field[i][j--] == 1 || field[i][j] == 2 && field[i][j--] == 2)
					count++;
			}
			else if (field[i][2]==1 && !first || field[i][2] == 2 && !first)
			{
				count++;
				first = true;
				j--;
			}
		}
		if (count == 3)
		{
			cout << "yes combo" << endl;
			return 1;
		}
		return 0;
	}


	void move()
	{
		srand(time(NULL));
		if (Mycoordinats.empty())
		{
			cout << "emp" << endl;
			int rand0 = rand() % 3, rand1 = rand() % 3;
			while (field[rand0][rand1] == 1)
				rand0 = rand() % 3, rand1 = rand() % 3;
			setO(rand0, rand1);
			Mycoordinats.push_back({ rand1,rand0 });
		}
		else
		{
			
			int rand0 = rand() % 3, rand1 = rand() % 3;
			while (field[rand0][rand1] == 1)
				rand0 = rand() % 3, rand1 = rand() % 3;
			setO(rand0, rand1);
			Mycoordinats.push_back({ rand1,rand0 });
			/*cout << "fill" << endl;
			int coord=Mycoordinats[Mycoordinats.size() - 1][0];
			int coord1 = Mycoordinats[Mycoordinats.size() - 1][1];
			cout << "coord: " << coord << " " << coord1 << endl;
			if (coord  !=2 && coord1!=2)
			{
				if (field[coord+1][coord1+1] != 1)
				{
					setO(coord++, coord++);
					Mycoordinats.push_back({ coord++, coord1++ });
				}
			}*/
		}
	}

	void showCoordinats()
	{

		for (int i = 0; i < Mycoordinats.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << Mycoordinats[i][j] << ",";
			}
			cout << endl;
		}
	}

	void show()
	{
		for (int i = 0; i < field.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << field[i][j];
			}
			cout << endl;
		}
	}
};



class beautiful
{
	vector <vector<string>> field;
public:
	beautiful()
	{
		for (int i = 0; i < 3; i++)
		{
			field.push_back({"∎","∎","∎"});
		}
	}

	void show()
	{
		for (int i = 0; i < field.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << field[i][j] << endl;
			}
		}
	}
};

void main()
{
cout << "hello " << endl;
	Field a;
	bool IsEnd = 0;
	int pos, pos1;
	while (!IsEnd)
	{
		cin >> pos;
		cin >> pos1;
		a.setX(pos, pos1);
		a.show();
		a.move();
		IsEnd=a.check();
	}
	/*bool isEnd = 0;
	int P1 = 0; 
	int pos, pos1;
	while (!isEnd)
	{
		if (P1 % 2)
			cout << "player 1" << endl;
		else if (!P1 % 2)
			cout << "player 2" << endl;
		cin >> pos;
		cin >> pos1;
		if (P1 % 2)
			a.setX(pos, pos1);
		else if (!P1 % 2)
			a.setO(pos, pos1);
		a.show();
		isEnd=a.check();
		P1++;
	}*/
}
