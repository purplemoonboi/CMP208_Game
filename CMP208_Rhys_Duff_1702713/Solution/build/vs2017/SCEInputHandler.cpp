#include "pch.h"
#include "SCEInputHandler.h"
#include "Event.h"

/*..gef input includes..*/
#include "input/input_manager.h"
#include "input/sony_controller_input_manager.h"


/*..Actions..*/
#include "AddForceToRightEngine.h"

//@brief Variable tracks how many pawn controllers are active. 
static uint32 controller_counter = 0;

SCE_InputHandler::SCE_InputHandler(gef::InputManager* input_manager_, Pawn* pawn_)
	:input_manager(input_manager_),
	pawn(pawn_)
{
	cross = new Button();
	circle = new Button();
	triangle = new Button();
	sqaure = new Button();

	dpad_up = new Button();
	dpad_down = new Button();
	dpad_left = new Button();
	dpad_right = new Button();

	start = new Button();
	options = new Button();

	right_bumper = new Button();
	right_trigger = new Button();
	right_stick_button = new Button();

	left_bumper = new Button();
	left_trigger = new Button();
	left_stick_button = new Button();

	BindButtons();
}

SCE_InputHandler::~SCE_InputHandler()
{
	delete cross;
	cross = nullptr;

	delete circle;
	circle =  nullptr;

	delete triangle;
	triangle =  nullptr;

	delete sqaure;
	sqaure =  nullptr;

	delete dpad_up;
	dpad_up =  nullptr;

	delete dpad_down;
	dpad_down =  nullptr;

	delete dpad_left;
	dpad_left= nullptr;

	delete dpad_right;
	dpad_right= nullptr;

	delete start;
	start= nullptr;

	delete options;
	options= nullptr;

	delete right_bumper;
	right_bumper= nullptr;

	delete right_trigger;
	right_trigger= nullptr;

	delete right_stick_button;
	right_stick_button= nullptr;

	delete left_bumper;
	left_bumper= nullptr;

	delete left_trigger;
	left_trigger= nullptr;

	delete left_stick_button;
	left_stick_button= nullptr;
}

void SCE_InputHandler::BindButtons()
{


	/*..Asign the actions to the buttons..*/
	right_trigger->action = &add_force_r;
	left_trigger->action = &add_force_l;
}

SCE_InputHandler* SCE_InputHandler::Create(gef::InputManager* input_manager_, Pawn* pawn_)
{
	return new SCE_InputHandler(input_manager_, pawn_);
}

Event* SCE_InputHandler::ControllerHandler()
{
	gef::SonyControllerInputManager* sce_in_manager = input_manager->controller_input();

	if (sce_in_manager)
	{

		const gef::SonyController* sce_controller = sce_in_manager->GetController(controller_counter);

		if (sce_controller->buttons_down() & gef_SONY_CTRL_CROSS)
		{
			return cross->action;
		}
		if (sce_controller->buttons_down() & gef_SONY_CTRL_L2)
		{
			return left_trigger->action;
		}
		if (sce_controller->buttons_down() & gef_SONY_CTRL_R2)
		{
			return right_trigger->action;
		}
		else
		{
			return nullptr;
		}
	}

}

void SCE_InputHandler::ProcessSonyController(float delta_time)
{
	input_manager->Update();

	Event* event_ = ControllerHandler();

	if (event_ != nullptr)
	{
		event_->Action(pawn, delta_time);
	}
}
