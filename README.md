# Bank Console App (C++)

This repository contains a console-based banking application written in C++, emphasizing Object-Oriented Programming (OOP) principles. The application manages client and user data through file handling for CRUD (Create, Read, Update, Delete) operations for both clients and users, integrating simple permission-based functionalities, including a login system for users.

## Key Features

- **Client Operations**:
  - Create, Read, Update, Delete client data
  - Manage client accounts and transactions

- **User Operations**:
  - Create, Read, Update, Delete user data
  - Permission-based operations
  - User login and authentication

## Admin Access

The application includes an admin user with default credentials for testing purposes:

- **Username**: admin
- **Password**: admin

## Screenshots

Here are some screenshots from the application:

#### Login
![Login](screenshots/login.png)

#### Main Menu
![Main Menu](screenshots/main_menu_screen.png)

#### Manage Users Menu
![Manage Users Menu](screenshots/manage_users_screen.png)

#### List Users
![List Users](screenshots/list_users_screen.png)

#### List Clients
![List Clients](screenshots/list_clients_screen.png)

#### Client Added Successfully
![Client Added Successfully](screenshots/add_client.png)

#### Access Denied
![Access Denied](screenshots/if_access_denied.png)

#### Invalid Login
![Invalid Login](screenshots/invalid_login.png)

## Custom Libraries

This repository includes five custom-built libraries implemented to enhance the functionalities of the banking application, designed to be versatile and usable in other C++ applications too:

1. **clsDate**: Handles date-related operations.
2. **clsPeriod**: Manages time periods and durations.
3. **clsInputValidation**: Validates user inputs and ensures data integrity.
4. **clsString**: Manipulates strings and formats data.
5. **clsUtil**: Contains miscellaneous functions used across the application.

## Compile and Run the Code

### Prerequisites

Ensure you have the following installed on your system:
- C++ compiler (e.g., GCC for Unix-like systems or MinGW for Windows)
- Git (for cloning the repository)

### Compilation

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/console-app-bank/yourproject.git
    cd console-app-bank
    ```

2. **Compile the Code:**

   - **For Unix-like systems (using GCC):**

     ```bash
     g++ -o console-app-bank console-app-bank.cpp
     ```
   
   - **For Windows (using MinGW):**

     ```bash
     g++ -o console-app-bank.exe console-app-bank.cpp
     ```

### Execution

Run the Executable:

- **For Unix-like systems (using GCC):**

    ```bash
    ./console-app-bank
    ```

- **For Windows:**

    ```bash
    console-app-bank.exe
    ```
