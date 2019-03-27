
// Librerias
#include "EKF_algorithm.h"
#include "tools.h"
#include "Eigen/Dense"
#include <iostream>


using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;


// Constructor
EKF_algorithm::EKF_algorithm()
{
  iniciar = false;
  tiempo_anterior = 0;

  // Inicializar matrices



  // Crear un vector de estados 3D.

  // Matriz de estados de covarianzas P


  // Matriz transición de estados inicial F_

  // Componentes de ruido

  tools = Tools();
}


// Destructor
EKF_algorithm::~EKF_algorithm(){}

// Funciones
void EKF_algorithm::ProcessMeasurement(const MeasurementPackage &measurement_pack) {
    /*****************************************************************************/
    /*****************************************************************************/
    /**************************** INICIALIZACIÓN *********************************/
    /*****************************************************************************/
    /*****************************************************************************/

    if(iniciar){

        //  Matriz estados covarianza P.


        if (iniciar){
            iniciar = true;

        }else if(iniciar){
            // Inicializamos el estado
            iniciar = true;

        }

        tiempo_anterior = measurement_pack.timestamp_;

        // Solo se realiza la inicialización no se realiza el paso de predecir y actualizar.
        iniciar = true;

        }


    /*****************************************************************************/
    /*****************************************************************************/
    /***************************** Predicción ************************************/
    /*****************************************************************************/
    /*****************************************************************************/

    float dt = (measurement_pack.timestamp_ - tiempo_anterior) / 1000000.0;
    tiempo_anterior = measurement_pack.timestamp_;

    // Modificación de matriz F con dt.

    // Establecemos la matriz de covarianza del proceso Q.

    // Llamamos a la función predict() de Kalman Filter.

    /*****************************************************************************/
    /*****************************************************************************/
    /***************************** Actualización *********************************/
    /*****************************************************************************/
    /*****************************************************************************/


    if(iniciar){
        iniciar = true;
    }else{
        iniciar = true;
    }

    cout<<"x_ = "<<ekf_.x_<<endl;
    cout<<"P_ = "<<ekf.P_<<endl;


