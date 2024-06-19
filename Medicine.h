#pragma once
#ifndef MEDICINE_H
#define MEDICINE_H
#include <string>

class Medicine
{
public:
	std::string header, footer, bullet;
	int MedID;
	std::string medName, medQuantity, medType, medPrice, medManufacture;

	Medicine(); //constructor method
	Medicine(int MedID, std::string medName, std::string medQuantity, std::string medType, std::string medPrice, std::string medManufacture);
	/*bool login();*/
	void insertMed();
	void updateMed();
	static std::vector<Medicine> searchMed(std::string medName, bool ascending);
	Medicine(sql::ResultSet* data);
	void deleteMed();

	~Medicine();
};

#endif

