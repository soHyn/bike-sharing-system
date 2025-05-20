class RentBike {
public:
	void searchBike() { findBike(); showSearchedBike(); }
	void rentBike() { getUserIdFromSession(); assignBike(); showResult();  }
};