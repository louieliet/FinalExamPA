#include "MainHeader.h"

int MakeEmptyMateriaFile(){

    ofstream file{ "materia.dat", ios::out | ios::binary };

    if (!file) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    Materia out;

    for(int i=0; i<10; ++i){
        file.write(reinterpret_cast<const char*>(&out), sizeof(Materia));
    }

    return 0;
}


int MakeMateriaFile(vector<Materia> list){

    fstream outFile{"materia.dat", ios::in | ios::out | ios::binary};

    if(!outFile){
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    for( auto i : list ){
        outFile.seekp( (i.getID()) * sizeof(Materia) );
        outFile.write( reinterpret_cast<const char*>(&i), sizeof(Materia) );
    }
    
    return 0;
}

void outputLine(ostream& output, const Materia& record) {
    
    output << left <<setw(20) << "Materia";
    output << left <<setw(20) << "Clave";
	output << setw(20) << "Profesor"
    << endl;
	
    output << left << setw(20) << record.getName()
        << setw(20) << record.getClave()
        << setw(5) << record.getProfesor() << endl;
}


int Search(vector<Materia> list)
{
    ifstream file{"materia.dat", ios::in};

    if(!file){
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string op;
    int flag;

    cout << "Deme la clave" << endl;
    cin >> op;

    flag = 0;

    for( auto i : list)
    {
        if(i.getClave()==op)
        {
            file.seekg(i.getID()*sizeof(Materia));
            file.read(reinterpret_cast<char*>(&i),sizeof(Materia));
            outputLine(cout, i);
            flag = 1;
        }

    }
    if(flag == 0){
        cout << "Error, no se encontro la materia" << endl;
    }
}




