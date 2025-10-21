/* Create a class IntegerSet for which each object can hold integers in the range 0 through
100. Represent the set internally as a dynamically allocated boolean array (bool*). Element a[i] is
true if integer i is in the set, and false otherwise.
The default constructor initializes a set to the so-called “empty set,” i.e., a set for which all elements
contain false.
• Implement a constructor that dynamically allocates memory for a boolean array of size 101 and
initializes all values to false.
• Implement a copy constructor to ensure deep copying of dynamically allocated memory.
• Implement a copy assignment operator to handle assignment between objects properly.
• Implement a destructor to properly free the allocated memory.
• Provide member functions for the common set operations:
– unionOfSets(const IntegerSet&): Creates a third set that is the set-theoretic union of two
existing sets.
– intersectionOfSets(const IntegerSet&): Creates a third set that is the set-theoretic
intersection of two existing sets.
– insertElement(int k): Inserts a new integer k into a set by setting a[k] to true.
– deleteElement(int m): Deletes integer m by setting a[m] to false.
– to_string() Returns a string containing a list of numbers separated by spaces. Include only
those elements that are present in the set.
– isEqualTo(const IntegerSet&): Determines whether two sets are equal.
• Provide an additional constructor that receives an array of integers and its size, and uses this array
to initialize a set object.
*/
#include<iostream>
using namespace std;
class integer_set{
    int size;
    bool*arr;
    public:
    integer_set(){
        size =  101;
        arr  = new bool[size];
        for(int i =0;i<size;i++){
            arr[i] = false;
        }
    }
    integer_set(int array[], int n){
        size = 101;
        arr = new bool[size];
        for(int i =0;i<size;i++){
            arr[i] = false;
        }
        for(int i =0;i<n;i++){
            if(array[i]>0 && array[i]<100){
            arr[array[i]] = true;
        }
    }
}
integer_set(const integer_set&other){
    size = other.size;
    arr = new bool[size];
    for(int i =0;i<size;i++){
        arr[i] = other.arr[i];
    }
}
integer_set& operator = (const integer_set&other){
    if(this != &other){
        delete []arr;
        size = other.size;
        arr = new bool[size];
    for(int i =0;i<size;i++){
        arr[i] = other.arr[i];
    }
}
return *this;
}
~integer_set(){
    delete[] arr;
}
void insertElement(int k){
    if(k>=0&&k<100){
        arr[k] = true;
    }
}
void deleteElement(int m){
    if(m>=0&&m<100){
        arr[m]=false;
    }
}
integer_set union_set(integer_set&other)const{
    integer_set result;
    for(int i =0;i<other.size;i++){
        result.arr[i] = (arr[i]||other.arr[i]);
    }
    return result;
}
integer_set intersection_set(integer_set&other)const{
    integer_set result;
    for(int i =0;i<other.size;i++){
        result.arr[i] = (arr[i]&&other.arr[i]);
    }
    return result;
}
   bool isEqualTo(const integer_set& other) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i])
                return false;
        }
        return true;
    }
       string to_string() const {
        string result = "";
        for (int i = 0; i < size; i++) {
            if (arr[i]) {
                result += std::to_string(i) + " ";
            }
        }
        if (result.empty())
            return "Empty Set";
        return result;
    }
};
int main(){
    integer_set set1;
    set1.insertElement(10);
    set1.insertElement(20);
    set1.insertElement(30);
    cout << "Set1: " << set1.to_string() << endl;

    integer_set set2 = set1;
    cout << "Set2 (copy of Set1): " << set2.to_string() << endl;

   
    set2.insertElement(40);
    cout << "Set2 after inserting 40: " << set2.to_string() << endl;

  
    integer_set set3;
    set3 = set1;
    cout << "Set3 (assigned from Set1): " << set3.to_string() << endl;

    
    int arrays[] = {5, 15, 25, 35};
    integer_set set4(arrays, 4);
    cout << "Set4 (from array): " << set4.to_string() << endl;

    integer_set set5 = set1.union_set(set4);
    cout << "Union of Set1 and Set4: " << set5.to_string() << endl;

    
    integer_set set6 = set1.intersection_set(set4);
    cout << "Intersection of Set1 and Set4: " << set6.to_string() << endl;

  
    cout << "Set1 == Set2 ? " << (set1.isEqualTo(set2) ? "Yes" : "No") << endl;
    cout << "Set1 == Set4 ? " << (set1.isEqualTo(set4) ? "Yes" : "No") << endl;

    
    set1.deleteElement(20);
    cout << "Set1 after deleting 20: " << set1.to_string() << endl;


    return 0;
}