/*Travel Cost Calculator. You are tasked with developing a program for a travel cost calculator
that computes the total travel expense using function overloading. Implement an overloaded function
calculateCost() that works as follows:
• For a Single Trip – Accepts a single parameter (distance in kilometers) and returns the cost based
on a fixed rate per kilometer.
• For a Round Trip – Accepts two parameters (distance for one way and a discount percentage)
and returns the total cost after applying the round-trip discount.
• For a Multi-City Trip – Accepts three parameters (distances between three consecutive cities)
and returns the total cost for all legs of the journey.
• For a Custom Route – Accepts an array of n distances and returns the total cost for the entire
route.
Hint: Assume a constant rate of cost per kilometer (e.g., $0.5/km) when computing the total.
Your program should prompt the user to choose a travel type, input the required values, and display the
corresponding total cost.*/
#include <iostream>
using namespace std;
const float rate = 0.5;
float calculateCost(int distance)
{
    return distance * rate;
}
float calculateCost(int distance, float discount)
{
    float Totalprice = 0;
    Totalprice = (distance * 2) * rate;
    Totalprice -= Totalprice * discount;
    return Totalprice;
}
float calculateCost(int dis1, int dis2, int dis3)
{
    int totdis = dis1 + dis2 + dis3;
    float total_price = (dis1 + dis2 + dis3) * rate;
    return total_price;
}
float calculateCost(int arr[], int n)
{
    int Total_dis = 0;
    for (size_t i = 0; i < n; i++)
    {
        Total_dis += arr[i];
    }
    return Total_dis * rate;
}
int main()
{
    int choice;
    
    cout<< "Enter your choice " << endl;
    cout << "1: Single Trip " << endl;
    cout << "2: Round Trip " << endl;
    cout << "3: Multi-city Trip " << endl;
    cout << "4:Custom Route " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int dis;
        cout << "Enter the distance in kilometer " << endl;
        cin >> dis;
        cout << "Price for single trip is :" << calculateCost(dis) << "$" << endl;
    }
    break;
    case 2:
    {
        int dis_way;
        cout << "Enter the distance for one way " << endl;
        cin >> dis_way;
        float dis_percent;
         cout << "Enter the discount " << endl;
         cin >> dis_percent;
        cout << "Price for Round trip is:" << calculateCost(dis_way, dis_percent) << "$" << endl;
        break;
    }
    case 3:
    {
        int dis1, dis2, dis3;
        cout << "Enter distance btw three consecutive cities " << endl;
        cin >> dis1 >> dis2 >> dis3;
        cout << "Price for Multi-cities is :" << calculateCost(dis1, dis2, dis3) << "$" << endl;
        break;
    }
    case 4:
    {
        int n;
        cout << "Enter the n distances " << endl;
        cin >> n;
        int *arr = new int[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Price for custom Route is: " << calculateCost(arr, n) << "$" << endl;
          delete[] arr;
    }
      
        break;
    default:
        cout << "Invalid choice " << endl;
        break;
    }

    return 0;
}