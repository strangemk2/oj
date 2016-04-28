#pragma once

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <set>

#include "linked_list.hpp"
#include "binary_tree.hpp"

template<typename T>
void print_iteratable(const T& d)
{
	for (auto &n : d) cout << n << ", ";
	cout << endl;
}
