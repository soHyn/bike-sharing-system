#include <string>
#include <vector>
using namespace std;

enum Role {ADMIN, MEMBER, GUEST};
class User {
private:
	string userId;
	string password;
	string phoneNum;
	Role role;
	vector<Bike> bikes;
	//setter


public:
	User(const String& userId, const String& password, const String& phoneNum, Role role) {
		this->userId = userId;
		this->password = password;
		this->phoneNum = phoneNum;
		this.role = role;
	}
	~User() {}
	void checkAdmin(String userId) {}
	User createUser() {}
	void authenticateUser() {} 
	void assignBike() {}
	List<object> getBikeInfosByUserId() { while (1) { getBikeInfo(); } }
}