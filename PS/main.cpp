#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

#include "bmp.h"
#include "filtres.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	if(argc <= 2) 
	{
		if(argc < 2)
			cout << "Error opening file\n";
		Docs();

		return 0;
	}

	Image newImage = Image(argv[1]);

	for(size_t i = 2; i < argc; i++) 
	{
		if(!strcmp(argv[i], "--negative") || !strcmp(argv[i], "-ng")) 
		{
			Negative op;
			op.Apply(newImage);
		}
		if(!strcmp(argv[i], "--cut") || !strcmp(argv[i], "-c")) 
		{
			if(i + 4 >= argc)
				throw runtime_error("Wrong format. Requires 4 numbers x y height width");
			size_t x = atoi(argv[i + 1]);
			size_t y = atoi(argv[i + 2]);
			size_t height = atoi(argv[i + 3]);
			size_t width = atoi(argv[i + 4]);
			Cut op(x, y, height, width);
			op.Apply(newImage);
			i += 3;
		}
		if(!strcmp(argv[i], "--grey") || !strcmp(argv[i], "-g")) 
		{
			MakeGray op;
			op.Apply(newImage);
		}
	}

	newImage.SaveImage();

	return 0;
}