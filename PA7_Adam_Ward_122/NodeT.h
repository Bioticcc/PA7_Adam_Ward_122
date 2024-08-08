#ifndef NODET_H
#define NODET_H

#include "Header.h"
#include "Data.h"
//#include "Stack.h"

#pragma once
template <typename T>
class NodeT
{
	

public:
	//constructor
	T data;
	NodeT* next;

	//NodeT() : data(data) : next(nullptr) {}
	NodeT(const T& data) : data(data), next(nullptr) {}
	//finally figured out why I use const &! its to avoid copying over large objects and wasting time, as sending its address is far faster!
};

#endif 

