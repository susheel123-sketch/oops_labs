/*Username Validation for Online Registration: You are building a program to validate usernames during
an online registration process. The program should enforce the following rules:
• The username must be at least 6 characters long.
• The username must contain at least one alphabetic character.
If the username does not meet these requirements, the program should throw an exception.
Write a function void checkUsername(const std::string& username) that:
• Throws a std::runtime_error if the username is less than 6 characters long.
• Throws a std::runtime_error if the username does not contain any alphabetic character.
• Prints "Username is valid and accepted." if both conditions are met.
In main(), prompt the user to enter a username, call checkUsername, and handle any exceptions.
*/
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
void checkUsername(const string name)
{
  if(name.size()<6)
  {
    throw runtime_error("User name must be 6 character long ");
  }
  bool istrue = false;
  for(char a:name)
  {
    if(isalpha(a))
    {
        istrue = true;
        break;
    }
  }
  if(istrue)
  {
    cout<<"Valid user name "<<endl;
    return ;
  }
  else{
    throw runtime_error("There must be alphabetical character");
  }
}
int main()
{
    string name;
    cout<<"Enter Username "<<endl;
    getline(cin,name);
    try
    {
        checkUsername(name);
    }
    catch(const runtime_error& e)
    {
       cout<<"Error:"<<e.what()<<endl;
    }
    
    return 0;
}