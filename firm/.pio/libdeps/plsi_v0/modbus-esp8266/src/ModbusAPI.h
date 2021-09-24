/*
    Modbus Library for Arduino
	Modbus public API implementation
    Copyright (C) 2014 Andr� Sarmento Barbosa
                  2017-2020 Alexander Emelianov (a.m.emelianov@gmail.com)
*/
#pragma once
#include "Modbus.h"

template <class T>
class ModbusAPI : public T {
	public:
/*	// New API
	template <typename TYPEID>		
	uint16_t write(TYPEID id, TAddress reg, uint16_t value, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t write(TYPEID id, TAddress reg, bool value, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t write(TYPEID id, TAddress reg, uint16_t* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t write(TYPEID id, TAddress reg, bool* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t read(TYPEID id, TAddress reg, uint16_t* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t read(TYPEID id, TAddress reg, bool* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);

	template <typename TYPEID>
	uint16_t push(TYPEID id, TAddress to, TAddress from, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pull(TYPEID id, TAddress from, TAddress to, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
*/
	// Legacy API
	bool Hregs(uint16_t offset, uint16_t* value, uint16_t numregs = 1) {return this->Reg(HREG(offset), value);}
    bool Coils(uint16_t offset, bool* value, uint16_t numregs = 1) {return this->Reg(COIL(offset), value);}
    bool Istss(uint16_t offset, bool* value, uint16_t numregs = 1) {return this->Reg(ISTS(offset), value);}
    bool Iregs(uint16_t offset, uint16_t* value, uint16_t numregs = 1) {return this->Reg(IREG(offset), value);}

	//bool addHreg(uint16_t offset, uint16_t* value, uint16_t numregs = 1) {return this->addReg(HREG(offset), value);}
    //bool addCoil(uint16_t offset, bool* value, uint16_t numregs = 1) {return this->addReg(COIL(offset), value);}
    //bool addIsts(uint16_t offset, bool* value, uint16_t numregs = 1) {return this->addReg(ISTS(offset), value);}
    //bool addIreg(uint16_t offset, uint16_t* value, uint16_t numregs = 1) {return this->addReg(IREG(offset), value);}

	bool addHreg(uint16_t offset, uint16_t value = 0, uint16_t numregs = 1);
    bool addCoil(uint16_t offset, bool value = false, uint16_t numregs = 1);
    bool addIsts(uint16_t offset, bool value = false, uint16_t numregs = 1);
    bool addIreg(uint16_t offset, uint16_t value = 0, uint16_t numregs = 1);

    bool Hreg(uint16_t offset, uint16_t value);
    bool Coil(uint16_t offset, bool value);
    bool Ists(uint16_t offset, bool value);
    bool Ireg(uint16_t offset, uint16_t value);

    bool Coil(uint16_t offset);
    bool Ists(uint16_t offset);
    uint16_t Ireg(uint16_t offset);
    uint16_t Hreg(uint16_t offset);

    bool removeCoil(uint16_t offset, uint16_t numregs = 1);
    bool removeIsts(uint16_t offset, uint16_t numregs = 1);
    bool removeIreg(uint16_t offset, uint16_t numregs = 1);
    bool removeHreg(uint16_t offset, uint16_t numregs = 1);

