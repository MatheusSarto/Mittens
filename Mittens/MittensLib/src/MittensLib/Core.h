#pragma once

#ifdef PLATAFORM_WINDOWS
	#include <Windows.h>
	#ifdef BUILD_DLL
		#define MTS_API __declspec(dllexport)
	#else
		#define MTS_API __declspec(dllimport)
	#endif
#else
	#error Only Windows Supported!
#endif

#define BIT(x) (1 << x)

#include <stdio.h>