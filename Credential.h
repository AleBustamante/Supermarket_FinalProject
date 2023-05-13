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
	int identifier;
	WorkerType workerType;
	string hashedPassword;
	bool hasPriviliges;


	static string encryptedString(const string& unencrypted);


public:
	Credential(int identifier = -1,  const string& hashedPassword = "pass", const WorkerType& workerType = WorkerType::unasigned, bool privileges = false);
	
	
	void setIdentifier(const int& identifier);
	void setWokerType(const WorkerType& workerType);
	void setHashedPassword(const string& hashedPassword);
	void setPriviliges(const bool& hasPriviliges);


	string getHashedPassword();
	WorkerType getWorkerType();


	static bool isPassCorrect(const string& triedPass);

};

