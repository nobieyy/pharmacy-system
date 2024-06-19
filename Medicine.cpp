#include "Medicine.h"
#include <ctime>
#include "DBConnection.h"
#include <vector>

using namespace std;

Medicine::Medicine()
{
	MedID = 0;
	medName = "";
	medQuantity = "";
	medType = "";
	medPrice = "";
	medManufacture = "";
}

Medicine::Medicine(int MedID, std::string medName, std::string medQuantity, std::string medType, std::string medPrice, std::string medManufacture)
{
	this->MedID = MedID;
	this->medName = medName;
	this->medQuantity = medQuantity;
	this->medType = medType;
	this->medPrice = medPrice ;
	this->medManufacture = medManufacture;
}

void Medicine::insertMed() {

	DBConnection db;
	db.prepareStatement("INSERT into medicine (medName,medQuantity,medType,medPrice,medManufacture) VALUES (?,?,?,?,?)");
	db.stmt->setString(1, medName);
	db.stmt->setString(2, medQuantity);
	db.stmt->setString(3, medType);
	db.stmt->setString(4, medPrice);
	db.stmt->setString(5, medManufacture);

	db.QueryStatement();
	db.~DBConnection();
}

void Medicine::updateMed() {

	DBConnection db;
	db.prepareStatement("UPDATE medicine SET medName=?,medQuantity=?,medType=?,medPrice=?,medManufacture=?,WHERE MedID=?");
	db.stmt->setString(1, medName);
	db.stmt->setString(2, medQuantity);
	db.stmt->setString(3, medType);
	db.stmt->setString(4, medPrice);
	db.stmt->setString(5, medManufacture);
	db.stmt->setInt(0, MedID);

	db.QueryStatement();
	db.~DBConnection();
}

void Medicine::deleteMed()
{
	DBConnection db;
	db.prepareStatement("delete from account where userid=?");
	db.stmt->setInt(0, MedID);
	db.QueryStatement();
	db.~DBConnection();
}


vector<Medicine> Medicine::searchMed(string medName, bool ascending)
{
	string query = "SELECT * FROM medicine WHERE"
		" medName LIKE ? "
		" ORDER BY MedID ";
	if (ascending)
	{
		query += " ASC";
	}
	else
	{
		query += " DESC";
	}

	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setString(1, "%" + medName + "%");

	vector<Medicine> medicines;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{
		while (db.res->next())
		{
			Medicine tmpMedicine(db.res);
			medicines.push_back(tmpMedicine);
		}
	}
	return medicines;
}