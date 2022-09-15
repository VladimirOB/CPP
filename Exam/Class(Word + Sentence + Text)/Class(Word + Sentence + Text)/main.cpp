#include "pch.h"
#include "Word.h"
#include "Sentence.h"
#include "Text.h"

void Task1()
{
	cout << "Task #1." << endl;
	Word word(".!?hello.!? world");
	Word word3(".!?qwerty alo.!? world");
	Word word2 = word;
	word2 = word3;
	word2.Print();
	cout << word2.Length() << endl;
	cout << word.get() << endl;
	word[0] = 'a';
	word.Print();
	for (size_t i = 0; i < 39; i++)
	cout << "-";
	cout << endl;
}

void Task2()
{
	cout << "Task #2." << endl;
	Sentence sentence("My windows	is very   close!	 ");
	Sentence sentence2 = sentence;
	Sentence sentence3;
	sentence3 = sentence2;
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.set("			Vitya   looks  like an old beach	");
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.Add("river");
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.Remove(0);
	sentence3.Print();
	sentence3 += "water";
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3[0] = "here";
	sentence3.Print();
	for (size_t i = 0; i < 39; i++)
	cout << "-";
	cout << endl;
}

void Task3()
{
	Text text("hello people! hello how are you? How me? Fine.");

	text.saveWords("2.txt");

	/*Text text2 = text;
	cout << text2 << endl;
	cout << "Length = " << text2.Length() << endl;
	text.set("Let's go? Okey go Jimmy! I wait you.  ");
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Add("Water is very cold? Yes yes..");
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Remove(0);
	text += "Ho ho ho.";
	text[0] = "Ha ha ha";
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Save("result.txt");*/
}

int main(void)
{
	//Task1();
	//Task2();
	//Task3();

}