/*
  Implementación del filtro extendido de kalman; EKF para la localización de un robot móvil
  en configuración diferencial. main.cpp

  Sergio Masa Avís --> sergioma295@gmail.com

  Pasos a seguir:
    1) Abrir terminal en la raiz del proyecto donde se encuentra el CMakeLists.txt
    2) --> mkdir build && cd build
    3) --> cmake .. && make
    4) --> ./EKF measurements/input.txt measurements/output.txt

*/


// Librerías

#include <iostream>
#include <vector>
#include "Eigen/Dense"
#include <fstream>          // check_files



using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;



// Prototipo de función comprobar argumentos.
void check_arguments(int,char* argv[]);

// Prototipo de función comprobar carpetas.
void check_files(ifstream&, string&, ofstream&, string&);


// main
int main(int argc, char* argv[])
{
    // Comprobamos los argumentos que ha pasado el usuario por consola.
    check_arguments(argc,argv);

    // Guardamos la carpeta que contiene los datos de entrada (sensores) en el directorio.
    string in_file_name_ = argv[1]; ifstream in_file_(in_file_name_.c_str(), ifstream::in);

    // Guardamos la carpeta que contiene los datos de salida (sensores) en el directo
    string out_file_name_ = argv[2]; ofstream out_file_(out_file_name_.c_str(), ofstream::out);


    // Comprobamos si ambos ficheros están en el directorio.
    check_files(in_file_, in_file_name_, out_file_, out_file_name_);



    cout << "Hello world!" << endl;
    return 0;
}


// Función para comprobar los argumentos que pasa el usuario por consola
void check_arguments(int argc,char* argv[]){

    string instructions = "Instrucciones del fichero: "; instructions += "Es necesarios poner la ruta de los ficheros de entrada (medidas) y salida. \nComando: ";
    instructions += argv[0]; instructions += " ../data/input.txt ../data/output.txt";

    // Check arguments
    bool valid_args = false;

    // Check if user has provide input and output files
    if(argc == 1){
        if(argv[0]!="./EKF"){cerr<<instructions<<endl;}

        }else if (argc ==2){ cerr<<"Faltan argumentos, ¡¡ VUELVA A INTENTARLO !! \n\n"<<instructions<<endl;

        }else if (argc==3){
            cerr<<"\n...Espere...\n"<<endl;
            valid_args = true;

        }else if(argc>3){cerr<<"Demasiados argumentos. ¡¡ VUELVA A INTENTARLO !!\n\n"<<instructions<<endl;}

    if(!valid_args){exit(EXIT_FAILURE);}
}

// Función para comprobar que existen los directorios indicados por el usuario
void check_files(ifstream& in_file, string& in_name, ofstream& out_file, string& out_name) {

  if (!in_file.is_open()) {
    cerr << "¡La carpeta '" << in_name<<"' no se puede abrir!" << endl;
    exit(EXIT_FAILURE);
  }

  if (!out_file.is_open()) {
    cerr << "¡La carpeta '" << out_name << "' no se puede abrir!"<<endl;
    exit(EXIT_FAILURE);
  }
}
