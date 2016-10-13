#pragma once
#ifndef _UnIndex_H_
#define _UnIndex_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <queue>

#define DEFAULT_PAGE_SIZE 100 // # de bytes
#define FILE_IDS_OFFSET 800 // # bits
#define OPTIMUM_BUFFER_SIZE 1000  // # de URL maximo en RAM
#define INT_BYTES 4
#define SIZE_CACHE 50  // tamaño de la cache

class UnIndex
{
private:

	std::fstream file;
	int current_page;
	int page_size;
	int elements_in_page;
	std::string  s;
	std::vector<unsigned long long> Ids;
	std::map<int, std::string> mapa;
	std::queue<int> cola;

public:
	UnIndex();
	~UnIndex();
	int CapacityPerPage();
	std::string Get(int id); //for this version.. reads all blocks from disk for every word
	//TODO: readBlock (read only a piece of results from one block in disk by demand)
	void write(std::string in);
	void Finish_write();
};

UnIndex::UnIndex()
{
	file.open("url.bin", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);
	//check if file is open
	page_size = DEFAULT_PAGE_SIZE;
	elements_in_page = page_size / sizeof(char);
	current_page = 0;
	s = "";
	Ids.push_back(0);
}
UnIndex::~UnIndex()
{
	file.close();
}
int UnIndex::CapacityPerPage()
{
	return elements_in_page;
}

void UnIndex::Finish_write(){
	file << s;
	file.flush();
	//file.close();
}
void UnIndex::write(std::string in)
{
	int sz = Ids.size();
	Ids.push_back(Ids[sz - 1] + in.size());
	
	s.append(in);
	if (s.length() > OPTIMUM_BUFFER_SIZE){
		file << s;
		file.flush();  // libera ram
		s.clear();
	}
	current_page++;
}
std::string UnIndex::Get(int id)
{
	id++; // one more because ID begin in 0

	if (id >= Ids.size())
	{
		return "Error no valid Index ...\n";
	}

	// El modulo es para busquedas recientes
	// el numero de busquedas tiene que almacenar en la tabla tiene que ser variable
	// y a medida de ingresar los nuevos elementos tienen que salir los ultimos
	if (mapa.find(id) != mapa.end()) {
		return mapa[id];
	}
	else {
		int size = Ids[id] - Ids[id - 1];
		char * buffer = new char[size];    // Arrego para extraer los caracteres del archivo
		file.seekg(file.beg + (Ids[id - 1]));  // moviendo el lector del file
		file.read(buffer, size);		   // Leendo desde el file
		std::string sr = "";

		for (int i = 0; i < size; i++) sr += buffer[i];

		// Actualizas los datos de la cola y del mapa
		if (cola.size() <= SIZE_CACHE){
			cola.push(id);
			mapa[id] = sr;
		}
		else {
			// Eliminamos elemento mas antiguo
			mapa.erase(mapa.find(cola.front()));
			cola.pop();
			// Agregamos nuevo elemento
			cola.push(id);
			mapa[id] = sr;
		}

		return sr;
	}
}
#endif
