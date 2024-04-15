#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <xstring>
#include <locale>

class ConsoleInit;
class Console;

class Console 
{
	private:
		int width, height;
		HANDLE console;
		DWORD colorText;
		DWORD colorBackgroundText;

	private:
		Console();
		
	

	public:
		
		void setEncodingConsoleOutput(UINT encodingPageId);
		void setEncodingConsoleInput(UINT encodingPageId);

		int getWidth() const;
		int getHeight() const;

		void setTitle(std::wstring title);
		void setColorText(DWORD color);
		void setBackgroundText(DWORD color);
		void fillConsole(DWORD color, DWORD widthFillRect, int x, int y);
		void setCursor(int x, int y);
		void clear();
		void setCursorVisible(bool turnOn);


		friend ConsoleInit;

		template<class T>
		std::wostream& operator<<(T& type);
};

class ConsoleInit
{

	private:
		static bool isInit;

	public:
		ConsoleInit() = delete;
		ConsoleInit(const ConsoleInit& a) = delete;

	public:

		static Console init();
};

//Global object Console
extern Console console;

template<class T>
std::wostream& Console::operator<<(T& type)
{
	std::wcout << type;

	return std::wcout;
}


