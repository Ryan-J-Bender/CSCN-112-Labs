#include <iostream> // Input and output to terminal
#include "House.h" // Includes house header file
#include <iomanip> // Getline, setw, left & right, etc.
#include <fstream> // Input/output to file

std::ofstream ofile;

House::House() { // Default constructor

	houseRooms;
}

House::House(std::vector<Room> hRooms) { // 1 argument constructor

	houseRooms = hRooms;
}

void House::showRooms(std::string n, int m, float d) const { // Displays current info and each room


	std::cout << "________________________________________" << std::endl;
	std::cout << " Client Name:   " << n << std::endl;
	std::cout << " Max Rooms:     " << m << std::endl;
	std::cout << " Distance:      " << d << std::endl;
	std::cout << " Current Rooms: " << houseRooms.size() << std::endl;
	std::cout << "________________________________________" << std::endl << std::endl;

	std::cout << "____________________________________________________________________________________________________" << std::endl;
	std::cout << std::setw(56) << std::right << "House Rooms" << std::endl;
	std::cout << std::setw(56) << std::right << "-----------" << std::endl << std::endl;
	std::cout << std::left << "Room #" << std::setw(20) << std::right << "# of Coats" << std::setw(27) << "Number of Gallons"
		<< std::setw(16) << "Length" << std::setw(15) << "Width" << std::setw(16) << "Height" << std::endl;

	for (int i = 0; i < houseRooms.size(); i++) {

		std::cout << std::left << i+1 << std::right << std::setw(25) << houseRooms.at(i).getCoats() << std::setw(27) << std::right << houseRooms.at(i).paintGallons() << std::right
		<< std::setw(16) << houseRooms.at(i).getLength() << std::right << std::setw(15) << houseRooms.at(i).getWidth()<< std::right << std::setw(16) << std::right << houseRooms.at(i).getHeight() << std::endl;
	}

	std::cout << "____________________________________________________________________________________________________" << std::endl;
}

void House::addRoom(float l, float w, float h, int c) { // Adds a room object to the vector

	houseRooms.push_back(Room(l, w, h, c));
}

int House::totalCoats() const { // Calculates total number of coats for a room

	int coatnum = 0;

	for (int i = 0; i < houseRooms.size(); i++) {

		coatnum += houseRooms.at(i).getCoats();
	}
	return coatnum;
}

void House::printInvoice(std::string n) const { // Prints out invoice with all information and costs

	double total = totalCoats() * hrRate;

	std::cout << "_______________________________________________________________________________" << std::endl;
	std::cout << std::setw(39 + (n.length() / 2) - 1) << std::right << n << std::endl;
	std::cout << std::setw(45) << std::right << "Final Invoice" << std::endl;
	std::cout << "_______________________________________________________________________________" << std::endl;
	
	std::cout << std::endl << "WePaintHousesLLC" << std::endl;
	std::cout << "Schmetterling Rd" << std::endl;
	std::cout << "Butterfly, PA 15552" << std::endl;
	std::cout << "(814)-867-5309" << std::endl;
	std::cout << "paintyourhouse.com" << std::endl;

	std::cout << "Billed to:  " << n << std::endl;


	std::cout << "_______________________________________________________________________________" << std::endl;
	std::cout << std::setw(44) << std::right << "Labor Costs" << std::endl;
	std::cout << std::setw(44) << std::right << "___________" << std::endl << std::endl;
	std::cout << std::left << "Rooms " << std::setw(20) << std::right << "# of Coats" << std::setw(27) << "Hourly Rate"
		<< std::setw(22) << "Total" << std::endl;

	std::cout << std::left << houseRooms.size() << std::setw(25) << std::right << totalCoats() << std::setw(27) << std::fixed << std::setprecision(2) << hrRate << std::setw(22) << total << std::endl;

	std::cout << "_______________________________________________________________________________" << std::endl;
	std::cout << std::setw(46) << std::right << "Product Charges" << std::endl;
	std::cout << std::setw(46) << std::right << "_______________" << std::endl << std::endl;
	std::cout << std::left << "Room $" << std::setw(20) << std::right << "Paint Cans" << std::setw(27) << "Unit Cost"
		<< std::setw(22) << "Ammount" << std::endl;

	for (int i = 0; i < houseRooms.size(); i++) {

		std::cout << std::left << i + 1 << std::fixed << std::setprecision(2) << std::right << std::setw(25) << houseRooms.at(i).paintGallons() << std::setw(27) << std::right << ppg << std::setw(22) << std::right << houseRooms.at(i).paintGallons() * ppg << std::endl;
	}

	std::cout << "_______________________________________________________________________________" << std::endl;
}

void House::printInvoiceToFile(std::string n) const { // Prints out invoice with info and costs to a file and checks for file opening/closing

	double total = totalCoats() * hrRate;

	ofile.open(n.append(".txt"));

	if (ofile.is_open()) {

		ofile << "_______________________________________________________________________________" << std::endl;
		ofile << std::setw(39 + (n.length() / 2) - 1) << std::right << n << std::endl;
		ofile << std::setw(45) << std::right << "Final Invoice" << std::endl;
		ofile << "_______________________________________________________________________________" << std::endl;

		ofile << std::endl << "WePaintHousesLLC" << std::endl;
		ofile << "Schmetterling Rd" << std::endl;
		ofile << "Butterfly, PA 15552" << std::endl;
		ofile << "(814)-867-5309" << std::endl;
		ofile << "paintyourhouse.com" << std::endl;

		ofile << "Billed to:  " << n << std::endl;


		ofile << "_______________________________________________________________________________" << std::endl;
		ofile << std::setw(44) << std::right << "Labor Costs" << std::endl;
		ofile << std::setw(44) << std::right << "___________" << std::endl << std::endl;
		ofile << std::left << "Rooms " << std::setw(20) << std::right << "# of Coats" << std::setw(27) << "Hourly Rate"
			<< std::setw(22) << "Total" << std::endl;

		ofile << std::left << houseRooms.size() << std::setw(25) << std::right << totalCoats() << std::setw(27) << std::fixed << std::setprecision(2) << hrRate << std::setw(22) << total << std::endl;

		ofile << "_______________________________________________________________________________" << std::endl;
		ofile << std::setw(46) << std::right << "Product Charges" << std::endl;
		ofile << std::setw(46) << std::right << "_______________" << std::endl << std::endl;
		ofile << std::left << "Room $" << std::setw(20) << std::right << "Paint Cans" << std::setw(27) << "Unit Cost"
			<< std::setw(22) << "Ammount" << std::endl;

		for (int i = 0; i < houseRooms.size(); i++) {

			ofile << std::left << i + 1 << std::fixed << std::setprecision(2) << std::right << std::setw(25) << houseRooms.at(i).paintGallons() << std::setw(27) << std::right << ppg << std::setw(22) << std::right << houseRooms.at(i).paintGallons() * ppg << std::endl;
		}

		ofile << "_______________________________________________________________________________" << std::endl;

		std::cout << "Your invoice has been successfully printed to " << n.append(".txt") << std::endl;
	}
	else {

		std::cout << "Error Opening File." << std::endl;
	}

	ofile.close();

	if (ofile.is_open())
		std::cout << "Error Closing File." << std::endl;

}