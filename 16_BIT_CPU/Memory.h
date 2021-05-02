#pragma once
#define NULL_MEMORY 0xff 
template <class DWORDSIZE> class Memory
{
	DWORDSIZE* addressSpace; 
	DWORDSIZE max_addr; 
public : 
	Memory(DWORDSIZE size){
		/// make a memory modual with size bits 

		max_addr = size / (8 * sizeof(DWORDSIZE));
		addressSpace = new DWORDSIZE[max_addr];	 
	}


	Memory(Memory&) = default; 
	Memory(Memory&&) = default;
	/// the copy constructor and the forward referance constructor shouldn't ever be used but they are kept
	/// so that the compiler can optimize.

	~Memory() { //clean up 
		delete[] addressSpace;
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
			return NULL_MEMORY; 
		}
		return this->addressSpace[addr]; 
	}
	DWORDSIZE GET_MAX_INDEX() {
		return this->max_addr; 
	}
};

