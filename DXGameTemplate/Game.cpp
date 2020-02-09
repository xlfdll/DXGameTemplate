#include "Game.h"

bool InitializeGame()
{
	if (!InitializeDirect3D())
	{
		return false;
	}

	InitializeDirectInput();

	// TODO: Initialization

	return true;
}

void UpdateGame()
{
	UpdateDirectInputDevices();
	UpdateController();

	// TODO: Logic

	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (d3ddev->BeginScene())
	{
		// TODO: Render

		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}

	// Use Esc key to quit

	if (KEYDOWN(DIK_ESCAPE) || CONTROLLER_BUTTONDOWN(0, XINPUT_GAMEPAD_BACK))
	{
		PostMessage(hWnd, WM_DESTROY, NULL, NULL);
	}
}

void ShutdownGame()
{
	// TODO: Exit

	ResetController();

	ShutdownDirectInput();
	ShutdownDirect3D();
}