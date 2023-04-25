#include <Mittens.h>

class AppInstance : public Mittens::Application
{
public:
	AppInstance() {}
	~AppInstance() {}
};

Mittens::Application* Mittens::CreateApplication()
{
	return new AppInstance();
}

