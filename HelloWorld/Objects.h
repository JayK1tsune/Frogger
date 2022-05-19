#pragma once

#include <string>

class GFunctions 
{
public:

	int DISPLAY_WIDTH = 1280;
	int DISPLAY_HEIGHT = 720;
	int DISPLAY_SCALE = 1;
};
GFunctions gfunctions;
enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_AGENT8,
	TYPE_CAR,
	TYPE_LOG,
	TYPE_LIVES,
	TYPE_TURTLE,
	

};
class GObject
{
public:
	float startX;
	float startY;
	float direction;
	int collision;
	int idCar;
	int idFrog;
	int live = 3;
	bool hasCollided;
	//used to spawn lives in the bottom left
	void lives(float yPos, float xPos, float Col)
	{
		startX = xPos;
		startY = yPos;
		idFrog = Play::CreateGameObject(TYPE_LIVES, { startX, startY }, collision, "frog_1");
		
		GameObject& obj_lifes = Play::GetGameObject(idFrog);
		obj_lifes.pos.y = startY;
		obj_lifes.pos.x = startX;


	}
	//used to spawn Lilly win pads
	void lilly(float yPos, float xPos, float Col)
	{

		startX = xPos;
		startY = yPos;
		/*	collision = Col;
			direction = direc;*/


		idCar = Play::CreateGameObject(TYPE_CAR, { yPos, xPos }, Col, "lilly_pad");
		GameObject& obj_car = Play::GetGameObject(idCar);
		
		obj_car.pos.y = startY;
		obj_car.pos.x = startX;





	}
	//spawn red car
	void spawnRedCar(float yPos, float xPos, int Col, float direc)
	{
		
		startX = xPos;
		startY = yPos;
	/*	collision = Col;
		direction = direc;*/
	

		idCar = Play::CreateGameObject(TYPE_CAR, { yPos, xPos }, Col, "car_1");
		GameObject& obj_car = Play::GetGameObject(idCar);
		obj_car.velocity = { direc,0 };
		obj_car.pos.y = startY;
		obj_car.pos.x = startX;
		




	}
	//spawn blue car
	void spawnBedCar(float yPos, float xPos, int Col, float direc)
	{

		startX = xPos;
		startY = yPos;
		/*	collision = Col;
			direction = direc;*/


		idCar = Play::CreateGameObject(TYPE_CAR, { yPos, xPos }, Col, "yellow_car");
		GameObject& obj_car = Play::GetGameObject(idCar);
		obj_car.velocity = { direc,0 };
		obj_car.pos.y = startY;
		obj_car.pos.x = startX;





	}
	//spawn Lorry
	void spawnLorry(float yPos, float xPos, int Col, float direc)
	{
		xPos = 0;
		startX = xPos;
		startY = yPos;
		/*	collision = Col;
			direction = direc;*/


		idCar = Play::CreateGameObject(TYPE_CAR, { yPos, xPos }, Col, "lorry_1");
		GameObject& obj_car = Play::GetGameObject(idCar);
		obj_car.velocity = { direc,0 };
		obj_car.pos.y = startY;
		obj_car.pos.x = startX;





	}
	//spawn Logs
	void spawnLog(float yPos, float xPos, int Col, float direc)
	{

		startX = xPos;
		startY = yPos;
		/*	collision = Col;
			direction = direc;*/


		idCar = Play::CreateGameObject(TYPE_CAR, { yPos, xPos }, Col, "log_1");
		GameObject& obj_car = Play::GetGameObject(idCar);
		obj_car.velocity = { direc,0 };
		obj_car.pos.y = startY;
		obj_car.pos.x = startX;





	}
	//updates the draw functions below 
	void spawnturtle(float yPos, float xPos, int Col, float direc)
	{

		startX = xPos;
		startY = yPos;
		/*	collision = Col;
			direction = direc;*/


		Play::CreateGameObject(TYPE_TURTLE, { startX, startY }, 50, "turtle_swim_1");
		GameObject& obj_tur = Play::GetGameObjectByType(TYPE_TURTLE);
		Play::SetSprite(obj_tur, "turtle_swim_1", 0.25f);
		obj_tur.velocity = { direc,0 };
		obj_tur.pos.y = startY;
		obj_tur.pos.x = startX;
		





	}
	void UpdateLog()
	{
		GameObject& obj_car = Play::GetGameObject(idCar);
		
		GameObject& obj_Frog = Play::GetGameObjectByType(TYPE_AGENT8);
		GameObject& obj_tur = Play::GetGameObjectByType(TYPE_TURTLE);
		Play::UpdateGameObject(obj_car);
		Play::UpdateGameObject(obj_tur);

		if (Play::IsLeavingDisplayArea(obj_car))
		{
			obj_car.pos.y = startY;
			obj_car.pos.x = 0;

		}
		
		Play::DrawObject(obj_car);
		Play::DrawObject(obj_car);
		Play::DrawObject(obj_car);
		Play::DrawObject(obj_tur);
	}
	void UpdateCar()
	{
		GameObject& obj_car = Play::GetGameObject(idCar);
		GameObject& obj_Frog = Play::GetGameObjectByType(TYPE_AGENT8);
		
		idFrog = Play::CreateGameObject(TYPE_AGENT8, { startX, startY }, collision, "frog_1");

		
		Play::UpdateGameObject(obj_car);

		if (Play::IsLeavingDisplayArea(obj_car))
		{
			obj_car.pos.y = startY;
			obj_car.pos.x = 0;

		}
		if (Play::IsColliding(obj_car, obj_Frog))
		{
			live--;
			obj_Frog.pos = { 640, 720 };
			hasCollided = true;
			
		}

		Play::DrawObject(obj_car);
		
	
		if (live <= 0 )
		{
			
			Play::DrawFontText("132px", "YOU LOSE ",
			{ gfunctions.DISPLAY_WIDTH / 2, 330 }, Play::CENTRE);
			obj_Frog.velocity = { 0,0 };

		}
		
	}
	void updateEnd()
	{
		Play::CentreSpriteOrigin("lilly_pad");
		GameObject& obj_Frog = Play::GetGameObjectByType(TYPE_AGENT8);
		GameObject& obj_car = Play::GetGameObject(idCar);

		if (Play::IsColliding(obj_car, obj_Frog))
		{
			Play::DrawFontText("132px", "YOU WIN ",
				{ gfunctions.DISPLAY_WIDTH / 2, 330 }, Play::CENTRE);
		}
		Play::UpdateGameObject(obj_car);

		Play::DrawObject(obj_car);
	}
	void UpdateLives() 
	{
		GameObject& obj_lifes = Play::GetGameObject(idFrog);
		Play::UpdateGameObject(obj_lifes);

		Play::DrawObject(obj_lifes);
	}


};
GObject gobject;


//Game Objects

GObject car1;
GObject car2;
GObject car3;
GObject car4;
GObject car5;
GObject car6;
GObject car7;
GObject lorry1;
GObject lorry2;
GObject log1;

GObject log3;
GObject log4;
GObject log5;
GObject log6;

GObject lilly1;
GObject lilly2;
GObject lilly3;
GObject lilly4;
GObject lilly5;

GObject lives1;
GObject lives2;
GObject lives3;

GObject turtle1;



