#include <Commands/Auto/AutoDoNothing.h>

AutoDoNothing::AutoDoNothing():
	CommandGroup("AutoDoNothing")
{
	SetTimeout(15.0);

}
