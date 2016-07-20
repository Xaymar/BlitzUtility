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

#include "ThreadWrapper.h"

class ThreadWrapper {
public:
	ThreadWrapper(void* ptr, void* data) {
		this->ptr = ptr;
		this->data = data;
	}
	~ThreadWrapper() {

	}

	static int Core(ThreadWrapper* data) {
		try {
			BP_CallFunction1((BP_BlitzFunction1_t)data->ptr, reinterpret_cast<int32_t>(data->data));
		} catch (const std::exception& e) {
			std::stringstream ss;
			ss << e.what();
			MessageBoxA(0, ss.str().c_str(), "ThreadWrapper", 0);
			throw;
		}
	}

private:
	void *ptr, *data;
	std::exception lastException;
};

DLL_FUNCTION(ThreadWrapper*) BU_ThreadWrapper_Create(void* ptr, void* data) {
#pragma comment(linker, "/EXPORT:BU_ThreadWrapper_Create=_BU_ThreadWrapper_Create@8")
	return new ThreadWrapper(ptr, data);
}

DLL_FUNCTION(void) BU_ThreadWrapper_Destroy(ThreadWrapper* pThreadWrapper) {
#pragma comment(linker, "/EXPORT:BU_ThreadWrapper_Destroy=_BU_ThreadWrapper_Destroy@4")
	delete pThreadWrapper;
}