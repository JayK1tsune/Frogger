#ifndef PLAY_IMPLEMENTATION
#define PLAY_IMPLEMENTATION
#endif
#ifndef PLAY_USING_GAMEOBJECT_MANAGER
#define PLAY_USING_GAMEOBJECT_MANAGER
#endif
#include "Play.h"
#include "Objects.h"

void spawncar(int a, int b, int c, int d)
{
	CarObject car;
	a = car.startX;
	b = car.startY;
	c = car.collision;
	d = car.direction;

	int id_car = Play::CreateGameObject(TYPE_CAR, { a, b }, c, "car_1");
	Play::GetGameObject(id_car).velocity = { c,0 };
	GameObject& obj_car = Play::GetGameObjectByType(TYPE_CAR);



	Play::UpdateGameObject(obj_car);

	if (Play::IsLeavingDisplayArea(obj_car))
	{
		obj_car.pos.y = a;
		obj_car.pos.x = b;
		
	}
	Play::DrawObject(obj_car);
}