#ifndef APPDATA_HPP_
#define APPDATA_HPP_

#include <bitset>

enum class Input { Right, Left, Down, Up, Fire };
enum class State { Playing, GameOver, Win };

struct appData {
  State m_state{State::Playing};
  std::bitset<5> m_input;  // [fire, up, down, left, right]
};

#endif
