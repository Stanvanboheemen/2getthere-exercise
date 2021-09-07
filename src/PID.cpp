#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    dt = 0.01;

    p_error = 0;
    i_error = 0;
    d_error = 0;
    cte_prev = 0;
}

void PID::UpdateError(double cte) {
    /**
   * TODO: Update PID errors based on cte.
   */
    p_error = cte;
    i_error = i_error + cte*dt;
    d_error = (cte-cte_prev)/dt;
    cte_prev = cte;
}

double PID::ControlAction() {
    double steer_value = - Kp*p_error - Ki*i_error - Kd*d_error;
    if (steer_value < -1) {
        steer_value = -1;
    } else if (steer_value > 1) {
            steer_value = 1;
    }
    else steer_value = steer_value;
    return steer_value;
}

double PID::TotalError() {
    /**
   * TODO: Calculate and return the total error
   */
    return p_error;  // TODO: Add your total error calc here!
}
