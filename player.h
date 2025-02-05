#ifndef PLAYER_H
#define PLAYER_H

#include "action_type.h"
#include "color.h"
#include "coordinate.h"
#include "player_shape.h"
#include "player_state.h"
#include "read_only.h"
#include <cmath>
#include <vector>
#include <set>


class player
{
public:
  player(const coordinate c = coordinate(0.0, 0.0),
           const player_shape shape = player_shape::rocket,
           const player_state state = player_state::active,
           const double player_max_speed = 2,
           const double player_acceleration = 0.1,
           const double player_deceleration = -0.001,
           const double player_acc_backward = -0.1,
           const double size = 100.0,
           const double turn_rate = 0.01,
           const color &any_color = color(),
           const std::string& ID = "0");


    /// Get the acceleration of the player
    double get_acceleration() const noexcept { return m_player_acceleration; }

    ///Get the backward acceleration of the player
    double get_acceleration_backward() const noexcept { return m_player_acc_backward; }

    ///Returns const ref to action set of the player
    const std::set<action_type>& get_action_set() const noexcept {return m_action_set;}

    ///Returns const ref to action set of the player
    std::set<action_type>& get_action_set() noexcept {return m_action_set;}

    /// Get the color of the player
    const color &get_color() const noexcept { return m_color; }

    /// Get the coordinate of the player
    coordinate get_position() const noexcept { return m_c; }

    /// Get the X coordinate of the player
    double get_x() const noexcept;

    /// Get the Y coordinate of the player
    double get_y() const noexcept;

    /// Get the shape of the player
    player_shape get_shape() const noexcept { return m_shape; }

    /// Get the state of the player
    player_state get_state() const noexcept { return m_state; }

    /// Get the radius of the player
    double get_diameter() const noexcept;

    ///Gets the ID of a player
    std::string get_ID() const noexcept {return m_ID.get_value(); }

    /// Get the speed of the player
    double get_speed() const noexcept { return m_player_speed; }

    /// Get the speed of the player
    double get_max_speed() const noexcept { return m_player_max_speed; }

    /// Get the direction of player movement, in radians
    double get_direction() const noexcept;

    /// Get the player's health
    double get_health() const noexcept { return m_health; }


    /// Is the player shooting?
    /// When a player shoots, 'm_is_shooting' is true for one tick.
    /// 'game' reads 'm_is_shooting' and if it is true,
    /// it (1) creates a projectile, (2) sets 'm_is_shooting' to false
    bool is_shooting() const noexcept { return m_is_shooting; }

    bool is_shooting_stun_rocket() const noexcept { return m_is_shooting_stun_rocket; }

    ///Places a player to a given x,y poisition
    void place_to_position(const coordinate& position) noexcept
    {
        m_c = position;
    }

    ///Set the color of the player
    void set_color(const color &c) {m_color = c;}

    /// Set the state of the player
    void set_state(const player_state &s) noexcept { m_state = s; }

    /// The player shoots, does nothing for now
    /// When a player shoots, 'm_is_shooting' is true for one tick.
    /// 'game' reads 'm_is_shooting' and if it is true,
    /// it (1) creates a projectile, (2) sets 'm_is_shooting' to false
    void shoot() noexcept { m_is_shooting = true; }

    /// Make the player stop shooting
    /// When a player shoots, 'm_is_shooting' is true for one tick.
    /// 'game' reads 'm_is_shooting' and if it is true,
    /// it (1) creates a projectile, (2) makes the player stop shooting
    void stop_shooting() noexcept { m_is_shooting = false; }

    void shoot_stun_rocket() noexcept { m_is_shooting_stun_rocket = true; }

    void stop_shooting_stun_rocket() noexcept { m_is_shooting_stun_rocket = false; }

    /// Set a player x position
    void set_x(double x) noexcept { m_c.set_x(x); }

    /// Set a player y position
    void set_y(double y) noexcept { m_c.set_y(y); }

    /// Turn the player left
    void turn_left() noexcept { m_direction_radians -= m_turn_rate; }

    /// Turn the player right
    void turn_right() noexcept { m_direction_radians += m_turn_rate; }

    //move a player
    void move() noexcept;

    /// Accelerate the player
    void accelerate() noexcept;

    /// Brake the player
    void brake() noexcept;

    /// Accelerate the player backward
    void acc_backward() noexcept;

    /// Make the player grow
    void grow();

    /// Make the player shrink
    void shrink();

private:
    /// The player's color, will change depending on food items
    color m_color;

  //The set of ongoing actions of a player
    std::set<action_type> m_action_set;

    /// When a player shoots, 'm_is_shooting' is true for one tick.
    /// 'game' reads 'm_is_shooting' and if it is true,
    /// it (1) creates a projectile, (2) sets 'm_is_shooting' to false
    bool m_is_shooting{false};

    bool m_is_shooting_stun_rocket{false};

    ///ID of the player
    read_only<std::string> m_ID;

    /// The coordinate of the player
    coordinate m_c;

    /// The shape of the player
    player_shape m_shape;

    /// The state of the player
    player_state m_state;

    /// The speed of the player
    double m_player_speed = 0;

    /// The maximum speed of the player
    double m_player_max_speed;

    /// The acceleration of the player
    double m_player_acceleration;

    /// The acceleration of the player
    double m_player_deceleration;

    ///The backward acceleration of player
    double m_player_acc_backward;

    /// The size of the player
    double m_diameter;

    /// How much a player grows when growing
    double m_growth_factor = 1.1;

    /// The direction of player in radians
    double m_direction_radians = 270 * M_PI / 180;

    /// The rate at which the player turns
    double m_turn_rate;

    /// Player's health percentage, the player always start with max health at
    /// construction
    double m_health = 1.0;
};

///Adds an action to the action set
void add_action(player& p, action_type action) noexcept;

/// Checks if two players are colliding
bool are_colliding(const player &p1, const player &p2) noexcept;

///create a player with a set color
player create_player_with_color(const color& in_color);

/// Get the blueness (from the color) of the player
int get_blueness(const player &p) noexcept;

/// Get the greenness (from the color) of the player
int get_greenness(const player &p) noexcept;

/// Get the redness (from the color) of the player
int get_redness(const player &p) noexcept;

/// Is a player blue?
bool is_blue(const player &p) noexcept;

/// Is a player green?
bool is_green(const player &p) noexcept;

/// Is a player red?
bool is_red(const player &p) noexcept;

/// Set player to stun
void stun(player &p) noexcept;

/// Is a player alive?
bool is_alive(const player& p) noexcept;

/// Is a player active?
bool is_active(const player &p) noexcept;

/// Is a player dead?
bool is_dead(const player& p) noexcept;

/// Is a player stunned?
bool is_stunned(const player &p) noexcept;

///Get color index
int get_colorhash(const player &p) noexcept;

///Removes an action from action set of the player
void remove_action(player& p, action_type) noexcept;

player create_player_with_id(const std::string& id);

/// Test the player class
void test_player();

/// Create player
player create_red_player();
player create_green_player();
player create_blue_player();
//winning scenario
bool is_first_player_loser(const player& player_one, const player& player_two);
bool is_first_player_winner (const player& player_one, const player& player_two);
#endif // PLAYER_H
