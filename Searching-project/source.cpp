#include <cstdio>
#include <iostream>
#include <fstream>
#include "File.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include "Swap.h"
#include "UnIndex.h"

int main(){
	std::ifstream f;
	File text;
	f.open("D:\\prueba.txt");
	UnIndex UnIdx;
	int ID = 0;
	while (!f.eof()){
		std::getline(f, text.url);
		std::getline(f, text.title);
		std::getline(f, text.content);
		std::getline(f, text.bug);
		
		UnIdx.write(text.url,ID);

		printf("%s\n", text.url.c_str());
		printf("%s\n", text.title.c_str());
		//printf("%s\n", text.content.c_str());
		ID++;
	}

	UnIdx.Finish_write(); // es importante despues de ingresar todos los URL`s

	for(int i = 0; i <= 20; i++) {
		std::cout << "id=" << i << std::endl;
		std::cout << UnIdx.Get(i) << std::endl << std::endl;
	}
	
	printf("Fin!\n");
	std::cin.get();

	return 0;
}
