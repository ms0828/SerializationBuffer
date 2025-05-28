#include <iostream>
#include "CPacket.h"

#pragma pack(1)
struct ST_HEADER
{
	int a = 0;
	short b = 0;
	__int64 c = 0;
	float d = 0;
	double e = 0;
};

int main()
{
	CPacket packet;
	ST_HEADER header;
	header.a = 1;
	header.b = 2;
	header.c = 3;
	header.d = 4.0f;
	header.e = 5.0;
	int putRet = packet.PutData((char*)&header, sizeof(ST_HEADER));

	packet << (char)0 << (unsigned char)1 << (short)2 << (unsigned short)3 << (long)4 << (unsigned long)5 << (__int64)6 << (unsigned __int64)7 << (float)8.0f << (double)9.0;




	
	char a;
	unsigned char b;
	short c;
	unsigned short d;
	long e;
	unsigned long f;
	__int64 g;
	unsigned __int64 h;
	float i;
	double j;


	ST_HEADER testHeader;
	int getLen = packet.GetData((char*)&testHeader, sizeof(ST_HEADER));
	packet >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

	int t = 0;
}