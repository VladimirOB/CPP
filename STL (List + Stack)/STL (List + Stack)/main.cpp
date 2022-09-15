#include "pch.h"


void Task1(const char* file_name_first, const char* file_name_second) // list-, stack-
{
    /*1. ������������ ������ 2 ����� �����, ��������� ������� �� ������� ����� ��� �����,
         ������� ����������� �� 2� �����. ������� ���� � 1� �����������.*/

    vector <string> s1;
    vector <string> s2;
    string tmp;
    fstream file_first(file_name_first, ios::in);
    fstream file_second(file_name_second, ios::in);

    if (!file_first.fail() && !file_second.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            s1.push_back(tmp);
        }
        while (!file_second.eof())
        {
            file_second >> tmp;
            s2.push_back(tmp);
        }
    }
    else
        cout << "Error opening one is files." << endl;
    file_first.close();
    file_second.close();
    file_first.open(file_name_first, ios::out);
  
    cout << "size1" << s1.size() << endl;

    for (size_t i = 0; i < s1.size(); i++)
    {
        for (size_t k = 0; k < s2.size(); k++)
        {
            if (s1[i] == s2[k])    
                s1[i].erase();
        }
    }


    if (!file_first.fail())
    {
        for (size_t i = 0; i < s1.size(); i++)
        {
            tmp = s1[i];
            file_first << tmp << " ";
        }
        cout << "Okey!" << endl;
    }
    else
        cout << "Error opening one is files." << endl;

    file_first.close();
}

void Task1v2(const char* file_name_first, const char* file_name_second) // list-, stack-
{
    /*1. ������������ ������ 2 ����� �����, ��������� ������� �� ������� ����� ��� �����,
         ������� ����������� �� 2� �����. ������� ���� � 1� �����������.*/

    list <string> l1;
    list <string> l2;
    string tmp;
    fstream file_first(file_name_first, ios::in);
    fstream file_second(file_name_second, ios::in);

    if (!file_second.fail() && !file_first.fail())
    {
        while (!file_second.eof())
        {
            file_second >> tmp;
            l2.push_back(tmp);
        }
        while (!file_first.eof())
        {
            file_first >> tmp;
            l1.push_back(tmp);
        }
    }
    else
        cout << "Error opening one is files." << endl;
    file_first.close();
    file_second.close();

   file_first.open(file_name_first, ios::out);

    // �������� ������������ ��������� STL �� ������� ������� ������ ��� ��������
    list<string>::iterator current;
    list<string>::iterator current2;

    list<string> newList;
    int flag = 0;
    // ������� ���� ��������� ������ �� ����� � ������

    for (current = l1.begin(); current != l1.end();current++)
    {
        for (current2 = l2.begin(); current2 != l2.end(); current2++)
        {
            if (*current != *current2)
            {
                flag++;
            }
        }
        if (flag == l2.size())
        {
            newList.push_back(*current2);
        }
        flag = 0;
    }

    list<string>::iterator new_current;
    if (!file_first.fail())
    {
        for (new_current = newList.begin(); new_current != newList.end(); new_current++)
        {
            tmp = *new_current;
            file_first << tmp << " ";
        }
        cout << "Okey!" << endl;
    }
    else
        cout << "Error opening one is files." << endl;

    file_first.close();
    
    
}

