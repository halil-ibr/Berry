#include <Berry.h>

class Sandbox : public Berry::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Berry::Application* Berry::CreateApplication()
{
	return new Sandbox();
}