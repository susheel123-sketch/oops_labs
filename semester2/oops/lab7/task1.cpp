/*Online Gaming Access Verification: You are developing a program for an online gaming platform that
restricts access to certain games based on age. The platform allows only users aged 16 or older to join
a competitive gaming match. If a user under 16 tries to join, the program should throw an exception.
Write a function void joinMatch(int age) that:
• Throws a std::invalid_argument exception if the age is less than 16.
• Displays "Access granted! You can join the match." otherwise.
In main(), prompt the user for their age, call joinMatch, and handle any exceptions*/
#include<iostream>
#include<stdexcept>
using namespace std;
void join_match(int age)
{
    if(age<16)
    {
        throw runtime_error("You are not eligible for this game ");
    }
    cout<<"You are eligible for this game "<<endl;
}
int main()
{
    try
    {
        int age;
        cout<<"Enter you age "<<endl;
        cin>>age;
        join_match(age);
    }
    catch(const runtime_error& e)
    {
        cout <<"Error:"<< e.what() << '\n';
    }
    
    return 0;
}