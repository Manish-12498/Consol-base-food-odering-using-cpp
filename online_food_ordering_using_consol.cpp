#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Class for menu items
class FoodItem {
public:
    int id;
    string name;
    double price;

    FoodItem(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }
};

// Class for a single order item
class OrderItem {
public:
    FoodItem food;
    int quantity;

    OrderItem(FoodItem f, int q) : food(f), quantity(q) {}

    double getTotal() {
        return food.price * quantity;
    }
};

// Main ordering system class
class FoodOrderingSystem {
private:
    vector<FoodItem> menu;
    vector<OrderItem> cart;
    string customerName;
    string customerPhone;

public:
    FoodOrderingSystem() {
        // Predefined menu items
        menu.push_back(FoodItem(1, "Pizza", 199.99));
        menu.push_back(FoodItem(2, "Burger", 99.49));
        menu.push_back(FoodItem(3, "Pasta", 149.99));
        menu.push_back(FoodItem(4, "Sandwich", 79.50));
        menu.push_back(FoodItem(5, "French Fries", 59.99));
        menu.push_back(FoodItem(6, "Cold Drink", 39.00));
    }

    void displayMenu() {
        cout << "\n========= MENU =========\n";
        cout << left << setw(5) << "ID" << setw(20) << "Item" << "Price (Rs.)" << endl;
        cout << "-------------------------------\n";
        for (auto &item : menu) {
            cout << left << setw(5) << item.id << setw(20) << item.name << fixed << setprecision(2) << item.price << endl;
        }
        cout << "-------------------------------\n";
    }

    void getCustomerDetails() {
        cout << "\nEnter your name: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter your phone number: ";
        getline(cin, customerPhone);
    }

    void takeOrder() {
        int id, qty;
        char choice;
        do {
            displayMenu();
            cout << "\nEnter item ID to order: ";
            cin >> id;
            cout << "Enter quantity: ";
            cin >> qty;

            if (cin.fail() || qty <= 0) {
                cout << "Invalid input! Please try again.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            bool found = false;
            for (auto &item : menu) {
                if (item.id == id) {
                    cart.push_back(OrderItem(item, qty));
                    cout << qty << " x " << item.name << " added to your cart.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Invalid Item ID! Try again.\n";
            }

            cout << "\nDo you want to order another item? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void generateBill() {
        double subtotal = 0;
        double discount = 0;
        cout << "\n========= BILL =========\n";
        cout << "Customer: " << customerName << endl;
        cout << "Phone: " << customerPhone << endl;
        cout << "-----------------------------------------------\n";
        cout << left << setw(20) << "Item" << setw(10) << "Qty" 
             << setw(10) << "Price(Rs.)" << setw(10) << "Total(Rs.)" << endl;
        cout << "-----------------------------------------------\n";

        for (auto &order : cart) {
            double total = order.getTotal();
            subtotal += total;
            cout << left << setw(20) << order.food.name << setw(10) << order.quantity
                 << setw(10) << order.food.price << setw(10) << total << endl;
        }

        if (subtotal > 500) {
            discount = subtotal * 0.10; // 10% discount for orders above Rs.500
            cout << "\nCongratulations! You got a 10% discount!\n";
        }

        double gst = (subtotal - discount) * 0.05;
        double grandTotal = subtotal - discount + gst;

        cout << "-----------------------------------------------\n";
        cout << left << setw(30) << "Subtotal:" << "Rs." << subtotal << endl;
        cout << left << setw(30) << "Discount (10% if applicable):" << "Rs." << discount << endl;
        cout << left << setw(30) << "GST (5%):" << "Rs." << gst << endl;
        cout << left << setw(30) << "Grand Total:" << "Rs." << grandTotal << endl;
        cout << "===============================================\n";

        saveToFile(subtotal, discount, gst, grandTotal);
    }

    void saveToFile(double subtotal, double discount, double gst, double grandTotal) {
        ofstream file("orders.txt", ios::app);
        if (file.is_open()) {
            file << "======== New Order ========\n";
            file << "Customer: " << customerName << "\nPhone: " << customerPhone << "\n";
            for (auto &order : cart) {
                file << order.food.name << " x " << order.quantity << " = Rs." << order.getTotal() << "\n";
            }
            file << "Subtotal: Rs." << subtotal << "\n";
            file << "Discount: Rs." << discount << "\n";
            file << "GST: Rs." << gst << "\n";
            file << "Total: Rs." << grandTotal << "\n";
            file << "===========================\n\n";
            file.close();
            cout << "\nOrder saved successfully in 'orders.txt'.\n";
        } else {
            cout << "\nError: Could not save order to file.\n";
        }
    }

    void viewPreviousOrders() {
        ifstream file("orders.txt");
        if (file.is_open()) {
            cout << "\n===== Previous Orders =====\n";
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "\nNo previous orders found.\n";
        }
    }

    void mainMenu() {
        int choice;
        do {
            cout << "\n=============================================\n";
            cout << "     WELCOME TO ONLINE FOOD ORDER SYSTEM     \n";
            cout << "=============================================\n";
            cout << "1. Place a New Order\n";
            cout << "2. View Previous Orders\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    getCustomerDetails();
                    takeOrder();
                    generateBill();
                    cart.clear();
                    break;
                case 2:
                    viewPreviousOrders();
                    break;
                case 3:
                    cout << "\nThank you for using our system! Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main() {
    FoodOrderingSystem system;
    system.mainMenu();
    return 0;
}
