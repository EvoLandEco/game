#include "menu_view.h"
#include "coordinate.h"

menu_view::menu_view()
    : m_window(
          sf::VideoMode(m_menu.get_w_width(), m_menu.get_height()),
          "tresinformal game_menu")
{
}

void menu_view::exec()
{
  while (m_window.isOpen())
  {
    bool must_quit{process_events()};
    if (must_quit)
      return;
    show();
  }
}

bool menu_view::process_events()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      m_window.close();
      return true; // Game is done
    }
  }
  return false;
}

void menu_view::show()
{
  // Start drawing the new frame, by clearing the screen
  m_window.clear();

  // Draw the background
  sf::Vector2f bg_dim(m_menu.get_height(), m_menu.get_height());
  sf::RectangleShape background_sprite(bg_dim);
  background_sprite.setPosition(10.0, 10.0);
  background_sprite.setFillColor(sf::Color::Black);
  m_window.draw(background_sprite);

  // Draw buttons
  draw_buttons();

  // Display all shapes
  m_window.display();
}

void menu_view::draw_buttons() noexcept
{
  sf::Color button_color;
  std::string button_label;
  for ( int i = 0; i < static_cast<int>(m_menu.get_buttons().size()); ++i)
  {
    // assign different color for buttons
    // i = 0: Action "Green"
    // i = 1: About  "Blue"
    // i = 2: Quit   "Red"
    // Only three buttons implemented
    switch (i)
    {
    case 0:
    {
      button_color = sf::Color::Green;
      button_label = "Option 1";
      break;
    }
    case 1:
    {
      button_color = sf::Color::Blue;
      button_label = "Option 2";
      break;
    }
    case 2:
    {
      button_color = sf::Color::Red;
      button_label = "Option 3";
      break;
    }
    default:
    {
      button_color = sf::Color::Black;
      button_label = "";
      break;
    }
    }

    coordinate button_position(m_menu.get_button(i).get_x(),
                               m_menu.get_button(i).get_y());

    // Create the button sprite
    sf::RectangleShape rect(m_menu.get_button(i).get_body());
    rect.setFillColor(button_color);
    rect.setOrigin(rect.getSize().x / 2.0, rect.getSize().y / 2.0);
    rect.setPosition(static_cast<float>(button_position.get_x()),
                     static_cast<float>(button_position.get_y()));

    // Create the button text
    sf::Text button_text;
    button_text.setString(button_label);
    button_text.setFont(m_game_resources.get_font());
    sf::FloatRect text_area = button_text.getLocalBounds();
    button_text.setOrigin(text_area.width / 2.0, text_area.height / 2.0);
    button_text.setPosition(static_cast<float>(button_position.get_x()),
                     static_cast<float>(button_position.get_y()));
    button_text.setCharacterSize(30);
    button_text.setFillColor(sf::Color::White);

    // Draw the buttons
    m_window.draw(rect);
    m_window.draw(button_text);
  }
}
