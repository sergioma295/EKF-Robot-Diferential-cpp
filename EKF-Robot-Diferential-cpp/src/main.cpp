/*
  Implementación del filtro extendido de kalman; EKF para la localización de un robot móvil
  en configuración diferencial. main.cpp

  Sergio Masa Avís --> sergioma295@gmail.com

*/


// Librerías

#include <iostream>
#include "Eigen/Dense"



using namespace std;
using namespace Eigen;



// Prototipo de función
void check_arguments(int argc,char* argv[]){
    string usage_instructions = "Usage instructions: ";
    usage_instructions += argv[0];
    usage_instructions += "path/to/input.txt output.txt";

    bool has_valid_args = false;

    // Check if user has provide input and output files
    if(argc == 1){
        cerr<<usage_instructions<<endl;

    }else if (argc ==2){
        cerr <<"Please include an output file.\n"<<usage_instructions<<endl;

    }else if (argc==3){
        has_valid_args = true;

    }else if(argc>3){
        cerr<<"Too many arguments.\n"<<usage_instructions<<endl;

    }

    if(!has_valid_args){
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[])
{
    // Comprobamos los argumentos que ha pasado el usuario por consola.
    check_arguments(argc,argv);
    cout << "Hello world!" << endl;
    return 0;
}
