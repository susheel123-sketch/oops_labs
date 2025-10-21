/*Define the Garage class, which represents a vehicle garage. The class should contain two vectors as private
members, with the first containing the vehicles’ IDs and the second one their corresponding parking slots
occupied. The class should contain the following functions:
• void park(int id , int slots) which parks a vehicle with ID id by adding it to the IDs vector only
if it is not already stored and the slots slots in the corresponding vector. If the ID is already stored,
the function should add the slots slots to the existing slots.
• void release(int id, int slots) which corresponds to removing slots for the vehicle with ID id.
The function should check if the ID is valid and if enough slots are currently occupied and, if so,
subtract slots from it, otherwise a related message should be displayed.
• void showStatus(int id) which checks if the ID id is valid, and if yes it displays the number of slots
currently occupied by the respective vehicle, otherwise a related message.
• The default constructor.
Write a program that tests the operation of the class. Alternatively, you can use the main() function
below.*/
#include<iostream>
#include<vector>
using namespace std;
class Garage{
    vector<int> ids;
    vector<int> slots;
public:
void park(int id, int slot){
    for(int i =0;i<ids.size();i++){
        if(ids[i]==id){
            slots[i]+=slot;
            cout<<slot<<" more slot occupied by vehicle "<<id<<endl;
            cout<<" total "<<slots[i]<<endl;
            return ;
        }
    }
    ids.push_back(id);
    slots.push_back(slot);
    cout<<slot<<" slots occupied by vehicle "<<id<<endl;
}
void release(int id, int slot){
    for (int i =0;i<ids.size();i++){
        if(ids[i]==id){
        if(slots[i]>slot){
            slots[i]-=slot;
            cout<<slot<<" slots released from "<<id<<endl;
            return ;
        }else {
            cout<<" The requested number of slots can't be released "<<endl;
           
        }
        return;
    }
}
    cout<<" Vehicle ID "<< id << " not found "<<endl;
}
void showStatus(int id){
    for(int i =0;i<ids.size();i++){
        if(ids[i]==id){
            cout<<slots[i]<<" slots occupied by Vehicle "<<ids[i]<<endl;
            return;
        }
}
cout<<"vehicle ID "<<id<<"  not found "<<endl;
}
};


int main(){
    Garage g;
g.park(101, 2); // print "2 slots occupied by vehicle 101"
g.park(102, 3); // print "3 slots occupied by vehicle 102"
g.park(103, 4); // print "4 slots occupied by vehicle 103"
g.park(101, 1); // print "1 more slot occupied by vehicle 101, total 3"
g.release(101, 2); // print "2 slots released for vehicle 101"
g.release(102, 5); // print "The requested number of slots cannot be released"
g.release(102, 2); // print "2 slots released for vehicle 102"
g.release(104, 1); // print "Vehicle ID 104 not found"
g.showStatus(101); // print "1 slot currently occupied by vehicle 101"
g.showStatus(102); // print "1 slot currently occupied by vehicle 102"
g.showStatus(103); // print "4 slots currently occupied by vehicle 103"
g.showStatus(104); // print "Vehicle ID 104 not found"
    
    return 0;
}