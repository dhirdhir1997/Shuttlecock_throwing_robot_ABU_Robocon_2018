long int get_pidchange_rr(long int optimal_value, long int sensor_value, long int prev_error, long int temp_integral) //PID algorithm to correct errors.
{
  float change;

  error = optimal_value - sensor_value;

  integral = temp_integral + Ki * error;

  if (integral > (200))
    integral = 200;
  else if (integral < (-200))
    integral = -200;

  derivative = error - prev_error;

  change = Kp * error + Ki * integral + Kd * derivative;

  previous_integral_rr = integral;
  previous_error_rr = error;
  change=change/100;
  return change;
}

long int get_pidchange_fl(long int optimal_value, long int sensor_value, long int prev_error, long int temp_integral) //PID algorithm to correct errors.
{
  float change;

  error = optimal_value - sensor_value;

  integral = temp_integral + Ki * error;

  if (integral > (200))
    integral = 200;
  else if (integral < (-200))
    integral = -200;

  derivative = error - prev_error;

  change = Kp * error + Ki * integral + Kd * derivative;

  previous_integral_fl = integral;
  previous_error_fl = error;
  change=change/100;
  return change;
}

long int get_pidchange_fr(long int optimal_value, long int sensor_value, long int prev_error, long int temp_integral) //PID algorithm to correct errors.
{
  float change;

  error = optimal_value - sensor_value;

  integral = temp_integral + Ki * error;

  if (integral > (200))
    integral = 200;
  else if (integral < (-200))
    integral = -200;

  derivative = error - prev_error;

  change = Kp * error + Ki * integral + Kd * derivative;

  previous_integral_fr = integral;
  previous_error_fr = error;
  change=change/100;
  return change;
}

