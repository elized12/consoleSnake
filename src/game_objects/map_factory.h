#pragma once
#include "standart_map.h"

enum NameMap
{
	StMap = 0
};

class MapFactory
{
	private:
		MapFactory() = delete;

	public:

		static Map* CreateMap(NameMap nameMap);
};
