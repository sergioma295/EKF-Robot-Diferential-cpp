#ifndef EKF_ALGORITHM_H
#define EKF_ALGORITHM_H



#include "measurement_package.h"
#include "Eigen/Dense"
#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.h"
#include "tools.h"

class EKF_algorithm {
public:

  // Constructor.

  EKF_algorithm();


  //Destructor.
  virtual ~EKF_algorithm();

  /**
  * Run the whole flow of the Kalman Filter from here.
  */
  void ProcessMeasurement(const MeasurementPackage &measurement_pack);

  /**
  * Kalman Filter update and prediction math lives in here.
  */
  KalmanFilter ekf_;

private:
  // check whether the tracking toolbox was initiallized or not (first measurement)
  bool iniciar;

  // previous timestamp
  long tiempo_anterior;

  // tool object used to compute Jacobian and RMSE
  Tools tools;
  Eigen::MatrixXd R_laser_;
  Eigen::MatrixXd R_radar_;
  Eigen::MatrixXd H_laser_;
  Eigen::MatrixXd Hj_;

  //acceleration noise components
  float noise_ax;
  float noise_ay;
};

#endif /* EKF_ALGORITHM_H */
