#include <iostream>
#include <string>
#include <myutils/cstring.h>


void testStrLen()
{
    const char *str = "Hello World";
    std::cout << "Length of \"" << str << '"' << " is :" << myutils::strLen(str) << std::endl;
}

void testStrCompare()
{
    std::cout << "strCompare(\"123\", \"1234\"): ";
    std::cout << myutils::strCompare("123", "1234") << std::endl; 

    std::cout << "strCompare(\"2\", \"1234\"): ";
    std::cout << myutils::strCompare("2", "1234") << std::endl; 

    std::cout << "strCompare(\"1233\", \"1234\"): ";
    std::cout << myutils::strCompare("1233", "1234") << std::endl; 

}

void testToLower()
{
    char str[] = "Hello Wolrd1235";
    std::cout << str << ", lowered: ";
    myutils::strToLower(str);
    std::cout << str << std::endl;

}
void testToUpper()
{
    char str[] = "Hello Wolrd1235";
    std::cout << str << ", lowered: ";
    myutils::strToUpper(str);
    std::cout << str << std::endl;

}

void testStrConcat()
{
    const int size = 100;

    char str1[size] = "Hello from ";

    std::cout << "before Concating: " << str1 << std::endl;
    myutils::strConcat(size, str1, "the other side!");
    std::cout << "After Concating: " << str1 << std::endl;

}

void testStrCopy()
{
    char destination[100] = "Please Override ME!";

    std::cout << "Before copying: " << destination << std::endl;
    myutils::strCopy(destination, "Hello There");
    std::cout << "After copying: " << destination << std::endl;


}
int main(int, char**){
    testStrLen();
    std::cout << std::endl;
    testStrCompare();
    std::cout << std::endl;
    testToLower();
    std::cout << std::endl;
    testToUpper();
    std::cout << std::endl;
    testStrConcat();
    std::cout << std::endl;
    testStrCopy();
    std::cout << std::endl;

}
