#include "bmp.h"

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

template <typename Type>
void Read(ifstream &fp, Type &result, size_t size) 
{
    fp.read(reinterpret_cast<char*>(&result), size);
}

template <typename Type>
void Write(ofstream &fp, Type &result, size_t size) 
{
    fp.write(reinterpret_cast<char*>(&result), size);
}


size_t GetBytesFromIndex(size_t index) 
{
	if(index == 0 || index == 7 || index == 8)
		return sizeof(uint16_t);

	return sizeof(uint32_t);
}

Image::Image(const char* fileName) 
{
	ifstream fileStream(fileName, ifstream::binary);
	fields_.fill(0);
	if(!fileStream) 
		throw runtime_error("Error opening file"); 

	for(size_t i = 0; i < 15; i++)
		Read(fileStream, fields_[i], GetBytesFromIndex(i));

	if(fields_[fieldsToIndex::Type] != BMP_FORMAT)
		throw runtime_error("This is file not bmp");

	fileStream.seekg(fields_[fieldsToIndex::BitsOffset], ios::beg);
	
	size_t cntBytesInPix = fields_[fieldsToIndex::BitCountInPixel] / 8;
	size_t height = fields_[fieldsToIndex::Height];
	size_t width = fields_[fieldsToIndex::Width];
	size_t padding = (4 - (width * cntBytesInPix) % 4) % 4;
	char pad[4];

	pixels_.resize(height);
	for(int i = 0; i < height; i++) 
	{
		pixels_[i].resize(width);
		for(int j = 0; j < width; j++) 
			pixels_[i][j].resize(4);
	}

	for(int i = 0; i < height; i++) 
	{
		for(int j = 0; j < width; j++) 
		{
			for(int k = 0; k < cntBytesInPix; k++)
				Read(fileStream, pixels_[i][j][k], 1);
		}
		Read(fileStream, pad, padding);
	}

	fileStream.close();
} 

void Image::SaveImage() 
{ 
	ofstream fileStream("out.bmp", ofstream::binary);

	for(size_t i = 0; i < 15; i++) 
		Write(fileStream, fields_[i], GetBytesFromIndex(i));

	fileStream.seekp(fields_[fieldsToIndex::BitsOffset], ios::beg);

	size_t cntBytesInPix = fields_[fieldsToIndex::BitCountInPixel] / 8;
	size_t height = fields_[fieldsToIndex::Height];
	size_t width = fields_[fieldsToIndex::Width];
	size_t padding = (4 - (width * cntBytesInPix) % 4) % 4;
	char pad[3] = {0, 0, 0};

	for(int i = 0; i < height; i++) 
	{
		for(int j = 0; j < width; j++) 
		{
			for(int k = 0; k < cntBytesInPix; k++) 
				Write(fileStream, pixels_[i][j][k], 1);
		}
		Write(fileStream, pad, padding);
	}

	fileStream.close();
}

void Docs() 
{ 
	cout << "./main <fileName>.bmp --<filtrs>\n";
	cout << "\t--help[-h] - Документация\n";
    cout << "\t--negative[-ng] -- применить фильтр \"негатив\"\n";
    cout << "\t--grey[-g] -- применить чернобелый фильтр\n";
    cout << "\t--cut[-c] x y высота ширина -- вырезать прямоугольник с левым верхним углом в точке (x, y) с заданной шириной и высотой.\n";
    cout << "\tРезультат сохранен в out.bmp\n"; 
}