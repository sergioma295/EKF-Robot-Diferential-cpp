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



using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;



// Prototipo de función
void check_arguments(int argc,char* argv[]){

    string instructions = "Instrucciones del fichero: ";
    instructions += "Es necesarios poner la ruta de los ficheros de entrada (medidas) y salida. \nComando: ";
    instructions += argv[0];
    instructions += " data/input.txt data/output.txt";

    // Check arguments
    bool valid_args = false;

    // Check if user has provide input and output files
    if(argc == 1){

        if(argv[0]!="./EKF"){
            cerr<<instructions<<endl;
        }

    }else if (argc ==2){

        cerr<<"Faltan argumentos, ¡¡ VUELVA A INTENTARLO !! \n\n"<<instructions<<endl;




    }else if (argc==3){

        cerr<<"¡Orden correcta! \n...Espere..."<<endl;
        valid_args = true;



    }else if(argc>3){
        cerr<<"Demasiados argumentos. ¡¡ VUELVA A INTENTARLO !!\n\n"<<instructions<<endl;

    }

    if(!valid_args){
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
