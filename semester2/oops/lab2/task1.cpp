/*
Rational Numbers: Modify the Rational class so that it dynamically allocates memory for the numerator
and denominator instead of using simple integer variables (num and den will now become pointers). The
class should represent rational numbers in their simplest form and provide arithmetic operations.
• Implement a constructor that dynamically allocates memory for the numerator and denominator
and ensures the fraction is stored in its simplest form.
• Implement a copy constructor to create deep copies of objects.
• Implement a copy assignment operator to handle assignment between objects properly.
• Implement a destructor to release dynamically allocated memory.
1:int get_num() const Returns the numerator of the rational number by
dereferencing the dynamically allocated memory
(return *num;).
2:int get_den() const Returns the denominator of the rational number
by dereferencing the dynamically allocated memory (return *den;).
3:void set_num(int n) Sets the numerator by updating the value in dynamically allocated memory (*num = n;).
4:void set_den(int d) Sets the denominator by updating the value in
dynamically allocated memory (*den = d;).
5:string to_string() const Converts the rational number to a string in
the form "num/den" by dereferencing pointers (return std::to_string(*num) + "/" +
6:std::to_string(*den);).
7:void reduce() Reduces the rational number to its lowest
terms by computing the greatest common divisor
(GCD) and updating *num and *den accordingly.
:Rational operator+(const Rational& r) const Returns the sum of the current rational number
and r by dynamically allocating a new Rational
object with the computed sum.
8:Rational operator-(const Rational& r) const Returns the difference of the current rational
number and r by dynamically allocating a new
Rational object with the computed difference.
Rational operator*(const Rational& r) const Returns the product of the current rational number and r by dynamically allocating a new Rational object with the computed product.
Rational operator/(const Rational& r) const Returns the quotient of the current rational number and r by dynamically allocating a new Rational object with the computed quotient.
bool operator==(const Rational& r) const Returns true if the current rational number is
equal to r by comparing *num and *den values.
bool operator!=(const Rational& r) const Returns true if the current rational number is
not equal to r by comparing *num and *den values.
Rational(const Rational& r) Copy constructor that creates a deep copy of another rational number by allocating new memory
and copying values.
Rational& operator=(const Rational& r) Copy assignment operator that ensures deep
copying by assigning new values to already allocated memory.
~Rational() Destructor that frees the dynamically allocated
memory for num and den using delete.

*/
#include<iostream>
using namespace std;
class rational{
    int*num;
    int*den;
    int gcd(int a, int b){
        return (b==0)?a:gcd(b,a%b);
    }
    void reduce(){
        if(*den==0) return;
        int g = gcd(*num,*den);

        (*num) = (*num)/g;
        (*den)= (*den)/g;
        if(*den<0){
            (*num) = -(*num);
            (*den) = -(*den);
        }

    }
    public:
    rational(){};
    rational(int a, int b){
        num = new int(a);
        if(b==0){
            den = new int(b);
        }else{
        den = new  int(b);
    }
        reduce();
}
    rational(const rational&z){
        num = new int(*z.num);
        den = new int(*z.den);
    }
    rational& operator=(const rational& r) {
    if (this != &r) {  
        *num = *r.num;
        *den = *r.den;
    }
    return *this;
}
~rational(){
    delete num;
    delete den;
}
    void set_den(int b){
         if(b==0){
            den = new int(b);
        }else{
        den = new  int(b);
    }
        reduce();
    }
    void set_nom(int b){
        num = new int(b);
        reduce();
    }
    int get_nom(){
        return *num;
    } 
    int get_den(){
        return *den;
    }
    string to_string() const {
        return std::to_string(*num) + "/" + std::to_string(*den);
    }
    rational operator+(const rational&ran)const{
       int new_nom = (*num)*(*ran.den)+(*den)*(*ran.den);
       int new_den = (*den)*(*ran.den);
       return rational(new_nom,new_den);
    }
    rational operator-(const rational&ran)const{
      int new_nom = (*num)*(*ran.den)-(*den)*(*ran.den);
       int new_den = (*den)*(*ran.den);
       return rational(new_nom,new_den);
    }
    rational operator*(const rational&ran)const{
        int new_nom = (*num)*(*ran.num);
       int new_den = (*den)*(*ran.den);
       return rational(new_nom,new_den);
    }
    rational operator/(const rational&ran)const{
        int new_nom = (*num)*(*ran.den);
       int new_den = (*den)*(*ran.num);
       return rational(new_nom,new_den);
       
    }
    bool operator == (const rational & r)const {
        return (*num == *r.num)&&(*den==*r.den);
    }
    bool operator !=(const rational & r) const{
        return !(*this == r);
    }
   

};
int main(){
    rational r1(4,5);
    rational r2 = r1;
    rational r3  = r1;
    cout<<"r1: "<<r1.to_string()<<endl;
    cout<<"r2: "<<r2.to_string()<<endl;
    cout<<"r3: "<<r3.to_string()<<endl;
    rational r4(4,6);
    rational sum = r1+r4;
    rational diff = r1-r4;
    rational mult = r1*r4;
    rational division = r1/r4;
    cout<<"Sum: "<<sum.to_string()<<endl;
    cout<<"Subtraction: "<<diff.to_string()<<endl;
    cout<<"Multiplication: "<<mult.to_string()<<endl;
    cout<<"Division: "<<division.to_string()<<endl;




    return 0;
}