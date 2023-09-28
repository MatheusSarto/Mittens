#include <Mittens.h>

class AppInstance : public Mittens::Application
{
public:
	AppInstance() {}
	~AppInstance() {}
};

Mittens::Application* Mittens::CreateApplication()
{
	OutputDebugStringA("Creating Application\n");
	return new AppInstance();
}

