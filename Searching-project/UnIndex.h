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
#include <utility>

#define DEFAULT_PAGE_SIZE 100 // # de bytes
#define FILE_IDS_OFFSET 800 // # bits
#define OPTIMUM_BUFFER_SIZE 1000  // # de URL maximo en RAM
#define INT_BYTES 4
#define SIZE_CACHE 50  // tamaño de la cache
#define DEFAULT_UNINDEX_FNAME "auxiliar.txt"
#define DEFAULT_UNINDEX_FNAME_2 "url.bin"

class UnIndex
{
private:

	std::fstream file;
	int current_page;
	int page_size;
	int elements_in_page;
	unsigned long long stringsize;
	std::string  s;
	std::map<int, std::string> mapa;
	std::map<int, std::pair<unsigned long long,int> > TableId;
	std::queue<int> cola;

public:
	UnIndex();
	~UnIndex();
	int CapacityPerPage();
	std::string Get(int id); //for this version.. reads all blocks from disk for every word
	//TODO: readBlock (read only a piece of results from one block in disk by demand)
	void write(std::string in, int ID);
	void Finish_write();
	void Save(std::string fname = DEFAULT_UNINDEX_FNAME);
	void Load(std::string fname = DEFAULT_UNINDEX_FNAME);
};

UnIndex::UnIndex()
{
	file.open("url.bin", std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);
	// check if file is open
	page_size = DEFAULT_PAGE_SIZE;
	elements_in_page = page_size / sizeof(char);
	current_page = 0;
	stringsize = 0;
	s = "";
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
void UnIndex::write(std::string in,int ID)
{
	int sz = in.size();
	
	TableId[ID] = std::make_pair(stringsize,sz);
	stringsize += sz;
	s.append(in);
	if (s.length() > OPTIMUM_BUFFER_SIZE){
		file << s;
		file.flush();  // libera RAM
		s.clear();
	}
	current_page++;
}

std::string UnIndex::Get(int id)
{
	if (TableId.find(id)==TableId.end())
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
		int size = TableId[id].second;
		unsigned long long pointer = TableId[id].first;

		char * buffer = new char[size];    // Arrego para extraer los caracteres del archivo
		file.seekg(file.beg + (pointer));  // moviendo el lector del file
		file.read(buffer, size);		   // Leendo desde el file
		
		std::string src(buffer, buffer + size); // transfer to src from buffer

		// Actualizas los datos de la cola y del mapa (CACHE)
		if (cola.size() <= SIZE_CACHE){
			cola.push(id);
			mapa[id] = src;
		}
		else {
			// Eliminamos elemento mas antiguo
			mapa.erase(mapa.find(cola.front()));
			cola.pop();
			// Agregamos nuevo elemento
			cola.push(id);
			mapa[id] = src;
		}
		return src;
	}
}

void UnIndex::Save(std::string fname)
{
	std::ofstream file;

	file.open(fname, std::ofstream::out);
	std::cout << fname.c_str() << std::endl;
	std::map<int, std::pair<unsigned long long, int> >::iterator it;
	for (it = TableId.begin(); it != TableId.end();it++){
		file << (*it).first << " " << (*it).second.first << " " << (*it).second.second << "\n";
	}
	file.close();
}

void UnIndex::Load(std::string fname)
{
	long long val;
	std::ifstream file;
	std::string buf, tmp2;
	std::stringstream aux;
	int id = 0, N;

	file.open(fname, std::ifstream::in);

	N = 0;
	while (!file.eof())
	{
		std::getline(file, tmp2);
		N++;
	}

	int key, size;
	unsigned long long pointer;

	file.close();
	file.open(fname, std::ifstream::in);

	for (int i = 0; i < N; i++)
	{
		std::getline(file, tmp2);
		std::istringstream is(tmp2);
		is >> key >> pointer >> size;
		TableId[key] = std::make_pair(pointer,size);
	}

	file.close();
}
#endif
