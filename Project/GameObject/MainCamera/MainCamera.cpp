#include"MainCamera.h"

MainCamera::MainCamera()
{
}

MainCamera::~MainCamera()
{
}

inline MainCamera* MainCamera::GetInstance()
{
	static MainCamera instance;
	return &instance;
}

void MainCamera::Initiaize()
{
	MainCamera::GetInstance()->viewProjection_.translation_.z = -10;
	MainCamera::GetInstance()->viewProjection_.translation_.y = 4;
	MainCamera::GetInstance()->viewProjection_.UpdateMatrix();
}

void MainCamera::Update()
{
	UpDownContorol();
	LeRiContorol();
	RotateControl();
	ZControl();

	ImGui::Begin("Camera");
	ImGui::Text("W,S yMove");
	ImGui::Text("A,D xMove");
	ImGui::Text("UP,DOWN zMove");
	ImGui::Text("LEFT,RIGHT yRotate");
	ImGui::End();

	MainCamera::GetInstance()->viewProjection_.UpdateMatrix();
}

void MainCamera::UpDownContorol()
{
	const float kSpeed = 0.1f;

	if (Input::PushKey(DIK_W))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.y += kSpeed;
	}
	else if (Input::PushKey(DIK_S))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.y -= kSpeed;
	}
}

void MainCamera::LeRiContorol()
{
	const float kSpeed = 0.1f;

	if (Input::PushKey(DIK_D))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.x += kSpeed;
	}
	else if (Input::PushKey(DIK_A))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.x -= kSpeed;
	}
}

void MainCamera::RotateControl()
{
	const float kSpeed = 0.01f;

	if (Input::PushKey(DIK_RIGHT))
	{
		MainCamera::GetInstance()->viewProjection_.rotation_.y += kSpeed;
	}
	else if (Input::PushKey(DIK_LEFT))
	{
		MainCamera::GetInstance()->viewProjection_.rotation_.y -= kSpeed;
	}
}

void MainCamera::ZControl()
{
	const float kSpeed = 0.1f;

	if (Input::PushKey(DIK_UP))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.z += kSpeed;
	}
	else if (Input::PushKey(DIK_DOWN))
	{
		MainCamera::GetInstance()->viewProjection_.translation_.z -= kSpeed;
	}
}
