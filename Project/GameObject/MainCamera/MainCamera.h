#pragma once
#include"ViewProjection.h"
#include"Input.h"
#include"ImGuiManager.h"

class MainCamera
{
public:
	MainCamera();
	~MainCamera();

	static MainCamera* GetInstance();


	static void Initiaize();

	static void Update();

	static ViewProjection GetViewProjection() { return MainCamera::GetInstance()->viewProjection_; }

private:
	ViewProjection viewProjection_{};

	static void UpDownContorol();
	static void LeRiContorol();
	static void RotateControl();
	static void ZControl();
};


