#!/bin/bash

./build.sh
ssh lvuser@roborio-4476-frc.local "cat > ~/FRCUserProgram.new && killall FRCUserProgram; mv ~/FRCUserProgram.new ~/FRCUserProgram && chmod +x ~/FRCUserProgram && ~/FRCUserProgram" < Debug/FRCUserProgram

