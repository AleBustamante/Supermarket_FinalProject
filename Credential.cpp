#include "Credential.h"

string Credential::encryptedString(const string& unencrypted) {
	string encrypted;
	char buffer;
	for (int i = 0; i < unencrypted.size(); i++) {
		buffer = (unencrypted[i] * ENCRYPTION_KEY) % 255;
		encrypted += buffer;
	}
	return encrypted;
}

Credential::Credential(const string& hashedPassword, const WorkerType& workerType, bool privileges){
	this->hashedPassword = hashedPassword;
	this->workerType = workerType;
	this->hasPriviliges = privileges;
}


void Credential::setWokerType(const WorkerType& workerType){
	this->workerType = workerType;
}

void Credential::setHashedPassword(const string& hashedPassword){
	this->hashedPassword = hashedPassword;
}

void Credential::setPriviliges(const bool& hasPriviliges){
	this->hasPriviliges = hasPriviliges;
}

string Credential::getHashedPassword(){	
	return hashedPassword;
}

WorkerType Credential::getWorkerType(){
	return workerType;
}

bool Credential::getHasPriviliges(){
	return hasPriviliges;
}

bool Credential::isPassCorrect(const string& triedPass){
	return triedPass == hashedPassword;
	//return encryptedString(triedPass) == hashedPassword;
}
