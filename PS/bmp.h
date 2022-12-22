#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include <array>
#include <cstdint>
#include <vector>

using namespace std;

const uint16_t BMP_FORMAT = 0x4D42;
const size_t BMP_HEADER_SIZE = 14;
const size_t BMP_INFO_SIZE = 40;

class Negative;
class Cut;
class MakeGray;

class Image { 
private:
	array<uint32_t, 15> fields_;
	vector< vector< vector<uint8_t> > > pixels_;
public:
	
	enum fieldsToIndex 
	{
		Type = 0, // 0
    	SizeFile, // 1 
    	Reserved, // 2
    	BitsOffset, // 3
    	SizeStruct, // 4
    	Width, // 5
    	Height, // 6
    	Planes, // 7
    	BitCountInPixel, // 8
    	Compression, // 9
    	SizeImage, // 10
    	XPelsPerMeter, // 11
    	YPelsPerMeter, // 12
    	ClrUsed, // 13
    	ClrImportant //14
	};
	enum colorsToIndex 
	{
		R = 0,
		G,
		B,
		A
	};
	Image(const char* fileName);
	void SaveImage();

	friend Negative;
	friend Cut;
	friend MakeGray;
};

void Docs();

#endif