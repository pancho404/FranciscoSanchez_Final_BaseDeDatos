#include <iostream>
#include <string>
#include <mysqlx/xdevapi.h>


using namespace mysqlx;


void addData(Session& session);
void removeData(Session& session);
void checkData(Session& session);
void updateData(Session& session);


int main()
{
	Session session("localhost", 33060, "root", "password", "mydb");

	int selected = 0;

	do
	{
		std::cout << "Choices: " << std::endl;
		std::cout << "1. Add Data " << std::endl;
		std::cout << "2. Update Data " << std::endl;
		std::cout << "3. Check Data " << std::endl;
		std::cout << "4. Remove Data " << std::endl;
		std::cout << "5. Quit " << std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> selected;

		switch (selected)
		{
		case 1:
			addData(session);
			break;
		case 2:
			updateData(session);
			break;
		case 3:
			checkData(session);
			break;
		case 4:
			removeData(session);
			break;
		case 5:
			break;
		default:
			std::cout << "Invalid choice, try again";
			break;
		}

	} while (selected != 5);

	return 0;
}


