#include "Customer.h"
#include "DBConnection.h"
#include <vector>

using namespace std;

Customer::Customer() : CustID(0), custName(""), password(""), custAge(""), custEmail(""), custAddress(""), custGender(""), custPhoneNumber("") {}

Customer::Customer(int CustID, string custName, string password, string custAge, string custEmail, string custAddress, string custGender, string custPhoneNumber)
    : CustID(CustID), custName(custName), password(password), custAge(custAge), custEmail(custEmail), custAddress(custAddress), custGender(custGender), custPhoneNumber(custPhoneNumber) {}

bool Customer::login() {
    DBConnection db;
    db.prepareStatement("SELECT * FROM customer WHERE username=? AND password=?");
    db.stmt->setString(1, custName);
    db.stmt->setString(2, password);
    db.QueryResult();

    if (db.res->rowsCount() == 1) {
        while (db.res->next()) {
            CustID = db.res->getInt("CustID");
            custName = db.res->getString("custName");
            password = db.res->getString("password");
            custAge = db.res->getString("custAge");
            custEmail = db.res->getString("custEmail");
            custAddress = db.res->getString("custAddress");
            custGender = db.res->getString("custGender");
            custPhoneNumber = db.res->getString("custPhoneNumber");
        }
        return true;
    }
    return false;
}

void Customer::insertCust() {
    DBConnection db;
    db.prepareStatement("INSERT into customer (custName,custAge,custEmail,custAddress,custGender,custPhoneNumber) VALUES (?,?,?,?,?,?)");
    db.stmt->setString(1, custName);
    db.stmt->setString(2, custAge);
    db.stmt->setString(3, custEmail);
    db.stmt->setString(4, custAddress);
    db.stmt->setString(5, custGender);
    db.stmt->setString(6, custPhoneNumber);
    db.QueryStatement();
}

void Customer::updateCustAddress() {
    DBConnection db;
    db.prepareStatement("UPDATE customer SET custAddress=? WHERE CustID=?");
    db.stmt->setString(1, custAddress);
    db.stmt->setInt(2, CustID);
    db.QueryStatement();
}

void Customer::updateCustPhoneNumber() {
    DBConnection db;
    db.prepareStatement("UPDATE customer SET custPhoneNumber=? WHERE CustID=?");
    db.stmt->setString(1, custPhoneNumber);
    db.stmt->setInt(2, CustID);
    db.QueryStatement();
}

vector<Customer> Customer::searchCustomer(string custName, string custPhoneNumber, bool ascending) {
    string query = "SELECT * FROM customer WHERE custName LIKE ? AND custPhoneNumber LIKE ? ORDER BY CustID ";
    query += ascending ? "ASC" : "DESC";

    DBConnection db;
    db.prepareStatement(query);
    db.stmt->setString(1, "%" + custName + "%");
    db.stmt->setString(2, "%" + custPhoneNumber + "%");

    vector<Customer> customers;
    db.QueryResult();

    while (db.res->next()) {
        Customer tmpCustomer(db.res);
        customers.push_back(tmpCustomer);
    }
    return customers;
}

Customer::Customer(sql::ResultSet* data) {
    CustID = data->getInt("CustID");
    custName = data->getString("custName");
    custAge = data->getString("custAge");
    custEmail = data->getString("custEmail");
    custAddress = data->getString("custAddress");
    custGender = data->getString("custGender");
    custPhoneNumber = data->getString("custPhoneNumber");
}

void Customer::deleteCust() {
    DBConnection db;
    db.prepareStatement("DELETE FROM customer WHERE CustID=?");
    db.stmt->setInt(1, CustID);
    db.QueryStatement();
}

Customer::~Customer() {}
