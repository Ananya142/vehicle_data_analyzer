# Vehicle Data Analyzer (C++)

## 📌 Project Overview

The **Vehicle Data Analyzer** is a menu-driven C++ application designed to manage and analyze vehicle inventory data. The project demonstrates effective use of **C++ STL**, **object-oriented programming**, and **clean modular design** to perform real-world data operations such as sorting, searching, filtering, and reporting.

This system supports:

* 🔐 Role-based login (Admin/User)
* 🚘 Vehicle management (Add, Update, Delete)
* 🔎 Search using Binary Search
* 📊 Inventory analytics
* 💾 File persistence (Data stored in text files)
* 🏗 Multi-file architecture


## 🛠 Technologies Used

* C++
* Object-Oriented Programming
* STL (vector, map, algorithm, accumulate)
* File Handling
* Binary Search
* Role-Based Access Control

## 🛠️ Tech Stack

* **Language:** C++
* **Concepts:** OOP, Clean Code, Modular Design
* **STL:** vector, map, algorithm, numeric
* **Compiler:** GCC / MSVC / Any standard C++ compiler

## 📂 Project Structure

```
VehicleSystem/
│
├── main.cpp
├── Vehicle.h
├── VehicleManager.h
├── VehicleManager.cpp
├── Auth.h
├── Auth.cpp
├── users.txt
├── vehicles.txt
└── README.md
```
## ✨ Features

* Add and manage vehicle records
* Display all vehicles in tabular format
* Sort vehicles by **price** and **year**
* Search vehicles by **ID**
* Filter vehicles by **price range**
* Generate analytical reports:
  * Total inventory value
  * Average vehicle price
  * Category-wise vehicle count
* Menu-driven console interface
* Input validation for robustness



## 📂 Data Model

Each vehicle record contains:

* Vehicle ID
* Make
* Model
* Manufacturing Year
* Price
* Category (SUV, Sedan, Truck, Electric, etc.)

## 🔐 Authentication System

### users.txt Format

```
username password role
```

Example:

```
admin admin123 admin
ananya 1234 user
```

### Roles

| Role  | Permissions               |
| ----- | ------------------------- |
| admin | Add, Delete, Update, View |
| user  | View, Search, Analytics   |



## 🚘 Vehicle Data Format

### vehicles.txt Format

```
id make model year price category
```

Example:

```
1 Toyota Camry 2019 24000 Sedan
2 Ford Mustang 2021 55000 Sports
3 Tesla Model3 2022 48000 Electric
```


## ▶️ How to Run

### Step 1: Open Terminal in Project Folder

```bash
cd VehicleSystem
```

### Step 2: Compile

```bash
g++ main.cpp VehicleManager.cpp Auth.cpp -o vehicle
```

### Step 3: Run (PowerShell)

```bash
.\vehicle
```
## 📋 Menu Options

1. Add Vehicle
2. Display All Vehicles
3. Sort by Price (Low to High)
4. Sort by Year (Newest First)
5. Search by Vehicle ID
6. Filter by Price Range
7. Generate Analysis Report
8. Exit

## 📊 Sample Analysis Output

* Total Inventory Value
* Average Vehicle Price
* Category-wise Vehicle Distribution

## 👩‍💻 Author

**Ananya Goel**






