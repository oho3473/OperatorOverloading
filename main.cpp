#include<iostream>
#include"String.h"

void TestPrint(String& string)
{
	std::cout << string.GetLength() << " : "
		<< string << std::endl;
}


int main()
{
	String empty;
	TestPrint(empty);

	String sized(10);
	TestPrint(sized);

	String s1("test");
	std::cout << s1[0] << s1[1] << s1[2] << s1[3] << s1[4] << s1[5] << std::endl;

	String s2(s1);
	String s3 = s1 + s2;
	TestPrint(s3);

	s3 += s3;
	s3[0] = 'T';
	TestPrint(s3);

	empty = s3;
	TestPrint(empty);

	empty = empty;
	TestPrint(empty);

}