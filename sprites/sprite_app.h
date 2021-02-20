#ifndef _sprite_app_H
#define _sprite_app_H

#include <system/application.h>
#include <graphics/sprite.h>
#include <maths/vector4.h>
#include <vector>

#include "primitive_builder.h"

#include "Actor.h"
#include "Pawn3d.h"

// FRAMEWORK FORWARD DECLARATIONS
namespace gef
{
	class Platform;
	class SpriteRenderer;
	class Renderer3D;
	class Font;
}

/*..Rhys Duff - 1702718..*/
//Forward declarations

class Pawn;
class Actor;
class PawnController;
class Camera;

class SpriteApp : public gef::Application
{
public:
	SpriteApp(gef::Platform& platform);
	void Init();
	void CleanUp();
	bool Update(float frame_time);
	void Render();
private:

	void HandleInput();

	void InitFont();
	void CleanUpFont();
	void DrawHUD();

	void SetupLights();

	gef::Font* font_;
	gef::Font* camera_debugger;
	gef::Font* controller_debugger;
	gef::Font* player_debugger;

	float fps_;
	gef::Sprite my_sprite_;


	/*..3D renderer..*/
	gef::Renderer3D* render_3D;
	gef::SpriteRenderer* sprite_renderer_;

	/*..Pawn..*/

	PrimitiveBuilder* primitive_builder;

	PawnController* player_controller;
	Pawn* player;
	Camera* main_camera;

};

#endif // _sprite_app_H
