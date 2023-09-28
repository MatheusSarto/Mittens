#pragma once
#include "Application.h"

#ifdef PLATAFORM_WINDOWS
#include <windows.h>
#include <string.h>
extern Mittens::Application* Mittens::CreateApplication();


int main(int argc, char** argv)
{

	auto app = Mittens::CreateApplication();

	app->Run();

	delete app;

}

#endif