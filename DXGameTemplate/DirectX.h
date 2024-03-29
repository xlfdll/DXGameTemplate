#pragma once

#include "Include.h"
#include "Configuration.h"
#include "State.h"

bool InitializeDirect3D();
void ShutdownDirect3D();

void InitializeDirectInput();
void UpdateDirectInputDevices();
void ShutdownDirectInput();

LPDIRECT3DSURFACE9 LoadDirect3DSurfaceFromFile(LPCTSTR fileName);
void DrawDirect3DSurface(LPDIRECT3DSURFACE9 source, LPDIRECT3DSURFACE9 dest, LONG x, LONG y);

LPDIRECT3DTEXTURE9 LoadDirect3DTexture(LPCTSTR fileName, D3DCOLOR transparentColor = D3DCOLOR_XRGB(0, 0, 0));

void DrawTextureFrame(LPDIRECT3DTEXTURE9 texture, int frame, float x, float y, LONG width, LONG height,
	int frameColumnCount, D3DCOLOR drawColor);
void DrawTextureFrame(LPDIRECT3DTEXTURE9 texture, int frame, float x, float y, LONG width, LONG height,
	int frameColumnCount, D3DCOLOR drawColor, float rotation, float scaling);

void DrawTile(LPDIRECT3DSURFACE9 source, int tileNumber, int tileWidth, int tileHeight, int tileColumnCount,
	LPDIRECT3DSURFACE9 dest, int x, int y);

#define KEYDOWN(index) (keys[index] & 0x80)
#define MOUSEDOWN(index) (mouseState.rgbButtons[index] & 0x80)