#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{

private: // private Access Modifier

    // private Properties
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int player_score = 0;
    const float move_offset = 0.1f;

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
    sf::Vector2f getPosition() {
        return position;
    }

    void setPosition(sf::Vector2f newPositionValue) {
        position = newPositionValue;
    }
    void takeDamage() {};
    void move() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // Move the player to the left
            position.x -= movement_speed * move_offset;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // Move the player to the right
            position.x += movement_speed * move_offset;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // Move the player up
            position.y -= movement_speed * move_offset;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // Move the player down
            position.y += movement_speed * move_offset;
        }
    }
    void shootBullets() {};
};

int main() {
    // creating player object
    Player player;
    // Load the player ship texture
    player.player_texture.loadFromFile("assets/textures/player_ship.png"); 
    // Set the player sprite variable
    player.player_sprite.setTexture(player.player_texture);   
    
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

        // Handle keyboard input
        player.move();

        // Clear the window
        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);

        // Display whatever you draw
        window.display();
    }

    return 0;
}