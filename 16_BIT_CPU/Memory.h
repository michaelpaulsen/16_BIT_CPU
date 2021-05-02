#pragma once
template <class DWORDSIZE> class Memory
{
	DWORDSIZE* addressSpace; 
	DWORDSIZE max_addr; 
public : 
	Memory(DWORDSIZE size) /// make a memory modual with size bits 
	{
		max_addr = size / (8 * sizeof(DWORDSIZE);
		addressSpace = new DWORDSIZE[max_addr];
		 
	}
	Memory(Memory&) = default; /// shouldn't be needed but want to keep them so that the compiler can optimse when possible
	Memory(Memory&&) = default; 

	~Memory() { //clean up 
		delete[] addressSpace
	}
	void setAddr(DWORDSIZE addr, DWORDSIZE value) {
		if (addr >= this->max_addr) { 
			/// should never be true because the cpu should error chek before making this call 
			/// but I wrote this just incase there's an error in hte way that the cpu makes its set calls
			return; 
		}
		this->addressSpace[addr] = value; 
	}
	DWORDSIZE readAddr(DWORDSIZE addr) {
		if (addr >= this->max_addr) {
			/// should never be true because the cpu should error chek before making this call 
			/// but I wrote this just incase there's an error in hte way that the cpu makes its read calls

			return; 
			/// returning void from non-void function may cause undifined behavior but this is fine
			/// because if this is use properly this line should never be acssesed 
		}
		return this->addressSpace[addr]; 
	}
};

