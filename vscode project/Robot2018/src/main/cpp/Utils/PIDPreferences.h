#pragma once
#include <string>
#include <ctre/Phoenix.h>
#include <Preferences.h>

void UpdatePID(std::string name, WPI_TalonSRX &talon, double p, double i, double d, double f);
void UpdatePID(std::string name, WPI_TalonSRX &talon, double p, double i, double d);
void UpdatePID(std::string name, WPI_TalonSRX &talon);
double GetP(std::string name, double v);
double GetI(std::string name, double v);
double GetD(std::string name, double v);
double UpdateSinglePreference(std::string name, double v);
