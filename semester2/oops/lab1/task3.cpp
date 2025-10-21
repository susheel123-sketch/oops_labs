/*Define the Movie class with private members the title of the movie, its code, and its price. It should also
contain the following public functions:
• void review(float grd) which grades the movie with the grade grd. The review() can be called
multiple times for the same movie. The final score is the average of the grades.
• a constructor that accepts as parameters the data of the movie and assigns them to the corresponding members of the object.
Add to the class any other function or member you think is needed.
The following test program declares an array of five objects of type Movie and initializes it. It calls the
review() of the objects few times. Then, the program reads the code of a movie from user and, if the
movie exists, the program displays its score and price. If the movie does not exist or it exists but has
not been graded, the program displays a related message.*/
#include<iostream>
#include<string>
using namespace std;
class Movie {
    string name;
    int code;
    int price;
    float  totalGrd = 0;
    float ReviewCount = 0;
    public:
    Movie(string a, int b, int c){
        name = a;
        code = b;
        price = c;
    }
    void review( float grd)
    {
        totalGrd += grd;
        ReviewCount++;

    }
    float getscore(){
        if(ReviewCount == 0) return 0;
        return totalGrd/ReviewCount;
    }
   int getcode(){
    return code;
   }
   int getprice(){
    return price;
   }
   
};

int main(){
    Movie movies[5] = {
Movie("Inception", 1, 15),
Movie("Interstellar", 2, 20),
Movie("The Matrix", 3, 10),
Movie("The Godfather", 4, 12),
Movie("Parasite", 5, 8)
};
movies[0].review(5);
movies[0].review(4);
movies[1].review(4);
movies[2].review(2);
movies[3].review(5);
int code;
cout << "Enter code: ";
cin >> code;
for (int i = 0; i < 5; i++) {
if (movies[i].getcode() == code) {
if (movies[i].getscore() == 0) {
cout << "The movie has not been graded yet" << endl;
} else {
cout << "The movie has score " << movies[i].getscore() << " and price " <<
movies[i].getprice() << endl;
}
return 0;
}
}
cout << "The movie does not exist" << endl;
    return 0;
}