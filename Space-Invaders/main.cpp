#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{

private: // private Access Modifier

    // private Properties
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int player_score = 0;

public: // public Access Modifier

    // public Properties
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    int movement_speed = 5;

    //Public Getter & Setter methods
    int getScore() const{
        return player_score;
    }

    void setScore(int newScore) {
        player_score = newScore;
    }
    void takeDamage() {};
    void move() {};
    void shootBullets() {};
};
int main() {
    // creating player object
    Player player;

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();
    }

    return 0;
}