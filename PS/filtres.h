#ifndef FILTERS_H_INCLUDED
#define FILTERS_H_INCLUDED

#include "bmp.h"

class Filtr {
public:
	virtual void Apply(Image& userImage) = 0;
};

class Negative:public Filtr {
public:
	void Apply(Image& userImage) override;
};

class MakeGray:public Filtr {
public:
	void Apply(Image& userImage) override;
};

class Cut:public Filtr {
public:
	void Apply(Image& userImage) override;
	Cut(size_t x, size_t y, uint32_t newHeight, uint32_t newWidth);
private:
	size_t x_;
	size_t y_;
	uint32_t newHeight_;
	uint32_t newWidth_;
};

#endif