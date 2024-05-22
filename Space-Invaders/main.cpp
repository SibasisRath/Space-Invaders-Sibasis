#include <SFML/Graphics.hpp>

int main() {

    // Define the video mode (dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    // Create a window object with specific dimensions and a title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // Game loop to keep the window open
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear the window
        window->clear(sf::Color::Black);

        // Draw your content here...
        // Draw a circle
        sf::CircleShape circle(50); // Radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(0, 0); // Set position
        window->draw(circle);

        // Draw a Square
        sf::RectangleShape square(sf::Vector2f(50,50));
        square.setFillColor(sf::Color::Red);
        square.setPosition(200, 200); // Set position
        window->draw(square);


        // Draw a triangle 
        sf::CircleShape tri(80, 3);
        tri.setFillColor(sf::Color::Blue);
        tri.setPosition(500, 500);
        window->draw(tri);

        // Draw a png. Take the png as the texture of a sprite
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(200, 100); // Position
        outscal_sprite.setRotation(45); // Rotation in degrees
        outscal_sprite.setScale(0.5, 0.5); // Scale factor

        window->draw(outscal_sprite);

        // Display what was drawn
        window->display();
    }

    return 0;
}