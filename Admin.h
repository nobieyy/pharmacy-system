#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<string>

class Admin
{
public://access specifier
	int AdminID; //numerical attributes
	std::string username, password, email; //text attribute

	Admin(); //constructor method
	Admin(int AdminID, std::string username, std::string password, std::string email);

	bool login();
	void insertCust();

	~Admin(); //destructor method

};

#endif

