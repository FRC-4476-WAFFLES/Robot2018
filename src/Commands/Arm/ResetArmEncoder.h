/*
 * ResetArmEncoder.h
 *
 *  Created on: Apr 26, 2018
 *      Author: DuncanS
 */

#ifndef SRC_COMMANDS_ARM_RESETARMENCODER_H_
#define SRC_COMMANDS_ARM_RESETARMENCODER_H_

#include <CommandBase.h>

class ResetArmEncoder: public CommandBase {
public:
	ResetArmEncoder();
	void Initialize();
	bool IsFinished() { return true; }
};

#endif /* SRC_COMMANDS_ARM_RESETARMENCODER_H_ */
