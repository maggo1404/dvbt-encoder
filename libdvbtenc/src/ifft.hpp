/*
*
*    DVB-T Encoder written in c++
*    Copyright (C) 2014  Patrick Rudolph <siro@das-labor.org>
*
*    This program is free software; you can redistribute it and/or modify it under the terms 
*    of the GNU General Public License as published by the Free Software Foundation; either version 3 
*    of the License, or (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
*    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*    See the GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along with this program; 
*    if not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef _DVBTENC_IFFT_H__
#define _DVBTENC_IFFT_H__

extern "C" {
#include <fftw3.h>
}
#include <iostream>
#include <inttypes.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "memory.hpp"
#include "settings.hpp"


using namespace std;

class DVBT_ifft
{
public:
	DVBT_ifft(DVBT_pipe *pin, DVBT_pipe *pout, DVBT_settings* dvbt_settings);
	~DVBT_ifft();
	bool encode();
private:
	void fftshift( dvbt_complex_t *in, dvbt_complex_t *out );
	DVBT_settings* dvbt_settings;
	fftwf_plan p;
	int fftshift_offset;
	dvbt_complex_t *bufA;
	dvbt_complex_t *bufB;
	dvbt_complex_t *tmp;
	unsigned int mReadSize;
	unsigned int mWriteSize;
	DVBT_pipe *pin;
	DVBT_pipe *pout;
};

#endif
