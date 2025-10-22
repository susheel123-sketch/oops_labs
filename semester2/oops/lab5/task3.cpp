/*Library Management System. You are tasked with developing a Library Management System using
the principle of separating interface from implementation in C++. The system should allow users to
create a library member account, borrow books, return books, and view borrowing history. To achieve
this, design a class named LibraryMember that provides the required functionalities. Implement the
class by separating the interface from the implementation.
Class Attributes:
• memberName (string): Stores the name of the library member.
• memberID (int): Unique membership ID.
• borrowedCount (int): Tracks the number of currently borrowed books.
• activityLog (vector<string>): Stores a record of all borrowing and returning activities.
Member Functions:
• LibraryMember(std::string name, int id, int startCount = 0): Initializes the member
with a name, ID, and an optional initial borrowed count (default: 0).
• void borrowBook(const std::string &bookTitle): Records that the member borrowed a
book and adds the entry to the activity log.
• bool returnBook(const std::string &bookTitle): Records that the member returned a book
if the borrowed count is positive and logs the activity. Displays an error if there are no borrowed
books.
• void displayMemberDetails() const: Displays the member’s name, ID, and the current number of borrowed books.
• void showActivityLog() const: Displays the full borrowing/returning history for the member.
The main.cpp file should be able to perform the following functions:
• Create a library member account.
• Record a few activities (borrowing and returning books).
• Display the member details and full activity log.
Last updated: 2025-09-23 04:12 Page 15 of 16
Sep 23, 2025
Constraints:
• The number of books returned cannot exceed the current number of borrowed books.
• Borrowing or returning a negative count of books is not allowed.
• Use separate files (LibraryMember.h, LibraryMember.cpp, and main.cpp) to follow the separation of interface from implementation principle.*/
#include "libraryMember.h"
#include<iostream>
librarymember::librarymember(string a, int b, int b_count){
    MemberName = a;
    member_id = b;
    borrowed_count = b_count;
}
void librarymember::borrowedbook(const string&booktitle, int count){
    if(count<=0){
        cout<<"Count borrow negative Number of books "<<endl;
        activitylog.push_back("Not borrowed Negative books ");
    }
    borrowed_count+=count;
    activitylog.push_back("Borrowed "+booktitle + "= "+to_string(count));
}
bool librarymember::returnedbook(const string&booktitle, int count ){
    if(count<=0){
        cout<<"Cannot return negative books "<<endl;
        return false;
    }
    if(borrowed_count>=count){
        borrowed_count-=count;
        cout<<"Returned "<<count<<" books "<<endl;
        activitylog.push_back("Retured "+to_string(count)+"book was "+booktitle);
        return true;
    }else{
        cout<<"Not valid No of books to return  "<<endl;
        return false;
    }
    
}
void librarymember::displayDetails()const{
    cout<<"Member name "<< MemberName <<endl;
    cout<<"Member Id "<<member_id<<endl;
    cout<<"Currently book borrowed "<<borrowed_count<<endl;

}
void librarymember::DisplaylogDetails()const{
    cout<<"----Activity logs ------"<<endl;
    for(const string&entry:activitylog){
        cout<<entry <<endl;
    }
}
// 
#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H
#include<iostream>
#include<vector>
using namespace std;
class librarymember{
string MemberName;
int member_id;
int borrowed_count;
vector<string>activitylog;
public:
librarymember(string a, int b, int b_count = 0);
void borrowedbook(const string&booktitle, int count = 1);
bool returnedbook(const string&booktitle, int count = 1);
void displayDetails()const;
void DisplaylogDetails()const;

};
#endif
// 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class LibraryMember{
    string member_name;
    int member_id;
    int borrowed_count;
    vector<string>activitylog;
    void savelog(const string&log){
        activitylog.push_back(log);
        fstream file("file.txt",ios::app);
        if(file.is_open()){
            file<<log<<endl;
            file.close();
        }
        
    }
    public:
    LibraryMember(string name, int id,int count = 0)
    {
        member_name = name;
        member_id = id;
        borrowed_count = count;
    }
    void borrowBook(const string& booktitle){
        borrowed_count++;
        savelog("Borrowed "+booktitle);

    }
    bool returnBook(const string &booktitle){

    }
    void displayMemberDetails()const{

    }
    void show_log_details(){

    }

};
int main(){
    return 0;
}