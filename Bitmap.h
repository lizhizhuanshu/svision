#ifndef SVISION_BITMAP_H
#define SVISION_BITMAP_H
struct Bitmap{
	unsigned char* origin_;
	unsigned int width_;
	unsigned int height_;
	int rowShift_;
	int pixelStride_;
};
#endif// SVISION_BITMAP_H

