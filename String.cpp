#include<iostream>
#include "String.h"


String::String() : mLength{ 0 }
{
	mString = new char[1];
	mString[0] = '\0';
}

String::String(int length) : mLength{ length }
{
	mString = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		mString[i] = '\0';
	}
}

String::String(const char* string)
{
	int index = 0;
	while (string[index] != '\0')
	{
		++index;
	}

	mString = new char[index+1];
	mLength = index;

	for (int index = 0; index < mLength; index++)
	{
		mString[index] = string[index];
	}

	mString[index] = '\0';
}

String::String(const String& string)
{
	mLength = string.GetLength();
	mString = new char[mLength + 1];
	for (int i = 0; i < mLength; ++i)
	{
		mString[i] = string[i];
	}

	mString[mLength] = '\0';
}

String::~String()
{
	delete[] mString;
	mString = nullptr;
	mLength = 0;
}

char& String::operator[](int index)
{
	return (index > mLength) ? mString[mLength] : mString[index];
}

char String::operator[](int index) const
{
	return (index > mLength) ? mString[mLength] : mString[index];
}

String String::operator+(const String& string)
{
	int newLength = mLength + string.GetLength();
	String result(newLength);
	int index = 0;

	for (int i = 0; i < mLength; ++i, ++index)
	{
		result[index] = mString[i];
	}

	for (int i = 0; i < string.mLength; ++i, ++index)
	{
		result[index] = string[i];
	}

	result[newLength] = '\0';

	return result;
}

void String::operator+=(const String& string)
{
	String result = *this + string;

	*this = result;
}

String& String::operator=(const String& string)
{
	if (this == &string)
		return *this;

	delete[] mString;
	mLength = string.GetLength();
	mString = new char[mLength + 1];

	for (int i = 0; i < mLength; ++i)
	{
		mString[i] = string[i];
	}
	mString[mLength] = '\0';

	return *this;
}

std::ostream& operator<<(std::ostream& os, const String string)
{
	os << string.mString;

	return os;
}
