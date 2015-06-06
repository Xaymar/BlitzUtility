//	BlitzUtility - Expanding the normal Blitz functionality.
//	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
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
#include <math.h>
#include "dllmain.h"
#include "Vector3.h"

struct Matrix3 {
	Vector3 X, Y, Z;

	void set(Matrix3 &M);
	void set(Vector3 &X, Vector3 &Y, Vector3 &Z);
	void set(float &XX, float &XY, float &XZ, float &YX, float &YY, float &YZ, float &ZX, float &ZY, float &ZZ);
	
	void rotate(float &pitch, float &yaw, float &roll);
	void angles(float &pitch, float &yaw, float &roll);

	void transpose();
};

