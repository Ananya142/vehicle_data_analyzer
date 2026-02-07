#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <limits>

// ==========================================
// 1. Data Model
// ==========================================

struct Vehicle {
    int id;
    std::string make;
    std::string model;
    int year;
    double price;
    std::string category; // e.g., SUV, Sedan, Truck

    // Constructor for convenience
    Vehicle(int id, std::string make, std::string model, int year, double price, std::string category)
        : id(id), make(make), model(model), year(year), price(price), category(category) {}

    // Helper to display vehicle details
    void display() const {
        std::cout << std::left << std::setw(5) << id 
                  << std::setw(15) << make 
                  << std::setw(15) << model 
                  << std::setw(8) << year 
                  << std::setw(10) << price 
                  << std::setw(10) << category << std::endl;
    }
};

// ==========================================
// 2. Logic & Manager (Modular Design)
// ==========================================

class VehicleManager {
private:
    std::vector<Vehicle> inventory;
    int nextId;

public:
    VehicleManager() : nextId(1) {}

    // --- Add Vehicle ---
    void addVehicle(const std::string& make, const std::string& model, int year, double price, const std::string& category) {
        inventory.emplace_back(nextId++, make, model, year, price, category);
        std::cout << "Vehicle added successfully (ID: " << nextId - 1 << ").\n";
    }

    // --- Display All ---
    void displayAll() const {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }
        printHeader();
        for (const auto& v : inventory) {
            v.display();
        }
        std::cout << "Total Vehicles: " << inventory.size() << "\n";
    }

    // --- Sorting (using std::sort) ---
    void sortByPrice(bool ascending = true) {
        auto comparator = [ascending](const Vehicle& a, const Vehicle& b) {
            return ascending ? (a.price < b.price) : (a.price > b.price);
        };
        std::sort(inventory.begin(), inventory.end(), comparator);
        std::cout << "Inventory sorted by price (" << (ascending ? "Low to High" : "High to Low") << ").\n";
    }

    void sortByYear() {
        std::sort(inventory.begin(), inventory.end(), [](const Vehicle& a, const Vehicle& b) {
            return a.year > b.year; // Newest first
        });
        std::cout << "Inventory sorted by year (Newest first).\n";
    }

    // --- Searching (using std::find_if) ---
    void searchById(int id) const {
        auto it = std::find_if(inventory.begin(), inventory.end(), [id](const Vehicle& v) { return v.id == id; });
        if (it != inventory.end()) {
            printHeader();
            it->display();
        } else {
            std::cout << "Vehicle with ID " << id << " not found.\n";
        }
    }

    void searchByMake(const std::string& make) const {
        printHeader();
        bool found = false;
        // Note: A loop with find_if inside is inefficient here, iterating manually or using copy_if is better for multiple matches.
        // For demonstration of finding *first* match:
        auto it = std::find_if(inventory.begin(), inventory.end(), [&make](const Vehicle& v) { 
            return v.make == make; 
        });
        
        // Since we want ALL matches for this search type, we iterate manually
        for(const auto& v : inventory) {
            if(v.make == make) {
                v.display();
                found = true;
            }
        }
        if(!found) std::cout << "No vehicles found by make: " << make << "\n";
    }

    // --- Filtering (using std::copy_if) ---
    void filterByPriceRange(double min, double max) const {
        std::vector<Vehicle> result;
        std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(result),
            [min, max](const Vehicle& v) { return v.price >= min && v.price <= max; });

        if (result.empty()) {
            std::cout << "No vehicles found in price range $" << min << " - $" << max << ".\n";
        } else {
            std::cout << "Found " << result.size() << " vehicle(s) in range:\n";
            printHeader();
            for (const auto& v : result) v.display();
        }
    }

    // --- Analysis (using std::map and std::accumulate) ---
    void generateCategoryReport() const {
        if (inventory.empty()) return;

        // 1. Group using Map: Category -> Count
        std::map<std::string, int> categoryCounts;
        for (const auto& v : inventory) {
            categoryCounts[v.category]++;
        }

        // 2. Calculate Average Price using std::accumulate
        double totalSum = std::accumulate(inventory.begin(), inventory.end(), 0.0, 
            [](double sum, const Vehicle& v) { return sum + v.price; });
        double average = totalSum / inventory.size();

        // 3. Display Analysis
        std::cout << "\n--- Inventory Analysis ---\n";
        std::cout << "Total Inventory Value: $" << std::fixed << std::setprecision(2) << totalSum << "\n";
        std::cout << "Average Vehicle Price: $" << average << "\n";
        std::cout << "Count by Category:\n";
        for (const auto& pair : categoryCounts) {
            std::cout << " - " << pair.first << ": " << pair.second << "\n";
        }
        std::cout << "--------------------------\n";
    }

private:
    void printHeader() const {
        std::cout << "\n" << std::left << std::setw(5) << "ID" 
                  << std::setw(15) << "Make" 
                  << std::setw(15) << "Model" 
                  << std::setw(8) << "Year" 
                  << std::setw(10) << "Price" 
                  << std::setw(10) << "Category" << "\n";
        std::cout << std::string(65, '-') << "\n";
    }
};

// ==========================================
// 3. User Interface (Main)
// ==========================================

void displayMenu() {
    std::cout << "\n=== Vehicle Data Analyzer ===\n";
    std::cout << "1. Add Vehicle\n";
    std::cout << "2. Display All Vehicles\n";
    std::cout << "3. Sort by Price (Low to High)\n";
    std::cout << "4. Sort by Year (Newest First)\n";
    std::cout << "5. Search by ID\n";
    std::cout << "6. Filter by Price Range\n";
    std::cout << "7. Generate Analysis Report\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    VehicleManager manager;

    // Pre-populate with dummy data for demonstration
    manager.addVehicle("Toyota", "Camry", 2019, 24000.00, "Sedan");
    manager.addVehicle("Ford", "Mustang", 2021, 55000.00, "Sports");
    manager.addVehicle("Tesla", "Model 3", 2022, 48000.00, "Electric");
    manager.addVehicle("Honda", "CR-V", 2020, 30000.00, "SUV");
    manager.addVehicle("Ford", "F-150", 2018, 35000.00, "Truck");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        // Input validation loop
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; 
        }

        switch (choice) {
            case 1: {
                std::string mk, md, cat;
                int yr;
                double pr;
                std::cout << "Enter Make: "; std::cin >> mk;
                std::cout << "Enter Model: "; std::cin >> md;
                std::cout << "Enter Year: "; std::cin >> yr;
                std::cout << "Enter Price: "; std::cin >> pr;
                std::cout << "Enter Category: "; std::cin >> cat;
                manager.addVehicle(mk, md, yr, pr, cat);
                break;
            }
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.sortByPrice();
                manager.displayAll();
                break;
            case 4:
                manager.sortByYear();
                manager.displayAll();
                break;
            case 5: {
                int id;
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                manager.searchById(id);
                break;
            }
            case 6: {
                double min, max;
                std::cout << "Enter Min Price: "; std::cin >> min;
                std::cout << "Enter Max Price: "; std::cin >> max;
                manager.filterByPriceRange(min, max);
                break;
            }
            case 7:
                manager.generateCategoryReport();
                break;
            case 8:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
