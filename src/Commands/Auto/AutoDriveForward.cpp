#include <Commands/Auto/AutoDriveForward.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/KnownPaths.h"

AutoDriveForward::AutoDriveForward() {
	AddSequential(new DriveAuto(DrivePastLine()));
}
