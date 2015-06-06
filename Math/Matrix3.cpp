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

#include "Matrix3.h"

void Matrix3::set(Matrix3 &M)
{
	if (this != &M) {
		this->X.set(M.X);
		this->Y.set(M.Y);
		this->Z.set(M.Z);
	}
}

void Matrix3::set(Vector3 &X, Vector3 &Y, Vector3 &Z)
{
	this->X.set(X);
	this->Y.set(Y);
	this->Z.set(Z);
}

void Matrix3::set(float &XX, float &XY, float &XZ, float &YX, float &YY, float &YZ, float &ZX, float &ZY, float &ZZ)
{
	this->X.set(XX, XY, XZ);
	this->Y.set(YX, YY, YZ);
	this->Z.set(ZX, ZY, ZZ);
}

void Matrix3::rotate(float &pitch, float &yaw, float &roll)
{
	this->X.mul(cos(yaw) * cos(roll), -sin(roll), sin(yaw));
	this->Y.mul(sin(roll), cos(pitch) * cos(roll), -sin(pitch));
	this->Z.mul(-sin(yaw), sin(pitch), cos(pitch) * cos(yaw));
}

void Matrix3::angles(float &pitch, float &yaw, float &roll)
{
	// ToDo
}

void Matrix3::transpose()
{
	Matrix3 temp;

	temp.set(*this);
	this->X.set(temp.X.X, temp.Y.X, temp.Z.X);
	this->Y.set(temp.X.Y, temp.Y.Y, temp.Z.Y);
	this->Z.set(temp.X.Z, temp.Y.Z, temp.Z.Z);
}
