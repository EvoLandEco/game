#include "player_state.h"
#include <cassert>

void test_player_state()
{
  assert(player_state::active != player_state::stunned);
  {
    assert(player_state::dead != player_state::stunned &&
              player_state::dead != player_state::active);
  }
  #ifdef FIX_ISSUE_276
  // Conversion to string
  {
    assert(to_str(player_state::active) == "active");
    assert(to_str(player_state::dead) == "dead");
    assert(to_str(player_state::stunned) == "stunned");
  }
  #endif // FIX_ISSUE_276
}
