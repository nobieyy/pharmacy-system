#include "Admin.h" 
#include <ctime>
#include "DBConnection.h"
using namespace std;

Admin::Admin() //initialize
{
	AdminID = 0;
	username = "";
	password = "";
	email = "";
}
Admin::Admin(int AdminID, std::string username, std::string password, std::string email) {
	this->AdminID = AdminID;
	this->username = username;
	this->password = password;
	this->email = email;
}
bool Admin::login() 
{
	DBConnection db;
	db.prepareStatement("SELECT * FROM admin WHERE username=? AND password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryResult();

	if (db.res->rowsCount() == 1) {
		while (db.res->next())
		{
			AdminID = db.res->getInt("AdminID");
			username = db.res->getString("username");
			password = db.res->getString("password");
			email = db.res->getString("email");
		}
		db.~DBConnection();
		return true;
	}

	return false;
}

void Admin::insertCust()
{
}


Admin::~Admin() {

}
