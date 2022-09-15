#include "pch.h"
#include "Word.h"
#include "Sentence.h"
#include "Text.h"


int main(void)
{
	cout << "Task #1." << endl;
	Word word(".!?hello.!? world");
	Word word3(".!?qwerty alo.!? world");
	Word word2 = word;
	word2 = word3;
	word2.Print();
	cout << word2.Length() << endl;
	cout << word.Get() << endl;
	word[0] = 'a';
	word.Print();
	for (size_t i = 0; i < 39; i++)
		cout << "-";
	cout << endl;


	cout << "Task #2." << endl;
	Sentence sentence("My windows	is very   close!	 ");
	Sentence sentence2 = sentence;
	Sentence sentence3;
	sentence3 = sentence2 = sentence;
	sentence3.Print();
	cout << "Get(3): " << sentence3.Get() << endl;
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.Set("			Vitya   looks  like an old beach	");
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.Add(word);
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3.Remove(0);
	sentence3.Print();
	sentence3 += word2;
	sentence3.Print();
	cout << "Length = " << sentence3.Length() << endl;
	sentence3[0] = "here";
	sentence3.Print();
	Sentence sentence4 = sentence3.Get();
	sentence4.Print();
	for (size_t i = 0; i < 39; i++)
		cout << "-";
	cout << endl;


	cout << "Task #3." << endl;
	Text text("hello people! hello how are you? How me? Fine.");
	cout << text.Get() << endl;
	Text text2;
	text2 = text;
	text2.Load("load.txt");
	cout << text2 << endl;
	cout << "Length = " << text2.Length() << endl;
	text.Set("Let's go? Okey go Jimmy! I wait you.  ");
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Add(sentence);
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Remove(0);
	text += sentence3;
	text[0] = sentence;
	cout << text << endl;
	cout << "Length = " << text.Length() << endl;
	text.Save("result.txt");
	text.saveWords("2.txt");

}