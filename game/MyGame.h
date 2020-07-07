#pragma once


#include "Game.h"


class CMyGame : public CGame
{
public:
	CMyGame();
	~CMyGame();

    // ----  Declare your game variables and objects here -------------

	// Variables
	int score;
	int carryAmount;
	int currentLevel;
	bool a;
	int ammo;
	int damage;
	int levelCD;
	int shotCD;
	int meleeCD;
	int healCount;
	int menuState;

    // Models and Model Lists
    CModelMd2 player;   // animated player model
    CModel box;		// another box (obj model)
	CModel grass;
	CModel coin;
	CModel barricade;
	CModel projectile;
	CModelMd2 ogro;
	CModelMd2 robot;
	CModelMd2 snake;
	CModelMd2 cobra;
	CModelList shotList;
	CModelList wallList;
	CModelList coinList;
	CModelList grassList;
	CModelList cobraList;
	CModelList snakeList;
	CModelList boxList;
	CModelList projectileList;
	
	
	
	
	// splash screen
	CSprite screen1;
	CSprite screen2;
	CSprite screen3;

	// game world floor
	CFloor floor;
	
	// health indicator
	CHealthBar hbar;

	
	// Font
	CFont font;


	//noises
	CSoundPlayer damageSound;
	CSoundPlayer gameOver;
	CSoundPlayer heal;
	CSoundPlayer laser;
	CSoundPlayer reload;
	CSoundPlayer wallHit;
	CSoundPlayer waveStart;
	CSoundPlayer death;
	CSoundPlayer music;
   // -----   Add you member functions here ------
   
	void SnakeControl();
	void ShotsControl();
	void PlayerControl();
	void projectileControl();
	void levelOne();
	void levelTwo();
	void levelThree();
	void levelFour();
	void levelFive();
	void levelSix();
	void levelSeven();
	void levelEight();
	void levelNine();
	void levelTen();
	void CameraControl(CGraphics* g);

   // ---------------------Event Handling --------------------------

	// Game Loop Funtions
	virtual void OnUpdate();
	virtual void OnDraw(CGraphics* g);
	virtual void OnRender3D(CGraphics* g);

	// Game Life Cycle
	virtual void OnInitialize();
	virtual void OnDisplayMenu();
	virtual void OnStartLevel(int level);
	virtual void OnStartGame();
	virtual void OnGameOver();
	virtual void OnTerminate();

	// Keyboard Event Handlers
	virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

	// Mouse Events Handlers
	virtual void OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle);
	virtual void OnLButtonDown(Uint16 x,Uint16 y);
	virtual void OnLButtonUp(Uint16 x,Uint16 y);
	virtual void OnRButtonDown(Uint16 x,Uint16 y);
	virtual void OnRButtonUp(Uint16 x,Uint16 y);
	virtual void OnMButtonDown(Uint16 x,Uint16 y);
	virtual void OnMButtonUp(Uint16 x,Uint16 y);
};
