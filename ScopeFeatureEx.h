#ifndef SVISION_SCOPE_FEATURE_EX_H
#define SVISION_SCOPE_FEATURE_EX_H

#include"base.h"
#include"color.h"
#include<string>
#include<vector>
class ScopeFeatureEx
{

	struct PointFeature
	{
		int x;
		int y;
		int color;
		int shiftColor;
	};

    std::vector<PointFeature> pointFeatures_;
	int compare(Bitmap* bitmap, int originX, int originY, PointFeature& pointFeature, const unsigned char* shift);
	void initializePointFeatures(const char* stringFeature,size_t size);
public:
	ScopeFeatureEx();
	ScopeFeatureEx(const char* stringFeature,size_t size);
	void load(const char* stringFeature, size_t size);
	int getPointCount()
	{
		return pointFeatures_.size();
	}
	std::string toString();
    int equal(Bitmap* bitmap, int x,int y,Color shift,int canErrorPointCount);
};


#endif //SVISION_SCOPE_FEATURE_EX_H