#include "PIDPreferences.h"

double UpdateSinglePreference(std::string name, double v) {
    if(!Preferences::GetInstance()->ContainsKey(name)) {
        Preferences::GetInstance()->PutDouble(name, v);
    }
    return Preferences::GetInstance()->GetDouble(name, v);
}

void UpdatePID(std::string name, WPI_TalonSRX &talon, double p, double i, double d, double f) {
	talon.Config_kP(UpdateSinglePreference(name + " P", p), 0, 0);
	talon.Config_kI(UpdateSinglePreference(name + " I", i), 0, 0);
	talon.Config_kD(UpdateSinglePreference(name + " D", d), 0, 0);
    talon.Config_kF(UpdateSinglePreference(name + " F", f), 0, 0);
}

void UpdatePID(std::string name, WPI_TalonSRX &talon, double p, double i, double d) {
    UpdatePID(name, talon, p, i, d, 0.0);
}

void UpdatePID(std::string name, WPI_TalonSRX &talon) {
    UpdatePID(name, talon, 0.0, 0.0, 0.0, 0.0);
}
