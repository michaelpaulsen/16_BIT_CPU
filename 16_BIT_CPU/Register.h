#pragma once
template<class W_SIZE_T > class Register
{
private:
	W_SIZE_T REGVAL = 0x00;



public: 
	[[nodiscard]] W_SIZE_T GetRegValue() {

		return this->REGVAL; 
	}
	void loadReg(W_SIZE_T loadVal) {
		this->REGVAL = loadVal;
	}
	void operator&=(W_SIZE_T lhs) { /// AND REG (const number)
		this->REGVAL &= lhs; 
	}
	void operator&=(Register<W_SIZE_T> lhs) { /// AND self REG2  
		this->REGVAL& lhs.GetRegValue(); 
	}
	void operator^=(W_SIZE_T lhs) { /// XOR REG (const number)
		this->REGVAL ^= lhs; 
	}
	void operator^=(Register<W_SIZE_T> lhs) { /// XOR self REG 
		this->REGVAL ^= lhs.GetRegValue(); 
	}
	void operator|=(int lhs) { /// LOR REG const 
		this->REGVAL |= lhs; 
	}
	void operator|=(Register<W_SIZE_T> lhs) {// LOR self and REG 
		 this->REGVAL |= lhs.GetRegValue( );
	}
	void operator<<=(int lhs) { /// SHL  REG (const number)
		this->REGVAL <<= lhs; 
	}
	void operator>>=(int lhs) { /// SHR  REG (const number)
		this->REGVAL >>= lhs; 
	}
	
};

