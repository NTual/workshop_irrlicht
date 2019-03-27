//
// EPITECH PROJECT, 2018
// bomberman
// File description:
// event receiver
//

#pragma once

#include <irr/irrlicht.h>

class EventReceiver : public irr::IEventReceiver
{
public:
	EventReceiver()
		{
			for (irr::u32 i = 0; i<irr::KEY_KEY_CODES_COUNT; ++i)
				KeyIsDown[i] = false;
		}
public:
	virtual bool OnEvent(const irr::SEvent& event)
		{
			if (event.EventType == irr::EET_KEY_INPUT_EVENT)
				KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			return false;
		}
	virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
		{
			return KeyIsDown[keyCode];
		}
private:
	bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};
