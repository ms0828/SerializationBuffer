#include <iostream>
#include <list>
#include "CPacket.h"

struct Item
{
	int type;
	int id;
};

CPacket& operator<<(CPacket& packet, const Item& item)
{
	packet << item.type;
	packet << item.id;
	return packet;
}

CPacket& operator<<(CPacket& packet, const std::list<Item>& itemList)
{
	for (const Item& item : itemList)
	{
		packet << item;
	}
	return packet;
}

int main()
{
	CPacket itemPacket;
	CPacket itemListPacket;

	Item item;
	item.type = 1;
	item.id = 2;


	std::list<Item> itemList;
	itemList.push_back(item);
	itemList.push_back(item);
	itemList.push_back(item);

	itemPacket << item;

	itemListPacket << itemList;

	int a = 0;
}