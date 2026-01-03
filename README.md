🍔 Online Food Ordering System (C++)

A console-based Online Food Ordering System built using C++ and Object-Oriented Programming (OOP) concepts.
The application allows users to place food orders, generate bills with GST & discounts, and store order history in a file.

📌 Features

📋 Predefined food menu

👤 Customer details (name & phone number)

🛒 Add multiple food items to cart

💰 Automatic bill generation

🎉 10% discount on orders above ₹500

🧾 GST calculation (5%)

💾 Order history saved in a file (orders.txt)

📖 View previous orders anytime

🧱 OOP-based design (classes & encapsulation)

🛠️ Technologies Used

Language: C++

Concepts:

Object-Oriented Programming (OOP)

File Handling (ifstream, ofstream)

STL (vector, string)

Input validation

Formatting output (iomanip)

📂 Project Structure
FoodOrderingSystem.cpp
orders.txt   (auto-created when an order is placed)

🧑‍🍳 Menu Items
ID	Item	Price (Rs.)
1	Pizza	199.99
2	Burger	99.49
3	Pasta	149.99
4	Sandwich	79.50
5	French Fries	59.99
6	Cold Drink	39.00
▶️ How to Run the Program

Clone the repository

git clone https://github.com/Manish-12498/<repo-name>.git


Compile the program

g++ FoodOrderingSystem.cpp -o food_order


Run the executable


📄 File Handling

All orders are saved in orders.txt

Each order includes:

Customer name & phone

Ordered items & quantities

Subtotal, discount, GST, and grand total

🧠 Concepts Demonstrated

Class design (FoodItem, OrderItem, FoodOrderingSystem)

Encapsulation and data abstraction

Vector-based dynamic storage

Menu-driven program

Real-world billing logic

🚀 Future Improvements

Login system for customers

Dynamic menu using files or database

Edit/remove items from cart

Payment simulation

GUI version (using Qt or web-based frontend)

👨‍💻 Author

Manish Chaurasiya
📌 Beginner C++ & Web Development Learner
🔗 GitHub: https://github.com/Manish-12498

⭐ If you like this project, give it a star on GitHub!
