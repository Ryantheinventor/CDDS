#pragma once

#include <cstdint>
#include "texture.h"

template<typename T>
uint32_t hash(const T &val);


template<>
uint32_t hash<uint32_t>(const uint32_t &val)
{
	return val * 2654435761;
}

template<>
uint32_t hash<size_t>(const size_t &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<int>(const int &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<bool>(const bool &val)
{
	return hash((uint32_t)val);
}

template<>
uint32_t hash<char>(const char &val)
{
	return hash((uint32_t)val);
}

template<size_t N>
uint32_t hash(char const (&string)[N])
{
	uint32_t rHash = 0;
	for (int i = 0; i < N; i++)
	{
		uint32_t charHash = hash((uint32_t)string[i]);
		rHash = rHash ^ charHash;
	}
	return rHash;
}

template<>
uint32_t hash<texture>(const texture &val)
{
	uint32_t rHash = 0;
	rHash = rHash ^ hash(val.texID);
	rHash = rHash ^ hash(val.width);
	rHash = rHash ^ hash(val.height);
	rHash = rHash ^ hash(val.channels);


	return rHash;
}