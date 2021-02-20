#pragma once
#include "GameObject.h"


namespace gef
{
	class Platform;
}

class PawnController;

///A 3D gameobject supporting user input.
class Pawn : public GameObject
{
public:

	/*..Constructor..*/

	/// @brief Constructor for the gameobject.
	/// @param[in] PawnController*	A pointer to the input handler.
	Pawn(PrimitiveBuilder* primitive_builder, gef::Platform& platform_);

	~Pawn();

public:

	/*..Methods public access..*/
	static Pawn* Create(PrimitiveBuilder* primitive_builder, gef::Platform& platform_);

	/// @brief Updates this objects attributes.
	/// @param[in] Delta time tracks the time since last frame.
	virtual void Update(float delta_time) override;

protected:
	//Not sure just yet if i'll need this here.
	PawnController* controller;


};

