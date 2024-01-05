#include <Mittens.h>
class ExampleLayer : public Mittens::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override 
	{
		std::cout << "ExampleLayer Update method\n";
	}

	void OnEvent(Mittens::Event& event) override
	{
		std::cout << "ExampleLayer OnEvent method\n";
	}

};

class AppInstance : public Mittens::Application
{
public:
	AppInstance() 
	{
		PushLayer(new ExampleLayer());
	}
	~AppInstance() {}
};

Mittens::Application* Mittens::CreateApplication()
{
	std::cout << "Creating Application\n";
	return new AppInstance();
}

