#include "MyGame.h"

using namespace std;

CMyGame::CMyGame(void) {}

CMyGame::~CMyGame(void) {}


// --------  game initialisation --------
void CMyGame::OnInitialize()
{
	// Loading graphics and sound assets
	cout << "Loading assets" << endl;
	carryAmount = 0;
	font.LoadDefault(); 
	CTexture::smooth=true;
	// enable lighting
	Light.Enable();
	screen1.LoadImageW("kye1.bmp");
	screen1.SetPosition(450, 350);

	screen2.LoadImageW("kye2.bmp");
	screen2.SetPosition(450, 350);

	screen3.LoadImageW("kye3.bmp");
	screen3.SetPosition(450, 350);
	// abarlith model
	player.LoadModel("Abarlith.md2","Abarlith.bmp"); 
	player.SetScale( 3.5f);
	
	// grass model
	grass.LoadModel("grass.obj", "grass.tga");
	grass.SetScale(1.5f);
	//ogro model
	ogro.LoadModel("ogro.md2", "ogro.bmp");
	ogro.SetScale(5.0f);
	//robot model
	robot.LoadModel("enemyOne.md2", "enemyOne.bmp");
	robot.SetScale(5.0f);
	// box model
	box.LoadModel("box.obj", "box.bmp");
	box.SetScale(3.0f);
	// coin model
	coin.LoadModel("coin.obj", "coin.bmp");
	coin.SetScale(7.0f);
	
	// cobra model
	cobra.LoadModel("cobra.md2", "cobra.bmp");
	cobra.SetScale(5.0f);
	
	// snake model
	snake.LoadModel("snake.md2", "snake.bmp");
	snake.SetScale(5.0f);
	
	//projectile model
	projectile.LoadModel("projectile.obj", "coin.bmp");
	projectile.SetScale(5.0f);
	// screen sprite
	
	
	// floor texture
	floor.LoadTexture("floor.bmp");
	floor.SetTiling(true);
	
	// player health bar
	hbar.SetSize(30,5);
	hbar.SetHealth(100);
	healCount = 0;
	ammo = 5;
	damage = 10;
	levelCD = 90;
	meleeCD = 60;
	menuState = 0;
	currentLevel = 1;
}

	
void CMyGame::OnStartLevel(int level)
{
	player.SetHealth(100);
	shotList.clear();
	snakeList.clear();
	wallList.clear();
	boxList.clear();
	levelCD = 90;
	//level 1-5 arena
	if (level < 6)
	{
		floor.SetSize(6000, 6000);

		//top left wall
		CModel* pWall = new CModel(-2850, 25, -2300, 300, 60, 50, CColor(50, 30, 10));
		wallList.push_back(pWall);
		//wall adj to top left
		pWall = new CModel(-2700, 25, -2350, 300, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top right of middle wall
		pWall = new CModel(600, 25, -2750, 500, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//middle wall
		pWall = new CModel(0, 25, 0, 150, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//right middle wall
		pWall = new CModel(1860, 25, 300, 300, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//bottom left wall
		pWall = new CModel(-600, 25, 2750, 500, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//bottom right wall
		pWall = new CModel(1260, 25, 2800, 400, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//bottom right adj wall
		pWall = new CModel(1210, 25, 2600, 150, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//left diagonal wall
		pWall = new CModel(-1300, 25, 1400, 1000, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(45);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//left middle wall
		pWall = new CModel(-1850, 25, -1000, 600, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//right dia wall
		pWall = new CModel(1900, 25, 1500, 750, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(-45);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top left L wall
		pWall = new CModel(1700, 25, -1700, 500, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top left L adj wall
		pWall = new CModel(1925, 25, -1950, 500, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top center
		pWall = new CModel(-600, 25, -1600, 750, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(54);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);
	}
	if (level > 5 && level < 10)
	{
		floor.SetSize(5000, 5000);

		//middle wall
		CModel* pWall = new CModel(0, 25, 0, 150, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//right middle wall
		pWall = new CModel(1860, 25, 300, 300, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//left diagonal wall
		pWall = new CModel(-1300, 25, 1400, 1000, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(45);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//left middle wall
		pWall = new CModel(-1850, 25, -1000, 600, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//right dia wall
		pWall = new CModel(1900, 25, 1500, 750, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(-45);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top left L wall
		pWall = new CModel(1700, 25, -1700, 500, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(90);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top left L adj wall
		pWall = new CModel(1925, 25, -1950, 500, 60, 50, CColor(50, 30, 10));
		pWall->SetHealth(1000);
		wallList.push_back(pWall);

		//top center
		pWall = new CModel(-600, 25, -1600, 750, 60, 50, CColor(50, 30, 10));
		pWall->Rotate(54);
		pWall->SetHealth(1000);
		wallList.push_back(pWall);
	}
	if (level == 1)
	{
		levelOne();
	}
	
	if (level == 2)
	{
		levelTwo();
	}

	if (level == 3)
	{
		levelThree();
	}
	
	if (level == 4)
	{
		levelFour();
	}

	if (level == 5)
	{
		levelFive();
	}

	if (level == 6)
	{
		levelSix();
	}

	if (level == 7)
	{
		levelSeven();
	}

	if (level == 8)
	{
		levelEight();
	}

	if (level == 9)
	{
		levelNine();
	}

	if (level == 10)
	{
		floor.SetSize(5000, 5000);

		//middle wall
		wallList.clear();
		CModel* pWall = new CModel(0, 25, 0, 150, 60, 50, CColor(50, 30, 10));
		wallList.push_back(pWall);

		levelTen();
	}
}
  
// Game Logic in the OnUpdate function called every frame @ 30 fps

void CMyGame::OnUpdate() 
{
	if (IsMenuMode() || IsGameOver()) return;
	
	long t =  GetTime();
	
	// --- updating models ----
	
	coinList.Update(t);
	snakeList.Update(t);
	shotList.Update(t);
	boxList.Update(t);
	projectileList.Update(t);
	if (meleeCD > 0) 
	{
		meleeCD--;
	}
	if (meleeCD < 0)
	{
		meleeCD = 0;
	}
	for (CModel* pBox : boxList)
	{
		pBox->Update(t);
	}
	for (CModel* pWall : wallList)
	{
		pWall->Update(t);
		if (pWall->GetHealth() < 1)
		{
			pWall->Delete();
		}
	}
	wallList.remove_if(deleted);
	for (CModel* pShot : shotList)
	{
		pShot->Update(t);
	}

	for (CModel* pShot : projectileList)
	{
		pShot->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
		pShot->Update(t);
	}

	PlayerControl();
	SnakeControl();
	ShotsControl();
	projectileControl();
	
	if (snakeList.size() == 0)
	{
		if (currentLevel < 10)
		{
			if (levelCD > 0)
			{
				levelCD--;
			}
			else
			{
				currentLevel++;
				OnStartLevel(currentLevel);
			}
		}
		else
		{
			GameOver();
		}
	}
		
	//cheat code
	//player.SetHealth(100);
}

void CMyGame::ShotsControl()
{
	//collision detection for shots and snakes
	for (CModel* pSnake : snakeList)
	{
		for (CModel* pShot : shotList)
		{
			if (pShot->HitTestFront(pSnake))
			{
				pSnake->SetHealth(pSnake->GetHealth() - damage);
				pShot->Delete();
				if (pSnake->GetHealth() == 0)
				{
					death.SetVolume(10);
					death.Play("monsterdeath.wav");
					pSnake->Delete();
					//ammo drop spawn
					if (rand() % 3 == 0)
					{
						box.SetToFloor(0);

						CModel* pBox = box.clone();
						pBox->SetPositionV(pSnake->GetPositionV());
						pBox->SetToFloor(0);
						pBox->SetOmega(50);
						pBox->SetStatus(0);
						boxList.push_back(pBox);
					}
					else if (rand() % 10 == 0)
					{
						box.SetToFloor(0);

						CModel* pBox = coin.clone();
						pBox->SetPositionV(pSnake->GetPositionV());
						pBox->SetToFloor(0);
						pBox->SetOmega(50);
						pBox->SetStatus(1);
						boxList.push_back(pBox);
					}
				}
			}
			break;
		}
	}

	shotList.remove_if(deleted);
	snakeList.remove_if(deleted);

	




	for (CModel* pShot : shotList)
	{
		if (currentLevel < 6)
		{

			// remove shots if outside the game area
			if (pShot->GetX() > 3000) { pShot->Delete(); }
			if (pShot->GetX() < -3000) { pShot->Delete(); }
			if (pShot->GetZ() > 3000) { pShot->Delete(); }
			if (pShot->GetZ() < -3000) { pShot->Delete(); }
		}
		if (currentLevel > 5)
		{

			// remove shots if outside the game area
			if (pShot->GetX() > 2500) { pShot->Delete(); }
			if (pShot->GetX() < -2500) { pShot->Delete(); }
			if (pShot->GetZ() > 2500) { pShot->Delete(); }
			if (pShot->GetZ() < -2500) { pShot->Delete(); }
		}
	}
	shotList.remove_if(deleted);
}

void CMyGame::SnakeControl()
{
	
	//setting speed and direction
	for (CModel* pSnake : snakeList)
	{
		pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
		if (pSnake->GetStatus() == 1)
		{
			pSnake->SetSpeed(400);
		}
		else if (pSnake->GetStatus() == 2 && (player.GetPositionV() - pSnake->GetPositionV()).Magnitude() > 750)
		{
			pSnake->SetSpeed(350);
		}
		else if (pSnake->GetStatus() == 2 && (player.GetPositionV() - pSnake->GetPositionV()).Magnitude() < 751)
		{
			pSnake->SetSpeed(10);
		}

		else
		{
			pSnake->SetSpeed(300);
		}
	}
	
	//snake repel
	for (CModel* sSnake : snakeList)
	{
		CVector v = sSnake->GetDirectionV()* sSnake->GetSpeed();
		
		for (CModel* pSnake : snakeList) {
			if (sSnake != pSnake) {
				CVector dist = sSnake->GetPositionV() - pSnake->GetPositionV();
				dist.SetY(0);
				v += dist.Normalized() * max(30, 100 / dist.Magnitude());
			}
		}
		sSnake->SetVelocityV(v);
		
	}
	
	//wall collison
	for (CModel* pWall : wallList)
	{
		for (CModel* pSnake : snakeList)
		{

			if (pSnake->HitTest(pWall))
			{

				pSnake->Stop();
				if (pSnake->GetStatus() == 1)
				{
					//play animation
					pWall->SetHealth(pWall->GetHealth() - 1);
				}
			}
		}

	}

	//player collision
	for (CModel* pSnake : snakeList)
	{
			if (pSnake->HitTestFront(&player))
			{

				pSnake->Stop();
				if (pSnake->GetStatus() == 0)
				{
					//play animation
					player.SetHealth(player.GetHealth() - 2);
				}
				else if (pSnake->GetStatus() == 1)
				{
					//play animation
					damageSound.SetVolume(10);
					damageSound.Play("damage.wav");
					player.SetHealth(player.GetHealth() - 1);
				}
			}
		
	}


	//snake collision
	for (CModel* sSnake : snakeList) {


		for (CModel* pSnake : snakeList)
		{

			if (pSnake->HitTest(sSnake))
			{
				if (pSnake != sSnake) 
				{

					if ((player.GetPositionV() - pSnake->GetPositionV()).Magnitude() > (player.GetPositionV() - sSnake->GetPositionV()).Magnitude())
					{
						pSnake->Stop();
					}
					else
					{
						sSnake->Stop();
					}
				}
				
				
			}

		}
	}
	//bounds check
	for(CModel* pSnake:snakeList)
		{
			if (currentLevel < 6)
			{
				pSnake->Update(GetTime());
				if (pSnake->GetX() > 2900) pSnake->SetX(2900);
				if (pSnake->GetX() < -2900) pSnake->SetX(-2900);
				if (pSnake->GetZ() > 2900) pSnake->SetZ(2900);
				if (pSnake->GetZ() < -2900) pSnake->SetZ(-2900);

			}
			else if (currentLevel > 5)
			{
				pSnake->Update(GetTime());
				if (pSnake->GetX() > 2400) pSnake->SetX(2400);
				if (pSnake->GetX() < -2400) pSnake->SetX(-2400);
				if (pSnake->GetZ() > 2400) pSnake->SetZ(2400);
				if (pSnake->GetZ() < -2400) pSnake->SetZ(-2400);

			}
		}
	//robot attack
	shotCD--;
	for (CModel* pSnake : snakeList)
	{
		if (pSnake->GetStatus() == 2)
		{
			if ((player.GetPositionV() - pSnake->GetPositionV()).Magnitude() < 800 &&  rand()%120==0)
			{
				cout << "shooting pew pew" << endl;
				//play animation
				CModel* pShot = new CLine(pSnake->GetPositionV(), 50, CColor(128,0,0));
				// rotation and direction same as the player
				pShot->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
				pShot->Move(50); // move starting point in front of the player
				pShot->SetSpeed(550);
				pShot->Die(3000);
				projectileList.push_back(pShot);
				shotCD = 150;
			}
		}
	}
	projectileList.remove_if(deleted);
	if (shotCD < 1)
	{
		shotCD = 150;
	}
}

void CMyGame::projectileControl()
{
	for (CModel* pShot : projectileList)
	{
		if (player.HitTest(pShot))
		{
			player.SetHealth(player.GetHealth() - 30);
			pShot->Delete();
		}
	}
	projectileList.remove_if(deleted);
}

void CMyGame::levelOne()
{
	player.SetPosition(0, 100, 75); player.SetStatus(0);
	//robot spawn

	//snake spawn
	snake.SetToFloor(0);
	snake.SetSpeed(400);
	snake.PlayAnimation(1, 8, 7, true);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();

	CModel* pSnake = ogro.clone();
	pSnake->SetPosition(-2600, 0, -2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage*2);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetStatus(0);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2800, 0, -2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetStatus(0);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->SetPosition(2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);
}

void CMyGame::levelTwo()
{
	//snake spawn
	snake.SetToFloor(0);
	snake.SetSpeed(400);
	snake.PlayAnimation(1, 8, 7, true);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	snakeList.clear();

	CModel* pSnake = ogro.clone();
	pSnake->SetPosition(-2800, 0, -2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2600, 0, -2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2600, 0, -2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);
}

void CMyGame::levelThree()
{
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();
	
	CModel* pSnake = ogro.clone();
	pSnake->SetPosition(-2800, 0, -2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(-2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(2600, 0, 2600);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(2600, 0, -2600);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);
}

void CMyGame::levelFour()
{
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();

	CModel* pSnake = robot.clone();
	pSnake->SetPosition(2800, 0, 2800); 
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetPosition(2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetPosition(2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(2400, 0, -2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2800, 0, -2800);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2600, 0, -2600);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2600, 0, 2600);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2400, 0, 2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

}
 
void CMyGame::levelFive()
{
	//snake spawn
	snake.SetToFloor(0);
	snake.SetSpeed(400);
	snake.PlayAnimation(1, 8, 7, true);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	snakeList.clear();

	CModel* pSnake = snake.clone();
	pSnake->Move(2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2600, 0, -2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2800, 0, -2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2600, 0, 2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2800, 0, 2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2600, 0, -2600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2800, 0, -2800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(-2400, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);

	pSnake = ogro.clone();
	pSnake->SetPosition(2400, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);

	snakeList.push_back(pSnake);
}

void CMyGame::levelSix()
{
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	snakeList.clear();


	CModel* pSnake = robot.clone();
	pSnake->SetPosition(-2400, 0, 2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(-2400, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2200, 0, 2200);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

}

void CMyGame:: levelSeven()
{
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();

	CModel* pSnake = robot.clone();
	pSnake->SetPosition(2400, 0, -2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2400, 0, -2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(2400, 0, 2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(-2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2200, 0, 2200);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

}

void CMyGame::levelEight()
{
	snake.SetToFloor(0);
	snake.SetSpeed(400);
	snake.PlayAnimation(1, 8, 7, true);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();

	CModel* pSnake = robot.clone();
	pSnake->SetPosition(2400, 0, -2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->SetPosition(-2400, 0, -2400);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(2200, 0, 2200);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->SetPosition(-2200, 0, 2200);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2000, 0, 2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2000, 0, 2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(0, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(0, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->SetStatus(1);
	pSnake->PlayAnimation(1, 8, 7, true);
	snakeList.push_back(pSnake);
}

void CMyGame::levelNine()
{
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	snakeList.clear();

	CModel* pSnake = ogro.clone();
	pSnake->Move(2400, 0, -2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(2400, 0, -1800);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2400, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2200, 0, -2200);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2200, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(2200, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);
}

void CMyGame::levelTen()
{
	snake.SetToFloor(0);
	snake.SetSpeed(400);
	snake.PlayAnimation(1, 8, 7, true);
	ogro.SetToFloor(0);
	ogro.SetSpeed(300);
	robot.SetToFloor(0);
	robot.SetSpeed(350);
	snakeList.clear();

	CModel* pSnake = ogro.clone();
	pSnake->Move(2400, 0, -2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->Move(2400, 0, -1800);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2400, 0, -1600);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2400, 0, -2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->Move(-2200, 0, -2200);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2200, 0, -2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(-2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->Move(-2200, 0, 2200);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(-2200, 0, 2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

	pSnake = ogro.clone();
	pSnake->Move(2400, 0, 2400);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(0);
	pSnake->SetToFloor(1);
	pSnake->PlayAnimation(40, 45, 5, true);
	snakeList.push_back(pSnake);

	pSnake = robot.clone();
	pSnake->Move(2200, 0, 2200);
	pSnake->PlayAnimation(40, 45, 5, true);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage * 2);
	pSnake->SetStatus(2);
	pSnake->SetToFloor(1);
	snakeList.push_back(pSnake);

	pSnake = snake.clone();
	pSnake->Move(2200, 0, 2000);
	pSnake->SetDirectionAndRotationToPoint(player.GetX(), player.GetZ());
	pSnake->SetHealth(damage);
	pSnake->PlayAnimation(1, 8, 7, true);
	pSnake->SetStatus(1);
	snakeList.push_back(pSnake);

}

void CMyGame::PlayerControl()
{
	bool move=true;
	
	//ammo box
	for (CModel* pBox : boxList)
	{
		if (player.HitTest(pBox) && pBox->GetStatus()==0)
		{
			ammo += 5;
			pBox->Delete();
		}
		else if (player.HitTest(pBox) && pBox->GetStatus() == 1)
		{
			healCount += 1;
			pBox->Delete();
		}
	}
	boxList.remove_if(deleted);
	

	//walls
	for (CModel* pWall : wallList)
	{
		if(player.HitTestFront(pWall))
		{

			move = false; player.Stop();

		}
	}
	//snakes	
	for (CModel* pSnake : snakeList)
	{
		if (player.HitTestFront(pSnake))
		{

			move = false; player.Stop();

		}
	}
	//bounds
	if (currentLevel < 6)
	{
		player.Update(GetTime());
		if (player.GetX() > 2900) player.SetX(2900);
		if (player.GetX() < -2900) player.SetX(-2900);
		if (player.GetZ() > 2900) player.SetZ(2900);
		if (player.GetZ() < -2900) player.SetZ(-2900);

	}
	else if (currentLevel > 5)
	{
		player.Update(GetTime());
		if (player.GetX() > 2400) player.SetX(2400);
		if (player.GetX() < -2400) player.SetX(-2400);
		if (player.GetZ() > 2400) player.SetZ(2400);
		if (player.GetZ() < -2400) player.SetZ(-2400);

	}
	if (IsKeyDown(SDLK_w) || player.IsAutoMoving())
	{
      if (move) player.SetSpeed(500);
	}
	else player.SetSpeed(0);
	if (IsKeyDown(SDLK_h) && healCount > 0)
	{
		if (player.GetHealth() < 65)
		{
			healCount--;
			heal.SetVolume(10);
			heal.Play("heal.wav");
			player.SetHealth(player.GetHealth() + 35);
		}
		else
		{
			heal.SetVolume(10);
			heal.Play("heal.wav");
			player.SetHealth(100);
		}
	}
		
	// play running sequence when UP key is pressed
	// otherwise play standing sequence
	
	if (IsKeyDown(SDLK_w) || player.IsAutoMoving() || player.GetSpeed() > 0)  player.PlayAnimation(40,45,7,true);
	else player.PlayAnimation(1,39,7,true);

	if (player.GetHealth() <= 0)
	{
		gameOver.Play("gameover.wav");
		GameOver();
	}
}


//-----------------  Draw 2D overlay ----------------------
void CMyGame::OnDraw(CGraphics* g)
{
	if (IsMenuMode() && menuState==0) {
		// draw screen here
		screen1.Draw(g);
		return;
	}
	if (IsMenuMode() && menuState == 1) {
		// draw screen here
		screen2.Draw(g);
		return;
	}
	if (IsMenuMode() && menuState == 2) {
		// draw screen here
		screen3.Draw(g);
		return;
	}
	if (ammo == 0)
	{
		font.SetColor(CColor::Blue()); font.SetSize(32); font.DrawText(Width/4, Height - 50, "out of ammo");
	}
	if (levelCD < 90 && levelCD > 60 )
	{
		font.SetColor(CColor::Blue()); font.SetSize(64); font.DrawText(Width /2, Height /2, "3");
	}
	if (levelCD < 61 && levelCD > 30)
	{
		font.SetColor(CColor::Blue()); font.SetSize(64); font.DrawText(Width / 2, Height / 2, "2");
	}
	if (levelCD < 31 && levelCD > 0)
	{
		font.SetColor(CColor::Blue()); font.SetSize(64); font.DrawText(Width / 2, Height / 2, "1");
	}
	// draw GTEC 3D text
	font.SetColor( CColor::Blue()); font.SetSize( 32); font.DrawText( Width-200,Height-50, "Kyes game" );
	font.SetColor(CColor::Blue()); font.SetSize(32); font.DrawText(10, Height - 50, "ammo");
	font.SetColor( CColor::Red()); font.DrawNumber(10,Height-100, ammo);
	font.SetColor(CColor::Blue()); font.SetSize(32); font.DrawText(Width / 2, Height - 50, "Current Wave");
	font.SetColor(CColor::Red()); font.DrawNumber(Width/2, Height - 100, currentLevel);
	font.SetColor(CColor::Blue()); font.SetSize(32); font.DrawText(Width / 2, 50, "Enemies left");
	font.SetColor(CColor::Red()); font.DrawNumber(Width / 2, 10, snakeList.size());
	font.SetColor(CColor::Blue()); font.SetSize(32); font.DrawText(Width / 4, 50, "Heals left");
	font.SetColor(CColor::Red()); font.DrawNumber(Width / 4, 10, healCount);
	CVector pos=WorldToScreenCoordinate(player.GetPositionV());
	hbar.SetPosition(pos.x,pos.y+50); 
	hbar.SetHealth( player.GetHealth());
	hbar.Draw(g);
	
	
	
	// draw GAME OVER if game over
   	if (IsGameOver())
   	{
		if (currentLevel == 10)
		{
			font.SetSize(64); font.SetColor(CColor::Red()); font.DrawText(250, 300, "YOU WIN");
		}
		else 
		{
			font.SetSize(64); font.SetColor(CColor::Red()); font.DrawText(250, 300, "GAME OVER");
		}
			
	}
	
}

void CMyGame::CameraControl(CGraphics* g)
{
	// game world tilt
    float tilt=70; 
    float scale=1.0f;
	
	// ------ Global Transformation Functions -----
	
	//glTranslatef(0,-100,0);  // move game world down 
	glRotatef(tilt,1,0,0);			// tilt game world around x axis
    glScalef(scale,scale,scale);			// scaling the game world
	
	// ---- 3rd person camera setup -----
	//glRotatef( rotation,0,1,0);		// rotate game world around y axis
	glTranslatef(-player.GetX(), 0, -player.GetZ());    // position game world
		
	UpdateView();
	Light.Apply();
}


// ----------------   Draw 3D world -------------------------
void CMyGame::OnRender3D(CGraphics* g)
{
	CameraControl(g);

	// ------- Draw your 3D Models here ----------

	floor.Draw(g); // if true with grid, false without grid
	//floor.Draw(true); //grid
	player.Draw(g);


	wallList.Draw(g);
	shotList.Draw(g);
	snakeList.Draw(g);
	projectileList.Draw(g);
	boxList.Draw(g);
	//ShowBoundingBoxes();
	ShowCoordinateSystem();
	//grassList.Draw(g);
	//coinList.Draw(g);
	
	for (CModel* pBox : boxList)
	{
		pBox->Draw(g);
	}

	for (CModel* pSnake : snakeList)
	{
		pSnake->Draw(g);
	}
}





// called at the start of a new game - display menu here
void CMyGame::OnDisplayMenu()
{
 
}

// called when Game Mode entered
void CMyGame::OnStartGame()
{
	music.SetVolume(5);
	music.Play("music.wav", -1);
	player.SetPosition(0, 100, 75); player.SetStatus(0);
    OnStartLevel(currentLevel);	
   
}


// called when Game is Over
void CMyGame::OnGameOver()
{
	music.Stop();
}

// one time termination code
void CMyGame::OnTerminate()
{
	
}

// -------    Keyboard Event Handling ------------

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_SPACE)
	{
		if (IsPaused()) ResumeGame();
		else PauseGame();

	}
	if (sym == SDLK_F2) {
		music.Stop();
		NewGame();
		OnInitialize();
		OnStartLevel(1);
	}
	if (sym == SDLK_1)
	{
		if (IsMenuMode() && menuState == 0)
		{
			StartGame();
		}
		else if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 1;
			StartGame();
		}
	}
	if (sym == SDLK_2 )
	{
		if (IsMenuMode() && menuState == 0)
		{
			menuState = 1;
		}
		else if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 2;
			StartGame();
		}
	}
	if (sym == SDLK_3)
	{
		if (IsMenuMode() && menuState == 0)
		{
			menuState = 2;
		}
		else if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 3;
			StartGame();
		}
	}
	
	if (sym == SDLK_4)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 4;
			StartGame();
		}
	}
	if (sym == SDLK_5)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 5;
			StartGame();
		}
	}
	if (sym == SDLK_6)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 6;
			StartGame();
		}
	}
	if (sym == SDLK_7)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 7;
			StartGame();
		}
	}
	if (sym == SDLK_8)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 8;
			StartGame();
		}
	}
	if (sym == SDLK_9)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 9;
			StartGame();
		}
	}
	if (sym == SDLK_0)
	{
		if (IsMenuMode() && menuState == 1)
		{
			currentLevel = 10;
			StartGame();
		}
		
	}
	if (sym == SDLK_b)
	{
		if (IsMenuMode() && menuState == 1)
		{ 
			menuState = 0;
		}
		else if (IsMenuMode() && menuState == 2)
		{
			menuState = 0;
		}
	}
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	
}

// -----  Mouse Events Handlers -------------

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
	CVector pos=ScreenToFloorCoordinate(x,y);
	
	player.SetDirectionAndRotationToPoint(pos.x,pos.z);
	
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{    
	if (!IsMenuMode()) {
		if (ammo > 0)
		{

			// create a new shot dynamically as a short line
			CModel* pShot = new CLine(player.GetPositionV(), 50);
			// rotation and direction same as the player
			pShot->SetDirection(player.GetRotation());
			pShot->SetRotation(player.GetRotation());
			pShot->Move(50); // move starting point in front of the player
			laser.SetVolume(10);
			laser.Play("laser.wav");
			pShot->SetSpeed(3000);
			pShot->Die(5000);
			shotList.push_back(pShot);
			ammo--;
		}
		shotList.remove_if(deleted);
	}
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
	if (!IsMenuMode()) {

		if (meleeCD == 0) {
			//trying to make melee attack without an animation 
			for (CModel* pSnake : snakeList)
			{
				CVector dist = player.GetPositionV() - pSnake->GetPositionV();
				CVector playerDir = player.GetDirectionV();
				

				if (dist.Magnitude() < 250 && (playerDir.Dot(dist) < 0))
				{
					cout << "we in dis bitch" << endl;
					//play animation
					player.PlayAnimation(57, 69, 8, false);
					death.SetVolume(10);
					if (pSnake->GetStatus() == 1)
					{
						pSnake->SetHealth(0);
					}
					else if (pSnake->GetStatus() != 1)
					{
						pSnake->SetHealth(pSnake->GetHealth() - 10);
					}
					if (pSnake->GetHealth() < 1)
					{
						death.Play("monsterdeath.wav");
						pSnake->Delete();
						if (rand() % 3 == 0)
						{
							box.SetToFloor(0);
							CModel* pBox = box.clone();
							pBox->SetPositionV(pSnake->GetPositionV());
							pBox->SetToFloor(0);
							pBox->SetOmega(50);
							boxList.push_back(pBox);
						}
						else if (rand() % 10 == 0)
						{
							box.SetToFloor(0);

							CModel* pBox = coin.clone();
							pBox->SetPositionV(pSnake->GetPositionV());
							pBox->SetToFloor(0);
							pBox->SetOmega(50);
							pBox->SetStatus(1);
							boxList.push_back(pBox);
						}
					}

				}

			}
			snakeList.remove_if(deleted);
			meleeCD = 60;
		}
	}
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
