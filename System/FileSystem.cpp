//	BlitzUtility - Expanding the normal Blitz functionality.
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

#include "FileSystem.h"

using namespace std;

DLL_FUNCTION(std::fstream*) BU_FileSystem_WriteFile(const char* path) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_WriteFile=_BU_FileSystem_WriteFile@4")
	std::fstream* file = new std::fstream();
	file->open(path, ios::in | ios::out || ios::trunc | ios::binary);
	return file;
}

DLL_FUNCTION(std::fstream*) BU_FileSystem_OpenFile(const char* path) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_OpenFile=_BU_FileSystem_OpenFile@4")
	std::fstream* file = new std::fstream();
	file->open(path, ios::in | ios::out | ios::binary);
	return file;
}

DLL_FUNCTION(std::fstream*) BU_FileSystem_ReadFile(const char* path) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_ReadFile=_BU_FileSystem_ReadFile@4")
	std::fstream* file = new std::fstream();
	file->open(path, ios::in | ios::binary);
	return file;
}

DLL_FUNCTION(void) BU_FileSystem_CloseFile(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_CloseFile=_BU_FileSystem_CloseFile@4")
	file->close();
	delete file;
}

DLL_FUNCTION(void) BU_FileSystem_FlushFile(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_FlushFile=_BU_FileSystem_FlushFile@4")
	file->flush();
}

DLL_FUNCTION(int32_t) BU_FileSystem_EOF(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_EOF=_BU_FileSystem_EOF@4")
	if (file->eof())
		return 1;
	if (file->bad())
		return -1;
	if (file->fail())
		return -2;
	
	return 0;
}

DLL_FUNCTION(void) BU_FileSystem_SeekFile(std::fstream* file, int32_t pos) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_SeekFile=_BU_FileSystem_SeekFile@8")
	file->seekg(pos);
	file->seekp(pos);
}

DLL_FUNCTION(void) BU_FileSystem_SeekFileIn(std::fstream* file, int32_t pos) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_SeekFileIn=_BU_FileSystem_SeekFileIn@8")
	file->seekg(pos);
}

DLL_FUNCTION(void) BU_FileSystem_SeekFileOut(std::fstream* file, int32_t pos) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_SeekFileOut=_BU_FileSystem_SeekFileOut@8")
	file->seekp(pos);
}

DLL_FUNCTION(int32_t) BU_FileSystem_FilePosIn(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_FilePosIn=_BU_FileSystem_FilePosIn@4")
	return (int32_t)file->tellg();
}

DLL_FUNCTION(int32_t) BU_FileSystem_FilePosOut(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_FilePosOut=_BU_FileSystem_FilePosOut@4")
	return (int32_t)file->tellp();
}

DLL_FUNCTION(void) BU_FileSystem_WriteByte(std::fstream* file, int32_t value) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_WriteByte=_BU_FileSystem_WriteByte@8")
	char myVal[1] = { value & 0xFF};
	file->write(myVal, 1);
}

DLL_FUNCTION(int32_t) BU_FileSystem_ReadByte(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_ReadByte=_BU_FileSystem_ReadByte@4")
	char myVal[1] = { 0 };
	file->read(myVal, 1);
	return myVal[0];
}

DLL_FUNCTION(void) BU_FileSystem_WriteShort(std::fstream* file, int32_t value) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_WriteShort=_BU_FileSystem_WriteShort@8")
	char myVal[2] = { value & 0xFF, (value >> 8) & 0xFF};
	file->write(myVal, 2);
}

DLL_FUNCTION(int32_t) BU_FileSystem_ReadShort(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_ReadShort=_BU_FileSystem_ReadShort@4")
	char myVal[2] = { 0, 0 };
	file->read(myVal, 2);
	return (myVal[1] << 8) + myVal[0];
}

DLL_FUNCTION(void) BU_FileSystem_WriteInt(std::fstream* file, int32_t value) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_WriteInt=_BU_FileSystem_WriteInt@8")
	char myVal[4] = { value & 0xFF, (value >> 8) & 0xFF, (value >> 16) & 0xFF , (value >> 24) & 0xFF };
	file->write(myVal, 4);
}

DLL_FUNCTION(int32_t) BU_FileSystem_ReadInt(std::fstream* file) {
#pragma comment(linker, "/EXPORT:BU_FileSystem_ReadInt=_BU_FileSystem_ReadInt@4")
	char myVal[4] = { 0, 0, 0, 0 };
	file->read(myVal, 4);
	return (myVal[3] << 24) + (myVal[2] << 16) + (myVal[1] << 8) + myVal[0];
}