#include <algorithm>
#include <vector>

#include "filtres.h"
#include "bmp.h"

using namespace std;

void Negative::Apply(Image& userImage) 
{
	size_t height = userImage.fields_[Image::fieldsToIndex::Height];
	size_t width = userImage.fields_[Image::fieldsToIndex::Width];

	for(size_t i = 0; i < height; i++) 
	{
		for(size_t j = 0; j < width; j++) 
		{
			for(size_t k = 0; k < 3; k++)
				userImage.pixels_[i][j][k] = ~userImage.pixels_[i][j][k];
		}
	}
}

Cut::Cut(size_t x, size_t y, uint32_t newHeight, uint32_t newWidth):x_(x), y_(x), newHeight_(newHeight), newWidth_(newWidth){}

void Cut::Apply(Image& userImage) 
{
	size_t height = userImage.fields_[Image::fieldsToIndex::Height];
	size_t width = userImage.fields_[Image::fieldsToIndex::Width];
	vector< vector< vector<uint8_t> > > copy(newHeight_, vector< vector<uint8_t> >(newWidth_));

	for(size_t i = 0; i < newHeight_; i++) 
	{
		for(size_t j = 0; j < newWidth_; j++)
			copy[i][j] = userImage.pixels_[i + x_][j + y_];
	}

	userImage.pixels_ = copy;
	size_t cntBytesInPix = userImage.fields_[Image::fieldsToIndex::BitCountInPixel] / 8;
	size_t subBytes = (height * width - newHeight_ * newWidth_) * cntBytesInPix;
	userImage.fields_[Image::fieldsToIndex::SizeFile] -= subBytes;
	userImage.fields_[Image::fieldsToIndex::SizeImage] -= subBytes;
	userImage.fields_[Image::fieldsToIndex::Height] = newHeight_;
	userImage.fields_[Image::fieldsToIndex::Width]  = newWidth_;
}

void MakeGray::Apply(Image& userImage) 
{
	size_t height = userImage.fields_[Image::fieldsToIndex::Height];
	size_t width = userImage.fields_[Image::fieldsToIndex::Width];
	for(size_t i = 0; i < height; i++) 
	{
		for(size_t j = 0; j < width; j++) 
		{
			double res =  userImage.pixels_[i][j][Image::colorsToIndex::R] * 0.299 + userImage.pixels_[i][j][Image::colorsToIndex::G] * 0.587 + userImage.pixels_[i][j][Image::colorsToIndex::B] * 0.114;

			res = (res > 255 ? 255 : res);
			for(int k = 0; k < 3; k++)
				userImage.pixels_[i][j][k] = static_cast<uint8_t> (res);
		}
	}
}