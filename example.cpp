/*****************************************************************************
	
	Super-Fast MWC1616 Pseudo-Random Number Generator 
	for Intel/AMD Processors (using SSE or SSE4 instruction set)
	Copyright (c) 2012, Ivan Dimkovic
	All rights reserved.

	Redistribution and use in source and binary forms, with or without 
	modification, are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright notice, 
	this list of conditions and the following disclaimer.
	
	Redistributions in binary form must reproduce the above copyright notice, 
	this list of conditions and the following disclaimer in the documentation 
	and/or other materials provided with the distribution.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
	THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
	PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
	OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
	LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#include "random.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main(int args, char *argv[])
{
	unsigned long N = 1000000000;
	if(args>1) N = atoi(argv[1]);

	Random rnd;
	
	const unsigned long loopLimit = N/RNDSTOREDNUMBERS;
	
	clock_t begin = clock();
	for(unsigned long i=0; i<loopLimit; i++) {
		for(unsigned int j=0; j<RNDSTOREDNUMBERS; j++)
		{
			rnd.nextFloat();
		}
		rnd.refillRandomFloats();
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Generating " << N << " floats took used " << elapsed_secs << " seconds." << endl;
	
	begin = clock();
	for(unsigned long i=0; i<loopLimit; i++) {
		for(uint32_t j=0; j<RNDSTOREDNUMBERS; j++)
		{
			rnd.nextDouble();
		}
		rnd.refillRandomDoubles();
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Generating " << N << " doubles took used " << elapsed_secs << " seconds." << endl;
	
	begin = clock();
	for(unsigned long i=0; i<loopLimit; i++) {
		for(uint32_t j=0; j<RNDSTOREDNUMBERS; j++)
		{
			rnd.nextUnsignedInt();
		}
		rnd.refillRandomUnsignedInts();
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Generating " << N << " unsigned ints took used " << elapsed_secs << " seconds." << endl;
}