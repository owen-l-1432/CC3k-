#include "seed.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine rng{seed};
