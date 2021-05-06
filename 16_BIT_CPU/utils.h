#pragma once
#include <string>
namespace utils {
	static int pow(int base, int power) {
		int ret = 1; 
		for (int x = 1; x <= power; x++) {
			ret *= base; 
		}
		return ret;
	}
	static int charToInt(char x) {
		return (x - '0'); 

	}
	static int stringToInt(const char* str) {
		int temp = sizeof(str) / sizeof(char); 
		int ret = 0; 
		for (int x = 0; x < sizeof(str) / sizeof(char); x++) {
			ret += utils::charToInt(str[x]) * pow(10, temp);
			temp--; 

		}
		return ret;
	}
	static int stringToInt(char* str) {
		int temp = sizeof(str) / sizeof(char);
		int ret = 0;
		for (int x = 0; x < sizeof(str) / sizeof(char); x++) {
			ret += utils::charToInt(str[x]) * pow(10, temp);
			temp--;

		}
		return ret;
	}
	static int stringToInt(std::string str) {
		int temp = str.length()
		int ret = 0;
		for (int x = 0; x < str.length(); x++) {
			ret += utils::charToInt(str[x]) * pow(10, temp);
			temp--;

		}
		return ret;
	}
	
};