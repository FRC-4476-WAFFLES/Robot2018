#!/bin/bash

# FIXME: Make sure the directory structure is still the same.
exit 1

./build.sh
ssh lvuser@roborio-4476-frc.local "cat > ~/FRCUserProgram && killall FRCUserProgram && ~/FRCUserProgram" < Debug/FRCUserProgram

