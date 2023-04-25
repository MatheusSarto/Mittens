#pragma once

#ifdef PLATAFORM_WINDOWS
	
extern Mittens::Application* Mittens::CreateApplication();

int main(int argc, char** argv)
{
	Mittens::Application* App = Mittens::CreateApplication();
	App->Run();
	delete App;
}
#endif