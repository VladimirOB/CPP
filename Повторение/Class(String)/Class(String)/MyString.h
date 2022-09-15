#pragma once
class MyString
{
	// Fields
	char* Str;
	int MaxSize; // ? 
public:
	MyString();
	MyString(const char* str, unsigned int maxSize);
	~MyString();
	void Set(const char* str);
	char* Get();
	int GetLength();
	int GetVowelsCount(int vow);
	void ToUpper();
	void ToLower();
	void RemoveDigits();
	bool SaveToFile();
	bool LoadFromFile();
	bool Contains(const char* str);
	void Print();
};

