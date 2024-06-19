#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "DBConnection.h"

class Customer {
public:
    std::string header, footer, bullet;
    int CustID;
    std::string custName, password, custEmail, custAddress, custGender, custAge, custPhoneNumber;

    Customer();
    Customer(int CustID, std::string custName, std::string password, std::string custAge, std::string custEmail, std::string custAddress, std::string custGender, std::string custPhoneNumber);
    bool login();
    void insertCust();
    void updateCustAddress();
    void updateCustPhoneNumber();
    static std::vector<Customer> searchCustomer(std::string custName, std::string custPhoneNumber, bool ascending);
    Customer(sql::ResultSet* data);
    void deleteCust();

    ~Customer();
};

#endif
