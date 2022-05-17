#include "Header.h"

int main(){

    Materia m1("POO","ProgramacionOrientada","Vicky");
    Materia m2("PA1","ProgramacionAvanzada","Ferro");
    Materia m3("MAT","Matematicas","Quintero");
    Materia m4("PYS","PersonaySociedad","Claudia");

    vector<Materia> materias{m1,m2,m3,m4};

    bool running = true;
    int op;

    MakeEmptyMateriaFile();
    MakeMateriaFile(materias);

    system("cls");

    while(running){

        system("Pause");

        cout << setw(20) << "-- Menu --" << endl;
        cout <<  "1. Buscar materia por clave " << endl;
        cout <<  "2. Salir " << endl;

        cin>> op;

        switch (op)
        {
        case 1:
            Search(materias);
            break;
        case 2:
            cout << "Hasta luego!" << endl;
            running = false;
        default:
            cout << "Introduzca una opcion valida" << endl;
            break;
        }
    }

    return 0;
}