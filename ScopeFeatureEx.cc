#include "ScopeFeatureEx.h"
#include "StringViewFeature.h"


int ScopeFeatureEx::compare(Bitmap* bitmap, int originX, int originY, PointFeature& pointFeature, const unsigned char* shift)
{
	int x = originX + pointFeature.x;
	int y = originY + pointFeature.y;
	return isInBitmapScope(bitmap, x, y)
		&& compareColor(computeCoordColor(bitmap, x, y), (const unsigned char*)&pointFeature.color, (const unsigned char*)&pointFeature.shiftColor, shift);
}

void ScopeFeatureEx::initializePointFeatures(const char* stringFeature, size_t size)
{
	size_t pos = 0;
    for(auto& feature:pointFeatures_){
		feature.x  = std::stoi(stringFeature, &pos, 10);
		stringFeature += pos + 1;
		feature.y = std::stoi(stringFeature, &pos, 10);
		stringFeature += pos + 1;
		feature.color = toIntColor(stringFeature);
		stringFeature += 7;
		if (stringFeature[-1] == '-')
		{
			feature.shiftColor = toIntColor(stringFeature);
			stringFeature += 7;
		}
		else
			feature.shiftColor = 0;
    }
}

ScopeFeatureEx::ScopeFeatureEx()
{
}



ScopeFeatureEx::ScopeFeatureEx(const char* stringFeature, size_t size)
{
	load(stringFeature, size);
}

void ScopeFeatureEx::load(const char* stringFeature, size_t size)
{
	auto pointCount = computeStringFeaturePointCount(stringFeature, size);
	pointFeatures_.resize(pointCount);
	initializePointFeatures(stringFeature, size);
}


std::string ScopeFeatureEx::toString()
{
	std::string result;
	char color[8] = { 0 };
    for(auto &feature:pointFeatures_){
		result.append(std::to_string(feature.x))
			.append("|")
			.append(std::to_string(feature.y))
			.append("|");
		sprintf(color, "%06X", feature.color);
		result.append(color, 6);
		if (feature.shiftColor != 0)
		{
			sprintf(color, "-%06X", feature.shiftColor);
			result.append(color, 7);
		}
		result.append(",");
    }
	result.pop_back();
	return result;
}


int ScopeFeatureEx::equal(Bitmap* bitmap, int x,int y,Color shift,int canErrorPointCount){
    int nowErrorCount = 0;
    for(auto &feature:pointFeatures_){
        if (!compare(bitmap, x, y, feature, (const unsigned char*)&shift)
            && ++nowErrorCount > canErrorPointCount)
        {
            return 0;
        }
    }
    return 1;
}