void Task2(const char* file_name_first, const char* file_name_second)
{
    /*2.������������ ������ ��� �����, ��������� �������� ��� ������� ����� �� �����
        � �������������� ���� � ��������� �� � ������� �����������.               */

    list <int> l1;
    int tmp;
    vector<int> v1;
    fstream file_first(file_name_first, ios::in);
    fstream file_result(file_name_second, ios::out);

    if (!file_first.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            l1.push_back(tmp);
        }
    }
    else
        cout << "Error opening one is files." << endl;
    file_first.close();

    // �������� ������������ ��������� STL �� ������� ������� ������ ��� ��������
    list<int>::iterator current;
    // ������� ���� ��������� ������ �� ����� � ������
    for (current = l1.begin(); current != l1.end(); current++)
    {
        for (size_t j = 2; j <= *current/2 ; j++)
        {
            if (*current % j == 0 && *current != j)
            {
                *current = 0;
                break;
            }
        }
        if (*current != 0)
        {
            v1.push_back(*current);
        }
        
    }
    sort(v1.begin(), v1.end());
    /*
    if (!file_first.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            l1.push_back(tmp);
        }
    }*/
    cout << "Result: " << endl;
    if (!file_result.fail())
    {
        for (size_t i = 0; i < v1.size(); i++)
        {
            tmp = v1[i];
            file_result << tmp << " ";
            cout << tmp << " ";
        }
        cout << "Okey!" << endl;
    }
    else
        cout << "Error opening one is files." << endl;

    file_result.close();
}


void Sieve()
{

     /*������� ������ �����, ������� ������� �� ���� � �� 1. ����� �� ������� � ����������� ������ ����� � ����� ���. (2.4.6.8.10.12.14.16.18.20.22..)
	 ������� ����. ������������� �����, ������� ������� �� ���� � �� 1. ��� �� ����� �� ������� � ����������� ������ ����� � ����� 3 
	 ������ (3,6,9,12,15,18,21,24,27,30..) ����� ������ �� �� ����, � �� �������� ����� �����. (x*x) �.�. ���������� ��������� ����� ��� ����������.
	 ���� ������������� ����� �������, 5 � ����������� ��� 5 (10,15,20,25,30).
	 ��� �� ��� ��� ���� ����. ������� ����� � �������� ������ ��� ������������ ����� �������. 
	 ������ 7*7=49, ��� ������ ��� 30.*/
    const int n = 100;
    bool sieve[n + 1];

    for (int i = 2; i < n + 1; i++) // 0 � 1 �� �������, ������� � 2-�
    {
        sieve[i] = true; // ��� ����� ������� ����������.
    }

    int x = 2; // ���������� �� ������� ���� ������.
    while (x * x <= n)
    {
        if (sieve[x]) // ���� x �������� �������, ��������� ���.
        {
            for (int y = x * x; y <= n; y += x) // �������� �� ���, �� �� ������ �� �������, ����������� ��� �� ���
            {
                sieve[y] = false; // ���������.
            }
        }
        x += 1;
    }

    for (int x = 2; x < n + 1; x++)
    {
        if (sieve[x])
            std::cout << x << '\t';
    }
    std::cout << '\n';
}


void Task3(const char* file_name_first, const char* file_name_second)
{
    /*3.������������ ������ ��� �����, ��������� �������� ������������ ��� �����
        �� ����� � ��������� �� � �������������� ����.*/

    vector <string> s1;
    string tmp;

    fstream file_first(file_name_first, ios::in);
    fstream file_result(file_name_second, ios::out);

    if (!file_first.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            s1.push_back(tmp);
        }
    }
    else
        cout << "Error opening one is files." << endl;

    random_device rd; // ������ 
    mt19937 g(rd()); //std::mt19937 - ��� ��������� ��������������� �����  (���� ������ rd �������� rand(), ����� �����������������)
    shuffle(s1.begin(), s1.end(), g); // ������� ����� ���������� ���� ������ ��� ������ mt19937
    //random_shuffle(s1.begin(), s1.end());
    if (!file_result.fail())
    {
        for (size_t i = 0; i < s1.size(); i++)
        {
            tmp = s1[i];
            file_result << tmp << " ";
        }
        cout << "Okey!" << endl;
    }
    else
        cout << "Error opening one is files." << endl;

    file_first.close();
    file_result.close();
}

class Rand
{
public:
    bool operator() (string a, string b)
    {
        srand(time(0));
        return a.size() < rand()% b.size();
    }
};


