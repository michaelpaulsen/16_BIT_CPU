#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <regex> 


#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "CPU.h" 
#include "utils.h"
class Parser
{
public: 
	CPU cpu = CPU(); 
private:

	std::regex parseIntCmd    = std::regex("([A-Z]*)([\\s@])([-+])(\\d\\d*)$");
	std::regex parseRegCmd    = std::regex("([A-Z]*)\\s([AXYZ])$");
	std::regex parseIntIntCmd = std::regex("([A-Z]*)([\\s@])([-+])(\\d\\d*)[, ]([-+])(\\d\\d*)$");
	std::regex parseRegIntCmd = std::regex("([A-Z]*)\\s([AXYZ])[, ]([-+])(\\d\\d*)$");
	std::regex parseRegRegCmd = std::regex("([A-Z]*)\\s([AXYZ])[, ]([AXYZ])$");
	std::ifstream document;
	char* line; 
public: 



	void Run() {
		std::string ln = "";
		std::smatch cmdData;
		std::string cmdname = ""; 
		while (std::getline(document, ln)) { // while there's data to read 
			if (ln[0] == ';') { // if the first char is ; continue as it is a comment
				continue; 
			}
			//std::regex_match(ln, data, getCmd);
			if (std::regex_match(ln, cmdData, parseIntCmd)) { //if the line is a single int line 
				cmdname = cmdData[0];
				if (cmdname == "LDA") {
					if (cmdData[3] >M_INT) {
						cpu.HLT(2);
						break;
					}
					cpu.LDA(utils::stringToInt(cmdData[3]));
					
				}
			}

		}


	}
	Parser(const char* fileName) {
		this->document = std::ifstream(fileName);
	}

};

