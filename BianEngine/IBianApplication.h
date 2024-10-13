#pragma once

#define ENTRYAPP(x) IBianApplication* EntryApplication() {return new x;}

class BIAN_API IBianApplication
{
public:
	IBianApplication();
	virtual ~IBianApplication() {};
	virtual VOID SetupGameSettings() = 0;
	virtual VOID OnLoad() = 0;
	virtual VOID OnUpdate() = 0;
};

IBianApplication* EntryApplication();