    bool onGetCoil(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onSetCoil(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onGetHreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onSetHreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onGetIsts(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onSetIsts(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onGetIreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool onSetIreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);

    bool removeOnGetCoil(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnSetCoil(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnGetHreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnSetHreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnGetIsts(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnSetIsts(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnGetIreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);
    bool removeOnSetIreg(uint16_t offset, cbModbus cb = nullptr, uint16_t numregs = 1);

	template <typename TYPEID>
	uint16_t writeCoil(TYPEID id, uint16_t offset, bool value, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t writeCoil(TYPEID id, uint16_t offset, bool* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t readCoil(TYPEID id, uint16_t offset, bool* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t writeHreg(TYPEID id, uint16_t offset, uint16_t value, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t writeHreg(TYPEID id, uint16_t offset, uint16_t* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t readIsts(TYPEID id, uint16_t offset, bool* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t readHreg(TYPEID id, uint16_t offset, uint16_t* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t readIreg(TYPEID id, uint16_t offset, uint16_t* value, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);

	template <typename TYPEID>
	uint16_t pushCoil(TYPEID id, uint16_t to, uint16_t from, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pullCoil(TYPEID id, uint16_t from, uint16_t to, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pullIsts(TYPEID id, uint16_t from, uint16_t to, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pushHreg(TYPEID id, uint16_t to, uint16_t from, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pullHreg(TYPEID id, uint16_t from, uint16_t to, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pullIreg(TYPEID id, uint16_t from, uint16_t to, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);

	template <typename TYPEID>
	uint16_t pullHregToIreg(TYPEID id, uint16_t offset, uint16_t startreg, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pullCoilToIsts(TYPEID id, uint16_t offset, uint16_t startreg, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pushIstsToCoil(TYPEID id, uint16_t to, uint16_t from, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t pushIregToHreg(TYPEID id, uint16_t to, uint16_t from, uint16_t numregs = 1, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);

    template <typename TYPEID>
	uint16_t readFileRec(TYPEID slaveId, uint16_t fileNum, uint16_t startRec, uint16_t len, uint8_t* data, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	template <typename TYPEID>
	uint16_t writeFileRec(TYPEID slaveId, uint16_t fileNum, uint16_t startRec, uint16_t len, uint8_t* data, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);

	template <typename TYPEID>
	uint16_t maskHreg(TYPEID slaveId, uint16_t offset, uint16_t andMask, uint16_t orMask, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
	//template <typename TYPEID>
	//uint16_t readWriteHreg(uint8_t slaveId, uint16_t readOffset, uint16_t* value, uint16_t numregs, uint16_t writeOffset, uint16_t* value, uint16_t numregs, cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
};

// FNAME	writeCoil, writeIsts, writeHreg, writeIreg
// REG		COIL, ISTS, HREG, IREG
// FUNC		Modbus function
// MAXNUM	Register count limit
// VALTYPE	bool, uint16_t
// VALUE	
#define IMPLEMENT_WRITEREG(FNAME, REG, FUNC, VALUE, VALTYPE) \
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::FNAME(TYPEID ip, uint16_t offset, VALTYPE value, cbTransaction cb, uint8_t unit) { \
	this->readSlave(offset, VALUE(value), Modbus::FUNC); \
	return this->send(ip, REG(offset), cb, unit); \
}
IMPLEMENT_WRITEREG(writeCoil, COIL, FC_WRITE_COIL, COIL_VAL, bool)
IMPLEMENT_WRITEREG(writeHreg, HREG, FC_WRITE_REG, , uint16_t)

#define IMPLEMENT_WRITEREGS(FNAME, REG, FUNC, VALUE, MAXNUM, VALTYPE) \
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::FNAME(TYPEID ip, uint16_t offset, VALTYPE* value, uint16_t numregs, cbTransaction cb, uint8_t unit) { \
	if (numregs < 0x0001 || numregs > MAXNUM) return false; \
	this->VALUE(REG(offset), offset, numregs, Modbus::FUNC, value); \
	return this->send(ip, REG(offset), cb, unit); \
}
IMPLEMENT_WRITEREGS(writeCoil, COIL, FC_WRITE_COILS, writeSlaveBits, 0x07D0, bool)
IMPLEMENT_WRITEREGS(writeHreg, HREG, FC_WRITE_REGS, writeSlaveWords, 0x007D, uint16_t)

#define IMPLEMENT_READREGS(FNAME, REG, FUNC, MAXNUM, VALTYPE) \
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::FNAME(TYPEID ip, uint16_t offset, VALTYPE* value, uint16_t numregs, cbTransaction cb, uint8_t unit) { \
	if (numregs < 0x0001 || numregs > MAXNUM) return false; \
	this->readSlave(offset, numregs, Modbus::FUNC); \
	return this->send(ip, REG(offset), cb, unit, (uint8_t*)value); \
}
IMPLEMENT_READREGS(readCoil, COIL, FC_READ_COILS, 0x07D0, bool)
IMPLEMENT_READREGS(readHreg, HREG, FC_READ_REGS, 0x007D, uint16_t)
IMPLEMENT_READREGS(readIsts, ISTS, FC_READ_INPUT_STAT, 0x07D0, bool)
IMPLEMENT_READREGS(readIreg, IREG, FC_READ_INPUT_REGS, 0x007D, uint16_t)

//#if defined(MODBUS_ADD_REG) // elpercha
//#define ADDREG this->addReg(REG(to), 0, numregs); \ // elpercha   
//#else // elpercha
#define ADDREG // elpercha
//#endif // elpercha

#define IMPLEMENT_PULL(FNAME, REG, FUNC, MAXNUM) \
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::FNAME(TYPEID ip, uint16_t from, uint16_t to, uint16_t numregs, cbTransaction cb, uint8_t unit) { \
	if (numregs < 0x0001 || numregs > MAXNUM) return false; \
	ADDREG \
	this->readSlave(from, numregs, Modbus::FUNC); \
	return this->send(ip, REG(to), cb, unit); \
}
IMPLEMENT_PULL(pullCoil, COIL, FC_READ_COILS, 0x07D0)
IMPLEMENT_PULL(pullIsts, ISTS, FC_READ_INPUT_STAT, 0x07D0)
IMPLEMENT_PULL(pullHreg, HREG, FC_READ_REGS, 0x007D)
IMPLEMENT_PULL(pullIreg, IREG, FC_READ_INPUT_REGS, 0x007D)
IMPLEMENT_PULL(pullHregToIreg, IREG, FC_READ_REGS, 0x007D)
IMPLEMENT_PULL(pullCoilToIsts, ISTS, FC_READ_COILS, 0x07D0)

#define IMPLEMENT_PUSH(FNAME, REG, FUNC, MAXNUM) \
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::FNAME(TYPEID ip, uint16_t to, uint16_t from, uint16_t numregs, cbTransaction cb, uint8_t unit) { \
	if (numregs < 0x0001 || numregs > MAXNUM) return false; \
	if (!this->searchRegister(REG(from))) return false; \
	this->writeSlaveWords(REG(from), to, numregs, Modbus::FUNC); \
	return this->send(ip, REG(from), cb, unit); \
}
IMPLEMENT_PUSH(pushCoil, COIL, FC_WRITE_COILS, 0x7D0)
IMPLEMENT_PUSH(pushHreg, HREG, FC_WRITE_REGS, 0x007D)
IMPLEMENT_PUSH(pushIregToHreg, IREG, FC_WRITE_REGS, 0x007D)
IMPLEMENT_PUSH(pushIstsToCoil, ISTS, FC_WRITE_COILS, 0x07D0)

template <class T> \
bool ModbusAPI<T>::addHreg(uint16_t offset, uint16_t value, uint16_t numregs) {
    return this->addReg(HREG(offset), value, numregs);
}
template <class T> \
bool ModbusAPI<T>::Hreg(uint16_t offset, uint16_t value) {
    return this->Reg(HREG(offset), value);
}
template <class T> \
uint16_t ModbusAPI<T>::Hreg(uint16_t offset) {
    return this->Reg(HREG(offset));
}
template <class T> \
bool ModbusAPI<T>::removeHreg(uint16_t offset, uint16_t numregs) {
    return this->removeReg(HREG(offset), numregs);
}
template <class T> \
bool ModbusAPI<T>::addCoil(uint16_t offset, bool value, uint16_t numregs) {
    return this->addReg(COIL(offset), COIL_VAL(value), numregs);
}
template <class T> \
bool ModbusAPI<T>::addIsts(uint16_t offset, bool value, uint16_t numregs) {
    return this->addReg(ISTS(offset), ISTS_VAL(value), numregs);
}
template <class T> \
bool ModbusAPI<T>::addIreg(uint16_t offset, uint16_t value, uint16_t numregs) {
    return this->addReg(IREG(offset), value, numregs);
}
template <class T> \
bool ModbusAPI<T>::Coil(uint16_t offset, bool value) {
    return this->Reg(COIL(offset), COIL_VAL(value));
}
template <class T> \
bool ModbusAPI<T>::Ists(uint16_t offset, bool value) {
    return this->Reg(ISTS(offset), ISTS_VAL(value));
}
template <class T> \
bool ModbusAPI<T>::Ireg(uint16_t offset, uint16_t value) {
    return this->Reg(IREG(offset), value);
}
template <class T> \
bool ModbusAPI<T>::Coil(uint16_t offset) {
    return COIL_BOOL(this->Reg(COIL(offset)));
}
template <class T> \
bool ModbusAPI<T>::Ists(uint16_t offset) {
    return ISTS_BOOL(this->Reg(ISTS(offset)));
}
template <class T> \
uint16_t ModbusAPI<T>::Ireg(uint16_t offset) {
    return this->Reg(IREG(offset));
}
template <class T> \
bool ModbusAPI<T>::removeCoil(uint16_t offset, uint16_t numregs) {
    return this->removeReg(COIL(offset), numregs);
}
template <class T> \
bool ModbusAPI<T>::removeIsts(uint16_t offset, uint16_t numregs) {
    return this->removeReg(ISTS(offset), numregs);
}
template <class T> \
bool ModbusAPI<T>::removeIreg(uint16_t offset, uint16_t numregs) {
    return this->removeReg(IREG(offset), numregs);
}
template <class T> \
bool ModbusAPI<T>::onGetCoil(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onGet(COIL(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onSetCoil(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onSet(COIL(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onGetHreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onGet(HREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onSetHreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onSet(HREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onGetIsts(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onGet(ISTS(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onSetIsts(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onSet(ISTS(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onGetIreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onGet(IREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::onSetIreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->onSet(IREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnGetCoil(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnGet(COIL(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnSetCoil(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnSet(COIL(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnGetHreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnGet(HREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnSetHreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnSet(HREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnGetIsts(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnGet(ISTS(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnSetIsts(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnSet(ISTS(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnGetIreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnGet(IREG(offset), cb, numregs);
}
template <class T> \
bool ModbusAPI<T>::removeOnSetIreg(uint16_t offset, cbModbus cb, uint16_t numregs) {
    return this->removeOnSet(IREG(offset), cb, numregs);
}
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::readFileRec(TYPEID slaveId, uint16_t fileNum, uint16_t startRec, uint16_t len, uint8_t* data, cbTransaction cb, uint8_t unit) {
			if (startRec > 0x270F) return 0;
			if (!this->readSlaveFile(&fileNum, &startRec, &len, 1, Modbus::FC_READ_FILE_REC)) return 0;
			return this->send(slaveId, HREG(0), cb, unit, data); // HREG(0) - just dummy value
		};
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::writeFileRec(TYPEID slaveId, uint16_t fileNum, uint16_t startRec, uint16_t len, uint8_t* data, cbTransaction cb, uint8_t unit) {
			if (startRec > 0x270F) return 0;
			if (!this->writeSlaveFile(&fileNum, &startRec, &len, 1, Modbus::FC_WRITE_FILE_REC, data)) return 0;
			return this->send(slaveId, HREG(0), cb, unit); // HREG(0) - just dummy value
		};
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::maskHreg(TYPEID slaveId, uint16_t offset, uint16_t andMask, uint16_t orMask, cbTransaction cb, uint8_t unit) {
			free(this->_frame);
			this->_len = 7;
			this->_frame = (uint8_t*) malloc(this->_len);
			this->_frame[0] = Modbus::FC_MASKWRITE_REG;
			this->_frame[1] = offset >> 8;
			this->_frame[2] = offset & 0x00FF;
			this->_frame[3] = andMask >> 8;
			this->_frame[4] = andMask & 0x00FF;
			this->_frame[5] = orMask >> 8;
			this->_frame[6] = orMask & 0x00FF;
			return this->send(slaveId, HREG(offset), cb, unit, nullptr, cb);	
		};
/*
template <class T> \
template <typename TYPEID> \
uint16_t ModbusAPI<T>::readWriteHreg(TYPEID slaveId,
			uint16_t readOffset, uint16_t* value, uint16_t numregs,
			uint16_t writeOffset, uint16_t* value, uint16_t numregs,
			cbTransaction cb = nullptr, uint8_t unit = MODBUSIP_UNIT);
*/