#ifndef KEY_TO_ACTION_MAP_H
#define KEY_TO_ACTION_MAP_H
#include "action_type.h"
#include "SFML/Graphics.hpp"

/// Convert a key to an action
class key_action_map
{
public:

  ///Constructor
  key_action_map(
    const sf::Keyboard::Key& key_to_go_left = sf::Keyboard::A,
    const sf::Keyboard::Key& key_to_go_right = sf::Keyboard::D,
    const sf::Keyboard::Key& key_to_accelerate = sf::Keyboard::W,
    const sf::Keyboard::Key& key_to_brake = sf::Keyboard::S,
    const sf::Keyboard::Key& key_to_shoot = sf::Keyboard::Q,
    const sf::Keyboard::Key& key_to_stun = sf::Keyboard::E
  );

  ///Find out which action is triggered by that key
  action_type to_action(sf::Keyboard::Key key) const noexcept;

  /// Find out which key triggers that action
  sf::Keyboard::Key to_key(action_type action) const noexcept;

  ///Find out if the key is mapped
  bool has_key(sf::Keyboard::Key key) const noexcept;

  ///Returns const ref of m_map
  const std::map<sf::Keyboard::Key, action_type>& get_raw_map() const noexcept {return m_map;}

private:
  std::map<sf::Keyboard::Key, action_type> m_map;
};

/// Get the default key to action map for player 1
key_action_map get_player_1_kam();

/// Get the default key to action map for player 2
key_action_map get_player_2_kam();

/// Get the default key to action map for player 3
key_action_map get_player_3_kam();

/// Draw a random key, for testing purposes
sf::Keyboard::Key get_random_key();

/// Draw the key to shoot a stun rocket
sf::Keyboard::Key get_stun_key(const key_action_map& m);

/// Draw a random key action map, for testing purposes
key_action_map get_random_kam();

/// Draw at random several kams for testing purposes, with no key repeats
std::vector<key_action_map> get_n_random_kams(int n);


bool operator==(const key_action_map& lhs, const key_action_map& rhs) noexcept;
bool operator!=(const key_action_map& lhs, const key_action_map& rhs) noexcept;

/// Check if key has action

void test_key_action_map();

#endif // KEY_TO_ACTION_MAP_H
