#ifndef climber_H
#define climber_H

#include "CommandBase.h"

class climber : public CommandBase {
public:
	climber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	constexpr float P = 1; //todo get number
};

#endif  // climber_H
