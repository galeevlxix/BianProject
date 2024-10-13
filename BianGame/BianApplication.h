#pragma once
#include "IBianApplication.h"

class BianApplication : public IBianApplication
{
public:
	BianApplication();
	~BianApplication();
	VOID SetupGameSettings();
	VOID OnLoad();
	VOID OnUpdate();
};