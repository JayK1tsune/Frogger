#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

struct Gamestate
{
	int score = 0;
};
Gamestate gamestate;

enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_AGENT8,
};
void HandlePlayerControls();

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\Frogger.png");
	Play::StartAudioLoop("music");
	Play::CreateGameObject(TYPE_AGENT8, { 640, 720 }, 20, "Frog");
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::DrawBackground();
	HandlePlayerControls();
	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
}
void HandlePlayerControls()
{
	GameObject& obj_Frog = Play::GetGameObjectByType(TYPE_AGENT8);
	if (Play::KeyDown(VK_UP))
	{
		obj_Frog.velocity = { 0, -4};
		Play::SetSprite(obj_Frog, "Frog_3", 0.2f);
	}
	else if (Play::KeyDown(VK_DOWN))
	{
		obj_Frog.acceleration = { 0, 1 };
		//obj_Frog.animSpeed = 0.5;
		Play::SetSprite(obj_Frog, "Frog_3", 0.2f);
		
	}
	else if (Play::KeyDown(VK_LEFT))
	{
		obj_Frog.acceleration = { -1, 0 };
		Play::SetSprite(obj_Frog, "Frog_3", 0.2f);
	}
	else if (Play::KeyDown(VK_RIGHT))
	{
		obj_Frog.acceleration = { 1, 0 };
		Play::SetSprite(obj_Frog, "Frog_3", 0.2f);
	}
	else
	{
		Play::SetSprite(obj_Frog, "Frog_1", 0.05f);
		obj_Frog.velocity *= 0.5f;
		obj_Frog.acceleration = { 0, 0 };
	}
	Play::UpdateGameObject(obj_Frog);
	if (Play::IsLeavingDisplayArea(obj_Frog))
		obj_Frog.pos = obj_Frog.oldPos;
	//Play::DrawLine({ obj_Frog.pos.x, 0 }, obj_Frog.pos, Play::cWhite);
	   Play::DrawObjectRotated(obj_Frog);
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

