#include "pch.h"


void Task1(const char* file_name_first, const char* file_name_second) // list-, stack-
{
    /*1. Пользователь вводит 2 имени файла, программа удаляет из первого файла все слова,
         которые встречаются во 2м файле. Порядок слов в 1м сохраняется.*/

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
    /*1. Пользователь вводит 2 имени файла, программа удаляет из первого файла все слова,
         которые встречаются во 2м файле. Порядок слов в 1м сохраняется.*/

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

    // создание специального указателя STL на текущий элемент списка для простора
    list<string>::iterator current;
    list<string>::iterator current2;

    list<string> newList;
    int flag = 0;
    // перебор всех элементов списка от конца в начало

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
    /*2.Пользователь вводит имя файла, программа копирует все простые числа из файла
        в результирующий файл и сортирует их в порядке возрастания.               */

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

    // создание специального указателя STL на текущий элемент списка для простора
    list<int>::iterator current;
    // перебор всех элементов списка от конца в начало
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

     /*находим первое число, которое делится на себя и на 1. бежим по массиву и зачёркиваем каждое число с шагом два. (2.4.6.8.10.12.14.16.18.20.22..)
	 находим след. незачёркнутое число, которое делится на себя и на 1. так же бежим по массиву и зачёркиваем каждое число с шагом 3 
	 тоесть (3,6,9,12,15,18,21,24,27,30..) можно начать не от него, а от квадрата этого числа. (x*x) т.к. предыдущие составные числа уже зачёркнуты.
	 след незачёркнутое число простое, 5 и зачёркиваем шаг 5 (10,15,20,25,30).
	 идём до тех пор пока след. простое число в квадрате меньше чем максимальное число массива. 
	 тоесть 7*7=49, это больше чем 30.*/
    const int n = 100;
    bool sieve[n + 1];

    for (int i = 2; i < n + 1; i++) // 0 и 1 не простые, поэтому с 2-х
    {
        sieve[i] = true; // все числа простые изначально.
    }

    int x = 2; // переменная по которой буду бежать.
    while (x * x <= n)
    {
        if (sieve[x]) // если x является простым, оставляем его.
        {
            for (int y = x * x; y <= n; y += x) // начинаем от Хкв, до не выходя за границы, увеличиваем вай на икс
            {
                sieve[y] = false; // составное.
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
    /*3.Пользователь вводит имя файла, программа хаотично перемешивает все слова
        из файла и сохраняет их в результирующий файл.*/

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

    random_device rd; // рандом 
    mt19937 g(rd()); //std::mt19937 - это генератор псевдослучайных чисел  (если вместо rd написать rand(), будет псевдослучайность)
    shuffle(s1.begin(), s1.end(), g); // функция Шаффл перемешала весь массив при помощи mt19937
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
    /*3.Пользователь вводит имя файла, программа хаотично перемешивает все слова
       из файла и сохраняет их в результирующий файл.*/

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
   

    //Пользователь вводит 2 имени файла, программа объединяет слова из обоих файлов в третий без повторений
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
   // // получить все элементы множества
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

    // Пользователь вводит имя файла, программа сохраняет во второй файл только повторяющиеся слова из первого
    
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
     
    // получить все элементы множества
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