#include "map_factory.h"

Map* MapFactory::CreateMap(NameMap nameMap)
{
	Map* map = nullptr;

	switch (nameMap)
	{
	case StMap:
		map = new StandartMap();
		break;
	default:
		break;
	}

	return map;
}

