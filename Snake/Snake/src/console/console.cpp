	#include "console.h"

	Console::Console()
	{
		console = GetStdHandle(STD_OUTPUT_HANDLE);
	
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

		GetConsoleScreenBufferInfo(console, &consoleInfo);

		height = abs(consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top) + 1;
		width = abs(consoleInfo.srWindow.Left - consoleInfo.srWindow.Right) + 1;

		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);

	}

	int Console::getHeight() const
	{
		return height;
	}

	void Console::setTitle(std::wstring title)
	{
		SetConsoleTitle(title.c_str());

	}

	void Console::setColorText(DWORD color)
	{
		colorText = color;

		SetConsoleTextAttribute(console, (colorText << 4) | colorBackgroundText);
	}

	void Console::setBackgroundText(DWORD color)
	{
		colorBackgroundText = color;

		SetConsoleTextAttribute(console, (colorText << 4) | colorBackgroundText);
	}

	void Console::fillConsole(DWORD color, DWORD widthFillRect, int x, int y)
	{
		COORD coord;

		coord.X = x;
		coord.Y = y;

		DWORD count;

		FillConsoleOutputAttribute(console, BACKGROUND_GREEN, 3600, coord, &count);
	}

	void Console::setCursor(int x, int y)
	{
		COORD coord;

		coord.X = x;
		coord.Y = y;

		SetConsoleCursorPosition(console, coord);
	}

	void Console::clear()
	{
		int lastColorText = colorText;

		setColorText(0);

		system("cls");

		colorText = lastColorText;

		setColorText(colorText);
	}

	void Console::setCursorVisible(bool turnOn)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;

		GetConsoleCursorInfo(console, &consoleCursorInfo);

		consoleCursorInfo.bVisible = turnOn ? TRUE : FALSE;

		SetConsoleCursorInfo(console, &consoleCursorInfo);


	}

	void Console::setEncodingConsoleOutput(UINT encodingPageId)
	{
		SetConsoleOutputCP(encodingPageId);
	}

	void Console::setEncodingConsoleInput(UINT encodingPageId)
	{
		SetConsoleCP(encodingPageId);
	}

	int Console::getWidth() const
	{
		return width;
	}

	Console ConsoleInit::init()
	{
		if (isInit) throw (L"Ошибка Инициализация");

		isInit = true;

		Console temp;

		return temp;

	}

	bool ConsoleInit::isInit = false;

	Console console = ConsoleInit::init();

