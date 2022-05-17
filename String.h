#pragma once


class String
{
private:
	char* mString;
	int mLength;

public:
	String();
	String(int length);
	String(const char* string);
	String(const String& string);
	~String();
	int GetLength() const { return mLength; }
	const char* GetString() const { return mString; }
	
public:
	char& operator[](int index);
	char operator[](int index) const;

	String operator+(const String& string);
	void operator+=(const String& string);
	String& operator=(const String& string);

	friend std::ostream& operator << (std::ostream& os, const String string);
};


