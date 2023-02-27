#include <iostream>
#include <string>
#include <mysql.h>


void enterData(MYSQL* connection);
void eraseData(MYSQL* connection);
void updateData(MYSQL* connection);
std::string checkName(MYSQL* connection, std::string& name);
std::string checkEmail(MYSQL* connection, std::string& email);


int main()
{

    std::string name, email;

    MYSQL* connection = mysql_init(NULL);
    if (!mysql_real_connect(connection, "localhost", "persona", "password", "final", 3306, NULL, 0))
    {
        std::cout << "Error connecting to database: " << mysql_error(connection) << std::endl;
        return 1;
    }

    int choice = 0;
    do {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Enter data" << std::endl;
        std::cout << "2. Erase data" << std::endl;
        std::cout << "3. Update data" << std::endl;
        std::cout << "4. Check name" << std::endl;
        std::cout << "5. Check email" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            enterData(connection);
            break;
        case 2:
            eraseData(connection);
            break;
        case 3:
            updateData(connection);
            break;
        case 4:
            std::cout << "Enter name to check: " << std::endl;
            std::cin >> name;
            checkName(connection, name);
            break;
        case 5:
            std::cout << "Enter email to check: " << std::endl;
            std::cin >> email;
            checkName(connection, email);
            break;
        case 6:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 6);

    mysql_close(connection);

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
    if (mysql_query(connection, query.c_str()))
    {
        std::cout << "Error entering data: " << mysql_error(connection) << std::endl;
    }
    else
    {
        std::cout << "Data entered successfully." << std::endl;
    }
}

void eraseData(MYSQL* connection)
{
    std::string name, email;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;

    std::string query = "DELETE FROM mytable WHERE name = '" + name + "'";
    if (mysql_query(connection, query.c_str())) 
    {
        std::cout << "Error erasing data: " << mysql_error(connection) << std::endl;
    }
    else 
    {
        std::cout << "Data erased successfully." << std::endl;
    }

    std::string secondQuery = "DELETE FROM mytable WHERE email = '" + email + "'";
    if (mysql_query(connection, secondQuery.c_str()))
    {
        std::cout << "Error erasing data: " << mysql_error(connection) << std::endl;
    }
    else
    {
        std::cout << "Data erased successfully." << std::endl;
    }
}


void updateData(MYSQL* connection)
{
    std::string name, email;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter new email: ";
    std::cin >> email;

    std::string query = "UPDATE mytable SET email = '" + email + "' WHERE name = '" + name + "'";
    if (mysql_query(connection, query.c_str()))
    {
        std::cout << "Error updating data: " << mysql_error(connection) << std::endl;
    }
    else 
    {
        std::cout << "Data updated successfully." << std::endl;
    }
}

std::string checkName(MYSQL* connection, std::string& name)
{

    std::string query = "SELECT * FROM mytable WHERE name = '" + name + "'";
    if (mysql_query(connection, query.c_str()) != 0)
    {
        std::cout << "Error selecting from database: " << mysql_error(connection) << std::endl;
        return "";
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (result == NULL)
    {
        std::cout << "Error storing result: " << mysql_error(connection) << std::endl;
        return "";
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == NULL)
    {
        std::cout << "Data not found in database." << std::endl;
        return "";
    }

    std::string data = row[1];

    mysql_free_result(result);
    return data;

}

std::string checkEmail(MYSQL* connection, std::string& email)
{

    std::string query = "SELECT * FROM mytable WHERE name = '" + email + "'";
    if (mysql_query(connection, query.c_str()) != 0)
    {
        std::cout << "Error selecting from database: " << mysql_error(connection) << std::endl;
        return "";
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (result == NULL)
    {
        std::cout << "Error storing result: " << mysql_error(connection) << std::endl;
        return "";
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == NULL)
    {
        std::cout << "Data not found in database." << std::endl;
        return "";
    }

    std::string data = row[1];

    mysql_free_result(result);
    return data;

}