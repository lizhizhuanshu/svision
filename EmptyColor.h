#ifndef SVISION_EMPTY_COLOR_H
#define SVISION_EMPTY_COLOR_H
class EmptyColor
{
	int result;
public:
	EmptyColor(int result = 0)
		:result(result)
	{
	}

	template< class TShift>
	int equal(const unsigned char* color ,TShift shift)
	{
		return result;
	}
};

#endif