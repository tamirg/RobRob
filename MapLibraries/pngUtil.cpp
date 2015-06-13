/*
 * pngUtil.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: colman
 */
#include "pngUtil.h"
#include "lodepng.h"
#include <iostream>
#include "../Map.h"

vector<vector<int> >  convertPngToPixels(const char* filename) {
	vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	unsigned x, y;
	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << endl;

	vector<unsigned char> navImage; //the raw pixels
	navImage.resize(width * height * 4);
	vector<vector<int> > mapGrid(Helper::MAP_HEIGHT, vector<int>(Helper::MAP_WIDTH));
	unsigned char color;
	for (y = 0; y < height; y++)
		for (x = 0; x < width; x++) {
			if (image[y * width * 4 + x * 4 + 0]
					|| image[y * width * 4 + x * 4 + 1]
					|| image[y * width * 4 + x * 4 + 2]) {
				color = 255;
				mapGrid[y][x] = Helper::FREE_CELL;
			} else {
				color = 0;
				mapGrid[y][x] = Helper::OCCUPIED_CELL;
			}
			navImage[y * width * 4 + x * 4 + 0] = color;
			navImage[y * width * 4 + x * 4 + 1] = color;
			navImage[y * width * 4 + x * 4 + 2] = color;
			navImage[y * width * 4 + x * 4 + 3] = 255;
		}
	cout << "width: " << width << " height: " << height;
	return mapGrid;
//	encodeOneStep("newMap.png", navImage, width, height);
}

void decodeOneStep(const char* filename) {
	vector<unsigned char> image; //the raw pixels
	unsigned width, height;

	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, vector<unsigned char> image,
		unsigned width, unsigned height) {
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
	if (error)
		cout << "encoder error " << error << ": "
				<< lodepng_error_text(error) << endl;
}
