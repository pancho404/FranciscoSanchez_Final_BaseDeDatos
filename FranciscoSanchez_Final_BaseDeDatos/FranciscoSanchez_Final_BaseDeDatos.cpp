#include <iostream>
#include <string>
#include <mysql.h>

enum class actions { ADD=1, UPDATE, CHECK, REMOVE};


void enterData(MYSQL* connection);
void eraseData(MYSQL* connection);
void updateData(MYSQL* connection);
void checkData(MYSQL* connection);


int main()
{
    MYSQL* conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "mydb", 3306, NULL, 0))
    {
        std::cout << "Error connecting to database: " << mysql_error(conn) << std::endl;
        return 1;
    }

    int choice = 0;
    do {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Enter data" << std::endl;
        std::cout << "2. Erase data" << std::endl;
        std::cout << "3. Update data" << std::endl;
        std::cout << "4. Check data" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            enterData(conn);
            break;
        case 2:
            eraseData(conn);
            break;
        case 3:
            updateData(conn);
            break;
        case 4:
            checkData(conn);
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 5);

    mysql_close(conn);

    return 0;
}


void enterData(MYSQL* connection)
{
    std::string name, email;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;

    // insert data into table
    std::string query = "INSERT INTO mytable (name, email) VALUES ('" + name + "', '" + email + "')";
    if (mysql_query(connection, query.c_str())) {
        std::cout << "Error entering data: " << mysql_error(connection) << std::endl;
    }
    else {
        std::cout << "Data entered successfully." << std::endl;
    }
}

void eraseData(MYSQL* connection)
{

}

void updateData(MYSQL* connection)
{

}

void checkData(MYSQL* connection)
{

}