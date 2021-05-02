#pragma once
#include "Register.h" 
#include "Memory.h"
#include <cstdint>
#include <array>
#include <bitset>
typedef  uint8_t D_WORD_SIZE; // word size 
typedef uint16_t D_LONG_SIZE; //Long size should be 2 word size 



class CPU
{
public:
	static const long MEM_MAX_BOUNDS = 1024 * 32;

private:
	std::array<Register<D_WORD_SIZE>, 5> register_list; //A X ETA ETX 
	Memory<D_WORD_SIZE> RAM = Memory<D_WORD_SIZE>(MEM_MAX_BOUNDS);
	bool bCPUHalted = false;
public:
	/**
	* ADD Functions to add a const to a reg and to add a reg to a reg 
	*/
	void ADD(Register<D_WORD_SIZE> lhs, D_WORD_SIZE rhs) {
		lhs.loadReg(lhs.GetRegValue() + rhs);

	}
	void ADD(Register<D_WORD_SIZE> lhs, Register<D_WORD_SIZE> rhs) {
		lhs.loadReg(lhs.GetRegValue() + rhs.GetRegValue()); 
	}
	
	/** A REG OPERATIONS*/

	[[nodiscard]] D_WORD_SIZE GDA() {
		/// Get the A REG (register_list[0]) value
		return this->register_list[0].GetRegValue();
	}
	void LDA(D_WORD_SIZE value) {
		//store the D_WORD_SIZE value to the a reg
		this->register_list[0].loadReg(value);
	}
	void LDA(D_LONG_SIZE PNTR) {
		/// to do implemnt memory access 
		if (PNTR > RAM.GET_MAX_INDEX()) {
			///if the given pointer is out of memory space then "throw" the an out of bounds exeption 
			this->register_list[4] |= 1 << 1; //set the error flag 
			return; 
		}
		/// if its not then get the memeory and set the a reg to it 
		this->register_list[0].loadReg(RAM.readAddr(PNTR));
	}
	void STA(D_LONG_SIZE addr) {
		RAM.setAddr(addr,  this->register_list[0].GetRegValue()); 
	}

	/** X REG OPERATIONS */
	
	[[nodiscard]] D_WORD_SIZE GDX() {
		/// Get the A REG (register_list[0]) value
		return this->register_list[1].GetRegValue();
	}
	void LDX(D_WORD_SIZE value) {
		//store the D_WORD_SIZE value to the a reg
		this->register_list[1].loadReg(value);
	}
	void LDX(D_LONG_SIZE PNTR) {
		/// to do implemnt memory access 
		if (PNTR > RAM.GET_MAX_INDEX()) {
			///if the given pointer is out of memory space then "throw" the an out of bounds exeption 
			this->register_list[1] |= 1 << 1; //set the error flag 
			return;
		}
		/// if its not then get the memeory and set the a reg to it 
		this->register_list[1].loadReg(RAM.readAddr(PNTR));
	}
	void STX(D_LONG_SIZE addr) {
		RAM.setAddr(addr,  this->register_list[1].GetRegValue());
	}



	/** Y REG OPERATIONS */
	[[nodiscard]] D_WORD_SIZE GDY() {
		/// Get the A REG (register_list[0]) value
		return this->register_list[2].GetRegValue();
	}
	void LDY(D_WORD_SIZE value) {
		//store the D_WORD_SIZE value to the a reg
		this->register_list[2].loadReg(value);
	}
	void LDY(D_LONG_SIZE PNTR) {
		/// to do implemnt memory access 
		if (PNTR > RAM.GET_MAX_INDEX()) {
			///if the given pointer is out of memory space then "throw" the an out of bounds exeption 
			this->register_list[4] |= 1 << 1; //set the error flag 
			return;
		}
		/// if its not then get the memeory and set the a reg to it 
		this->register_list[2].loadReg(RAM.readAddr(PNTR));
	}
	void STY(D_LONG_SIZE addr) {
		RAM.setAddr(addr,  this->register_list[2].GetRegValue());
	}
	
	/**Z REG OPERATIONS
	*TODO: ADD Z REG 
	*/

};
