#include <irr/irrlicht.h>
#include <iostream>
#include "EventReceiver.hpp"

irr::video::IVideoDriver *driver;
irr::scene::ISceneManager *scene;

int main() {
    EventReceiver *receiver = new EventReceiver;
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1200, 750), 16, false, false, false, receiver);
    irr::video::SColor color;

    if (!device) {
        exit(84);
    }

    driver = device->getVideoDriver();
    scene = device->getSceneManager();
    device->setWindowCaption(L"Workshop");
    color = irr::video::SColor(0, 255, 255, 255);

    while (device->run()) {
        if (device->isWindowActive()) {
            driver->beginScene(true, true, color);
            scene->drawAll();
            driver->endScene();
        }
    }
}
