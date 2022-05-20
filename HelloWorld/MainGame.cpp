#ifndef PLAY_IMPLEMENTATION
#define PLAY_IMPLEMENTATION
#endif
#ifndef PLAY_USING_GAMEOBJECT_MANAGER
#define PLAY_USING_GAMEOBJECT_MANAGER
#endif
#include "Play.h"
#include "Objects.h"

void HandlePlayerControls();
void UpdateObjects();
//void Lives();


// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( gfunctions.DISPLAY_WIDTH, gfunctions.DISPLAY_HEIGHT, gfunctions.DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\Frogger.png");
	//Play::StartAudioLoop("music");
	Play::CreateGameObject(TYPE_AGENT8, { 640, 720 }, 20, "Frog");
	Play::CentreSpriteOrigin("Frog");
	//top cars
	car1.spawnRedCar(410, 0, 50, 5);
	car7.spawnBedCar(410, 600, 50, 5);
	car3.spawnRedCar(410, 960, 50, 5);
	//bottom cars
	car6.spawnBedCar(600, 800, 50, 7);
	car2.spawnRedCar(600, 280, 50, 7);

	//middle cars
	car4.spawnBedCar(510, 800, 50, 4);
	car5.spawnBedCar(510, 400, 50, 4);
	lorry1.spawnLorry(510, -200, 50, 2);
	//bottom lane 1
	log1.spawnLog(240, 800, 50, 3);
	log3.spawnLog(240, 400, 50, 3);
	log7.spawnLog(240, -200, 50, 3);
	log4.spawnLog(150, 50, 50, 6);
	log5.spawnLog(150, 800, 50, 6);
	log6.spawnLog(150, 1000, 50, 6);

	//turtle1.spawnturtle(200, 0,50, 5);

	//lillypads
	lilly1.lilly(70, 160, 50);
	lilly2.lilly(70, 390, 50);
	lilly3.lilly(70, 620, 50);
	lilly4.lilly(70, 850, 50);
	lilly5.lilly(70, 1075, 50);

	lives1.lives(700, 5,0);
	lives2.lives(700, 50,0);
	lives3.lives(700, 100,0);
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::DrawBackground();
	HandlePlayerControls();
	UpdateObjects();
	
	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
}
void HandlePlayerControls()
{

	GameObject& obj_Frog = Play::GetGameObjectByType(TYPE_AGENT8);
	Play::CentreSpriteOrigin("Frog_1");
	Play::CentreSpriteOrigin("jumping_frog");
	if (Play::KeyDown(VK_UP))
	{
		obj_Frog.velocity = { 0, -4 };
		

		
		Play::SetSprite(obj_Frog, "jumping_frog", 0.05f);
	}
	else if (Play::KeyDown(VK_DOWN))
	{
		obj_Frog.velocity = { 0, 4 };
	
		Play::SetSprite(obj_Frog, "jumping_frog", 0.05f);

	}
	else if (Play::KeyDown(VK_LEFT))
	{
		obj_Frog.velocity = { -4, 0 };
		
		Play::SetSprite(obj_Frog, "jumping_frog", 0.05f);
	}
	else if (Play::KeyDown(VK_RIGHT))
	{
		obj_Frog.velocity = { 4, 0 };
		Play::SetSprite(obj_Frog, "jumping_frog", 0.05f);
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
void UpdateObjects()
{
	car1.UpdateCar();
	car2.UpdateCar();
	car3.UpdateCar();
	car4.UpdateCar();
	car5.UpdateCar();
	car6.UpdateCar();
	car7.UpdateCar();
	lorry1.UpdateCar();
	log1.UpdateLog();
	log3.UpdateLog();
	log4.UpdateLog();
	log5.UpdateLog();
	log6.UpdateLog();
	log7.UpdateLog();
	turtle1.UpdateLog();
	lilly1.updateEnd();
	lilly2.updateEnd();
	lilly3.updateEnd();
	lilly4.updateEnd();
	lilly5.updateEnd();
	lives1.UpdateLives();
	lives2.UpdateLives();
	lives3.UpdateLives();



}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	
	return PLAY_OK;
//}
//void Lives()
//{
//	std::vector<int> lives_id = Play::CollectGameObjectIDsByType(TYPE_LIVES);
//	gobject.idFrog = Play::CreateGameObject(TYPE_LIVES, { gobject.startX, gobject.startY }, gobject.collision, "frog_1");
//	GameObject& obj_lifes = Play::GetGameObject(gobject.idFrog);
//	if (lives1.live > 3)
//	{
//		Play::DestroyGameObject(lives_id[0]);
//	}

