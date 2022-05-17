#include <iostream>
#include <fstream>  
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <wchar.h>
#include <locale.h>

using namespace std;


class Materia {
public:
	Materia(const string& id = "NON", const string& name = "NONE", const string& profesor = "PANCHO") 
	{
        setClave(id);
        setProfe(profesor);
		setNombre(name);
		
	}
	void setClave(const string& clave) {

		size_t length{ clave.size() };
		length = (length < 4 ? length : 3);
		clave.copy(this->clave, length);
		this->clave[length] = '\0'; 

	}
	void setNombre(const string& nombre) {

		size_t length{ nombre.size() };
		length = (length < 15 ? length : 14);
		nombre.copy(this->nombre, length);
		this->nombre[length] = '\0'; 

	}
    
	void setProfe(const string& profesor) {

		size_t length{ profesor.size() };
		length = (length < 15 ? length : 14);
		profesor.copy(this->profesor, length);
		this->profesor[length] = '\0'; 

	}
    
    int setfileID()
    {
        int v1 = rand() % 10;
        return v1;
    }
    string getClave() const {return clave;}
	string getName() const {return nombre;}
    string getProfesor() const {return profesor;}
    int getID() const {return fileid;}
	
private:
    
    int fileid = setfileID();
    char clave[4];
	char nombre[15];
    char profesor[15];

};
