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
	NodeT(T data) : data(data), next(nullptr) {}
};

#endif 

