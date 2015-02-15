#include <irrlicht.h>

using namespace irr;

int main()
{
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1024, 768));

	device->setWindowCaption(L"Irrlicht Engine - SVG Textures Demo");

	video::IVideoDriver* driver = device->getVideoDriver();

	video::ITexture* image1 = driver->getTexture("../imgs/tiger.svg", 100, 100);
	video::ITexture* image2 = driver->getTexture("../imgs/tiger.svg", 200, 200);
	video::ITexture* image3 = driver->getTexture("../imgs/tiger.svg", 400, 400);

	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, video::SColor(255,120,102,136));

			driver->draw2DImage(image1, core::position2d<s32>(0,0));
			driver->draw2DImage(image2, core::position2d<s32>(100,100));
			driver->draw2DImage(image3, core::position2d<s32>(300,300));

			driver->endScene();
		}
	}

	device->drop();

	return 0;
}
