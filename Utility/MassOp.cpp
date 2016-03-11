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
#include "MassOp.h"

MassOp::MassOp(uint32_t length) : length(length) {
	this->instructions = new MassOpInstruction[length];
}

MassOp::~MassOp() {
	delete this->instructions;
}

DLL_FUNCTION(MassOp*) BU_MassOp_Create(uint32_t length) {
	MassOp* myMassOp = new MassOp(length);
	return myMassOp;
}

DLL_FUNCTION(void) BU_MassOp_Destroy(MassOp* massop) {
	delete massop;
}

DLL_FUNCTION(void) BU_MassOp_Instruction(MassOp* massop, uint32_t index, MassOpType type, MassOpCode code, intptr_t leftOperand, intptr_t rightOperand, intptr_t result) {
	massop->instructions[index].type = type;
	massop->instructions[index].code = code;
	massop->instructions[index].leftOperand = leftOperand;
	massop->instructions[index].rightOperand = rightOperand;
	massop->instructions[index].result = result;
}

DLL_FUNCTION(void) BU_MassOp_Run(MassOp* massop) {
	for (uint32_t index = 0; index < massop->length; index++) {
		MassOpInstruction* instr = &massop->instructions[index];
		switch (instr->code) {
			case GoTo:
				index = instr->leftOperand;
				break;
			case SetOpCode:
				massop->instructions[instr->leftOperand].code = instr->rightOperand;
				break;
			case CopyLeft:
				if (instr->leftOperand != instr->rightOperand) {
					switch (instr->result) {
						case 0:
							massop->instructions[instr->rightOperand].leftOperand = massop->instructions[instr->leftOperand].leftOperand;
							break;
						case 1:
							massop->instructions[instr->rightOperand].rightOperand = massop->instructions[instr->leftOperand].leftOperand;
							break;
						case 2:
							massop->instructions[instr->rightOperand].result = massop->instructions[instr->leftOperand].leftOperand;
							break;
					}
				}
				break;
			case CopyRight:
				if (instr->leftOperand != instr->rightOperand) {
					switch (instr->result) {
						case 0:
							massop->instructions[instr->rightOperand].leftOperand = massop->instructions[instr->leftOperand].rightOperand;
							break;
						case 1:
							massop->instructions[instr->rightOperand].rightOperand = massop->instructions[instr->leftOperand].rightOperand;
							break;
						case 2:
							massop->instructions[instr->rightOperand].result = massop->instructions[instr->leftOperand].rightOperand;
							break;
					}
				}
				break;
			case CopyOut:
				if (instr->leftOperand != instr->rightOperand) {
					switch (instr->result) {
						case 0:
							massop->instructions[instr->rightOperand].leftOperand = massop->instructions[instr->leftOperand].result;
							break;
						case 1:
							massop->instructions[instr->rightOperand].rightOperand = massop->instructions[instr->leftOperand].result;
							break;
						case 2:
							massop->instructions[instr->rightOperand].result = massop->instructions[instr->leftOperand].result;
							break;
					}
				}
				break;
			case If:
				if (instr->leftOperand != instr->rightOperand) {
					if (massop->instructions[instr->leftOperand].result == massop->instructions[instr->rightOperand].result) {
						index += instr->result;
					}
				}
				break;
			case IfValue:
				if (instr->leftOperand != instr->rightOperand) {
					if (massop->instructions[instr->rightOperand].result == instr->rightOperand) {
						index += instr->result;
					}
				}
				break;
			default:
				switch (instr->type) {
					case Double:
						switch (instr->code) {
							case Create:
								instr->result = (uint32_t) BU_Double_New();
								break;
							case Destroy:
								BU_Double_Destroy((double_t*)instr->leftOperand);
								break;
							case Copy:
								instr->result = (uint32_t) BU_Double_Copy((double_t*)instr->leftOperand);
								break;
							case Set:
								BU_Double_Set((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
							case Add:
								BU_Double_Add((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
							case Sub:
								BU_Double_Sub((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
							case Mul:
								BU_Double_Mul((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
							case Div:
								BU_Double_Div((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
							case Compare:
								instr->result = BU_Double_Compare((double_t*)instr->leftOperand, (double_t*)instr->rightOperand);
								break;
						}
						break;
					case Long:
						switch (instr->code) {
							case Create:
								instr->result = (uint32_t) BU_Long_New();
								break;
							case Destroy:
								BU_Long_Destroy((int64_t*)instr->leftOperand);
								break;
							case Copy:
								instr->result = (uint32_t) BU_Long_Copy((int64_t*)instr->leftOperand);
								break;
							case Set:
								BU_Long_Set((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
							case Add:
								BU_Long_Add((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
							case Sub:
								BU_Long_Sub((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
							case Mul:
								BU_Long_Mul((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
							case Div:
								BU_Long_Div((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
							case Compare:
								instr->result = BU_Long_Compare((int64_t*)instr->leftOperand, (int64_t*)instr->rightOperand);
								break;
						}
						break;
				}
		}
	}
}
