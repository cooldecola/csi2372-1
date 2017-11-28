#include <iostream>
#include <random>

struct RandomDice {
  unsigned random_gen(unsigned seed, unsigned min, unsigned max) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud(min, max);
    return ud(e);
  }
};