void Task3v2(const char* file_name_first, const char* file_name_second)
{
    /*3.������������ ������ ��� �����, ��������� �������� ������������ ��� �����
       �� ����� � ��������� �� � �������������� ����.*/

    vector <string> s1;
    string tmp;

    fstream file_first(file_name_first, ios::in);
    fstream file_result(file_name_second, ios::out);

    if (!file_first.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            s1.push_back(tmp);
        }
    }
    else
        cout << "Error opening one is files." << endl;
    srand(time(0));
    for (size_t i = 1; i < s1.size(); i++)
    {
        swap(s1[rand() % i], s1[rand() % i]);
    }


    if (!file_result.fail())
    {
        for (size_t i = 0; i < s1.size(); i++)
        {
            tmp = s1[i];
            file_result << tmp << " ";
        }
        cout << "Okey!" << endl;
    }
    else
        cout << "Error opening one is files." << endl;

    file_first.close();
    file_result.close();
}

int main(void)
{
    char task1_file_name_first[] = "DB/t.txt", task1_file_name_second[] = "DB/t2.txt";
    char task2_file_name_first[] = "DB/s.txt", task2_file_name_second[] = "DB/s2.txt";
    char task3_file_name_first[] = "DB/rand.txt", task3_file_name_second[] = "DB/rand_result2.txt";

    //Task1(task1_file_name_first, task1_file_name_second); // vector
    //Task1v2(task1_file_name_first, task1_file_name_second); // list 

    //Task2(task2_file_name_first, task2_file_name_second); // list
    //Sieve();
    
    //Task3(task3_file_name_first, task3_file_name_second); // vector (shuffle)
    //Task3v2(task3_file_name_first, task3_file_name_second); // vector
   

    //������������ ������ 2 ����� �����, ��������� ���������� ����� �� ����� ������ � ������ ��� ����������
   // char task1_file_name_first11[] = "DB/cw.txt", task1_file_name_second11[] = "DB/cw2.txt";
   // set <string> s;
   // set <string> s2;
   // string tmp;
   // fstream file_first(task1_file_name_first11, ios::in);
   // fstream file_second(task1_file_name_second11, ios::in);
   // fstream file3("DB/333.txt", ios::out);
   // if (!file_first.fail() && !file_second.fail())
   // {
   //     while (!file_first.eof())
   //     {
   //         file_first >> tmp;
   //         s.insert(tmp);
   //     }
   //     while (!file_second.eof())
   //     {
   //         file_second >> tmp;
   //         s2.insert(tmp);
   //     }
   // }
   // set <string> s3;
   // set_union(s.begin(), s.end(), s2.begin(), s2.end(),
  	//std::inserter(s3, s3.begin()));

   // set <string>::iterator p2;

   // cout << "---------" << endl;
   // // �������� ��� �������� ���������
   // if (!file3.fail())
   // {
   //     for (p2 = s3.begin(); p2 != s3.end(); p2++)
   //     {
   //         cout << *p2 << endl;
   //           file3 << *p2 << " ";
   //     }
   // }
   // file_first.close();
   // file_second.close();
   // file3.close();

    // ������������ ������ ��� �����, ��������� ��������� �� ������ ���� ������ ������������� ����� �� �������
    
     char task1_file_name_first11[] = "DB/cw_task2.txt", task1_file_name_second11[] = "DB/cw_task2_result.txt";
    multiset <string> s;
    multiset <string> s2;
    string tmp;
    fstream file_first(task1_file_name_first11, ios::in);
    fstream file_second(task1_file_name_second11, ios::out);
    if (!file_first.fail())
    {
        while (!file_first.eof())
        {
            file_first >> tmp;
            s.insert(tmp);
        }
    }
    multiset <string>::iterator p;
     
    // �������� ��� �������� ���������
    if (!file_second.fail())
    {
        for (p = s.begin(); p != s.end(); p++)
        {
            cout << *p << endl;
            if (s.count(*p) > 1)
                file_second << *p << " ";
        }
    }
    file_first.close();
    file_second.close();


}