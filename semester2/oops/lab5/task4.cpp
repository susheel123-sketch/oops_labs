/*Vehicle Management System: Develop a Vehicle Management System that manages different types
of vehicles, allowing users to store and retrieve details about cars, bikes, and trucks.
(a) Define Classes Using Inheritance
Create a base class Vehicle and derive the following three classes from it:
• Car: Represents passenger cars.
• Bike: Represents motorbikes or scooters.
• Truck: Represents heavy-duty trucks.
(b) Implement the Base Class (Vehicle)
The Vehicle class should have:
• Attributes: brand (string), model (string), and yearManufactured (int).
• A constructor to initialize all attributes.
• A printDetails() method that prints all vehicle details.
(c) Implement the Derived Classes
Each derived class must:
• Have 2–3 additional attributes:
– Car: numDoors (int), fuelType (string).
– Bike: engineCC (int), hasABS (bool).
– Truck: payloadCapacity (double), numAxles (int).
• A constructor that initializes both inherited and new attributes.
• A printDetails() method that prints all attributes, including inherited ones.
(d) Implement the main() Function
• Create at least 5 instances of each derived class (Car, Bike, Truck).
• Store them in an array of pointers to the base class (Vehicle*).
• Iterate through the array and call the printDetails() method for each object*/
