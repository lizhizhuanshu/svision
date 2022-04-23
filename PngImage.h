#ifndef SVISION_PNG_IMAGE_H
#define SVISION_PNG_IMAGE_H

#include<vector>
#include "Bitmap.h"


class PngImage :public Bitmap
{
	std::vector<unsigned char> data_;
	const char* error_;
public:
	PngImage();
	bool toBoolResult(unsigned int error);
	bool load(const unsigned char* data, unsigned int size);
	bool load(const char* path);
	const char* errorText(){
		return error_;
	}
};

#endif //SVISION_PNG_IMAGE_H


