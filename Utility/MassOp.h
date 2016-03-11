//	Blitz - Steam wrapper for Blitz.
//	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as
//	published by the Free Software Foundation, either version 3 of the 
//	License, or (at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "BlitzUtility.h"
#include "Type\Double.h"

enum MassOpType {
	Long = 0,
	Double		= 1,

	Vector2		= 10,
	Vector3		= 11,
};

enum MassOpCode {
	Create		= 0,
	Destroy		= 1,
	Copy		= 2,
	TempCreate	= 5,
	TempCopy	= 6,
	TempCleanup	= 7,

	Set			= 10,
	Add			= 11,
	Sub			= 12,
	Mul			= 13,
	Div			= 14,
	Compare		= 15,

	// Special OPCodes (Control MassOp)
	// Goto - Go to a specific intruction
	//  oper_l = target massop index
	GoTo		= 249,
	// SetOpCode - Change OpCode at position
	//  oper_l = target massop index
	//  oper_r = new OpCode
	SetOpCode	= 250, 
	// CopyLeft - Copy oper_l to new MassOp instruction.
	//  oper_l = source massop index
	//  oper_r = target massop index
	//  out = target position (0/oper_l, 1/oper_r, 2/out)
	CopyLeft	= 251,
	// CopyRight - Copy oper_r to new MassOp instruction.
	//  oper_l = source massop index
	//  oper_r = target massop index
	//  out = target position (0/oper_l, 1/oper_r, 2/out)
	CopyRight	= 252,
	// CopyOut - Copy out to new MassOp instruction.
	//  oper_l = source massop index
	//  oper_r = target massop index
	//  out = target position (0/oper_l, 1/oper_r, 2/out)
	CopyOut = 253,
	// If - If the result of index oper_l is equal to index oper_r, skip out instructions.
	//  oper_l = source massop index
	//  oper_r = target massop index
	//  out = instructions to skip
	If = 254,
	// IfValue - If the result of index oper_l is equal to oper_r, skip out instructions.
	//  oper_l = source massop index
	//  oper_r = value to compare with
	//  out = instructions to skip
	IfValue = 255
};

struct BlitzBank {
	uint32_t identifier;
	uint32_t address;
	uint32_t size;
};

struct MassOpInstruction {
	uint8_t type;
	uint8_t code;
	uint32_t leftOperand, rightOperand;
	uint32_t result;
};

struct MassOp {
	MassOp(uint32_t length);
	~MassOp();

	uint32_t length;
	MassOpInstruction* instructions;
};

DLL_FUNCTION(MassOp*) BU_MassOp_Create(uint32_t length);
#pragma comment(linker, "/EXPORT:BU_MassOp_Create=_BU_MassOp_Create@4")
DLL_FUNCTION(void) BU_MassOp_Destroy(MassOp* massop);
#pragma comment(linker, "/EXPORT:BU_MassOp_Destroy=_BU_MassOp_Destroy@4")
DLL_FUNCTION(void) BU_MassOp_Instruction(MassOp* massop, uint32_t index, MassOpType type, MassOpCode code, intptr_t leftOperand, intptr_t rightOperand, intptr_t result);
#pragma comment(linker, "/EXPORT:BU_MassOp_Instruction=_BU_MassOp_Instruction@28")
DLL_FUNCTION(void) BU_MassOp_Run(MassOp* massop);
#pragma comment(linker, "/EXPORT:BU_MassOp_Run=_BU_MassOp_Run@4")