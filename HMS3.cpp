#include <bits/stdc++.h>
using namespace std;

class Hospital {
public:
	string H_name;
	string location;
	int available_beds;
	float rating;
	string contact;
	string doctor_name;
	int price;
};

class Patient : public Hospital {
public:
	string P_name;
	int P_id;
};

void PrintHospitalData(
	vector<Hospital>& hospitals)
{
	cout << "PRINT hospitals DATA:"
		<< endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {
		cout << hospitals[i].H_name
			<< "				 "
			<< "	 "
			<< hospitals[i].location
			<< "		 "
			<< hospitals[i].available_beds
			<< "				 "
			<< hospitals[i].rating
			<< "		 "
			<< hospitals[i].contact
			<< "			 "
			<< hospitals[i].doctor_name
			<< "				 "
			<< "	 "
			<< hospitals[i].price
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

void PrintPatientData(
	vector<Patient>& patients,
	vector<Hospital>& hospitals)
{
	cout << "PRINT patients DATA:"
		<< endl;
	cout << "Patient_Name	 "
		<< "Patient_Id	 "
		<< "Patient_Contact	 "
		<< "Alloted_Hospital	 "
		<< "Patient_Expenditure	 \n";

	for (int i = 0; i < 4; i++) {
		cout << patients[i].P_name
			<< "			 "
			<< "		 "
			<< patients[i].P_id
			<< "			 "
			<< "		 "
			<< patients[i].contact
			<< "				 "
			<< hospitals[i].H_name
			<< "				 "
			<< patients[i].price
			<< "		 "
			<< endl;
	}

	cout << endl
		<< endl;
}

bool name(Hospital& A, Hospital& B)
{
	return A.H_name > B.H_name;
}

void SortHospitalByName(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		name);

	cout << "SORT BY NAME:"
		<< endl
		<< endl;
	PrintHospitalData(hospitals);
}

bool rating(Hospital& A, Hospital& B)
{
	return A.rating > B.rating;
}

void SortHospitalByRating(vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		rating);

	cout << "SORT BY Rating:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

bool beds(Hospital& A, Hospital& B)
{
	return A.available_beds > B.available_beds;
}

void SortByBedsAvailable(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds);

	cout << "SORT BY Available Beds:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

bool beds_price(Hospital& A, Hospital& B)
{
	return A.price < B.price;
}

void SortByBedsPrice(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds_price);

	cout << "SORT BY Available Beds Price:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

void PrintHospitalBycity(
	string city, vector<Hospital> hospitals)
{
	cout << "PRINT hospitals by Name :"
		<< city << endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {

		if (hospitals[i].location != city)
			continue;
		cout << hospitals[i].H_name
			<< "				 "
			<< "	 "
			<< hospitals[i].location
			<< "		 "
			<< hospitals[i].available_beds
			<< "				 "
			<< hospitals[i].rating
			<< "		 "
			<< hospitals[i].contact
			<< "			 "
			<< hospitals[i].doctor_name
			<< "			 "
			<< "		 "
			<< hospitals[i].price
			<< "		 "
			<< endl;
	}
	cout << endl
		<< endl;
}

void HospitalManagement(
	string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[],
	string hospital_Name[], string locations[], int beds[],
	float ratings[], string hospital_Contact[],
	string doctor_Name[], int prices[])
{

	vector<Hospital> hospitals;

	Hospital h;

	for (int i = 0; i < 4; i++) {
		h.H_name = hospital_Name[i];
		h.location = locations[i];
		h.available_beds = beds[i];
		h.rating = ratings[i];
		h.contact = hospital_Contact[i];
		h.doctor_name = doctor_Name[i];
		h.price = prices[i];
		hospitals.push_back(h);
	}

	vector<Patient> patients;
	Patient p;
	for (int i = 0; i < 4; i++) {
		p.P_name = patient_Name[i];
		p.P_id = patient_Id[i];
		p.contact = patient_Contact[i];
		p.price = bookingCost[i];
		patients.push_back(p);
	}

	cout << endl;

	PrintHospitalData(hospitals);
	PrintPatientData(patients, hospitals);

	SortHospitalByName(hospitals);
	SortHospitalByRating(hospitals);
	PrintHospitalBycity("Bangalore", hospitals);
	SortByBedsAvailable(hospitals);
	SortByBedsPrice(hospitals);
}

int main()
{
	string patient_Name[] = { "P1", "P2", "P3", "P4" };
	int patient_Id[] = { 2, 3, 4, 1 };
	string patient_Contact[]
		= { "234534XXX7", "234576XXX2", "857465XXX9","567657XXX0" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };
	string hospital_Name[] = { "H1", "H2", "H4", "H3" };
	string locations[] = { "Bangalore", "Bangalore","Mumbai ", "Prayagraj" };
	int beds[] = { 4, 5, 6, 9 };
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[]
		= { "657534XXX7", "298766XXX2", "324565XXX9","343456XXX4" };
	string doctor_Name[] = { "D1", "D4", "D3", "D2" };
	int prices[] = { 100, 200, 100, 290 };

	HospitalManagement(
		patient_Name, patient_Id, patient_Contact,
		bookingCost, hospital_Name, locations, beds,
		ratings, hospital_Contact, doctor_Name, prices);

	return 0;
}

