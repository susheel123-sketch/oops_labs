/*Create a class called Book that includes three pieces of information as data members—a string title, a
string author, and an int price.
Your class should have a constructor with three parameters that uses the parameters to initialize the
three data members. For the purpose of this exercise, assume that the values provided for title and
author are always valid, but ensure that the price value is non-negative; if it isn’t, set the price to 0.
Provide a set and a get function for each data member.
Provide a member function getBookInfo that returns the book’s details as string in the format title by
author - $price.
Write a test program that demonstrates class Book’s capabilities. Alternatively, you can use the main()
function below.
*/
#include<iostream>
#include<string>
using namespace std;
class Book{
    string title;
    string author;
    int price;
    public:
    Book(){
        title = "Unknown";
        author = "Unknown";
        price = 0;
    }
    Book(string a, string b, int c){
        title = a;
        author =b;
        if(c>0){
            price = c;
        }
        else {
            price = 0;
        }
    }
    void setitle(string d){
        title = d;
    }
    void setauthor(string e){
        author = e;
    }
    void setprice(int f){
        price = f;
    }
    string gettitle(){
        return title;
    }
    string getauthor(){
        return author;
    }
    int getprice(){
        price;
    }
void getBookInfo(){
    cout<<"The "<<title <<" by "<<author<<" - $"<<price<<endl;
}

};
using namespace std;
int main(){
    Book b1("The Alchemist","Paulo Coelho",500);
    b1.getBookInfo();
    b1.setprice(600);
    b1.getBookInfo();
    b1.setauthor("Coelho");
     b1.getBookInfo();
     Book b2("Unknown", "Unknown Author", -200);
      b2.getBookInfo();

    
    return 0;
} 







