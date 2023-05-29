#pragma once
#include <string>

using namespace std;

constexpr int ENCRYPTION_KEY = 8;

enum WorkerType{
	unasigned,
	cashier,
	warehouse,
	management
};


class Credential{
public:
	WorkerType workerType;
	string hashedPassword;
	bool hasPriviliges;


	string encryptedString(const string& unencrypted);


	Credential(const string& hashedPassword = "pass", const WorkerType& workerType = WorkerType::unasigned, bool privileges = false);
	
	
	void setWokerType(const WorkerType& workerType);
	void setHashedPassword(const string& hashedPassword);
	void setPriviliges(const bool& hasPriviliges);


	string getHashedPassword();
	WorkerType getWorkerType();
	bool getHasPriviliges();


	 bool isPassCorrect(const string& triedPass);

};

