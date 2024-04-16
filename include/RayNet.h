
#pragma once

#include <iostream>
#include <fstream>

#include <memory>

#include <vector>
#include <array>
#include <string>

#include <cstdlib>
#include <cassert>

#include <cmath>
#include <random>
#include <limits>
#include <numbers>

#include <SDL2/SDL.h>

#include "Configs.h"
#include "Benchmark.h"


#define DEG_TO_RAD(deg) ((deg)*(M_PI/180.0))
#define LOG(str, val) std::cout << "--\t" str << " = " << val << "\t--" << std::endl;
#define NEWLINE std::cout << '\n';

using std::cout;
using std::endl;

using std::sin;
using std::cos;
using std::tan;
using std::sqrt;
using std::abs;

using std::vector;
using std::string;

using std::unique_ptr;
using std::shared_ptr;

