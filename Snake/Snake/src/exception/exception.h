#pragma once
#include <string>

class Exception
{
private:
	std::string nameExp, msgExp;

protected:
	Exception(std::string name, std::string msg) : nameExp(name), msgExp(msg) {}

public:
	std::string getName();
	std::string getMessage();

};