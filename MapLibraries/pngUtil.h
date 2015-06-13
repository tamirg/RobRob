/*
 * pngUtil.h
 *
 *  Created on: Mar 30, 2015
 *      Author: colman
 */

#ifndef PNGUTIL_H_
#define PNGUTIL_H_
#include <iostream>
#include <vector>
using namespace std;

void encodeOneStep(const char* filename, std::vector<unsigned char> image, unsigned width, unsigned height);
void decodeOneStep(const char* filename);
vector<vector<int> > convertPngToPixels(const char* filename);



#endif /* PNGUTIL_H_ */
