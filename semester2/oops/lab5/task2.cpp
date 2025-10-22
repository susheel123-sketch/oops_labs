/*Complex Numbers. Define a class for complex numbers. A complex number is a number of the form:
a + b · i
where a and b are numbers of type double, and i represents the quantity √
−1. Represent a complex
number as two values of type double. Name the member variables real and imaginary. The variable
representing the coefficient of i should be called imaginary. Call the class Complex.
Include the following constructors:
• A constructor with two parameters of type double that initializes the member variables to given
values.
• A constructor with a single parameter of type double (named realPart) that initializes the object
to realPart +0i.
• A default constructor that initializes an object to 0 + 0i.
Overload the following operators so they correctly apply to the Complex class:
• + (addition)
• - (subtraction)
• * (multiplication)
• == (equality comparison)
• » (input stream)*
• « (output stream)
Write a test program to validate your class.
/
#include<iostream>
using namespace std;
class complex{
double real;
double imag;
public:
complex(){
    real = 0;
    imag = 0;
}
complex(double realpart){
    real = realpart;
    imag = 0;
}
complex(double a, double b){
    real  =a;
    imag = b;
}
complex operator+(complex &other)const{
    complex temp;
    temp.real = real+other.real;
    temp.imag = imag +other.imag;
    return temp;
}
complex operator-(const complex &other)const{
    complex temp;
    temp.real = real-other.real;
    temp.imag = imag -other.imag;
    return temp;
}
complex operator*(const complex &other)const{
    complex temp;
    temp.real = real*other.real-imag*other.imag;
    temp.imag = real*other.imag +imag*other.real;
    return temp;
}
bool operator==(const complex &other)const{
 return(real == other.real && imag == other.imag);
}
friend ostream&  operator<<(ostream& os,const complex &other) {
    os<<other.real<<" + "<<other.imag<<"i"<<endl;
    return os;
}
friend istream& operator>>(istream& in, complex& other){
    cout<<"Enter the value of real and imag number "<<endl;
    in>>other.real>>other.imag;
    return in;
}
};

int main(){
    complex z1,z2(5,6);
    cin>>z1;
    complex z3 = z1+z2;
    cout<<z3;
    // if(z1==z2){
    //     cout<<"Complex number are equal "<<endl;
    // }
    // else{
    //     cout<<"Not equal "<<endl;
    // }
   
    return 0;
}