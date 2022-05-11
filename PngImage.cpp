

#include "PngImage.h"
#include<lodepng.h>

struct ImageSource
{
	const char* data;
	unsigned int size;
	unsigned long offset;
};



PngImage::PngImage()
	:error_(nullptr)
{
	origin_ = nullptr;
	pixelStride_ = 4;
}


bool PngImage::toBoolResult(unsigned int error)
{
	if(error)
	{
		this->error_ = lodepng_error_text(error);;
		return false;
	}
	rowShift_ = pixelStride_ * width_;
	origin_ = data_.data();
	return true;
}
bool PngImage::load(const unsigned char* data, unsigned int size)
{
	lodepng::State state;
	data_.clear();
	auto error = lodepng::decode(this->data_,this->width_,this->height_,state,data,size);
	return toBoolResult(error);
}

bool PngImage::load(const char* path)
{
	data_.clear();
	auto error = lodepng::decode(this->data_,this->width_,this->height_,path);
	return toBoolResult(error);
}

