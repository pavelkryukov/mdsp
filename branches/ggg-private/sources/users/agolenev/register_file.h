/**
 * register_file.h - Specification of register file (RF) model
 * Define classes and methods to operate with RF of simulated architecture
 * Copyright 2009 MDSP team
 */

#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <iostream>
#include <cassert>
#include "types.h"
#include "memory.h"

#define low_byte 0;
#define high_byte 1;

/**
 * class RegVal implements a object to interaction with RF 
 */

class RegVal: public ByteLine
{
    ByteLine* byte_line;
    
public:
    /* Constructors and destructor */
    RegVal( unsigned int number_of_bytes_in_reg_val)
    {
       byte_line = new ByteLine( number_of_bytes_in_reg_val);
       if ( !byte_line)
       {
            cout << "ERROR: Can not allocate memory!\n";
            assert(0);
        }
    }
    ~RegVal()
    {
        delete byte_line;
    }
    
    /* Get/set methods */
    hostUInt8 getByteVal( unsigned int byte_num)
    {
        return byte_line->getByteVal(byte_num);
    }
    
    void setByteVal( unsigned int byte_num, hostUInt8 byte_val)
    {
        byte_line->setByteVal(byte_num, byte_val);
    }
    
    unsigned int getSizeOfMemVal() 
    { 
        return this->byte_line->getSizeOfLine(); 
    }
};

/**
 * class RegisterFileModel implements RF of simulated architecture and infrastructure to operate with it
 */

class RegisterFileModel 
{
    RegVal* register_file;

public:
    /* Constructors and destructor */ 
    RegisterFileModel( unsigned int number_of_registers, unsigned int size_of_register_in_bytes);
    ~RegisterFileModel()
    {
        delete register_file;
    }
     
    
    /* Read a logical set of bytes (RegVal) form physical register with number reg_num */
     RegVal* readReg( physRegNum reg_num);
    
    
    /* Write a logical set of bytes (RegVal) to physical register with number reg_num */ 
    void writeReg( physRegNum reg_num, RegVal reg_value);
     
};

#endif /* REGISTER_FILE_H */
