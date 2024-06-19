#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

#include "Admin.h"
#include "Menu.h"
#include "Customer.h"
#include "Medicine.h"
#include "Report.h"

using namespace std;

void loginAdmin();
void roleMenu();
void loginCustomer();
void customer(Admin user, Customer cust);
void homeCust(Customer cust, Medicine med);
void custM(Admin user, Customer cust);
void custDel(Admin user, Customer cust);
void medM(Admin user, Medicine med);
void medicine(Admin user, Medicine med);
void medDel(Admin user, Medicine med);
void report();
void home(Admin user, Customer cust);


int listCust(Admin user);
int listMed(Admin user);

int main() {
	
	Menu mainmenu;
	mainmenu.header = "----------Welcome to Pharmacy Management System----------";
	mainmenu.addOption("Login");
	mainmenu.addOption("Exit");

	while (1) {
		switch (mainmenu.prompt())
		{
		case 1: 
			roleMenu();
			break;
		case 2:
			return 0;
		default:
			break;
		}
	}
}

void roleMenu() {
	Menu roleMenu;
	roleMenu.header = "--------Please Choose Role---------";
	roleMenu.addOption("Login as admin");
	roleMenu.addOption("Login as customer");
	roleMenu.addOption("Back");

	while (1) {
		switch (roleMenu.prompt())
		{
		case 1:
			loginAdmin();
			break;
		case 2:
			loginCustomer();
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}
}

void loginCustomer() {
	Menu custMenu;
	custMenu.header = "----------LOGIN----------";
	custMenu.addOption("Username");
	custMenu.addOption("Password");
	custMenu.addOption("Login");
	custMenu.addOption("Back");

	Customer cust;
	Medicine med;

	while (1) {
		switch (custMenu.prompt())
		{
		case 1:
			cout << "Insert Username:";
			cin >> cust.custName;
			custMenu.setValue(0, cust.custName);
			break;
		case 2:
			cout << "Insert Password:";
			cin >> cust.password;
			custMenu.setValue(1, cust.password);
			break;
		case 3:
			if (cust.login()) {
				homeCust(cust, med);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}

void homeCust(Customer cust, Medicine med)
{
	Menu homeCust;
	homeCust.addOption("Medicine");
	homeCust.addOption("Back");

	while (1) {
		homeCust.header = "Welcome " + cust.custName;
		switch (homeCust.prompt())
		{
		case 1:
			medM(cust, med);
			break;
		case 2:
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}
}

void loginAdmin() {
	Menu loginAdmin;
	loginAdmin.header = "----------LOGIN----------";
	loginAdmin.addOption("Username");
	loginAdmin.addOption("Password");
	loginAdmin.addOption("Login");
	loginAdmin.addOption("Back");

	Admin user;
	Customer cust;
	while (1) {
		switch (loginAdmin.prompt())
		{
		case 1:
			cout << "Insert Username:";
			cin >> user.username;
			loginAdmin.setValue(0, user.username);
			break;
		case 2:
			cout << "Insert Password:";
			cin >> user.password;
			loginAdmin.setValue(1, user.password);
			break;
		case 3:
			if (user.login()) {
				home(user, cust);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}

void home(Admin user, Customer cust, Medicine med) {
	Menu homeMenu;
	homeMenu.addOption("Customer");
	homeMenu.addOption("Medicine");
	homeMenu.addOption("Report");
	homeMenu.addOption("Back");

	while (1) {
		homeMenu.header = "Welcome " + user.username;
		switch (homeMenu.prompt())
		{
		case 1:
			custM(user, cust);
			break;
		case 2:
			medicine(user, med);
			break;
		case 3:
			//report();
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}

void custM(Admin user, Customer cust) {
	Menu custHome;
	/*customer custMenu;*/
	custHome.header = "\t\t ----------- ** CUSTOMER ** ----------- \t\t";
	custHome.addOption("\t\tAdd customer");
	custHome.addOption("\t\tList customer");
	custHome.addOption("\t\tBack");

	while (1) {
		switch (custHome.prompt())
		{
		case 1:
			customer(user, cust);
			break;
		case 2:
			listCust(user);
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}
}

void customer(Admin user, Customer cust)  {
	Customer newacc;
	Menu custMenu;
	custMenu.header = "\n\n\t ---------- Registration Customer ----------\t\n\n";
	custMenu.addOption("\t\tCustomer name:");
	custMenu.addOption("\t\tAge:");
	custMenu.addOption("\t\tEmail:");
	custMenu.addOption("\t\tAddress:");
	custMenu.addOption("\t\tGender:");
	custMenu.addOption("\t\tPhone number:");
	custMenu.addOption("\t\tPassword:");
	custMenu.addOption("\t\tRegister");
	custMenu.addOption("\t\tBack");

	string tmpinput;
	char tmpinput1;
	bool valid = true;

	while (1) {
		switch (custMenu.prompt())
		{
		case 1:
			cout << "Insert Name:";
			getline(cin, newacc.custName);
			custMenu.setValue(0, newacc.custName);
			break;
		case 2:
			cout << "Age:";
			getline(cin, newacc.custAge);
			custMenu.setValue(1, newacc.custAge);
			break;
		case 3:
			cout << "Email:";
			cin >> newacc.custEmail;
			custMenu.setValue(2, newacc.custEmail);
			break;
		case 4:
			cout << "Address:";
			getline(cin, newacc.custAddress);
			custMenu.setValue(3, newacc.custAddress);
			break;
		case 5:
			cout << "Gender:";
			cin >> newacc.custGender;
			custMenu.setValue(4, newacc.custGender);
			break;
		case 6:
			cout << "Phone number:";
			cin >> newacc.custPhoneNumber;
			custMenu.setValue(5, newacc.custPhoneNumber);
			break;
		case 7:
			cout << "Password:";
			cin >> newacc.password;
			custMenu.setValue(6, newacc.password);
			break;
		case 8:
			cust = newacc;
			newacc.insertCust();
			cout << "Successfully registered";
			_getch;
			break;
		case 9:
			return;
		default:
			break;
		}
	}
}


int listCust(Admin user) {
	vector<Customer> customers;
	Customer searchC;
	string displayC = "";
	Customer cust;

	string custName = "", custPhoneNumber = "", custEmail = "", custAddress = "";
	bool asc = true;

	Menu searchCust;
	searchCust.header = "\n\n\t\tList of customers\n";
	searchCust.addOption(" View By Customer Name: ");
	searchCust.addOption(" View By Customer Phone Number: ");
	searchCust.addOption(" Toggle Sort Order (Ascending/Descending): ");
	searchCust.addOption(" Update Customer's Address: ");
	searchCust.addOption(" Update Customer's Phone Number: ");
	searchCust.addOption(" Back");
	searchCust.addOption(" Delete Customer");

	while (true) {
		searchCust.setValue(2, asc ? "Ascending" : "Descending");

		if (displayC.empty()) {
			displayC = "\n\tResult:\n\n";
			stringstream tmpCustomer;

			tmpCustomer << setw(10) << "Customer ID  | "
				<< setw(36) << "Customer Name    | "
				<< setw(16) << "Customer Email   | "
				<< setw(26) << "Customer Address    | "
				<< setw(26) << "Customer Phone Number   |\n";

			for (const auto& customer : customers) {
				tmpCustomer << setw(10) << customer.CustID << "  |"
					<< setw(35) << customer.custName << "  |"
					<< setw(16) << customer.custEmail << "  |"
					<< setw(25) << customer.custAddress << "  |"
					<< setw(25) << customer.custPhoneNumber << "  |\n";
			}
			displayC += tmpCustomer.str();
		}
		searchCust.footer = displayC;

		switch (searchCust.prompt()) {
		case 1:
			cout << "Insert Customer Name: ";
			cin.ignore();
			getline(cin, custName);
			searchCust.setValue(0, custName);
			customers = Customer::searchCustomer(custName, "", asc);
			displayC.clear();
			break;
		case 2:
			cout << "Insert Customer Phone number: ";
			cin.ignore();
			getline(cin, custPhoneNumber);
			searchCust.setValue(1, custPhoneNumber);
			customers = Customer::searchCustomer("", custPhoneNumber, asc);
			displayC.clear();
			break;
		case 3:
			asc = !asc;
			customers = Customer::searchCustomer("", "", asc);
			displayC.clear();
			break;
		case 4:
			cout << "Insert Customer ID: ";
			cin >> searchC.CustID;
			cin.ignore();
			cout << "Insert new Address: ";
			getline(cin, searchC.custAddress);
			searchC.updateCustAddress();
			customers = Customer::searchCustomer("", "", asc); // Refresh customer list
			displayC.clear();
			break;
		case 5:
			cout << "Insert Customer ID: ";
			cin >> searchC.CustID;
			cin.ignore();
			cout << "Insert new Phone Number: ";
			getline(cin, searchC.custPhoneNumber);
			searchC.updateCustPhoneNumber();
			customers = Customer::searchCustomer("", "", asc); // Refresh customer list
			displayC.clear();
			break;
		case 6:
			return 0; // Exit the loop and function
		case 7:
			cout << "Insert Customer ID to delete account: ";
			cin >> searchC.CustID;
			searchC.deleteCust();
			customers = Customer::searchCustomer("", "", asc); // Refresh customer list
			displayC.clear();
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}
	return 0;
}

void custDel(Admin user, Customer cust)
{
	Menu deleteC;
	char confirm;

	deleteC.header = "\n\n\t -------------------- DELETE CUSTOMER -------------------- \n\n";

	cout << "\n\n\tAre you sure want to delete customer details? (y/n)\n\n";
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'Y')
	{
		cust.deleteCust();
		cout << "\n\n\t Your customer account deleted.";
		_getch();
		customer(user, cust);
	}
	else
	{
		cout << "\n\n\t Your customer details saved. \n\n\t Press any key to continue. ";
		_getch();
		customer(user, cust);
	}
}

//void customerUp(Admin user, Customer cust) {
//	Customer temp = cust;
//	Customer newUpdate;
//	Menu custUp;
//	custUp.header = "\n\n\t ---------- Update profile customer ----------\n\n\t ";
//	custUp.addOption("Customer ID: ");
//	custUp.addOption("Customer name: ");
//	custUp.addOption("Age: ");
//	custUp.addOption("Email: ");
//	custUp.addOption("Address: ");
//	custUp.addOption("Gender: ");
//	custUp.addOption("Phone number: ");
//	custUp.addOption("Save");
//	custUp.addOption("Back");
//
//	char confirm;
//	string tmpImput;
//	while (1) {
//		custUp.setValue(0, to_string(temp.CustID));
//		custUp.setValue(1, temp.custName);
//		custUp.setValue(2, temp.custAge);
//		custUp.setValue(3, temp.custEmail);
//		custUp.setValue(4, temp.custAddress);
//		custUp.setValue(5, temp.custGender);
//		custUp.setValue(6, temp.custPhoneNumber);
//
//		switch (custUp.prompt())
//		{
//		case 1:
//			cout << "\n\nID cannot change.";
//			_getch();
//			break;
//		case 2:
//			cout << "Insert Full name ";
//			getline(cin, temp.custName);
//			break;
//		case 3:
//			cout << "Insert age ";
//			getline(cin, temp.custAge);
//			break;
//		case 4:
//			cout << "Insert new Email ";
//			cin >> temp.custEmail;
//			break;
//		case 5:
//			cout << "Insert new address ";
//			cin >> temp.custAddress;
//			break;
//		case 6:
//			cout << "Insert gender ";
//			cin >> temp.custGender;
//			break;
//		case 7:
//			cout << "Insert new phone number ";
//			cin >> temp.custPhoneNumber;
//			break;
//		case 8:
//			cout << "\n\n\ Update customer profile? (y/n)";
//			char confirm;
//			confirm = _getch();
//			if (confirm == 'Y' || confirm == 'y') {
//				cust = temp;
//				cust.updateCust();
//				cout << "\n\n\tInformation updated";
//				_getch();
//			}
//			break;
//		case 9:
//			return;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//}

void medM(Admin user, Medicine med) {
	Menu medHome;
	medHome.header = "\t\t ----------- ** MEDICINE ** ----------- \N";
	medHome.addOption("\t\t Add Medicine");
	medHome.addOption("\t\t List Medicine");
	medHome.addOption("\t\t Delete Medicine");

	while (1) {
		switch (medHome.prompt())
		{
		case 1:
			medicine(user, med);
			break;
		case 2:
			listMed(user);
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}

}


void medicine(Admin user, Medicine med)
{
	Medicine newmed;
	Menu menuMed;
	menuMed.header = "\t\t ---------- ** MEDICINE MENU ** ---------- \n";
	menuMed.addOption("\t\tMedicine name: ");
	menuMed.addOption("\t\tMedicine quantity: ");
	menuMed.addOption("\t\tMedicine type: ");
	menuMed.addOption("\t\tMedicine price: ");
	menuMed.addOption("\t\tMedicine manufacture: ");
	menuMed.addOption("\t\tAdd medicine");
	menuMed.addOption("\t\tBack");

	string tmpinputmed;
	char tmpinput2;
	bool valid = true;

	while (1) {
		switch (menuMed.prompt())
		{
		case 1:
			cout << "Insert Medicine Name:";
			getline(cin, newmed.medName);
			menuMed.setValue(0, newmed.medName);
			break;
		case 2:
			cout << "Insert Medicine Quantity:";
			getline(cin, newmed.medQuantity);
			menuMed.setValue(1, newmed.medQuantity);
			break;
		case 3:
			cout << "Insert Medicine Type:";
			cin >> newmed.medType;
			menuMed.setValue(2, newmed.medType);
			break;
		case 4:
			cout << "Insert Medicine Price:";
			getline(cin, newmed.medPrice);
			menuMed.setValue(3, newmed.medPrice);
			break;
		case 5:
			cout << "Medicine Manufacturer:";
			cin >> newmed.medManufacture;
			menuMed.setValue(4, newmed.medManufacture);
			break;
		case 6:
			med = newmed;
			newmed.insertMed();
			cout << "Successfully add medicine";
			_getch;
			break;
		case 7:
			return;
		default:
			break;
		}
	}
}

void medDel(Admin user, Medicine med)
{
	Menu deleteM;
	char confirm;

	deleteM.header = "\n\n\t -------------------- DELETE MEDICINE -------------------- \n\n";

	cout << "\n\n\tAre you sure want to delete medicine details? (y/n)\n\n";
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'Y')
	{
		med.deleteMed();
		cout << "\n\n\t Your medicine details deleted.";
		_getch();
		medicine(user, med);
	}
	else
	{
		cout << "\n\n\t Your medicine details saved. \n\n\t Press any key to continue. ";
		_getch();
		medicine(user, med);
	}
}

int listMed(Admin user)
{
	vector<Medicine> medicines;
	Medicine searchM;
	string displayM = "";

	int MedID = 0;
	string medName = "", medQuantity = "", medType = "", medManufacture = "";
	bool asc = true;

	Menu searchMed;
	searchMed.header = "\n\n\t\t------ List of medicine ------\t\t\n";
	searchMed.addOption("\t\tView By Medicine Name");
	searchMed.addOption("\t\tView By ");
	searchMed.addOption("\t\tView All List Medicine: ");
	searchMed.addOption("\t\tUpdate : ");
	searchMed.addOption("\t\tUpdate : ");
	searchMed.addOption("\t\tBack");
	searchMed.addOption("\t\tDelete Medicine details");

	while (1)
	{
		if (asc)
		{
			searchMed.setValue(2, "Ascending");
		}
		else
		{
			searchMed.setValue(2, "Descending");
		}
		if (displayM == "")
		{
			displayM = "\n\tResult:\n\n";
			stringstream tmpMedicine;

			tmpMedicine << setw(10) << "\tMedicine ID  | " << setw(36) << "\tMedicine Name    | " << setw(16) << "\tMedicine Quantity   | " << setw(26) << "\tMedicine Type    | " << setw(26) << "\tMedicine Price   | " << "\n "
				<< endl;
			for (int i = 0; i < medicines.size(); i++)
			{
				tmpMedicine << setw(10) << medicines[i].MedID << "\t  |" << setw(35) << medicines[i].medName << "\t  |" << setw(16) << medicines[i].medQuantity << "\t|" << setw(25) << medicines[i].medType << "\t |" << setw(25) << medicines[i].medPrice << "\t |" << endl;
			}
			displayM += tmpMedicine.str();
		}
		searchM.footer = displayM;

		switch (searchMed.prompt())
		{
		case 1:
			cout << " Insert Medicine Name: ";

		}
	}

}


