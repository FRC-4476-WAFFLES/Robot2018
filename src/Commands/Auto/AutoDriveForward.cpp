#include <Commands/Auto/AutoDriveForward.h>
#include "Commands/Drive/DriveAuto.h"

AutoDriveForward::AutoDriveForward() {
	AddSequential(new DriveAuto("drive straight forward"));
}
