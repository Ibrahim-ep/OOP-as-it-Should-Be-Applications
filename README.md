# 🏦 Bank System (OOP Applications)

This project is a comprehensive Bank Management System developed as part of the "OOP as it Should Be" series. It focuses on shifting from procedural programming to a pure Object-Oriented design, emphasizing encapsulation, abstraction, and modularity.

🚀 Key Features

Client Management: Full CRUD operations (Add, Delete, Update, Find) for bank clients.

Transaction System:

Deposit and Withdrawal.

Total Balances calculation.

Transfer between accounts with a dedicated Transfer Log.

User Management: Advanced system with permissions (Manage Users, Add/Delete/Update Users).

Security & Access:

Secure Login/Logout screens.

Permission-based menu access (only authorized users can access specific screens).

Auditing: Automatic logging of login/logout activities and transfer transactions.

Currency Exchange: Integrated system to manage different currencies and exchange rates.

🏗️ OOP Principles Applied

This project is not just a functional app; it's a demonstration of high-level C++ design:

Encapsulation: Using private members and public Get/Set properties to protect data integrity.

Abstraction: Separating complex logic into specialized classes so the UI (Screens) doesn't need to know the implementation details.

Inheritance: Utilizing base classes (like clsPerson) to create specialized classes (clsClient, clsUser).

Static Methods & Members: Shared logic and global system states managed through static utilities.

Layered Architecture:

Core Logic: Business rules and data handling.

Screens Library: UI components for a clean console interface.

Data Layer: Managing persistence via file handling.

📂 File Structure

The project follows a modular header-only or implementation-separated approach:

Plaintext
├── BankSystem/
│   ├── Core/           # Business logic classes (clsClient, clsUser, etc.)
│   ├── Lib/            # Utility libraries (Input validation, String manipulation)
│   ├── Screens/        # UI logic (Main Screen, Transaction Screens, Login)
│   └── data/           # Persistent storage (.txt files)
🛠️ Tech Stack

Language: C++11/17/20

Concepts: Object-Oriented Design (OOD), File Streams (fstream), String Tokenization.

Tools: Visual Studio code / G++ Compiler.

⚙️ How to Run

Clone the Repository:

Bash
git clone https://github.com/Ibrahim-ep/OOP-as-it-Should-Be-Applications.git
cd BankSystem
Compile: Use any C++ compiler (G++ example):

Bash
g++ -o BankApp main.cpp
Launch:

Bash
./BankApp
👤 Author

Ibrahim

GitHub: @Ibrahim-ep

Course Reference: Inspired by the ProgrammingAdvices "OOP as it Should Be" curriculum.
